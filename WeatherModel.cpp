//
//

#include "WeatherModel.h"
#include "ApiCall.h"
#include <iostream>
#include "json.h"
#include <string>
using json=nlohmann::json;
using namespace std;
using json=nlohmann::json;
WeatherModel::WeatherModel()
{
    const string Url = "https://api.open-meteo.com/v1/forecast?latitude=52.9662&longitude=-1.0879&models=best_match";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for (int i = 0; i <6; ++i)
    {
        cout << "Time: " << jsonResponse["hourly"]["time"][i] << "\n";
        cout << "Temperature (2m): " << jsonResponse["hourly"]["temperature_2m"][i] << " °C\n";
        cout << "Precipitation: " << jsonResponse["hourly"]["precipitation"][i] << " mm\n";
        cout << "Relative Humidity: " << jsonResponse["hourly"]["relative_humidity_2m"][i] << " %\n";


    }
}