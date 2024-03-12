#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"


double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){
    return initVelocityY + acclY()*time;
}

double posX(double initPositionX, double initVelocityX, double time){
    return initPositionX + initVelocityX*time;
}

double posY(double initPositionY, double initVelocityY, double time){
    return initPositionY + initVelocityY*time +acclY()*pow(time,2)/2;
}

void printTime(double time) {
    int hours = time/3600;
    time -= hours*3600;
    int min = time/60;
    time -= min*60;
    cout << "Det er " << hours << " timer, " << min << " minutter og " << time << " sekunder" << endl;
}

double flightTime(double initVelocityY){
    return -2*initVelocityY/acclY();
}

double getUserInputTheta() {
    double theta = 0.0;
    cout << "\nHva er utgangsvinkelen? ";
    cin >> theta;
    return theta;
}

double getUserInputInitVelocity() {
    double vel = 0.0;
    cout << "\nHva er utgangsfarta? ";
    cin >> vel;
    return vel;
}

double degToRad(double deg) {
    return deg/180*M_PI;
}

double getVelocityX(double theta, double initVelocity) {
    return initVelocity*cos(theta);
}

double getVelocityY(double theta, double initVelocity) {
    return initVelocity*sin(theta);
}

vector<double> getVelocityVector(double theta, double initVelocity) {
    return {getVelocityX(degToRad(theta), initVelocity), getVelocityY(degToRad(theta), initVelocity)};
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return posX(0, velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractise() {
    int avstand_blink = randomWithLimits(100,1000);
    bool victory = false;
    double initVel = 0;
    double theta = 0;
    int forsøk = 0;
    int x_coordinate = 0;

    do {
        initVel = getUserInputInitVelocity();
        theta = getUserInputTheta();
        theta = degToRad(theta);
        x_coordinate = getDistanceTraveled(getVelocityX(theta, initVel), getVelocityY(theta, initVel));

        if (targetPractice(avstand_blink, getVelocityX(theta, initVel), getVelocityY(theta, initVel)) < 5){
            victory = true;
            cout << "\nHurra! Du vant.";
        }
        else {
            forsøk++;
            cout << "Avstanden til blinken er " << 
            targetPractice(avstand_blink, getVelocityX(theta, initVel), getVelocityY(theta, initVel)) << endl 
            << "Det tok " << flightTime(getVelocityY(theta, initVel)) << " sekunder" << endl
            << "La oss prøve igjen" << endl;
        }

    } while (forsøk < 10 && victory == false);

    if (victory == false) {
        cout << "\nJaja, det var synd. Bedre lykke neste gang." << endl;
    }
}