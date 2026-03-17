#include "../headers/auth.h"
#include "../external/nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

json load_users() {
  std::ifstream file("data/users.json");

  if (!file.is_open())
    return json::object();

  if (file.peek() == std::ifstream::traits_type::eof())
    return json::object();

  json j;

  try {
    file >> j;

    if (!j.is_object()) {
      return json::object();
    }
  } catch (const json::parse_error &e) {
    return json::object();
  }

  return j;
}

void save_users(const json &j) {
  std::ofstream file("data/users.json");
  if (file.is_open()) {
    file << j.dump(4);
  }
}

void create_user(std::string name, std::string password) {
  json users = load_users();

  if (users.contains(name)) {
    std::cout << "Error: Username already taken.\n";
    return;
  }

  std::string hashed_pw = picosha2::hash256_hex_string(password);

  // This part creates a nested object for each user
  users[name] = {{"password", hashed_pw}};

  save_users(users);
  std::cout << "Signup successful for " << name << "!\n";
}

bool login_user(std::string name, std::string password) {
  json users = load_users();

  if (!users.contains(name)) {
    std::cout << "User not found.\n";
    return false;
  }

  std::string input_hash = picosha2::hash256_hex_string(password);

  std::string stored_hash = users[name].at("password").get<std::string>();

  if (input_hash == stored_hash) {
    std::cout << "Login successful! Welcome, " << name << ".\n";
    return true;
  }

  std::cout << "Incorrect password.\n";
  return false;
}
