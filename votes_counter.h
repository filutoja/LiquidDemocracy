#ifndef VOTES_COUNTER_H
#define VOTES_COUNTER_H

#include "node.h"

#include <string>
#include <vector>
#include <map>

class VotesCounter
{
public:
    VotesCounter() = default;
    std::string CountVotes(const std::vector<std::string>& input_data);

private:
    struct Vote {
        std::string name {};
        std::string decision {};
        std::string election {};
    };

    void AddVote(const Vote& vote);
    std::string ConvertElectionsToStringResult();
    std::vector<std::vector<std::string>> Split(const std::vector<std::string>& input);

    std::map<std::string, NodePtr> voters {};
    std::map<std::string, NodePtr> elections {};
    unsigned votes_number {};
};

#endif // VOTES_COUNTER_H
