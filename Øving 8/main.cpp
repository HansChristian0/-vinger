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
    std::cout << result[6] << std::endl;
}

int main() {
    int a = 19;
    fillInFibnumb(&a, 7);
    std::cout << *(&a+5) << std::endl;
    return 0;
}

//------------------------------------------------------------------------------
