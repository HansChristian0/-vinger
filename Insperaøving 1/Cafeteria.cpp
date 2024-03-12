#include "Cafeteria.h"
#include "utilities.h"

Cafeteria::Cafeteria(string n, Location l) : name{n}, location{l} {
    for(auto p : mainDishPrices) {
        stock.insert({p.first, 0});
    }
    for(auto p : sideDishPrices) {
        stock.insert({p.first, 0});
    }
}

vector<DailyMenu> Cafeteria::getWeeklyMenu() {
    return weeklyMenu;
}

void Cafeteria::setWeeklyMenu(vector<DailyMenu> menu) {
    weeklyMenu = menu;
}

int Cafeteria::getStock (string item) {
    return stock.at(item);
}

void Cafeteria::setStock(string item, int amount) {
    stock.at(item) = amount;
}

void Cafeteria::removeStock(string item) {
    stock.at(item)--;
}

//------------------------------------------------------------------------------------------------

DailyMenu Cafeteria::getDailyMenu(Weekday w) {
    // BEGIN: 1c
    
    DailyMenu dummy;
    enum Weekday day;
    day = w;
    dummy = Cafeteria::weeklyMenu.at(0);
    return dummy;

    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu) {
    // BEGIN: 1d
    if (Cafeteria::getStock(menu.mainDish) >=1 && Cafeteria::getStock(menu.sideDish) >= 1) {
        return true;
    }

    return false;

    // END: 1d
}

void Cafeteria::saveToFile(string fileName) {
    // BEGIN: 1e
    filesystem::path filNavn{fileName};
    ofstream outputStream{filNavn};
    vector<DailyMenu> menu = Cafeteria::getWeeklyMenu();
    for (DailyMenu& el : menu) {
        outputStream << el << endl;
    }


    // END: 1e
}


void Cafeteria::importStock(string fileName) {
    // BEGIN: 2a
    filesystem::path filsti{fileName};
    ifstream inputStream{filsti};
    string inputString;
    if (inputStream) {
        vector<string> stockStatus;
        string reader;
        while (getline(inputStream, inputString)) {
            stringstream ss;
            ss = stringstream(inputString);
            while (getline(ss, reader, ',')){
                stockStatus.push_back(reader);
            }
            stock.at(stockStatus.at(0)) = stoi(stockStatus.at(1));
            stockStatus = {};
        }
    }


    // END: 2a
}


vector<DailyMenu> generateWeeklyMenu() {
    // BEGIN: 2c

    vector<DailyMenu> dummy;
    for (int i=0; i<7; i++) {
        dummy.push_back(getRandomMenu());
    }
    return dummy;

    // END: 2c
}