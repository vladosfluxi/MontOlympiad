#include <iostream>
#include <string>
#include "../external/nlohmann/json.hpp"

using json = nlohmann::json;

#ifndef MENU_H
#define MENU_H

void show_menu();
char input_choice();
void handle_user_choice(char choice, const json& stats, const json& questions);

#endif
