#include "sources/auth.cpp"
#include "sources/menu.cpp"
#include "sources/stats.cpp"
#include "sources/test.cpp"
#include <fstream>
#include <iostream>

int main() {
  std::string username, password;
  int auth_choice;
  bool authenticated = false;

  // --- STEP 1: AUTHENTICATION LOOP ---
  while (!authenticated) {
    std::cout << "\n=== WELCOME TO THE MATH APP ===\n";
    std::cout << "1. Sign Up\n2. Log In\n3. Exit\nSelection: ";
    std::cin >> auth_choice;

    if (auth_choice == 3)
      return 0;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (auth_choice == 1) {
      create_user(username, password);
    } else if (auth_choice == 2) {
      if (login_user(username, password)) {
        authenticated = true;
      }
    } else {
      std::cout << "Invalid choice.\n";
    }
  }

  // --- STEP 2: APP CONTENT (Only reached if authenticated is true) ---

  // Load your data files
  std::ifstream file("data/statistics.json");
  if (!file.is_open()) {
    std::cerr << "Error: could not open statistics file\n";
    return 1;
  }
  json statistics_json;
  file >> statistics_json;
  file.close();

  std::ifstream file_test("data/math-questions.json");
  if (!file_test.is_open()) {
    std::cerr << "Error: could not open math-questions file\n";
    return 1;
  }
  json math_test;
  file_test >> math_test;
  file_test.close();

  // Start the actual app logic
  show_menu();
  handle_user_choice(input_choice(), statistics_json, math_test);

  return 0;
}
