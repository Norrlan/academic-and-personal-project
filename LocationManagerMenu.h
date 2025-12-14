
//

#ifndef WDA_1_LOCATIONMANAGERMENU_H
#define WDA_1_LOCATIONMANAGERMENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Locations
{
private:
    string City;
    string Country;
    int id;
    double latitude;
    double longitude;


public:
    //Constructor
    Locations(const std::string& City,
              const std::string& Country,
              double latitude,
              double longitude)
            : City(City), Country(Country), id(-1), latitude(latitude), longitude(longitude) {}


    string getCountry() const{ return Country;}
    string getCity() const{ return City;}
    void setId(int newId) { id=newId;}
    int  getId() const{ return id;}
    double getLat() const {return latitude;}
    double getLong() const {return longitude;}

 
};

class LocationManager {
private:
    vector<Locations> locations;
    //int nextId = -1; // to auto increment the ID

public:
    LocationManager();
    //methods for saving and loading existing locations from file.
    void SaveLocation(const std::string& filename );

   void showMenu(); // method to display the menu for location Manager
   void NewLocation();
   void ModifyLocation();// I made it static because of an error message
   void RemoveLocation();
   void SearchForLocation();
   void FavouriteLocation();
    int generateNewId (const std::string& filename);
   //static void ExportData();
};



#endif //WDA_1_LOCATIONMANAGERMENU_H
