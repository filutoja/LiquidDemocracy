#include <gtest/gtest.h>

#include "votes_counter.h"

class VotesCounterTests : public ::testing::Test {
public:
    std::unique_ptr<VotesCounter> votes_counter;

    void SetUp() {
        votes_counter = std::make_unique<VotesCounter>();
    }

    void TearDown() {
        votes_counter.reset();
    }
};

TEST_F(VotesCounterTests, EmptyInput) {
    EXPECT_EQ("0 Invalid\n", votes_counter->CountVotes({}));
}

TEST_F(VotesCounterTests, InvalidDataVoteTooShort) {
    std::vector<std::string> input_data{"HakunaMatata"};
    std::string expected {"1 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, InvalidDataVoteTooLong) {
    std::vector<std::string> input_data{"To be, or not to be"};
    std::string expected {"1 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, InvalidDataVoteWrongDecision) {
    std::vector<std::string> input_data{"Just Do It"};
    std::string expected {"1 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, SamePersonVotesTwice) {
    std::vector<std::string> input_data{"Bill pick Potato",
                                        "Bill pick Tomato"};
    std::string expected {"2 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, DelegatesHimself) {
    std::vector<std::string> input_data{"Bill delegate Bill"};
    std::string expected {"1 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, OneCorrectVote) {
    std::vector<std::string> input_data{"Bill pick Orange"};
    std::string expected {"1 Orange\n"
                          "0 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, TwoCorrectVotesWithOneDelagate) {
    std::vector<std::string> input_data{"Bill pick Orange",
                                        "Tom delegate Bill"};
    std::string expected {"2 Orange\n"
                          "0 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}

TEST_F(VotesCounterTests, TwoDelegatesNoPicks) {
    std::vector<std::string> input_data{"Bill delegate El",
                                        "Tom delegate Bill"};
    std::string expected {"2 Invalid\n"};

    EXPECT_EQ(expected, votes_counter->CountVotes({input_data}));
}
