#include "iostream"
#include "Stopwatch.h"
#include "vector"
#include "memory"
#include "algorithm"
#include "optimizationTask.h"
#include "iostream"
#include "random"
#include "myArray.h"
/*
template<class T> T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template<class T> std::vector<T> shuffle(std::vector<T> vec) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, vec.size()-1);
    T placeholder;
    int num1;
    int num2;
    for (int i=0; i<vec.size()*2; i++) {
        num1 = distr(gen);
        num2 = distr(gen);
        placeholder = vec.at(num1);
        vec.at(num1) = vec.at(num2);
        vec.at(num2) = placeholder;
    }
    return vec;
}

template<class T> std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
    for (T& el : vec) {
        os << el << "  ";
    }
    os << std::endl;
    return os;
}*/

int main() {

    MyArray<std::string, 4> array;
    array.fill("r");
    std::cout << array.at(3) << std::endl;
    std::cout << array.getSize() << std::endl;
    return 0;

/*std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
a = shuffle(a); // Resultat, rekkefølgen i a er endret.
std::vector<double> b{1.2, 2.2, 3.2, 4.2};
b = shuffle(b); // Resultat, rekkefølgen i b er endret.
std::vector<std::string> c{"one", "two", "three", "four"};
c = shuffle(c); // Resultat, rekkefølgen i c er endret.
std::cout << c;*/

    /*
    Stopwatch klokke;

    klokke.start();
    optimizationTask();
    std::cout << klokke.stop() << std::endl;
    */
    /*
    std::vector<int> vec;
    vec.resize(1000000);
    klokke.start();
    for (int i=0; i<1000000; i++) {
        vec.at(i) = i;
    }
    double elapsedTime = klokke.stop();

    std::cout << elapsedTime << std::endl;
    */

    /*

    int n = 1000000;
    constexpr int size = 1000000/2;
        klokke.start();
    for (int i=0; i<n; i++) {
        // Stack allocation
        std::array<int, size> arr1;
    }
    std::cout << klokke.stop()/n << std::endl;
    klokke.start();
    for (int i=0; i<n; i++) {
        // Stack allocation
        //Heap allocation
        std::array<int, size>* arr2 = new std::array<int, size>;
        delete arr2;
    }
    std::cout << klokke.stop()/n << std::endl;*/
}
