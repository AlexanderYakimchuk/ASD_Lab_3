#include <iostream>
#include <iomanip>

using namespace std;

enum sex {Male, Female};

struct date {
    unsigned int year, month, day;
};

struct properties {
    unsigned int key;
    char name[30];
    char surname[30];
    sex person_sex;
    date birthday;
    unsigned int salary;
};

const char separator = ' ';
const int nameWidth     = 15;
const int numWidth      = 6;
const unsigned int SIZE = 50;
properties TABLE[SIZE];

void displayTable();
void ReadLine(properties*);
void addToTable(properties);
void deleteRaw(unsigned int);
void updateRaw(unsigned int);
int countRaws();
void searchByKey(unsigned int);
void searchByAddress(unsigned int);


int main(){
    properties a;
    ReadLine(&a);
    addToTable(a);
    ReadLine(&a);
    addToTable(a);
    displayTable();
    searchByKey(1);
}


void displayTable(){
    cout << left << setw(numWidth) << setfill(separator) << "key";
    cout << left << setw(nameWidth) << setfill(separator) << "Name";
    cout << left << setw(nameWidth) << setfill(separator) << "Surname";
    cout << left << setw(numWidth) << setfill(separator) << "Day";
    cout << left << setw(numWidth) << setfill(separator) << "Month";
    cout << left << setw(numWidth) << setfill(separator) << "Year";
    cout << left << setw(numWidth) << setfill(separator) << "Salary";
    cout << endl;
    for (int i = 0; i < SIZE; i++){
        if (TABLE[i].key != 0){
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].key;
            cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].name;
            cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].surname;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.day;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.month;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.year;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].salary;
            cout << endl;
        }
    }
}

void ReadLine(properties *line){
    cout << "Name: "; cin >> line->name;
    cout << "Surname: "; cin >> line->surname;
    cout << "Day of birth: "; cin >> line->birthday.day;
    cout << "Month of birth: "; cin >> line->birthday.month;
    cout << "Year of birth: "; cin >> line->birthday.year;
    cout << "Salary: "; cin >> line->salary;
}

void addToTable(properties line){
    for (int i = 0; i < SIZE; i++)
        if (TABLE[i].key == 0){
            TABLE[i] = line;
            TABLE[i].key = (unsigned int) (i + 1);
            return;
        }
}

void updateRaw(unsigned int n){
    properties new_line;
    if (n <= countRaws()){
        ReadLine(&new_line);
        TABLE[n-1] = new_line;
        TABLE[n-1].key = n;
    }
    else
        cout << endl << "No such line" << endl;
}

void deleteRaw(unsigned int n){
    for (int i = n - 1; i < SIZE; i++){
        if (TABLE[i+1].key == 0) TABLE[i].key = 0;
        TABLE[i+1].key = TABLE[i].key;
        TABLE[i] = TABLE[i+1];
    }
}

int countRaws(){
    int count = 0;
    for (int i = 0; i < SIZE; i++){
        if (TABLE[i].key != 0) count += 1;
        else return count;
    }
}

void searchByKey(unsigned int n){
    unsigned int i = n - 1;
    for (int i = 0; i < SIZE; i++) {
        if (TABLE[i].key == n) {
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].key;
            cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].name;
            cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].surname;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.day;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.month;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.year;
            cout << left << setw(numWidth) << setfill(separator) << TABLE[i].salary;
            cout << endl;
        }
    }
}

void searchByAddress(unsigned int i){
    if (TABLE[i].key != 0) {
        cout << left << setw(numWidth) << setfill(separator) << TABLE[i].key;
        cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].name;
        cout << left << setw(nameWidth) << setfill(separator) << TABLE[i].surname;
        cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.day;
        cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.month;
        cout << left << setw(numWidth) << setfill(separator) << TABLE[i].birthday.year;
        cout << left << setw(numWidth) << setfill(separator) << TABLE[i].salary;
        cout << endl;
    }
}