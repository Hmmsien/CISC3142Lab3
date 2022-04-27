#include "FileOption.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void ReadFile(string fileName, vector<record_t>& records) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }
    string line;
    getline(file, line); // Skip the first line(dummy line)
    record_t record;

    string cell;
    while (getline(file, line)) {
        stringstream ss(line);
        int i = 0;
        while (getline(ss, cell, ',')) {
            if (i == 0) record.studentID = cell;
            else if (i == 1) record.curseNo = stoi(cell);
            else if (i == 2) record.instructorID = cell;
            else if (i == 3) record.termID = cell;
            else if (i == 4) record.sectionID = cell;
            else if (i == 5) record.grade = cell;
            i++;
        }
        // For debug, output the record data
        // cout << record.studentID << " " << record.curseNo << " " << record.instructorID << " " << record.termID << " " << record.sectionID << " " << record.grade << endl;
        records.push_back(record);
    }
    file.close();
}

void WritePassRate(std::string fileName, std::unordered_map<std::string, double> pass_rate_result) {
    FILE *file = fopen(fileName.c_str(), "w");
    if (file == nullptr) {
        cout << "File not found!" << endl;
        return;
    }
    fprintf(file, "instructorID,courseID,pass_rate\n");
    for (auto it = pass_rate_result.begin(); it != pass_rate_result.end(); it++) {
        auto space_pose = it->first.find(' ');
        fprintf(file, "%s,%s,%.2f%%\n", it->first.substr(0, space_pose).c_str(), it->first.substr(space_pose + 1).c_str(),
                        it->second * 100);
    }
    fclose(file);
}

void WriteWRate(std::string fileName,
                   std::unordered_map<std::string, double> w_rate_result) {
    FILE *file = fopen(fileName.c_str(), "w");
    if (file == nullptr) {
        cout << "File not found!" << endl;
        return;
    }
    fprintf(file, "instructorID,courseID,W_rate\n");
    for (auto it = w_rate_result.begin(); it != w_rate_result.end();
         it++) {
        auto space_pose = it->first.find(' ');
        fprintf(file, "%s,%s,%.2f%%\n", it->first.substr(0, space_pose).c_str(),
                it->first.substr(space_pose + 1).c_str(), it->second * 100);
    }
    fclose(file);
}

void WriteFallVsSpringPassRate(
    std::string fileName,
    std::unordered_map<std::string, double> fall_vs_spring_pass_rate_result) {
    FILE *file = fopen(fileName.c_str(), "w");
    if (file == nullptr) {
        cout << "File not found!" << endl;
        return;
    }
    fprintf(file, "courseID,Fall vs Spring,pass_rate\n");
    for (auto it = fall_vs_spring_pass_rate_result.begin();
         it != fall_vs_spring_pass_rate_result.end(); it++) {
        auto space_pose = it->first.find(' ');
        fprintf(file, "%s,%s,%.2f%%\n", it->first.substr(0, space_pose).c_str(),
                it->first.substr(space_pose + 1).c_str(), it->second * 100);
    }
    fclose(file);
}
