#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
private:
    vector<map<string, string>> emner;

public:
    vector<map<string, string>> getEmner() {
        return emner;
    }
    void addCourse(string emnekode, string emnenavn);
    void removeCourse(string emnekode);
    string getCourse(string emnekode);
    friend ostream& operator<<(ostream& os, const CourseCatalog& cp);
    void readToFile(vector<map<string, string>> emner);
    void readFromFile(filesystem::path filePath);
};
