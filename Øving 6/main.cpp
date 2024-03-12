#include "std_lib_facilities.h"
#include "filesystem"
#include "coursecatalog.h"
#include "bouncingBall.h"

void inputStringToFile() {
    string str;
    string input;
    std::filesystem::path fileName {"text.txt"};
    std::ofstream outputStream {fileName};
    string outputString {""};

    while (input != "quit") {
        cout << "\nLegg til ord ";
        if (input != "quit") {
            cin >> input;
            for (const char& el : input) {
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
void readFromFileAndCopy() {
    filesystem::path fileName {"text.txt"};
    filesystem::path fileNameCopy {"textcopy.txt"};
    ifstream inputStream {fileName};
    ofstream outputStream {fileNameCopy};
    string line;
    int lineNum {1};
    if (inputStream) {
        while (getline(inputStream, line)){
            outputStream << lineNum << " " << line << endl;
            lineNum++;
        }
    }
}   

int main() {
    bouncingBall();
    return 1;
}