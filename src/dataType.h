#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>

struct record_t {
    std::string studentID;
    int curseNo;
    std::string instructorID;
    std::string termID;
    std::string sectionID;
    std::string grade;
};

class Enrollment {
public:
    // A constructor for define a new enrollment
    Enrollment(std::string studentID_, int curseNo_, std::string instructorID_,
               std::string termID_, std::string sectionID_, std::string grade_)
        : studentID(studentID_),
          curseNo(curseNo_),
          instructorID(instructorID_),
          termID(termID_),
          sectionID(sectionID_),
          grade(grade_) {}
    void updatingGrade(std::string grade_) { grade = grade_; }

private:
    std::string studentID;
    int curseNo;
    std::string instructorID;
    std::string termID;
    std::string sectionID;
    std::string grade;
};

#endif // DATA_TYPE_H
