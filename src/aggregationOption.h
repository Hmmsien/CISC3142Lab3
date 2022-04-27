#include "dataType.h"
#include <unordered_map>
#include <string>
#include <vector>

// Key: instructorID + " " + courseID
std::unordered_map<std::string, int> count(std::vector<record_t> records);
std::unordered_map<std::string, double> pass_rate(std::vector<record_t> records);
std::unordered_map<std::string, double> W_rate(std::vector<record_t> records);
std::unordered_map<std::string, double> fall_vs_spring_pass_rate(std::vector<record_t> records);
