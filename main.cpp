#include <iostream>
#include "WeatherVariable.h"
#include <Limits>
#include "HourlyForecast.h"
#include "LocationManagerMenu.h"
#include "AirQuality.h"
#include "ApiCall.h"

using namespace std;

int main()
{
    cout << "***************************       MENU  ******************************** "<<endl;
    int option;
    LocationManager locationManager;
    WeatherVariable weatherVariable;

    do
    {
        cout << "1. Location Management\n";
        cout << "2. Weather Forecast\n";
        cout << "3. Air Quality\n";
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid inpit please enter a number.\n"<< endl;
            continue;
        }

        switch (option)
        {
            case 1:
                locationManager.showMenu();
                break;
            case 2:
                weatherVariable.Showmenu();
                break;
            case 3:
                // Call any method or perform actions related to air quality here
                AirQuality airQuality;
                airQuality.Showmenu();
                break;
            case 4:
                cout << "\tClosing Weather Application\n";
                break;
            default:
                cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
                break;

        }
    }
    while (option != 4);

    return 0;
}
