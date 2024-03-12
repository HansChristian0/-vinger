#include "std_lib_facilities.h"
#include "test.h"
#include "utilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void printVector(vector<int> vec) {
    for (int& el : vec) {
        cout << el << endl;
    }
}

void testString() {
    string grades = randomizeString(8, 'A', 'F');
    cout << grades << endl;
    vector<int> gradeCount;

    for (int karakter=int('A'); karakter<=int('F'); karakter++) {
        for (int antall_av_karakter=0; antall_av_karakter < countChar(grades, char(karakter)); antall_av_karakter++) {
            gradeCount.push_back(int('G') - karakter);
        }
    }
    printVector(gradeCount);
    cout << accumulate(gradeCount.begin(), gradeCount.end(), 0)/double(gradeCount.size());
}