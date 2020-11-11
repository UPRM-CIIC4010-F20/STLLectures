#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    // CLASS CODE HERE <

};

int countUnique(const vector<Student> &students)
{
    // CLASS CODE HERE
    return 0;
}

int main() {

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(21, "Amanda", "Vazquez"));
    testStudents.push_back( Student(32, "Fernando", "Davis"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "Count of Unique Students: " << countUnique(testStudents) << endl;
    
}