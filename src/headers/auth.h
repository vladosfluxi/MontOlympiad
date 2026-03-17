#include "../external/nlohmann/json.hpp"
#include "../external/picosha2.h"
#include <fstream>
#include <string>

using json = nlohmann::json;

#ifndef AUTH_H
#define AUTH_H

std::string hash_password(const std::string &password);

void create_user(std::string name, std::string password);

json load_users();

void save_users(std::string name, std::string password);

bool login_user(std::string name, std::string password);

#endif
