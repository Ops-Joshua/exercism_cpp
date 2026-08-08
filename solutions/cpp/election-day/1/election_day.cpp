#include <string>
#include <vector>

namespace election
{

    // The election result struct is already created for you:

    struct ElectionResult
    {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    // Task 1
    // vote_count takes a reference to an `ElectionResult` as an argument and will
    // return the number of votes in the `ElectionResult.
    int vote_count(ElectionResult &candidate_result)
    {
        return candidate_result.votes;
    }

    // Task 2
    // increment_vote_count takes a reference to an `ElectionResult` as an argument
    // and a number of votes (int), and will increment the `ElectionResult` by that
    // number of votes.
    void increment_vote_count(ElectionResult &candidate_result, int vote_add)
    {
        candidate_result.votes += vote_add;
    }

    // Task 3
    // determine_result receives the reference to a final_count and returns a
    // reference to the `ElectionResult` of the new president. It also changes the
    // name of the winner by prefixing it with "President". The final count is given
    // in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
    // `ElectionResults` of all the participating candidates.
    ElectionResult &determine_result(std::vector<ElectionResult>& all_results)
    {
        int i_top{0};
        int top_vote{all_results[0].votes};

        for (std::size_t i = 1; i < all_results.size(); ++i)
        {
            if (all_results[i].votes > top_vote)
            {
                i_top = i;
                top_vote = all_results[i].votes;
            }
        }
        all_results[i_top].name = "President " + all_results[i_top].name;
        
        return all_results[i_top];
    }

} // namespace election
