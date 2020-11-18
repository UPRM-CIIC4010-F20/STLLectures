#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>

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

bool orderByLastName(Student s1, Student s2) 
{
    return (s1.getLastName().compare(s2.getLastName()) < 0);
}

double integrate(double a, double b, function<double(double)> f)
{

    int intervals = 1000;
    double deltaX = (b-a)/intervals;
    double result =0;
    for(int i=0; i<intervals; i++) {
        double xi = a + i * deltaX;
        double nextHeight = (f(xi) + f(xi+deltaX)) / 2.0;
        double nextArea = nextHeight * deltaX;
        result += nextArea;
    }
    return result;
}

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

    cout << "Sorting Examples" << endl;
    cout << "Using operator < from element type" << endl;
    random_shuffle(testStudents.begin(), testStudents.end());
    sort(testStudents.begin(), testStudents.end());


    cout << "Using operator comparator standalone function" << endl;
    random_shuffle(testStudents.begin(), testStudents.end());
    sort(testStudents.begin(), testStudents.end(), orderByLastName);

    cout << "Using comparator class" << endl;
    // Exercise for students

    cout << "Using lambda expression" << endl;
    random_shuffle(testStudents.begin(), testStudents.end());
    sort(testStudents.begin(), testStudents.end(),
         [](Student s1, Student s2) {
             return (s1.getFirstName().compare(s2.getFirstName()) < 0);
         });

    // cout << "Numerical Integration Examples" << endl;
    cout << "Integral of f(x)=e^x^2 from 0 to 1 is: " 
        << integrate(0,1,[](double x) { return exp(x*x);}) << endl;
    cout << "Integral of f(x)=e^x^2 from 0 to 1 is: " 
        << integrate(0,1,[](double x) { return exp(x*x);}) << endl;
    cout << "Integral of f(x)= from 0 to 1 is: " 
        << integrate(2,4,[](double x) { return x*x*pow(sin(x),3);}) << endl;
    cout << "Integral of f(x)=sin^2(x)... from 0 to 1 is: " 
        << integrate(0,M_PI,
        [](double x) 
        { 
            return pow(sin(x),2)+2*pow(sin(2*x),4);
        }
        ) << endl;


}
