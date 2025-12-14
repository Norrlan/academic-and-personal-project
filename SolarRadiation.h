
#ifndef WDA_1_SOLARRADIATION_H
#define WDA_1_SOLARRADIATION_H
#include <string>
#include<vector>
//extern double  avgSolarRadiation;// for avergae solar radiation
//extern double  avgDirectRadiation; //

class SolarRadiation {
private:
    struct Solar {
        int Shortwave;//Shortwave Solar Radiation GHI;
        int  DirectRadiation; //Direct Solar Radiation
        int DHI;// Diffuse Solar Radiation DHI
        double DNI; // Direct Normal Irradiance DNI
        int GTI; // Global Tilted Radiation GTI
        double Terrestrial;//Terrestrial Solar Radiation
        double GHI_Instant;// Shortwave Solar Radiation GHI (Instant)
        double InstantDirectRadiation; // Direct Solar Radiation (Instant)
        double InstantDHI; // Diffuse Solar Radiation DHI (Instant)
        double InstantDNI; // Direct Normal Irradiance DNI (Instant)
        double instant_GTI; // Global Tilted Iradiation Instatnt
        double InstantTerrestrial;//Terrestrial Solar Radiation (Instant)
       std:: string time;
    };


public:
    SolarRadiation();// Constructor
    std::vector <Solar> solar;
};


#endif //WDA_1_SOLARRADIATION_H
