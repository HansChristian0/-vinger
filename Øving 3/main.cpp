#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main() {
    playTargetPractise();
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand-toOperand) <= maxError) {
        cout << "De er like nok" << endl;
    } else {
        cout << "De er ikke like nok" << endl;
    }
}