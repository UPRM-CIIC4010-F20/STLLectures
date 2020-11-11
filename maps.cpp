#include <iostream>
#include <string>
#include <map>

using namespace std;

// https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem


int main() {

// 3
// sam 99912222
// tom 11122222
// harry 12299933
// sam
// edward
// harry

    map<string, string> phoneBook;

    int numEntries;
    cin >> numEntries;

    for (int i=0; i<numEntries; i++) {
        string nextName;
        cin >> nextName;
        string nextPhone;
        cin >> nextPhone;
        phoneBook[nextName] = nextPhone;
    }

    string lookupName;
    while (cin >> lookupName) {
        if (phoneBook.count(lookupName) == 0) {
            cout << "Not found" << endl;
        } else {
            cout << lookupName << "=" << phoneBook[lookupName] << endl;
        }
    }
    return 0;

}
