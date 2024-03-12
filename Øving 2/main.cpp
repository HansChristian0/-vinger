#include "std_lib_facilities.h"
#include "AnimationWindow.h"

void avslutt() {
    cout << "Den er god" << endl;
}

void inputAndPrintInteger() {
    int input;
    cout << "Skriv et tall: ";
    cin >> input;
    cout << "\nDu skrev: " << input << endl;;
}

int inputInteger() {
    int value;
    cout << "Skriv inn et tall: ";
    cin >> value;
    return value;
}

void inputTwoIntegersAnPrintSum() {
    int tall1 = inputInteger();
    cout << endl;
    int tall2 = inputInteger();
    cout << "\nSummen av tallene er " << tall1+tall2 << endl;
}

bool isOdd(int x) {
    if (x%2 == 0) {
        return false;
    } else {
        return true;
    }
}

void sumOfNIntegers() {
    int antall_ledd, ledd;
    int sum = 0;
    cout << "Hvor mange tall skal vi summere? ";
    cin >> antall_ledd;
    for (int i=0; i<antall_ledd; i++) {
        cout << "\nSkriv inn et tall ";
        cin >> ledd;
        sum += ledd;
    }
    cout << "\nSummen er " << sum << endl;
}

void sumUntilInputZero() {
    int input;
    int sum = 0;
    do {
        cout << "\nSkriv et tall ";
        cin >> input;
        sum += input;
    } while (input != 0);
    cout << "Summen er " << sum << endl;
}

double inputDouble() {
    double value;
    cout << "Skriv inn et tall: ";
    cin >> value;
    return value;
}

double doubleRound(double value, double precision = 0.01) {
    return round(value/precision)*precision;
}

void convertFromNokToEuro() {
    double NOK = inputDouble();
    while (NOK < 0) {
        cout << "\nDet tallet var negativt. La oss prøve igjen. " << endl;
        NOK = inputDouble();
    }
    double euro = NOK/9.75;
    cout << NOK << "\nkroner er " << doubleRound(euro) << " euro.";
}

void printVector(vector<vector<int>> vec) {
    cout << endl;
    for (int i=0; i<vec.size(); i++){
        for (int j=0; j<vec.at(i).size(); j++){
            cout << right << setw(5) << vec.at(i).at(j) ;
        }
        cout << endl;
    }
}

void printMultiplicationTable() {
    int height = 1;
    int width = 1;
    cout << "Enter height: ";
    cin >> height;
    cout << "\nEnter widht: ";
    cin >> width;
    vector<vector<int>> table(height, vector<int>(width));
    for(int i=0; i<table.size(); i++){
        for(int j=0; j<table.at(i).size(); j++){
            table.at(i).at(j) = (i+1)*(j+1);
        }
    }
    printVector(table);
}

double calculateDiscriminant(double a, double b, double c) {
    return pow(b,2)-4*a*c;
}

void printRealRoots(double a, double b, double c) {
    if (calculateDiscriminant(a,b,c) > 0) {
        double rot1 = (-b+sqrt(calculateDiscriminant(a,b,c)))/(2*a);
        double rot2 = (-b-sqrt(calculateDiscriminant(a,b,c)))/(2*a);
        cout << "\nRøttene er " << rot1 << " og " << rot2 << endl;
    }
    else if (calculateDiscriminant(a,b,c) == 0) {
        double rot = (-b)/(2*a);
        cout << "\nRoten er " << rot << endl;
    } else {
        cout << "Likinga har 0 reelle løsninger";
    }

}

void solveQuadradicEquation() {
    cout << "a: ";
    double a = inputDouble();
    cout << endl;
    cout << "b: ";
    double b = inputDouble();
    cout << endl;
    cout << "c: ";
    double c = inputDouble();
    printRealRoots(a,b,c);
}

void pythagoras() {
    int width_window = 1100;
    int height_window = 700;
    AnimationWindow win{100, 100, width_window, height_window, "Pytagoras"};

    int grunnlinje_trekant = 70;
    int høyde_trekant = 110;
    
    int trekantNV[2] =  {width_window * 2 / 5 - grunnlinje_trekant / 2, height_window * 3 / 5};
    int trekantNH[2] =  {width_window * 2 / 5 + grunnlinje_trekant / 2, height_window * 3 / 5};
    int trekantO[2] =  {width_window * 2 / 5 - grunnlinje_trekant / 2, height_window * 3 / 5 - høyde_trekant};
    
    win.draw_triangle(Point{trekantNV[0], trekantNV[1]}, Point{trekantNH[0], trekantNH[1]}, Point{trekantO[0], trekantO[1]});
    win.draw_rectangle(Point{trekantNV[0], trekantNV[1]}, grunnlinje_trekant, grunnlinje_trekant, Color::red);
    win.draw_rectangle(Point{trekantO[0]-høyde_trekant, trekantO[1]}, høyde_trekant, høyde_trekant, Color::green);
    win.draw_quad(Point{trekantNH[0], trekantNH[1]}, Point{trekantNH[0]+høyde_trekant, trekantNH[1]-grunnlinje_trekant}, Point{trekantO[0]+høyde_trekant, trekantO[1]-grunnlinje_trekant}, Point{trekantO[0], trekantO[1]});

    win.wait_for_close();
}

vector<int> calculateBalance(int innskudd=10000, int rente=3, int antall_år=10) {
    vector<int> årsoversikt;
    for (int i=0; i<antall_år; i++){
        årsoversikt.push_back(innskudd*pow((1+static_cast<double>(rente)/100),i));
    }
    return årsoversikt;
}

void printBalance(vector<int> vec) {
    cout << right << setw(10) << "År" << setw(10) << "Saldo" << endl;
    for (int i=0; i<vec.size(); i++) {
        cout << right << setw(10) << i << setw(10) << vec.at(i) << endl;
    }
}

int main() {
    int valgtInt;
    do {
        cout << "0) Avslutt" << endl 
        << "1) Print integer" << endl
        << "2) Print integer (return)" << endl
        << "3) Summer to tall" << endl
        << "4) Summer N tall" << endl
        << "5) Summer tall helt til input er 0" << endl
        << "6) Print double (return)" << endl
        << "7) Konverter fra NOK til euro" << endl
        << "8) Print gangetabellen" << endl
        << "9) Løs andregradslikning" << endl
        << "10) Pytagorasplot" << endl
        << "11) Print balanse" << endl;
        cin >> valgtInt;

        switch (valgtInt) {
        case 0:
        {
            avslutt();
            break;
        }
        case 1:
        {
            cout << endl;
            inputAndPrintInteger();
            cout << endl;
            break;
        }
        case 2: 
        {
            cout << endl;
            int number = inputInteger();
            cout << "\nDu skrev " << number << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            inputTwoIntegersAnPrintSum();
            cout << endl;
            break;
        }
        case 4:
        {
            cout << endl;
            sumOfNIntegers();
            cout << endl;
            break;
        }
        case 5:
        {
            cout << endl;
            sumUntilInputZero();
            cout << endl;
            break;
        }
        case 6:
        {
            cout << endl;
            double number = inputDouble();
            cout << "\nDu skrev " << number << endl;
            cout << endl;
            break;
        }
        case 7:
        {
            cout << endl;
            convertFromNokToEuro();
            cout << endl;
            break;
        }
        case 8:
        {
            cout << endl;
            printMultiplicationTable();
            cout << endl;
            break;
        }
        case 9:
        {
            cout << endl;
            solveQuadradicEquation();
            cout << endl;
            break;
        }
        case 10:
        {
            pythagoras();
            break;
        }
        case 11:
        {
            cout << endl;
            printBalance(calculateBalance());
            cout << endl;
            break;
        }
        default:
            break;
        }
    } while (valgtInt != 0);

    return 0;
}

//------------------------------------------------------------------------------
/*
1e) Jeg brukte returnerfunkjsonen fordi da kan jeg bare sette en variabel lik funksjonen.

2c) Jeg brukte en for-løkke i a fordi det var gitt på forhånd hvor mange iterasjoner vi skulle ha.
I b er ikke antall interasjoner gitt, kun at vi skulle kjøre så lenge et krav var oppfylt (Men minst én gang).
Derfor tenkte jeg at en do while-løkke var en god idé.

2f) Du bør bruke inputFloat fordi vi skal jobbe med floats. Det sto ingen plass at vi skal returnere noe.
*/