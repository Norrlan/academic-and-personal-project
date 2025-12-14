//
// Created by obabi on 15/04/2024.
//

#ifndef WDA_1_EUROPEANAIR_H
#define WDA_1_EUROPEANAIR_H
#include <string>
#include<vector>
using namespace std;

class EuropeanAir {

protected:
    struct Euro {
        int european_aqi;//Shortwave Solar Radiation GHI;
        int european_aqi_pm2_55; //Direct Solar Radiation
        int european_aqi_pm10;// Diffuse Solar Radiation DHI
        int european_aqi_nitrogen_dioxide; // Direct Normal Irradiance DNI
        int european_aqi_ozone; // Global Tilted Radiation GTI
        int european_aqi_sulphur_dioxide;//Terrestrial Solar Radiation
        std::string time;
    };


public:
    EuropeanAir();// Constructor
    std::vector <Euro> euro;


};


#endif //WDA_1_EUROPEANAIR_H
