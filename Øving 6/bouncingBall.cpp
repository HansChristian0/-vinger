#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};

map<int, Color> returnIntToColor() {
    map<int, Color> intToColor;
    intToColor.insert(pair<int, Color>(1, Color::blue_violet));
    intToColor.insert(pair<int, Color>(2, Color::red));
    intToColor.insert(pair<int, Color>(3, Color::green_yellow));
    intToColor.insert(pair<int, Color>(4, Color::sandy_brown));

    return intToColor;
}

istream& operator>>(istream& is, Config& cfg) {
    string line;
    string ord;
    vector<string> fileStrings;
    getline(is, line);
    stringstream ss(line);
    while (getline(ss, ord, ' ')){
        fileStrings.push_back(ord);
    }
    cfg.colorUp = stoi(fileStrings.at(0));
    cfg.colorDown = stoi(fileStrings.at(1));
    cfg.speed = stoi(fileStrings.at(2));
    return is;
}



void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    filesystem::path configFile{"konfigurasjon.txt"};
    ifstream is{configFile};
    string line;
    Config slowBall;
    Config fastBall;
    vector<Config> configs;
    bool moveUp = true;
    int n;
    if(is) {
        while (getline(is, line)) {
            istringstream lineStream(line);
            Config cfg;
            lineStream >> cfg;
            configs.push_back(cfg);
        }
    }
    if (configs.size() >= 2) {
        slowBall = configs.at(0);
        fastBall = configs.at(1);
    }

    Config config {slowBall};
    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = config.speed * cos(alpha);
        increment_y = config.speed * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                if (config.speed == slowBall.speed) {
                    config = fastBall;
                } else {
                    config = slowBall;
                }
            }
        } else {
            // moving rightwards
            x += increment_x;
        }
        increment_x = config.speed * cos(alpha);
        increment_y = config.speed * sin(alpha);

        // movement i y-direction
        if ((y - increment_y) > 0 && moveUp == true) {
            // move upwards
            y -= increment_y;
            if (config.speed == slowBall.speed) {
                n=1;
            } else {
                n=3;;
            }
            window.draw_circle(Point{x,y}, 30, returnIntToColor().at(n));
            
        } else {
            // move downward
            moveUp = false;
            y += increment_y;
            if (config.speed == slowBall.speed) {
                n=2;
            } else {
                n=4;
            }
            window.draw_circle(Point{x,y}, 30, returnIntToColor().at(n));
            if (y+increment_y > window.height()){
                moveUp = true;
            }    
        }
    
        window.next_frame();
    }
}

