
//

#include "DailyWeatherVar.h"
#include"ApiCall.h"
#include <iostream>
#include "json.h"
#include <string>
using namespace std;
using json=nlohmann::json;
DailyWeatherVar::DailyWeatherVar()
{
    const string Url="https://api.open-meteo.com/v1/gfs?latitude=52.52&longitude=13.41&daily=weather_code,temperature_2m_max,"
                     "temperature_2m_min,apparent_temperature_max,apparent_temperature_min,"
                     "sunrise,sunset,daylight_duration,sunshine_duration,uv_index_max,"
                     "uv_index_clear_sky_max,precipitation_sum,rain_sum,showers_sum,"
                     "snowfall_sum,precipitation_hours,precipitation_probability_max,"
                     "wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant,"
                     "shortwave_radiation_sum,"
                     "et0_fao_evapotranspiration&timezone=America%2FLos_Angeles";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i =0; i < 7; i++)
    {
        cout << "Weather code:" << jsonResponse["daily"]["weather_code"][i]<<"\n";

        cout << "Maximum Temperature (2 m):" << jsonResponse["daily"][",temperature_2m_max"][i] << "\n";
        cout << "Minimum Temperature (2 m):" <<  jsonResponse["daily"]["temperature_2m_min"][i] << "\n";
        cout << "Maximum Apparent Temperature (2 m):" <<  jsonResponse["daily"]["apparent_temperature_max"][i] << "\n";
        cout << "Minimum Apparent Temperature (2 m):" <<  jsonResponse["daily"]["apparent_temperature_min"][i] << "\n";
        cout << "Sunrise:" << jsonResponse["daily"]["sunrise"][i] << "\n";
        cout << "Sunset:" << jsonResponse["daily"]["sunset"][i] << "\n";
        cout << "Daylight Duration:" << jsonResponse["daily"]["daylight_duration"][i] << "\n";
        cout<< "\n";
        cout << "Sunshine Duration:" <<  jsonResponse["daily"]["sunshine_duration"][i] << "\n";
        cout << "UV Index:" <<  jsonResponse["daily"]["uv_index_max"][i] << "\n";
        cout << "UV Index Clear Sky:" <<  jsonResponse["daily"]["uv_index_clear_sky_max"][i] << "\n";
        cout << "Precipitation Sum:" <<  jsonResponse["daily"]["precipitation_sum"][i] << "\n";
        cout << "Rain Sum:" <<  jsonResponse["daily"]["rain_sum"][i] << "\n";
        cout << "Showers Sum:" <<  jsonResponse["daily"]["showers_sum"][i] << "\n";
        cout << "Snowfall Sum:" <<  jsonResponse["daily"]["snowfall_sum"][i] << "\n";
        cout << "Precipitation Hours:" <<  jsonResponse["daily"]["precipitation_hours"][i] << "\n";
        cout << "Precipitation Probability Max:" <<  jsonResponse["daily"]["precipitation_probability_max"][i] << "\n";
        cout << "Maximum Wind Speed (10 m):" <<  jsonResponse["daily"]["wind_speed_10m_max"][i] << "\n";
        //
        cout << "Maximum Wind Gusts (10 m):" <<  jsonResponse["daily"]["wind_direction_10m_dominant"][i] << "\n";
        cout << "Dominant Wind Direction (10 m)" <<  jsonResponse["daily"]["shortwave_radiation_sum"][i] << "\n";
        cout << "Shortwave Radiation Sum:" <<  jsonResponse["daily"]["precipitation_probability_max"][i] << "\n";
        cout << "Reference Evapotranspiration (ET₀):" <<  jsonResponse["daily"]["et0_fao_evapotranspiration"][i] << "\n";
        cout<< "\n";


        /*
*/







    }


}

