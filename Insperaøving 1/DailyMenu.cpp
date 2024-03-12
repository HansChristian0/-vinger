#include "DailyMenu.h"

const map<string, double> mainDishPrices {
    // Main dishes
    {"Burger", 55},
    {"Lasagna", 70},
    {"Chicken", 60},
    {"Porkchops", 65},
    {"Beef", 90},
    {"Soup", 50},
    {"Cinnamon bun", 25},
    {"Baguette", 54},
};

const map<string, double> sideDishPrices {
    {"Salad", 40},
    {"Fries", 30},
    {"Rice", 20},
    {"Mashed potatoes", 25},
    {"Pasta", 35},
    {"Caviar", 150},
    {"Couscous", 50},
    {"Root vegetables", 35}
};

const map<string, double> adjectivePriceModifiers {
    {"Vegan", 1.4},
    {"Vegetarian", 1.2},
    {"Gluten-free", 2.5},
    {"Lactose-free", 1.3},
    {"Sugar-free", 1.1},
    {"Whole grain", 1.2},
    {"Organic", 1.4},
    {"Local", 1.6}    

};

//------------------------------------------------------------------------------------------------

DailyMenu createDailyMenu(string adjective, string mainDish, string sideDish) {
    // BEGIN: 1a
    DailyMenu dummy;
    dummy.adjective = adjective;
    dummy.mainDish = mainDish;
    dummy.sideDish = sideDish;
    dummy.price = mainDishPrices.at(mainDish) + sideDishPrices.at(sideDish) + adjectivePriceModifiers.at(adjective);
    return dummy;

    // END: 1a
}
ostream& operator<<(ostream& os, DailyMenu d) {

    // BEGIN: 1b
    os << "Hovedretten er: " << d.mainDish << ", sidretten er: " << d.sideDish << " og koster " << d.price << " kroner." << endl;
    return os;

    // END: 1b
}

string getDishFromNumber(map<string, double> m, int n) {
    int i = 0;
    for(const auto& dish : m) {
        if(i == n) {
            return dish.first;
        }
        i++;
    }
    
    return "";
}

DailyMenu getRandomMenu() {
    // BEGIN: 2b
    random_device rd;
    uniform_int_distribution<int> distribution(1, 7);
    int mapSize = 8;
    
  
    DailyMenu dummy;
    default_random_engine generator(rd());

    string mainDish = getDishFromNumber(mainDishPrices, distribution(generator));
    string sideDish = getDishFromNumber(sideDishPrices, distribution(generator));
    string adjective = getDishFromNumber(adjectivePriceModifiers, distribution(generator));

    dummy.mainDish = mainDish;
    dummy.sideDish = sideDish;
    dummy.price = mainDishPrices.at(mainDish) + sideDishPrices.at(sideDish) + adjectivePriceModifiers.at(adjective);

    return dummy;

    // END: 2b
}