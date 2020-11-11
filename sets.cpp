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

    bool operator<(const Student &s2) const
    {
        return (this->getId() < s2.getId());
    }

};

int countUnique(const vector<Student> &students)
{
    set<Student> uniqueStudents;

    for(Student s : students) {
        uniqueStudents.insert(s);
    }

    return uniqueStudents.size();
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