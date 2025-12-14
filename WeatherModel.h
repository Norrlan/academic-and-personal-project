
//

#ifndef WDA_1_WEATHERMODEL_H
#define WDA_1_WEATHERMODEL_H

#include <string>
#include<vector>
using namespace std;

class WeatherModel
        {
public:
    struct WmodelRecord
            {
        std::string time;
        double temperature_2m;
        double precipitation;
        double relative_humidity_2m;
        double wind_speed_10m;
        double wind_direction_10m;
        double cloud_cover;
    };
    WeatherModel();
    std::vector<WmodelRecord> modelData;
    void fetchModelData(const std::string& modelName);
    void display() const;




};




#endif //WDA_1_WEATHERMODEL_H
