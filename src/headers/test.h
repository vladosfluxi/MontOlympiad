#include "../external/nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

#ifndef TEST_H 
#define TEST_H

void display_question(json test,int question_number);

#endif
