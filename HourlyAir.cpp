//
// Created by obabi on 15/04/2024.
//

#include "HourlyAir.h"
#include <iostream>
#include "json.h"
#include <string>
#include"ApiCall.h"
using namespace  std;
using json=nlohmann::json;

HourlyAir::HourlyAir()
{
    const string Url="https://air-quality-api.open-meteo.com/v1/air-quality?latitude=52.52&longitude=13.41&hourly=pm10,pm2_5,carbon_monoxide,nitrogen_dioxide,sulphur_dioxide,ozone,aerosol_optical_depth,dust,uv_index,uv_index_clear_sky,ammonia,alder_pollen,birch_pollen,grass_pollen,mugwort_pollen,olive_pollen,ragweed_pollen&timezone=America%2FLos_Angeles&past_days=1&forecast_days=1";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i = 0; i < 48; i++) {
        cout << "Weather code:" << jsonResponse["hourly"]["pm10"][i] << "\n";

        cout << "pm2_5:" << jsonResponse["hourly"]["pm10"][i] << "\n";
        cout << "carbon_monoxide" << jsonResponse["hourly"]["carbon_monoxide"][i] << "\n";
        cout << "nitrogen_dioxide" << jsonResponse["hourly"]["nitrogen_dioxide"][i] << "\n";
        cout << "sulphur_dioxide:" << jsonResponse["hourly"]["sulphur_dioxide"][i] << "\n";
        cout << "ozone::" << jsonResponse["hourly"]["ozone"][i] << "\n";
        cout << "aeorsol_optical_depth:" << jsonResponse["hourly"]["aeorsol_optical_depth"][i] << "\n";
        cout << "\n";
        cout << "dust:" << jsonResponse["hourly"]["dust"][i] << "\n";
        cout << "UV Index:" << jsonResponse["hourly"]["uv_index"][i] << "\n";
        cout << "UV Index Clear Sky:" << jsonResponse["hourly"]["uv_index_clear_sky"][i] << "\n";
        cout << "ammonia:" << jsonResponse["hourly"]["ammonia"][i] << "\n";
        cout << "alder_pollen" << jsonResponse["hourly"]["alder_pollen"][i] << "\n";
        cout << "birch_pollen:" << jsonResponse["hourly"]["birch_pollen"][i] << "\n";
        cout << "grass_pollen:" << jsonResponse["hourly"]["grass_pollen"][i] << "\n";
        cout << "mugwort_pollen:" << jsonResponse["hourly"]["mugwort_pollen"][i] << "\n";
        cout << "olive_pollen:" << jsonResponse["hourly"]["olive_pollen"][i] << "\n";
        cout << "ragweed_pollen:" << jsonResponse["hourly"]["ragweed_pollen"][i] << "\n";
    }


}