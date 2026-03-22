#include "../external/nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

#ifndef TEST_H 
#define TEST_H

void display_question(const json& questions_data, int question_index);
double run_test(const json& questions_data);

#endif
