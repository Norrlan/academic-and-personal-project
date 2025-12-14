//
// Created by obabi on 13/04/2024.
//

#include "HourlyForecast.h"
#include"ApiCall.h"
#include <iostream>
#include "json.h"
#include <string>
using namespace std;
using json=nlohmann::json;
HourlyForecast::HourlyForecast()

{// Fetch the data from the https URL.
const string Url="https://api.open-meteo.com/v1/forecast?latitude=52.9662&longitude=-1.0879&hourly=,precipitation,relative_humidity_2m,rain,evapotranspiration,visibility,wind_gusts_10m,dew_point_2m,wind_speed_180m,wind_direction_180m,cloud_cover,snow_depth,snowfall,precipitation_probability,uv_index,uv_index_clear_sky,is_day,surface_pressure,pressure_msl,weather_code,showers,temperature_2m2";
       string jsonRes=GetRequest(Url);
       json jsonResponse=json::parse(jsonRes);

      for(int i =0; i < 24; i++)

      {
          cout << "Time: " << jsonResponse["hourly"]["time"][i] << "\n";
          cout << "Precipitation: " << jsonResponse["hourly"]["precipitation"][i] << " mm\n";
          cout << "Relative Humidity: " << jsonResponse["hourly"]["relative_humidity_2m"][i] << " %\n";
          cout << "Rain: " << jsonResponse["hourly"]["rain"][i] << " mm\n";
          cout << "Evapotranspiration: " << jsonResponse["hourly"]["evapotranspiration"][i] << " mm\n";
          cout << "Visibility: " << jsonResponse["hourly"]["visibility"][i] << " m\n";
          cout << "Wind Gusts: " << jsonResponse["hourly"]["wind_gusts_10m"][i] << " km/h\n";
          cout << "Dew Point: " << jsonResponse["hourly"]["dew_point_2m"][i] << "C\n";
          cout << "Wind Speed (180m): " << jsonResponse["hourly"]["wind_speed_180m"][i] << " km/h\n";
          cout << "Wind Direction (180m): " << jsonResponse["hourly"]["wind_direction_180m"][i] << " °\n";
          cout << "Temperature (2m): " << jsonResponse["hourly"]["temperature_2m"][i] << " °C\n";
          cout << "Cloud Cover: " << jsonResponse["hourly"]["cloud_cover"][i] << " %\n";
          cout << "Snow Depth: " << jsonResponse["hourly"]["snow_depth"][i] << " m\n";
          cout << "Snowfall: " << jsonResponse["hourly"]["snowfall"][i] << " cm\n";
          cout << "Precipitation Probability: " << jsonResponse["hourly"]["precipitation_probability"][i] << " %\n";
          cout << "UV Index: " << jsonResponse["hourly"]["uv_index"][i] << "\n";
          cout << "UV Index Clear Sky: " << jsonResponse["hourly"]["uv_index_clear_sky"][i] << "\n";
          cout << "Is Day: " << jsonResponse["hourly"]["is_day"][i] << "\n";
          cout << "Surface Pressure: " << jsonResponse["hourly"]["surface_pressure"][i] << " hPa\n";
          cout << "Sea Level Pressure: " << jsonResponse["hourly"]["pressure_msl"][i] << " hPa\n";
          cout << "Weather Code (WMO): " << jsonResponse["hourly"]["weather_code"][i] << "\n";
          cout << "Showers: " << jsonResponse["hourly"]["showers"][i] << " mm\n";




      }


      }







