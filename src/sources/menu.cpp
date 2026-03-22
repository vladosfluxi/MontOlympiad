#include "../headers/menu.h"
#include "../headers/learn.h"
#include "../headers/stats.h"
#include "../headers/test.h"
#include <iostream>

void clear_screen() {
  std::cout << "\033[2J\033[H" << std::flush;
}

void pause() {
  std::cout << "\nPress Enter to continue...";
  std::cin.ignore(1000, '\n');
}

void show_menu() {
  clear_screen();
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

void handle_user_choice(char choice, const json& stats, const json& questions, const std::string& username) {
  switch (choice) {
  case '1':
    show_learning_content();
    break;

  case '2': {
    double score = run_test(questions);
    save_result(username, score);
    break;
  }

  case '3':
    for (auto it = stats.begin(); it != stats.end(); ++it) {
      show_lowest(stats, it.key());
      show_highest(stats, it.key());
      show_average(stats, it.key());
    }
    pause();
    break;

  default:
    std::cout << "Unexpected error.\n";
    break;
  }
}
