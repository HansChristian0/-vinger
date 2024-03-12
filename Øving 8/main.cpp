#include "iostream"

void fillInFibnumb(int* result, int length) {
    for (int i=0; i<length; i++) {
        if (i == 0 or i == 1) {
            result[i] = 1;
        }
        else {
            result[i] = result[i-1]+result[i-2];
        }
    }
}

void printArray(int* arr, int length) {
    for (int i=0; i<length; i++) {
        std::cout << arr[i] << std::endl;
    }
}

void createFib() {
    int length;
    std::cout << "Hvor mange tall skal vi generere? " << std::endl;
    std::cin >> length;
    int* fibMinne = new int[length];
    fillInFibnumb(fibMinne, length);
    printArray(fibMinne, length);
    delete[] fibMinne;
}

int main() {
    createFib();
    return 0;
}
