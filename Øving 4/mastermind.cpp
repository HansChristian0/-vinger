#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"


int checkCharAndPosition(string løsning, string gjett);
int checkChar(string løsning, string gjett);

constexpr int word_size = 4;
constexpr int getWordSize(){
    return word_size;
}

void playMastermind() {
    string løsning = randomizeString(word_size, 'A', 'F');
    cout << "Løsnig: " << løsning << endl;
    string gjett;
    int forsøk = 0;
    do {
        gjett = readInputToString(word_size, 'A', 'F');
        cout << "\n Du har " << checkCharAndPosition(løsning, gjett) << " på rett posisjon." << endl
        << "Du har " << checkChar(løsning, gjett) << " rette boksatver." << endl;
        forsøk++;
        if (checkCharAndPosition(løsning, gjett) == word_size) {
            cout << "Gratulerer, du klarte det! " << endl;
        }
        if (checkCharAndPosition(løsning, gjett) < word_size && forsøk == word_size) {
            cout << "Det ble dessverre tap. Vil du spille igjen (J/N) " << endl;
        }
    } while (checkCharAndPosition(løsning, gjett) < word_size && forsøk < 7);
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