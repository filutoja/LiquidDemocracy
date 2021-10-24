#include <iostream>
#include <string>
#include <vector>

#include "votes_counter.h"

int main()
{
    std::vector<std::string> input_data;
    for (std::string line; std::getline(std::cin, line) && !line.empty();) {
        input_data.push_back(line);
    }

    VotesCounter vote_counter;
    std::cout << vote_counter.CountVotes(input_data);
    return 0;
}
