#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"


int checkCharAndPosition(string løsning, string gjett);
int checkChar(string løsning, string gjett);

void playMastermind() {
    string løsning = randomizeString(4, 'A', 'F');
    cout << "Løsnig: " << løsning << endl;
    string gjett;
    int forsøk = 0;
    do {
        gjett = readInputToString(4, 'A', 'F');
        cout << "\n Du har " << checkCharAndPosition(løsning, gjett) << " på rett posisjon." << endl
        << "Du har " << checkChar(løsning, gjett) << " rette boksatver." << endl;
        forsøk++;
        if (checkCharAndPosition(løsning, gjett) == 4) {
            cout << "Gratulerer, du klarte det! " << endl;
        }
        if (checkCharAndPosition(løsning, gjett) < 4 && forsøk == 4) {
            cout << "Det ble dessverre tap. Vil du spille igjen (J/N) " << endl;
        }
    } while (checkCharAndPosition(løsning, gjett) < 4 && forsøk < 5);
    string spille_igjen = "N";
    cout << "Vil du spille igjen (J/N) " << endl;
    cin >> spille_igjen;
    if (spille_igjen == "J"){
        playMastermind();
    }

}

int checkCharAndPosition(string løsning, string gjett) {
    int rett = 0;
    for (int x=0; x<løsning.size(); x++) {
        if (løsning[x] == gjett[x]){
            rett++;
        }
    }
    return rett;
}

int checkChar(string løsning, string gjett) {
    int rett = 0;
    for (int x=0; x<løsning.size(); x++) {
        for (int j=0; j<løsning.size(); j++) {
            if (gjett[x] == løsning[j]){
            rett++;
            løsning[j] = '*';
            break;
        }
        }
    }
    return rett;
}