#include <iostream>
#include <iomanip>
#include "ansiicodes.h"

using namespace std;

//=====================================
// Battery State of Charge Generator
//=====================================

int main() {

    //Display title
    cout << "Battery Voltage to State of Charge (SoC Generator)" << endl;
    cout << "--------------------------------------------------" << endl;


    //Ask for user information
    int minVoltage = 0;
    int maxVoltage = 0;
    int voltageStep = 0;

    cout << "Enter minimum voltages to show in table [mV]: ";
    cin >> minVoltage;
    cout << "Enter maximum voltages to show in table [mV]: ";
    cin >> maxVoltage;
    cout << "Enter voltage step size [mV]: ";
    cin >> voltageStep;
    cout << endl;


    //Output descriptions
    const int VOLTAGE_WIDTH = 5;
    const int SOC_WIDTH = 5;
    int voltage = minVoltage;
    int stateOfCharge = 0;

    const int MIN_CHARGE = 3000;
    const int PERCENT = 100;
    const int VOLTAGE_RANGE = 1200;

    string description = " ";

    cout << ANSII_BOLD;
    cout << "   " << "Voltage" << "  " << "   SoC" << " " << "Description" << endl;
    cout << "   " << "-------" << "  " << "------" << " " << "-----------" << endl;

    while (voltage <= maxVoltage){
        //Convert SoC
        stateOfCharge = (voltage - MIN_CHARGE)*PERCENT/VOLTAGE_RANGE;

        //Change colours and descriptions
        if (stateOfCharge < 0){
            stateOfCharge = 0;
            description = "Too low!";
            cout << ANSII_NORMAL << ANSII_BOLD << ANSII_RED;

        } else if (stateOfCharge < 15){
            description = "Too low!";
            cout << ANSII_NORMAL << ANSII_BOLD << ANSII_RED;

        } else if (stateOfCharge < 35){
            description = "Low";
            cout << ANSII_NORMAL<< ANSII_BLUE;

        } else if (stateOfCharge < 95){
            description = "OK";
            cout << ANSII_NORMAL;

        } else if (stateOfCharge <= 100){
            description = "Full";
            cout << ANSII_NORMAL << ANSII_GREEN;

        } else {
            stateOfCharge = 100;
            description = "CAUTION: Overcharged!";
            cout << ANSII_NORMAL << ANSII_BOLD << ANSII_RED;
        }

        //Print table
        cout << "   " << setw(VOLTAGE_WIDTH) << voltage << "mV";
        cout << "  " << setw(SOC_WIDTH) << stateOfCharge << "% ";
        cout << description << endl;

        //Increase voltage
        voltage = voltage + voltageStep;
    }


    return 0;
}

