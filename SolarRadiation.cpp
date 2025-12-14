//
//

#include "SolarRadiation.h"
#include"ApiCall.h"
#include <iostream>
#include "json.h"
#include <string>

using namespace std;

using json=nlohmann::json;
SolarRadiation:: SolarRadiation()
{
    const string Url="https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=shortwave_radiation,"
                     "direct_radiation,diffuse_radiation,direct_normal_irradiance,global_tilted_irradiance,terrestrial_radiation,"
                     "shortwave_radiation_instant,direct_radiation_instant,diffuse_radiation_instant,"
                     "direct_normal_irradiance_instant,global_tilted_irradiance_instant,"
                     "terrestrial_radiation_instant&timezone=Europe%2FLondon&past_days=1&forecast_days=1";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i =0; i <=48; i++)
    {

        cout << "Shortwave Solar Radiation GHI:" << jsonResponse["hourly"]["shortwave_radiation"][i]<<"\n";
        cout << "Direct Solar Radiation:" << jsonResponse["hourly"]["direct_radiation"][i] << "\n";
        cout << "Diffuse Solar Radiation DHI:" <<  jsonResponse["hourly"]["diffuse_radiation"][0] << "\n";
        cout << "Direct Normal Irradiance DNI:" <<  jsonResponse["hourly"]["direct_normal_irradiance"][i] << "\n";
        cout << "Global Tilted Radiation GTI:" <<  jsonResponse["hourly"]["global_tilted_irradiance"][i] << "\n";
        cout << "Terrestrial Solar Radiation:" << jsonResponse["hourly"]["terrestrial_radiation"][i] << "\n";
        cout << "Shortwave Solar Radiation GHI (Instant):" << jsonResponse["shortwave_radiation_instant"][i] << "\n";
        cout << "Direct Solar Radiation (Instant):" <<  jsonResponse["hourly"]["direct_radiation_instant"][i] << "\n";
        cout << "Diffuse Solar Radiation DHI (Instant):" <<  jsonResponse["hourly"]["diffuse_radiation_instant"][i] << "\n";
        cout << "Direct Normal Irradiance DNI (Instant):" <<  jsonResponse["hourly"]["direct_normal_irradiance_instant"][i] << "\n";
        cout << "Global Tilted Radiation GTI Instant:" <<  jsonResponse["hourly"]["global_tilted_irradiance_instant"][i] << "\n";
        cout << "Terrestrial Solar Radiation (Instant):" <<  jsonResponse["hourly"]["terrestrial_radiation_instant"][i] << "\n";

    }
}







