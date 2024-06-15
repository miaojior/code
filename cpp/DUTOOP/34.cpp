#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(string name1 = "", char s = 'M') : name(name1), sex(s) {}
    virtual void ShowMe() = 0; // 虚函数
    friend istream& operator>>(istream& in, Person& p);
protected:
    string name;
    char sex;
};

istream& operator>>(istream& in, Person& p) {
    in >> p.name >> p.sex;
    return in;
}

class Staff : virtual public Person {
protected:
    int wID; // 工作号
public:
    Staff(int id = 0, string name1 = "", char s = 'M') : Person(name1, s), wID(id) {}
    void ShowMe() override {
        cout << "姓名:" << name << endl;
        cout << "性别:" << sex << endl;
        cout << "工号:" << wID << endl;
    }
    friend istream& operator>>(istream& in, Staff& p);
};

istream& operator>>(istream& in, Staff& p) {
    in >> p.name >> p.sex >> p.wID;
    return in;
}

class Student : virtual public Person {
protected:
    int sID; // 学号
public:
    Student(int id = 0, string name1 = "", char s = 'M') : Person(name1, s), sID(id) {}
    void ShowMe() override {
        cout << "姓名:" << name << endl;
        cout << "性别:" << sex << endl;
        cout << "学号:" << sID << endl;
    }
    friend istream& operator>>(istream& in, Student& p);
};

istream& operator>>(istream& in, Student& p) {
    in >> p.name >> p.sex >> p.sID;
    return in;
}

class Staff_Student : public Staff, public Student {
public:
    Staff_Student(string name1 = "", char s = 'M', int id1 = 0, int id2 = 0)
        : Person(name1, s), Staff(id2, name1, s), Student(id1, name1, s) {}
    void ShowMe() override {
        cout << "姓名:" << name << endl;
        cout << "性别:" << sex << endl;
        cout << "学号:" << sID << endl;
        cout << "工号:" << wID << endl;
    }
    friend istream& operator>>(istream& in, Staff_Student& p);
};

istream& operator>>(istream& in, Staff_Student& p) {
    in >> p.name >> p.sex >> p.sID >> p.wID;
    return in;
}

class School {
private:
    Person* p[100];
    int size;
public:
    School() : size(0) {}
    void append(Person& p1) {
        if (size < 100) {
            p[size++] = &p1;
        }
    }
    void display() {
        for (int i = 0; i < size; ++i) {
            p[i]->ShowMe();
        }
    }
};

int main() {
    School sch;
    Staff s1;
    cin >> s1;
    sch.append(s1);
    
    Student st1;
    cin >> st1;
    sch.append(st1);
    
    Staff_Student ss1;
    cin >> ss1;
    sch.append(ss1);
    
    sch.display();
    return 0;
}
