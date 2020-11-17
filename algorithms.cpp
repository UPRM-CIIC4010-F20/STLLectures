#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <algorithm>

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

bool evenIdFunction(Student s)
{
    if ((s.getId() % 2) == 0) {
        cout << "Student with even id: " << s.getId() << endl;
        return true;
    } else {
        cout << "Student with odd id: " << s.getId() << endl;
        return false;    
    }
}

class EvenIdClass
{
public:
    bool operator()(Student s)
    {
        if ((s.getId() % 2) == 0)
        {
            cout << "Student with even id: " << s.getId() << endl;
            return true;
        }
        else
        {
            cout << "Student with odd id: " << s.getId() << endl;
            return false;
        }
    }
};

int main()
{
    vector<Student> testStudents;
    vector<Student>::iterator it = testStudents.begin();
    testStudents.push_back(Student(10, "Bienve", "Velez"));
    testStudents.push_back(Student(65, "Joshua", "Cruz"));
    testStudents.push_back(Student(21, "Amanda", "Vazquez"));
    testStudents.push_back(Student(32, "Fernando", "Davis"));
    // testStudents.push_back(Student(65, "Joshua", "Cruz"));
    testStudents.push_back(Student(43, "Alejandra", "Munoz"));
    testStudents.push_back(Student(54, "Fatima", "Puig"));
    // testStudents.push_back(Student(65, "Joshua", "Cruz"));
    // testStudents.push_back(Student(65, "Joshua", "Cruz"));
    testStudents.push_back(Student(76, "Rey", "Cotto"));

    cout << "for_each using standalone function" << endl;
    for_each(testStudents.begin(), testStudents.end(), evenIdFunction);

    cout << "for_each using functional class" << endl;
    EvenIdClass evenIdInstance;
    for_each(testStudents.begin(), testStudents.end(), evenIdInstance);

    cout << "for_each using lambda expressions" << endl;
    for_each(testStudents.begin(), testStudents.end(),
             [](Student s) {
                 if ((s.getId() % 2) == 0)
                 {
                     cout << "Student with even id: " << s.getId() << endl;
                     return true;
                 }
                 else
                 {
                     cout << "Student with odd id: " << s.getId() << endl;
                     return false;
                 }
             });

    Student s1(10, "Bienve", "Velez");
    bool found1 = binary_search(testStudents.begin(), testStudents.end(), s1);
    Student s2(11, "Fulano", "de Tal");
    bool found2 = binary_search(testStudents.begin(), testStudents.end(), s2);
    Student s3(65, "Joshua", "Cruz");
    bool found3 = binary_search(testStudents.begin(), testStudents.end(), s3);

    vector<Student>::iterator pos;
    pos = find_if(testStudents.begin(), testStudents.end(), evenIdFunction);
    if (pos == testStudents.end()) {
        cout << "Not Found" << endl;
    } else {
        cout << "Found" << endl;
    }
    cout << "First student with an even id is: " << pos->getFirstName() << endl;
    pos = find_if(pos+1, testStudents.end(), evenIdFunction);
    cout << "Second student with an even id is: " << pos->getFirstName() << endl;


}
