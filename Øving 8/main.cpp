#include "iostream"
#include "matrix.h"
#include "fibonacci.h"
#include "dummy.h"

int main() {
    Matrix a{4,5};
    a.set(2,2,9);
    Matrix b{5};
    b = a;
    std::cout << "Heiisaann" << std::endl;
    std::cout << &a;
    std::cout << std::endl;
    std::cout << &b;
    return 0;
}