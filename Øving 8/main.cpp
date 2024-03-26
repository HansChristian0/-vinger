#include "iostream"
#include "matrix.h"
#include "fibonacci.h"
#include "dummy.h"

int main() {
    Matrix a{2,2};
    a.set(1,1,1);
    a.set(1,2,2);
    a.set(2,1,3);
    a.set(2,2,4);
    Matrix b{2};
    b.set(1,1,4);
    b.set(1,2,3);
    b.set(2,1,2);
    b.set(2,2,1);
    Matrix c{2};
    c.set(1,1,1);
    c.set(1,2,3);
    c.set(2,1,1.5);
    c.set(2,2,2);

    a-=c;
    std::cout << &a << std::endl;
    return 0;
    std::cout << "Test" std::endl;
}