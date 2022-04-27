/**
 * @file main.cpp
 * @brief use **unordered_map** to store <key, value> pair
 * The key is the data item that needs to be grouped for statistics, and the
 * value is the statistical result.
 *
 *
 * dataFlow: FileOption(input) -> main.c -> aggregationOption -> FileOption(output)
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

#include "FileOption.h"
#include "aggregationOption.h"
#include "dataType.h"
using namespace std;

int main(int argc, char *argv[]) {
    // Read file by command line arguments
    vector<record_t> records;
    for (int i = 1; i < argc; i++) {
        ReadFile(argv[i], records);
    }

    // Calculate the pass rate for each course for each teacher
    // Use instructorID + " " + courseID as key and pass rate as double value
    unordered_map<string, double> pass_rate_result = pass_rate(records);

    // Calculate the W rate for each course for each teacher
    // Use instructorID + " " + courseID as key and W rate as double value
    unordered_map<string, double> W_rate_result = W_rate(records);
    unordered_map<string, double> fall_vs_spring_pass_rate_result = fall_vs_spring_pass_rate(records);

    // Write data to output file folder
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d-%H-%M-%S");;

    WritePassRate("./output/pass_rate_" + oss.str() + ".csv", pass_rate_result);
    WriteWRate("./output/W_rate_" + oss.str() + ".csv", W_rate_result);
    WriteFallVsSpringPassRate("./output/fall_vs_spring_pass_rate_" + oss.str() + ".csv", fall_vs_spring_pass_rate_result);

    return 0;
}
