#include "../headers/stats.h"
#include <iostream>

void show_lowest(const json& data, const std::string& subject) {
    if (!data.contains(subject)) return;

    // Get the array of students
    auto& students = data[subject]["students"];
    
    // Initialize with a very high number or the first student's score
    double lowestScore = std::numeric_limits<double>::max();
    std::string worstStudentName = "None";

    for (const auto& student : students) {
        double currentScore = student["score"].get<double>();
        
        if (currentScore < lowestScore) {
            lowestScore = currentScore;
            worstStudentName = student["name"];
        }
    }

    std::cout << "Lowest in " << subject << ": " << worstStudentName 
              << " with " << lowestScore << std::endl;
}

// <----- SHOW HIGHES IMPLEMENTATION
void show_highest(const json& data, const std::string& subject) {
    if (!data.contains(subject) || !data[subject].is_array()) return;

    double highest = std::numeric_limits<double>::lowest();
    
    for (const auto& student : data[subject]) {
        double score = student.value("score", 0.0);
        if (score > highest) {
            highest = score;
        }
    }
    
    std::cout << "Highest score in " << subject << ": " << highest << std::endl;
}
