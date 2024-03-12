#include "coursecatalog.h"
#include "std_lib_facilities.h"


void CourseCatalog::addCourse(string emnekode, string emnenavn) {
    map<string, string> fag;
    fag.insert({emnekode, emnenavn});
    emner.push_back(fag);
}

void CourseCatalog::removeCourse(string emnekode) {
    int index{0};
    for (const map<string, string>& fag : emner) {
        for (const pair<string, string>& emne : fag) {
            if (emne.first == emnekode) {
                emner.erase(emner.begin() + index);
            }
        }
        index++;
    }
}

string CourseCatalog::getCourse(string emnekode) {
    for (const map<string, string>& fag : emner) {
        for (const pair<string, string>& emne : fag) {
            if (emne.first == emnekode) {
                return emne.second;
            }
        }
    }
    return "###";
}

ostream& operator<<(ostream& os, const CourseCatalog& cp) {
    for (const map<string, string>& fag : cp.emner) {
        for (const pair<string, string>& emne : fag) {
            os << "Emnekode: " << emne.first << ", emnenavn: " << emne.second << endl;
        }
    }
    return os;
}

void CourseCatalog::readToFile(vector<map<string, string>> emner) {
    string str;
    string outputString {""};

    filesystem::path fileName {"emner.txt"};
    ofstream outputStream {fileName};
    for (const map<string, string>& fag : emner) {
        for (const pair<string, string>& emne : fag) {
            for (const char& el : emne.first) {
                str.push_back(el);
            }
            str.push_back(' ');
            for (const char& el : emne.second) {
                str.push_back(el);
            }
            str.push_back(',');
        }
    }

    for (char& el : str) {
        if (el == ',') {
            outputStream << outputString << endl;
            outputString = "";
        } else {
            outputString.push_back(el);
        }
    }

}

void CourseCatalog::readFromFile(filesystem::path filePath) {
    ifstream inputStream {filePath};
    string line;
    string word;
    vector<string> placeholder{};

    if (inputStream) {
        while (getline(inputStream, line)){
            placeholder = {};
            stringstream ss(line);
            while (getline(ss, word, ' ')){
                placeholder.push_back(word);
            }
            map<string, string> emne;
            CourseCatalog::addCourse(placeholder.at(0), placeholder.at(1));
        }
    }
}