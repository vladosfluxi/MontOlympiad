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
    if (!data.contains(subject)) return;

    auto& students = data[subject]["students"];
    double highest = std::numeric_limits<double>::lowest();
    std::string bestStudentName = "None";

    for (const auto& student : students) {
        double score = student["score"].get<double>();
        if (score > highest) {
            highest = score;
            bestStudentName = student["name"];
        }
    }

    std::cout << "Highest in " << subject << ": " << bestStudentName
              << " with " << highest << std::endl;
}

void show_average(const json& data, const std::string& subject) {
    if (!data.contains(subject)) return;

    auto& students = data[subject]["students"];
    if (students.empty()) return;

    double total = 0.0;
    for (const auto& student : students) {
        total += student["score"].get<double>();
    }

    std::cout << "Average in " << subject << ": "
              << total / students.size() << std::endl;
}
