#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

void read_File() {
    vector<vector<string>> data;

    ifstream inputFile;
    inputFile.open("../data/1115.csv");

    string line;

    vector<recordType> dataFile;

    int lineCount = 0;
    getline(inputFile, line); // ignore header line

    recordType newRecord;

    while (getline(inputFile, line) && !line.empty())
    {
        stringstream mystream(line);

        string temp;
        getline(mystream, newRecord.studentId, ',');
        getline(mystream, temp, ',');
        newRecord.courseNo = stod(temp);
        getline(mystream, newRecord.instructorId, ',');
        getline(mystream, newRecord.termId, ',');
        getline(mystream, newRecord.sectionId, ',');
        getline(mystream, newRecord.grade, ',');
        if (!mystream)
            break; // something went wrong reading the line

        dataFile.push_back(newRecord);
        lineCount++;
    }

    for_each(dataFile.begin(), dataFile.end(), [](vector<recordType> & vs) {
        copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " ")); 
        cout << "\n"; }); 
}