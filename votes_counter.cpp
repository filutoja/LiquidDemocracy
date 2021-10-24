#include "votes_counter.h"

#include <algorithm>
#include <set>
#include <utility>
#include <sstream>
#include <iterator>

std::string VotesCounter::CountVotes(const std::vector<std::string>& input_data) {
    auto splited_data = Split(input_data);

    for(const auto v : splited_data) {
        if(v.size() != 3) {
            continue;
        }
        const Vote vote {v[0], v[1], v[2]};

        if(vote.name == vote.election) {
            continue;
        }
        if(voters.find(vote.name) == voters.end()) {
                voters[vote.name] = std::make_shared<Node>(vote.name);
        } else if(auto parent = voters[vote.name]->GetParent().lock()) {
            parent->RemoveChild(vote.name);
            continue;
        }

        AddVote(vote);
    }

    return ConvertElectionsToStringResult();
}

std::vector<std::vector<std::string>> VotesCounter::Split(const std::vector<std::string>& input) {
    std::vector<std::vector<std::string>> res;
    for(const auto& line : input) {
        votes_number++;
        std::istringstream buffer(line);
        res.push_back({std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>()});
    }
    return res;
}

void VotesCounter::AddVote(const Vote& vote){
    if(vote.decision == "pick") {
        if(elections.find(vote.election) == elections.end()) {
            elections[vote.election] = std::make_shared<Node>(vote.election);
        }
        elections[vote.election]->AddChild(voters[vote.name]);
        voters[vote.name]->SetParent(elections[vote.election]);
    } else if(vote.decision == "delegate") {
        if(voters.find(vote.election) == voters.end()) {
            voters[vote.election] = std::make_shared<Node>(vote.election);
        }
        voters[vote.election]->AddChild(voters[vote.name]);
        voters[vote.name]->SetParent(voters[vote.election]);
    }
}

std::string VotesCounter::ConvertElectionsToStringResult() {
    std::set <std::pair<int, std::string>> ordered_elections;
    for(const auto& election : elections) {
        ordered_elections.insert({election.second->CountAllChildren(), election.first});
    }

    unsigned valid_votes {};
    std::string res {};

    for (auto it = ordered_elections.rbegin(); it != ordered_elections.rend(); ++it){
       if(it->first != 0) {
           res+= std::to_string(it->first) + " " + it->second + "\n";
           valid_votes += it->first;
       }
    }
    res += std::to_string(votes_number - valid_votes) + " Invalid\n";
    return res;
}
