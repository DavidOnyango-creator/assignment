#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    string courseName;

    Course(string name) {
        courseName = name;
    }
};

class Student {
private:
    string name;
    vector<Course> courses;   // Association

public:
    Student(string n) {
        name = n;
    }

    void registerCourse(Course c) {   // Dependency
        courses.push_back(c);
    }

    void displayCourses() {
        cout << "Student: " << name << endl;
        cout << "Registered Courses:\n";
        for(auto c : courses)
            cout << "- " << c.courseName << endl;
    }
};

int main() {
    Course c1("Biochemistry");
    Course c2("Mathematics II");

    Student s1("Dave");
    s1.registerCourse(c1);
    s1.registerCourse(c2);

    s1.displayCourses();

    return 0;
}