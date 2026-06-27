//Lab 1
#include <iostream>
#include <string>
using namespace std;

//Structure declaration to store student info
struct Student {
    int ID;
    string name;
    string course;
    int age;
};

int main() {

    Student student_record[5];
    //Initialise Student Record
    student_record[0] = {101, "Adam", "CS", 20};
    student_record[1] = {102, "Lisa", "IT", 18};
    student_record[2] = {103, "Akmal", "IT", 19};
    student_record[3] = {104, "Jessica", "CS", 20};
    student_record[4] = {105, "John", "IT", 21};

    // Display student records
    cout << "Student Records:\n";

    for (int i = 0; i < 5; i++) {
        cout << "ID: " << student_record[i].ID
             << ", Name: " << student_record[i].name
             << ", Course: " << student_record[i].course
             << ", Age: " << student_record[i].age
             << endl;
    }

    // Search for student by ID
    int search;
    cout << "\nEnter Student ID to search: ";
    cin >> search;

    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (student_record[i].ID == search) {
            cout << "Found: "
                 << student_record[i].name
                 << " (" << student_record[i].course << ")\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << search
             << " not found.\n";
    }

    // Update student record
    int update;
    cout << "\nEnter Student ID to update: ";
    cin >> update;

    for (int i = 0; i < 5; i++) {
        if (student_record[i].ID == update) {

            cout << "Enter new name: ";
            cin >> student_record[i].name;

            cout << "Enter new age: ";
            cin >> student_record[i].age;

            cout << "Enter new course: ";
            cin >> student_record[i].course;

            cout << "Record updated successfully!\n";
            break;
        }
    }
    cout << "\nUpdated Student Records:\n";

    for (int i = 0; i < 5; i++) {
        cout << "ID: " << student_record[i].ID
             << ", Name: " << student_record[i].name
             << ", Course: " << student_record[i].course
             << ", Age: " << student_record[i].age
             << endl;
}

    return 0;
}