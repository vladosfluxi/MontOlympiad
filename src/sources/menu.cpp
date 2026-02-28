#include "../headers/menu.h"
#include <iostream>

void show_menu() {
  std::cout << "\n===== ELECTRONIC SCHOOL SYSTEM =====\n";
  std::cout << "1. Learning content\n";
  std::cout << "2. Generate & take a test\n";
  std::cout << "3. Statistics\n";
  std::cout << "4. Exit\n";
}

char input_choice() {
  char choice;

  while (true) {
    std::cout << "Enter your choice (1-4): ";

    if (!(std::cin >> choice)) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }

    if (choice >= '1' && choice <= '4') {
      std::cin.ignore(1000, '\n');
      return choice;
    }

    std::cout << "Invalid choice. Please try again.\n";
    std::cin.ignore(1000, '\n');
  }
}

void handle_user_choice(char choice) {
  switch (choice) {
  case '1':
    break;

  case '2':
    break;

  case '3':
    break;
  case '4':
    std::cout << "Exiting program...\n";
    break;

  default:
    std::cout << "Unexpected error.\n";
    break;
  }
}
