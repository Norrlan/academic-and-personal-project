//
// Created by obabi on 13/04/2024.
//

#ifndef WDA_1_HOURLYFORECAST_H
#define WDA_1_HOURLYFORECAST_H
#include <string>
#include<vector>
using namespace std;
class HourlyForecast {
protected:
    struct Hourly{
        string time;
        double precipitation;
        double relative_humidity_2m;
        double rain;
        double evapotranspiration;
        double visibility;
        double wind_gusts_10m;
        double dew_point_2m;
        double wind_speed_180m;
        double wind_direction_180m;
        double cloud_cover;
        double snow_depth;
        double snowfall;
        double precipitation_probability;
        double uv_index;
        double uv_index_clear_sky;
        int is_day;
        double surface_pressure;
        double pressure_msl;
        int weather_code;
        double showers;
        double temperature_2m2;


    };

public:
    HourlyForecast( );// Constructor
    vector<Hourly> HourlyData;

};


#endif //WDA_1_HOURLYFORECAST_H
