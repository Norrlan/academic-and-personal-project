
#include "PressureLvl.h"
#include "ApiCall.h"
#include <iostream>
#include "json.h"
#include <string>

using namespace std;

using json=nlohmann::json;
PressureLvl:: PressureLvl()
{
    const string Url= "https://api.open-meteo.com/v1/forecast?latitude=52.9662&longitude=-1.0879&hourly=temperature_1000hPa,temperature_975hPa,relative_humidity_1000hPa,relative_humidity_975hPa,cloud_cover_1000hPa,cloud_cover_975hPa,wind_speed_1000hPa,wind_speed_975hPa,"
                      "wind_direction_975hPa,wind_direction_1000hPa,geopotential_height_1000hPa,geopotential_height_975hPa";

    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i =0; i <=12; i++)
    {
        cout << "Time: " << jsonResponse["hourly"]["time"][i] << "\n";
        cout << "Temperature (1000 hPa): " << jsonResponse["hourly"]["temperature_1000hPa"][i] << " °C\n";
        cout << "Temperature (975 hPa): " << jsonResponse["hourly"]["temperature_975hPa"][i] << " °C\n";
        cout << "Relative Humidity (1000 hPa): " << jsonResponse["hourly"]["relative_humidity_1000hPa"][i] << " %\n";
        cout << "Relative Humidity (975 hPa): " << jsonResponse["hourly"]["relative_humidity_975hPa"][i] << " %\n";
        cout << "Cloud Cover (1000 hPa): " << jsonResponse["hourly"]["cloud_cover_1000hPa"][i] << " %\n";
        cout << "Cloud Cover (975 hPa): " << jsonResponse["hourly"]["cloud_cover_975hPa"][i] << " %\n";
        cout << "Wind Speed (1000 hPa): " << jsonResponse["hourly"]["wind_speed_1000hPa"][i] << " km/h\n";
        cout << "Wind Speed (975 hPa): " << jsonResponse["hourly"]["wind_speed_975hPa"][i] << " km/h\n";
        cout << "Wind Direction (1000 hPa): " << jsonResponse["hourly"]["wind_direction_1000hPa"][i] << " °\n";
        cout << "Wind Direction (975 hPa): " << jsonResponse["hourly"]["wind_direction_975hPa"][i] << " °\n";
        cout << "Geopotential Height (1000 hPa): " << jsonResponse["hourly"]["geopotential_height_1000hPa"][i] << " m\n";
        cout << "Geopotential Height (975 hPa): " << jsonResponse["hourly"]["geopotential_height_975hPa"][i] << " m\n";


    }


}


