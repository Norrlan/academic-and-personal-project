//
// Created by obabi on 15/04/2024.
//

#ifndef WDA_1_HOURLYAIR_H
#define WDA_1_HOURLYAIR_H
#include <string>
#include<vector>
using namespace std;

class HourlyAir
{
protected:
    struct Aero {
        double pm10;//Shortwave Solar Radiation GHI;
        double  pm2_5; //Direct Solar Radiation
        int carbon_monoxide;// Diffuse Solar Radiation DHI
        double nitrogen_dioxide; // Direct Normal Irradiance DNI
        double sulphur_dioxide; // Global Tilted Radiation GTI
        int ozone;//Terrestrial Solar Radiation
        double  aeorsol_optical_depth;// Shortwave Solar Radiation GHI (Instant)
        int dust; // Direct Solar Radiation (Instant)
        double uv_index; // Diffuse Solar Radiation DHI (Instant)
        double uv_index_clear_sky; // Direct Normal Irradiance DNI (Instant)
        double ammonia; // Global Tilted Iradiation Instatnt
        double alder_pollen;//Terrestrial Solar Radiation (Instant)
        double birch_pollen; // Direct Normal Irradiance DNI (Instant)
        double grass_pollen; // Global Tilted Iradiation Instatnt
        int mugwort_pollen;//Terrestrial Solar Radiation (Instant)
        int olive_pollen; // Direct Normal Irradiance DNI (Instant)
        int ragweed_pollen; // Global Tilted Iradiation Instatnt
        std::string time;
    };

public:
    HourlyAir();// Constructor
    std::vector <Aero> aero;
};






#endif //WDA_1_HOURLYAIR_H
