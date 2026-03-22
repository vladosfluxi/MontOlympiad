#include <string>
#include <fstream>
#include <limits>
#include "../external/nlohmann/json.hpp"
using json = nlohmann::json;


#ifndef STATS_H
#define STATS_H

// <----- FUNTION THAT SHOWS LOWEST SCORE
void show_lowest(const json& data,const std::string& subject);

// <----- FUNCTION THAT SHOWS HIGHEST SCORE
void show_highest(const json& data, const std::string& subject);

// <----- FUNTION THAT SHOWS AVERAGE SCORE
void show_average(const json& data, const std::string& subject);

// <----- FUNCTION THAT SAVES A TEST RESULT
void save_result(const std::string& username, double score);


#endif 
