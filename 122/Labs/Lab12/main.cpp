#include "Student.hpp"
#include <vector>

int main() {

    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v[2] = 5;

    for (int i : v) {
        std::cout << i << std::endl;
    }

    return 0;

    // TestPerson t = TestPerson();

    // std::cout << t.testAll() << std::endl;

    Student me = Student("Logan", 19, "microwave", 5.6);

    Student::Course cpts122 = { .courseName = "Comp Sci 122", .credits = 3, .currentGrade = 4 };
    Student::Course hist105 = { .courseName = "Hist 105", .credits = 2.5, .currentGrade = 3 };
    me.addCourse(cpts122);
    me.addCourse(hist105);

    std::cout << me;

    Student you;

    std::cin >> you;

    std::cout << you;

    return 0;
}