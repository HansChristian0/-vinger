#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int a, int b) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(a,b);
    
    int randomNumber = distribution(generator);
    return randomNumber;
}