
//

#ifndef WDA_1_DAILYWEATHERVAR_H
#define WDA_1_DAILYWEATHERVAR_H
#include <string>
#include<vector>
using namespace std;

class DailyWeatherVar {
protected:
    struct Daily{
        int Weathercode;
        double MaximumTemperature2m;
        double MinimumTemperature2m;
        double MaximumApparentTemperature ;
        double MinimumApparentTemperature;
        string Sunrise;
        double DaylightDuration;
        string Sunset;
        double SunshineDuration;
        double UVIndex;
        double UVIndexClearSky;
        double PrecipitationSum;
        double SunshineDurartion;
        double Rainsum;
        double Showersum;
        double Snowfallsum;
        int Precipitatiionhrs;
        int  PrecipitationProbMax;
        double MaxWindSpd;
        double MaxWindGust;
        int  SDominantWindDir;
        double ShortwaveRadSum;
        double RefEvatranspiration;



    };



public:
    DailyWeatherVar();//Constructor
    vector<Daily> DailyWeatherData;

};








#endif //WDA_1_DAILYWEATHERVAR_H
