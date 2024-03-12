#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& a,  int& b);

struct Student {
    string name;
    string studyProgram;
    int age;
};
void printStudent(Student student);
bool isInProgram(Student student, string given_study_program);

string randomizeString(int length, char start, char end);

string readInputToString(int n, char start, char end);
int countChar(string ord, char bokstav);
