cmake_minimum_required(VERSION 3.27)
project(WDA_1)

set(CMAKE_CXX_STANDARD 17)



find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
link_directories(${CURL_LINK_DIRS})
## Path to the directory where libcurl is installed
#set(CURL_LIBRARY_DIR "curl")
#
## Include libcurl headers
#include_directories(${CURL_LIBRARY_DIR}/include)
#
#
## Link against libcurl
#target_link_libraries(WDA_1 ${CURL_LIBRARY_DIR}/libcurl.a)
#
#
## Set the path to vcpkg toolchain file
add_executable(WDA_1 main.cpp
        LocationManagerMenu.cpp
        LocationManagerMenu.h
        WeatherVariable.cpp
        WeatherVariable.h
        GetRequest.cpp
        GetRequest.h
        HourlyForecast.cpp
        HourlyForecast.h
        json.h
        ApiCall.cpp
        ApiCall.h
        SolarRadiation.cpp
        SolarRadiation.h
        DailyWeatherVar.cpp
        DailyWeatherVar.h
        "AirQuality.cpp"
        "AirQuality.h"
        HourlyAir.cpp
        HourlyAir.h
        EuropeanAir.cpp
        EuropeanAir.h
        PressureLvl.cpp
        PressureLvl.h
        ExportData.cpp
        ExportData.h
        WeatherModel.cpp
        WeatherModel.h
)
target_link_libraries(WDA_1 PRIVATE CURL::libcurl)
#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")