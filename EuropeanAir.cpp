#include <iostream>
#include "json.h"
#include <string>
#include"ApiCall.h"
#include "EuropeanAir.h"
using namespace  std;
using json=nlohmann::json;

EuropeanAir::EuropeanAir() {
    const string Url="https://air-quality-api.open-meteo.com/v1/air-quality?latitude=52.52&longitude=13.41&hourly=european_aqi,european_aqi_pm2_5,european_aqi_pm10,european_aqi_nitrogen_dioxide,european_aqi_ozone,european_aqi_sulphur_dioxide&timezone=Europe%2FLondon&past_days=1&forecast_days=1";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i = 0; i < 48; i++) {
        cout << "european_aqi:" << jsonResponse["hourly"]["european_aqi"][i] << "\n";
        cout << "european_aqi_pm2_5:" << jsonResponse["hourly"]["european_aqi_pm2_5"][i] << "\n";
        cout << "european_aqi_pm10" << jsonResponse["hourly"]["european_aqi_pm10"][i] << "\n";
        cout << "european_aqi_nitrogen_dioxide:" << jsonResponse["hourly"]["european_aqi_nitrogen_dioxide"][i] << "\n";
        cout << "european_aqi_ozone:" << jsonResponse["hourly"]["european_aqi_ozone"][i] << "\n";
        cout << "european_aqi_sulphur_dioxide:" << jsonResponse["hourly"]["european_aqi_sulphur_dioxide"][i] << "\n";
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