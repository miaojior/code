#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using std::cin; using std::cout; using std::endl;
using std::string;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    int score;
    int index;
    bool operator<(const Student& other) const {
        if (score == other.score) 
            return index < other.index;
        return score > other.score;
    }
};

class GradeBook {
private:
    Student students[MAX_STUDENTS];
    int studentCount;
public:
    GradeBook();
    void readInput();
    void printStudents();
};

int main() {
    GradeBook gradeBook;
    gradeBook.readInput();
    gradeBook.printStudents();
    return 0;
}


GradeBook::GradeBook() : studentCount(0){}

void GradeBook::readInput() {
    cin >> studentCount;
    for (int i = 0; i < studentCount; ++i){
        cin >> students[i].name >> students[i].score;
        students[i].index = i;
    }
    std::sort(students, students + studentCount);
}

void GradeBook::printStudents(){
    for (int i = 0; i < studentCount; ++i)
        cout << std::right << std::setw(15) << students[i].name 
             << std::right << std::setw(5)  << students[i].score << endl;
}