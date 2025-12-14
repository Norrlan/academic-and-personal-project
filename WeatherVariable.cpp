//
// Created by obabi on 13/04/2024.
//WeatherVariable.cpp

#include "WeatherVariable.h"
#include "HourlyForecast.h"
#include "SolarRadiation.h"
#include "DailyWeatherVar.h"
#include "PressureLvl.h"
#include "ExportData.h"
#include "WeatherModel.h"
#include <iostream>
using namespace std;
WeatherVariable::WeatherVariable() {

}
void WeatherVariable::Showmenu()
{
    int option;
    do {
        cout << "1.Hourly Forecast" << endl;
        cout << "2. Solar Radiation" << endl;
        cout << "3.Daily Weather Varaibles" << endl;
        cout << "4.Weather Models" << endl;
        cout << "5.Pressure Levels" << endl;
        cout << "6.Export Weather Data" << endl;
        cout << "7.Mainmenu" << endl;
        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                HourlyForecast();
                break;
            case 2:
                SolarRadiation();
                break;
            case 3:
              DailyWeatherVar();
               break;
            case 4:
                WeatherModel();
                break;
            case 5:
                PressureLvl();
                break;
            case 6:
                ExportData();// export data into csv format
                break;
            case 7:
                return; // Return to the main menu
            default:
                cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
                break;
        }
    } while (true); // Continue looping until the user chooses to return to
}


void WeatherVariable::HourlyForecast()
{
    class HourlyForecast hourly;
}

void WeatherVariable::SolarRadiation()
{
    class SolarRadiation solar;
}

void WeatherVariable::DailyWeatherVar()
{
    class DailyWeatherVar dailyWeatherVar;
}

void WeatherVariable::PressureLvl()
{
     class PressureLvl PressureRecord;
}

void WeatherVariable::WeatherModel()
{
    class WeatherModel WmodelRecord;
}

void WeatherVariable::ExportData() {
    cout << " Exporting...\n";
    ::ExportData exporter;
    ::HourlyForecast hourly;
    // Assume hourly.HourlyData has been populated already
    std::vector<std::string> times;
    std::vector<double> temps;
    std::vector<double> precips;
    std::vector<double> humidities;

    for (const auto &h: hourly.HourlyData)
    {
        times.push_back(h.time);
        temps.push_back(h.temperature_2m2);
        precips.push_back(h.rain);
        humidities.push_back(h.relative_humidity_2m);
    }

    exporter.exportHourlyToCSV("hourly_forecast.csv", times, temps, precips, humidities);
    ::PressureLvl pressure;
    // Assume pressure.pressureData has been populated already
    std::vector<std::string> p_times;
    std::vector<double> temp1000, temp975, rh1000, rh975, cloud1000, cloud975;
    std::vector<double> ws1000, ws975, wd1000, wd975, geo1000, geo975;

    for (const auto &p: pressure.Pressure)
    {
        temp1000.push_back(p.temperature_1000hPa);
        temp975.push_back(p.temperature_975hPa);
        rh1000.push_back(p.relative_humidity_1000hPa);
        rh975.push_back(p.relative_humidity_975hPa);
        cloud1000.push_back(p.cloud_cover_1000hPa);
        cloud975.push_back(p.cloud_cover_975hPa);
        ws1000.push_back(p.wind_speed_1000hPa);
        ws975.push_back(p.wind_speed_975hPa);
        wd1000.push_back(p.wind_direction_1000hPa);
        wd975.push_back(p.wind_direction_975hPa);
        geo1000.push_back(p.geopotential_height_1000hPa);
        geo975.push_back(p.geopotential_height_975hPa);
    }

    exporter.exportPressureToCSV("pressure_forecast.csv",
                                 p_times, temp1000, temp975,
                                 rh1000, rh975, cloud1000, cloud975,
                                 ws1000, ws975, wd1000, wd975,
                                 geo1000, geo975);
    std::cout << "Export complete: hourly_forecast.csv and pressure_forecast.csv created.\n";

}


