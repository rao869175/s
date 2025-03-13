#include <iostream>
#include <string>
#include <vector>
#include <conio.h>  
using namespace std;
class Student {
private:
    string id, name, course_enrolled, grades;

public:
    Student(string i, string n, string c, string g) : id(i), name(n), course_enrolled(c), grades(g) {}

    void setId(string i) {
        id = i;
    }

    string getId() {
        return id;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setCourseEnrolled(string c) {
        course_enrolled = c;
    }

    string getCourseEnrolled() {
        return course_enrolled;
    }

    void setGrades(string g) {
        grades = g;
    }

    string getGrades() {
        return grades;
    }

    void display_student() {
        cout << " ID :" << id << endl;
        cout << " Name :" << name << endl;
        cout << " Course Enrolled :" << course_enrolled << endl;
        cout << " Grades :" << grades << endl;
    }
};

void update_student(vector<Student> &students) {
    string sname;
    bool found = false;
    int choice;
    cout << "\t\t Enter Name to Update the Record: ";
    cin.ignore();
    getline(cin, sname);
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == sname) {
            found = true;
            cout << "\t\t ------Student Found----" << endl;
            cout << "\t\t 1. Update ID" << endl;
            cout << "\t\t 2. Update Name" << endl;
            cout << "\t\t 3. Update Course Enrolled" << endl;
            cout << "\t\t 4. Update Grades" << endl;
            cout << "\t\t Enter Your Choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    string id;
                    cout << "\t\t Enter New ID: ";
                    cin >> id;
                    students[i].setId(id);
                    break;
                }
                case 2: {
                    string name;
                    cout << "\t\t Enter The New Name: ";
                    cin.ignore();
                    getline(cin, name);
                    students[i].setName(name);
                    break;
                }
                case 3: {
                    string course_enrolled;
                    cout << "\t\t Enter New Course Enrolled: ";
                    cin.ignore();
                    getline(cin, course_enrolled);
                    students[i].setCourseEnrolled(course_enrolled);
                    break;
                }
                case 4: {
                    string grades;
                    cout << "\t\t Enter New Grades: ";
                    cin >> grades;
                    students[i].setGrades(grades);
                    break;
                }
                default:
                    cout << "\t\t Invalid Number" << endl;
            }
        }
    }
    if (!found) {
        cout << "\t\t Record Not Found" << endl;
    }
}

void Search_student(vector<Student> &students) {
    string id;
    cout << "\t\t Enter the ID: ";
    cin.ignore();
    getline(cin, id);
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "\t\t-------Student Found--------" << endl;
            students[i].display_student();
            return;
        }
    }
    cout << "\t\t Student Not Found" << endl;
}

void display_allStudents(vector<Student> &students) {
    if (students.empty()) {
        cout << "\t\t No Student Found" << endl;
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        students[i].display_student();
        cout << endl;
    }
}

void Add_new_student(vector<Student> &students) {
    string id, name, course_enrolled, grades;
    cout << " Enter the ID: ";
    cin >> id;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            cout << "\t\t Student Already Exists" << endl;
            return;
        }
    }
    cout << " Enter the Name: ";
    cin >> name;
    cout << " Enter the Course Enrolled: ";
    cin.ignore();
    getline(cin, course_enrolled);
    cout << " Enter the Grades: ";
    cin >> grades;
    Student new_student(id, name, course_enrolled, grades);
    students.push_back(new_student);
    cout << "\t\t Student added Successfully....." << endl;
}

void delete_student(vector<Student> &students) {
    string name;
    bool found = false;
    cout << " Enter Name To delete: ";
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            students.erase(students.begin() + i);
            cout << "\t\t Student Removed Successfully" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\t\t Student Not Found" << endl;
    }
}

void login() {
    string username, password;
    cout << "\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN FIRST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout << " Enter Username: ";
    cin >> username;
    cout << " Enter Password: ";
    cin >> password;
    cout << "\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN SUCCESSFUL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout << " Press any key to continue...";
    getch(); // Wait for a key press
}

int main() {
    vector<Student> students;
    students.push_back(Student("1", "Ali", "Computer Science", "A"));

    login();

    char choice;
    do {
        system("cls");
        int op;
        cout << "\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Information System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
        cout << "\t\t 1. Add New Student" << endl;
        cout << "\t\t 2. Display All Students" << endl;
        cout << "\t\t 3. Search Student" << endl;
        cout << "\t\t 4. Update Student" << endl;
        cout << "\t\t 5. Delete Student" << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << " Enter your Choice: ";
        cin >> op;
        switch (op) {
            case 1:
                Add_new_student(students);
                break;
            case 2:
                display_allStudents(students);
                break;
            case 3:
                Search_student(students);
                break;
            case 4:
                update_student(students);
                break;
            case 5:
                delete_student(students);
                break;
            case 6:
                exit(0);
            default:
                cout << "\t\t Invalid Number......" << endl;
        }

        cout << "\t\t Do You Want To Continue [Yes/No]?: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

