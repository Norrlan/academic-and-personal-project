
#ifndef WDA_1_PRESSURELVL_H
#define WDA_1_PRESSURELVL_H
#include <string>
#include<vector>

class PressureLvl {
private:
    struct PressureRecord
            {
        double temperature_1000hPa;
        double temperature_975hPa;
        double relative_humidity_1000hPa;
        double relative_humidity_975hPa;
        double cloud_cover_1000hPa;
        double cloud_cover_975hPa;
        double wind_speed_1000hPa;
        double wind_speed_975hPa;
        double wind_direction_1000hPa;
        double wind_direction_975hPa;
        double geopotential_height_1000hPa;
        double geopotential_height_975hPa;


    };

    public:
        PressureLvl();// Constructor
        std::vector <PressureRecord> Pressure;

};


#endif //WDA_1_PRESSURELVL_H
