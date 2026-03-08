#include <iostream>
#include <string>
#include "../external/nlohmann/json.hpp"

using json = nlohmann::json;

// --- OUTPUT FUNCTION ---
void display_question(const json& questions_data, int question_index) {
    auto& q = questions_data["questions"][question_index];

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "Category: " << q["category"].get<std::string>() 
         << " | Points: " << q["points"] << std::endl;
    std::cout << "Question: " << q["question"].get<std::string>() << std::endl;

    auto& options = q["options"];
    for (int i = 0; i < options.size(); ++i) {
        std::cout << "  " << i + 1 << ") " << options[i].get<std::string>() << std::endl;
    }
}

