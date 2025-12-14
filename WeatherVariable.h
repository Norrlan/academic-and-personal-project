//
// Created by obabi on 13/04/2024.
//

#ifndef WDA_1_WEATHERVARIABLE_H
#define WDA_1_WEATHERVARIABLE_H
#include <iostream>
#include <string>

class HourlyForecast;
class WeatherVariable {
public:
    WeatherVariable();
    void HourlyForecast();
    void SolarRadiation();
    void DailyWeatherVar();
    void Showmenu();
    void PressureLvl();
    void WeatherModel();
    void ExportData();
};


#endif //WDA_1_WEATHERVARIABLE_H

