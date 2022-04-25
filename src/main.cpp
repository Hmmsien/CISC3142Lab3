#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

const regex comma(",");

struct recordType {
    string studentId;
    int courseNo;
    string instructorId;
    string termId;
    string sectionId;
    string grade;
};

class enrollment {
    
    enrollment() {

    }

    void updateGrade() {

    }

};

int main() {
    vector<vector<string>> data;
    recordType temp;
    string line;

    ifstream inputFile;
    inputFile.open("../data/1115.csv");

    if (inputFile.is_open()){
        while ( getline (inputFile, line) ){
            vector<string> row {sregex_token_iterator(line.begin(),line.end(),comma,-1), sregex_token_iterator() };
            data.push_back(row);
        }
    inputFile.close();
    }   else {
        printf("Fail to open file.");
    }

    // Print result. Go through all lines and then copy line elements to std::cout
    for_each(data.begin(), data.end(), [](vector<string> & vs) {
        copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " ")); 
        cout << "\n"; });

    
    return 0;
}
