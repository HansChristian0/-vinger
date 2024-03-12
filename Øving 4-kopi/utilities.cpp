#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void swapNumbers(int& a,  int& b){
    int temp = a;
    a = b;
    b = temp;
}

void printStudent(Student student) {
    cout << "Studenten heter " << student.name << " (" << student.age << ") og studerer " << student.studyProgram << endl;
}

bool isInProgram(Student student, string given_study_program) {
    if (student.studyProgram == given_study_program) {
        return true;
    } else {
        return false;
    }
}

int randomWithLimits(int a, int b) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(a,b);
    
    int randomNumber = distribution(generator);
    return randomNumber;
}

string randomizeString(int length, char start, char end) {
    string tilfeldig_ord = "";
    for (int x=0; x<length; x++) {
        char append_string = char(randomWithLimits(int(start), int(end)));
        tilfeldig_ord.push_back(append_string);
    }
    return tilfeldig_ord;
}

string readInputToString(int n, char start, char end) {
    string tilfeldig_ord = "";
    char karakter = start;
    for (int x=0; x<n; x++) {
        do {
            cout << "Oppgi en karakter " << endl;
            cin >> karakter;
            if (int(toupper(karakter))<int(toupper(start)) || int(toupper(karakter))>int(toupper(end))){
                cout << "Den karakteren var utenfor gitt intervall. Prøv igjen " << endl;
            } else {
                tilfeldig_ord.push_back(toupper(karakter));
            }
        } while (int(toupper(karakter))<int(toupper(start)) || int(toupper(karakter))>int(toupper(end)));
    }
    return tilfeldig_ord;
}

int countChar(string ord, char bokstav) {
    int teller = 0;

    for (char& el : ord) {
        if (toupper(el) == toupper(bokstav)) {
            teller++;
        }
    }
    return teller;
}
