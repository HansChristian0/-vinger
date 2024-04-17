#include "iostream"
#include "Stopwatch.h"
#include "vector"
#include "memory"
#include "algorithm"
#include "optimizationTask.h"

int main() {
    Stopwatch klokke;

    klokke.start();
    optimizationTask();
    std::cout << klokke.stop() << std::endl;

    return 0;

/*
Test 1: Knappe 6
Test 2: 
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
