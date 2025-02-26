#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class student {
protected:
    int std;
    string firstname;
    string lastname;
    vector<int> credits;
    vector<double> grades;
    vector<string> coursenames;

public:
    student(int std, const string& fname, const string& lname) 
        : std(std), firstname(fname), lastname(lname) {}

    double GetGPA() {
        double sumgrades = 0;
        int sumcredits = 0;
        for (size_t i = 0; i < credits.size(); i++) {
            sumgrades += grades[i] * credits[i];
            sumcredits += credits[i];
        }
        return sumgrades / sumcredits;
    }

    void registerCourse(int credit, const string& name, double grade) {
        credits.push_back(credit);
        grades.push_back(grade);
        coursenames.push_back(name);
    }

    void listcourses() {
        cout << "\nلیست دروس:\n";
        for (size_t i = 0; i < credits.size(); i++) {
            cout << coursenames[i] << " - " << credits[i] << " واحد - نمره: " << grades[i] << endl;
        }
    }
};

int main() {
    int std;
    string firstname, lastname;
    cout << "شماره دانشجویی: ";
    cin >> std;
    cin.ignore();
    cout << "نام: ";
    getline(cin, firstname);
    cout << "نام خانوادگی: ";
    getline(cin, lastname);
    student s(std, firstname, lastname);
    int numCourses;
    cout << "چند درس پاس کردید؟ ";
    cin >> numCourses;
    for (int i = 0; i < numCourses; i++) {
        string courseName;
        int credit;
        double grade;

        cin.ignore();
        cout << "نام درس";
        getline(cin, courseName);
        
        cout << "تعداد واحد: ";
        cin >> credit;
        
        cout << "نمره: ";
        cin >> grade;

        s.registerCourse(credit, courseName, grade);
    }

    s.listcourses();
    cout << "معدل: " << s.GetGPA() << endl;
}