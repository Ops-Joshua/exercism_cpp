#include <array>
#include <string>
#include <vector>
#include <charconv>


// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // Implement round_down_scores
    //first a vector of ints
    std::vector<int> rd_scores;
    for ( auto num : student_scores)
    {
         rd_scores.push_back(static_cast<int>(num));
    }
    return rd_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // Implement count_failed_students
    int fails {0};
    for (auto count : student_scores)
    {
        if (count <= 40) ++fails;
    }
    return fails;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    //Implement letter_grades
    int interval {};
    
    interval = static_cast<int>((highest_score - 40) / 4);
    std::array grade_marks = {41, (41 + interval), (41 + interval * 2), (41 + interval * 3)};
    return grade_marks;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    //Implement student_ranking
    std::vector<std::string> rank{};
    for (std::size_t i = 0; i < student_scores.size(); ++i)
    {
        //  {"1. Joci: 100", "2. Sara: 99", "3. Kora: 90", "4. Jan: 84", "5. Indra: 66", "6. Bern: 53", "7. Fred: 47"}
        std::string combo = std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);
        rank.push_back(combo);
    }
    return rank;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // Implement perfect_score
    for (std::size_t i = 0; i < student_scores.size(); ++i)
    {
            if (student_scores[i] == 100)
            {
               return  student_names[i];
            } 
    }
    return ("");
}
