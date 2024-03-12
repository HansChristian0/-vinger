#include "std_lib_facilities.h"

/* 
Oppgave 1
def isFibNum(n):
    a = 0
    b = 1
    while b<n:
        temp = b
        b += a
        a = temp
    return b == n
*/

int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    }
    else {
        cout << "B is greater than A" << endl;
        return b;
    }
}

int fib(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers" << endl;
    for (int x=1; x<n+1; x++) {
        cout << x << ": " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i=1; i<n+1; i++){
        totalSum += i*i;
        cout << i*i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n) {
        cout << acc << endl;
        acc += num;
        num++;
    }
}

bool isPrime(int n) {
    for (int j=2; j<n; j++) {
        if (n%j == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n) {
    for (int number=2; number<n; number++) {
        if (isPrime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
}

void inputAndPrintNameAndAge() {
    string name;
    int age;
    cout << "Skriv inn navn: ";
    cin >> name;
    cout << "Skriv in allderen til " << name << ": ";
    cin >> age;
    cout << name << " er " << age << " år gammel." << endl;

}

int main() {
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(2, 3) << endl;
    cout << "Oppgave c)" << endl;
    fib(7);
    cout << "Oppgave d)" << endl;
    squareNumberSum(5);
    cout << "Oppgave e)" << endl;
    triangleNumbersBelow(20);
    cout << "Oppgave f)" << endl;
    cout << isPrime(21) << endl;
    naivePrimeNumberSearch(20);
    inputAndPrintNameAndAge();

    return 0;
}