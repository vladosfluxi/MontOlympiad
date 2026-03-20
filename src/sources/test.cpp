#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "../external/nlohmann/json.hpp"
#include "../headers/menu.h"

using json = nlohmann::json;

// --- OUTPUT FUNCTION ---
void display_question(const json& questions_data, int question_index) {
    auto& q = questions_data["questions"][question_index];

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "Category: " << q["category"].get<std::string>() 
         << " | Points: " << q["points"] << std::endl;
    std::cout << "Question: " << q["question"].get<std::string>() << std::endl;

    auto& options = q["options"];
    for (int i = 0; i < (int)options.size(); ++i) {
        std::cout << "  " << i + 1 << ") " << options[i].get<std::string>() << std::endl;
    }
}

void run_test(const json& questions_data) {
    clear_screen();
    const auto& questions = questions_data["questions"];
    int total = (int)questions.size();

    int num_questions;
    while (true) {
        std::cout << "How many questions? (1-" << total << "): ";
        if (std::cin >> num_questions && num_questions >= 1 && num_questions <= total) {
            std::cin.ignore(1000, '\n');
            break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. ";
    }

    std::vector<int> indices(total);
    for (int i = 0; i < total; ++i) indices[i] = i;
    std::shuffle(indices.begin(), indices.end(), std::mt19937{std::random_device{}()});
    indices.resize(num_questions);

    int correct = 0;
    int earned_points = 0;
    int max_points = 0;

    for (int qi = 0; qi < num_questions; ++qi) {
        int idx = indices[qi];
        const auto& q = questions[idx];
        int points = q["points"].get<int>();
        max_points += points;

        clear_screen();
        std::cout << "Question " << qi + 1 << " of " << num_questions;
        display_question(questions_data, idx);

        int answer;
        while (true) {
            std::cout << "Your answer (1-4): ";
            if (std::cin >> answer && answer >= 1 && answer <= 4) {
                std::cin.ignore(1000, '\n');
                break;
            }
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. ";
        }

        int correct_idx = q["answer"].get<int>();
        if (answer - 1 == correct_idx) {
            std::cout << "Correct!\n";
            ++correct;
            earned_points += points;
        } else {
            std::cout << "Wrong! Correct answer was: "
                      << q["options"][correct_idx].get<std::string>() << "\n";
        }
    }

    std::cout << "\n========== RESULTS ==========\n";
    std::cout << "Correct: " << correct << "/" << num_questions << "\n";
    std::cout << "Points:  " << earned_points << "/" << max_points << "\n";
    double pct = max_points > 0 ? 100.0 * earned_points / max_points : 0.0;
    std::cout << "Score:   " << pct << "%\n";
    std::cout << "==============================\n";
}

