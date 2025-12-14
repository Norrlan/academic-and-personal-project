

#ifndef WDA_1_EXPORTDATA_H
#define WDA_1_EXPORTDATA_H


#include <string>
#include <vector>

class ExportData {
public:
    ExportData();

    // Export hourly forecast data into CSV
    void exportHourlyToCSV(const std::string& filename,
                           const std::vector<std::string>& time,
                           const std::vector<double>& temperature,
                           const std::vector<double>& precipitation,
                           const std::vector<double>& humidity);

    // Export pressure-level data into CSV
    void exportPressureToCSV(

            const std::string& filename,
                             const std::vector<std::string>& time,
                             const std::vector<double>& temperature_1000hPa,
                             const std::vector<double>& temperature_975hPa,
                             const std::vector<double>& humidity_1000hPa,
                             const std::vector<double>& humidity_975hPa,
                             const std::vector<double>& cloud_1000hPa,
                             const std::vector<double>& cloud_975hPa,
                             const std::vector<double>& wind_speed_1000hPa,
                             const std::vector<double>& wind_speed_975hPa,
                             const std::vector<double>& wind_dir_1000hPa,
                             const std::vector<double>& wind_dir_975hPa,
                             const std::vector<double>& geopotential_1000hPa,
                             const std::vector<double>& geopotential_975hPa);
};





#endif //WDA_1_EXPORTDATA_H
