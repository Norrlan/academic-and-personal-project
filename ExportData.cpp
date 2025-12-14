#include "ExportData.h"
#include "fstream"
#include "iostream"

ExportData::ExportData() {}
void ExportData::exportHourlyToCSV(const std::string &filename, const std::vector<std::string> &time,
                                   const std::vector<double> &temperature, const std::vector<double> &precipitation,
                                   const std::vector<double> &humidity)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << filename << "for writing.\n";
        return;
    }


    file << "Time, Temperature (C), Precipitation (mm), Humidity (%)\n";
    for (size_t i = 0; i < time.size(); ++i)
    {
        file << time[i] << ",";
        file << (i < temperature.size() ? std::to_string(temperature[i]) :"") << ",";
        file << (i < precipitation.size() ? std::to_string(precipitation[i]) : "") << ",";
        file << (i < humidity.size() ? std::to_string(humidity[i]) : "") << "\n";
    }
    file.close();
    std::cout << "Hourly forecast exported to " << filename << "\n";
}

void ExportData::exportPressureToCSV(const std::string &filename, const std::vector<std::string> &time,
                                     const std::vector<double> &temperature_1000hPa,
                                     const std::vector<double> &temperature_975hPa,
                                     const std::vector<double> &humidity_1000hPa,
                                     const std::vector<double> &humidity_975hPa,
                                     const std::vector<double> &cloud_1000hPa, const std::vector<double> &cloud_975hPa,
                                     const std::vector<double> &wind_speed_1000hPa,
                                     const std::vector<double> &wind_speed_975hPa,
                                     const std::vector<double> &wind_dir_1000hPa,
                                     const std::vector<double> &wind_dir_975hPa,
                                     const std::vector<double> &geopotential_1000hPa,
                                     const std::vector<double> &geopotential_975hPa)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << filename << "for writing.\n";
        return;
    }

    file << "Time,Temp_1000hPa,Temp_975hPa,RH_1000hPa,RH_975hPa,Cloud_1000hPa,Cloud_975hPa,"
            "WindSpeed_1000hPa,WindSpeed_975hPa,WindDir_1000hPa,WindDir_975hPa,"
            "Geopotential_1000hPa,Geopotential_975hPa\n";


    for (size_t i = 0; i < time.size(); i++)
    {
        file << time[i] << ",";
        file << (i < temperature_1000hPa.size() ? std::to_string(temperature_1000hPa[i]) : "") << ",";
        file << (i < temperature_975hPa.size() ? std::to_string(temperature_975hPa[i]) : "") << ",";
        file << (i < humidity_1000hPa.size() ? std::to_string(humidity_1000hPa[i]) : "") << ",";
        file << (i < humidity_975hPa.size() ? std::to_string(humidity_975hPa[i]) : "") << ",";
        file << (i < cloud_1000hPa.size() ? std::to_string(cloud_1000hPa[i]) : "") << ",";
        file << (i < cloud_975hPa.size() ? std::to_string(cloud_975hPa[i]) : "") << ",";
        file << (i < wind_speed_1000hPa.size() ? std::to_string(wind_speed_1000hPa[i]) : "") << ",";
        file << (i < wind_speed_975hPa.size() ? std::to_string(wind_speed_975hPa[i]) : "") << ",";
        file << (i < wind_dir_1000hPa.size() ? std::to_string(wind_dir_1000hPa[i]) : "") << ",";
        file << (i < wind_dir_975hPa.size() ? std::to_string(wind_dir_975hPa[i]) : "") << ",";
        file << (i < geopotential_1000hPa.size() ? std::to_string(geopotential_1000hPa[i]) : "") << ",";
        file << (i < geopotential_975hPa.size() ? std::to_string(geopotential_975hPa[i]) : "") << "\n";
    }

    file.close();
    std::cout << "Pressure-level forecast exported to " << filename << "\n";



}



