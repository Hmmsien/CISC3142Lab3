#include "aggregationOption.h"
#include <unordered_set>
using namespace std;

unordered_set<string> passedGrade {"A", "A+", "A-", "B+", "B", "B-", "C+", "C", "C-"};
unordered_set<string> fall {"T04", "T08", "T12", "T16", "T20", "T23"};
unordered_set<string> spring {"T02", "T06", "T10", "T14", "T18", "T21"};

std::unordered_map<std::string, int> count(std::vector<record_t> records) {
    std::unordered_map<std::string, int> result;
    for (auto record : records) {
        std::string key = record.instructorID + " " + to_string(record.curseNo);
        if (result.find(key) == result.end()) {
            result[key] = 1;
        } else {
            result[key]++;
        }
    }
    return result;
}

std::unordered_map<std::string, double> pass_rate(std::vector<record_t> records) {
    std::unordered_map<std::string, int> grade_cnt = count(records);
    std::unordered_map<std::string, double> pass_rate_result;
    for (auto record : records) {
        if (passedGrade.count(record.grade) == 0) {
            continue;
        }
        std::string key = record.instructorID + " " + to_string(record.curseNo);
        if (pass_rate_result.find(key) == pass_rate_result.end()) {
            pass_rate_result[key] = 1;
        } else {
            pass_rate_result[key]++;
        }
    }

    for (auto item : pass_rate_result) {
        pass_rate_result[item.first] = 1.0 * item.second / grade_cnt[item.first];
    }

    return pass_rate_result;
}

std::unordered_map<std::string, double> W_rate(std::vector<record_t> records) {
    std::unordered_map<std::string, int> grade_cnt = count(records);
    std::unordered_map<std::string, double> W_rate_result;
    for (auto record : records) {
        if (record.grade != "W") {
            continue;
        }
        std::string key = record.instructorID + " " + to_string(record.curseNo);
        if (W_rate_result.find(key) == W_rate_result.end()) {
            W_rate_result[key] = 1;
        } else {
            W_rate_result[key]++;
        }
    }

    for (auto item : W_rate_result) {
        W_rate_result[item.first] = 1.0 * item.second / grade_cnt[item.first];
    }

    return W_rate_result;
}


unordered_map<string, double> fall_vs_spring_pass_rate(vector<record_t> records) {
    unordered_map<string, int> passed;
    unordered_map<string, int> total;
    unordered_map<string, double> result;

    // Traverse records to calculate passed count and total count
    for (auto record : records) {
        if (fall.count(record.termID)) {
            total[to_string(record.curseNo) + " " + "Fall"]++;
            if (passedGrade.count(record.grade)) {
                passed[to_string(record.curseNo) + " " + "Fall"]++;
            }
        } else if (spring.count(record.termID)) {
            total[to_string(record.curseNo) + " " + "Spring"]++;
            if (passedGrade.count(record.grade)) {
                passed[to_string(record.curseNo) + " " + "Spring"]++;
            }
        }
    }

    for (auto item : total) {
        result[item.first] = 1.0 * passed[item.first] / total[item.first];
        // result[item.first] = 1.0 * item.second / total[item.first];
    }
    return result;
}
