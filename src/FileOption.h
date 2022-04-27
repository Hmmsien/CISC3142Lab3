#ifndef FILE_OPTION_H
#define FILE_OPTION_H

#include "dataType.h"
#include <string>
#include <vector>
#include <unordered_map>

// Read the file and store the records in the vector
void ReadFile(std::string fileName, std::vector<record_t>& records);
void WritePassRate(std::string fileName, std::unordered_map<std::string, double> pass_rate_result);
void WriteWRate(std::string fileName, std::unordered_map<std::string, double> W_rate_result);
void WriteFallVsSpringPassRate(std::string fileName, std::unordered_map<std::string, double> fall_vs_spring_pass_rate_result);

#endif // FILE_OPTION_H
