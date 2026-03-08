#include "sources/stats.cpp"
#include "sources/menu.cpp"
#include "sources/test.cpp"
#include <fstream>


int main(){

  ifstream file("data/statistics.json");
  
  if(!file.is_open()){
    std::cerr << "Error: could not open a file";
    return 1;
  }
  
  json statistics_json;
  file >> statistics_json;

  file.close();
  
  ifstream file_test("data/math-questions.json");
  if(!file_test.is_open()){
    std::cerr << "Error: could not open a file";
    return 1;
  }

  json math_test;

  file_test >> math_test;

  show_menu();
  handle_user_choice(input_choice());
}



