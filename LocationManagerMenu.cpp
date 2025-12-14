//
// Created by obabi on 13/04/2024.
//LocationManagerMenu

#include "LocationManagerMenu.h"
#include <iostream>
#include<fstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

LocationManager::LocationManager() {

}

void LocationManager::SaveLocation(const std::string &locationsfile)// Saves location by file writing to the txt file
{
    ofstream file(locationsfile);

    if (!file.is_open())
    {
        cerr << "Unable to open file: " << locationsfile << endl;
        return;

    }
    for (const auto& loc : locations)
    {
        file  << loc.getCity()<< ","
              << loc.getCountry() << ","
              << loc.getId() << ","
              << loc.getLat() << ","
              << loc.getLong() << endl;
    }
    file.close(); // Close the file
    cout << "Location data saved to file: " << locationsfile << endl;

}

// Location Menu that user sees.
void LocationManager::showMenu()
{
    int option;
    do {
        cout << "1. Add New Location By(Id,Name,Longitude,Latitude)" << endl;
        cout << "2. Modify Location Data" << endl;
        cout << "3. Remove Location By Name or ID" << endl;
        cout << "4. Search Location(s) By(Name or ID)" << endl;
        cout << "5. Set favourite Location (By Name or Id)" << endl;
        cout << "6. Previous window" << endl;
        cout << "7. Exit to Main Menu" << endl;
        cout << "\nEnter your choice: ";

        cin >> option;
        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number.\n" << endl;
            continue; // restart loop
        }

        switch (option) {
            case 1:
                NewLocation();
                break;
            case 2:
                ModifyLocation();
                break;
            case 3:
                RemoveLocation();
                break;
            case 4:
                SearchForLocation();
                break;
            case 5:
                FavouriteLocation();
                break;
            case 6:
                return; // Return to the previous menu
            case 7:
                return; // Exit to the main menu
            default:
                cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
                break;
        }
    } while (true); // Continue looping until an explicit return is encountered
}

// To generate new unique ID for each new location added
int LocationManager::generateNewId(const std::string &filename)
{
    ifstream inFile(filename);
    string line;
    int maxId =0;

    while (getline(inFile, line))
    {
        stringstream  ss(line);
        vector<string> tokens;
        string token;

        while (getline(ss, token,',')) tokens.push_back(token);

        if (tokens.size() >= 3)
        {
            try
            {
                int id = stoi(tokens[2]);
                if (id > maxId) maxId = id;
            }
            catch (...)
            {
                // ignore invalid IDs
            }
        }
    }

    inFile.close();
    return maxId + 1;
}

void LocationManager::NewLocation()
{
    string countryName, cityName ;
    double latitude, longitude;

    // Prompt user for country name and validate input
    cout << "Enter Location Country Name: ";
    cin >> countryName;
    if (cin.fail())
    {
        cerr << "Invalid input. Name must be a string." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    // Prompt user for name and validate input
    cout << "Enter Location City Name: ";
    cin >> cityName;
    if (cin.fail())
    {
        cerr << "Invalid input. Name must be a string.\n" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    // Prompt user for latitude and validate input
    cout << "Enter Location Latitude: ";
    cin >> latitude;
    if (cin.fail()) {
        cerr << "Invalid input. Latitude must be a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Prompt user for longitude and validate input
    cout << "Enter the Longitude: ";
    cin >> longitude;
    if (cin.fail()) {
        cerr << "Invalid input. Longitude must be a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Validate latitude and longitude
    if (latitude == 0.0 || longitude == 0.0)
    {
        cout << "Invalid latitude and longitude values\n";
        return;
    }

    //Generate unique ID from file
    int newId = generateNewId("locationsfile.txt");

    //Create and store location in memory
    Locations newLoc(cityName, countryName, latitude, longitude);
    newLoc.setId(newId);
    locations.push_back(newLoc);

    //Append new locations to file
    ofstream outFile("locationsfile.txt", ios::app);
    if (!outFile)
    {
        cerr << "Error opening file for writing.\n";
        return;
    }

    outFile <<cityName <<"," << countryName << "," << newId << "," << fixed << setprecision(6)
    <<latitude << "," << fixed << setprecision(6) << longitude << endl;
    outFile.close();


    cout << "\nNew location added:\n" << endl;
    cout << "City: " << cityName << endl;
    cout << "Country: " << countryName << endl;
    cout << "ID: " << newLoc.getId() << endl;
    cout << "Latitude: " << fixed << setprecision(6) << latitude << endl;
    cout << "Longitude: " << fixed << setprecision(6) << longitude << endl;






}

// swaps stored location data with current location data
//id stays fixed

void LocationManager::ModifyLocation()
{
    int choice;
    string searchKey;

    // --- Menu loop ---
    do {
        cout << "Modify Location Menu\n";
        cout << "1. Modify by ID\n";
        cout << "2. Modify by Name\n";
        cout << "3. Return to Previous Menu\n";
        cout << "\nEnter your choice: ";

        cin >> choice;

        // Input validation
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n" << endl;
            continue;
        }

        if (choice == 3) return; // exit back to LocationManager menu

        switch (choice) {
            case 1:
                cout << "Enter ID to modify: ";
                cin >> searchKey;
                break;
            case 2:
                cout << "Enter Name to modify: ";
                cin >> searchKey;
                break;
            case 3:
                cout << "Enter ID to modify";
                cin >> searchKey;
                break;
            default:
                cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
                continue;
        }

        // File processing
        ifstream inFile("locationsfile.txt");
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            stringstream  ss(line);
            vector<string> tokens;
            string  token;

            while(getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() ==5)
            {
                string city = tokens[0];
                string country = tokens[1];
                string id = tokens[2];
                string  lat = tokens[3];
                string lon = tokens[4];

                if (searchKey == city || searchKey == country || searchKey==id )
                {
                    string newCity, newCountry;
                    double  newLat, newLong;
                    cout << "Enter new City:";
                    cin>> newCity;
                    cout << "Enter new Country: ";
                    cin >> newCountry;
                    cout << "Enter new Latitude: ";
                    cin >> newLat;
                    cout << "Enter new Longitude: ";
                    cin >> newLong;
                    tempFile  << newCity << "," << newCountry << "," << id << ","
                              << fixed << setprecision(6) << newLat << ","
                              << fixed << setprecision(6) << newLong << endl;
                    found = true;
                    continue;
                }
            }
            tempFile << line << endl;
        }
        inFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Location not found.\n";
            remove("temp.txt");
        }
        else
        {
            remove("locationsfile.txt");
            rename("temp.txt", "locationsfile.txt");
            cout << "Location updated.\n";
        }

    } while (true);
}


void LocationManager::RemoveLocation()
{
    int option;
    string searchKey;

    // Menu
    do {
        cout << "Remove Location Menu\n";
        cout << "1. Remove by Name\n";
        cout << "2. Remove by ID\n";
        cout << "3. Return to Previous Menu\n";
        cout << "\nEnter your choice: ";

        cin >> option;

        // Input validation
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n" << endl;
            continue;
        }

        if (option == 3) return; // exit back to LocationManager menu.
        switch (option)
        {
            case 1:
                cout << "Enter location City to modify: ";
                cin >> searchKey;
                break;
            case 2:
                cout << "Enter location ID to modify: ";
                cin >> searchKey;
                break;
            default:
                cout << "Wrong choice selected. Pick 1, 2, or 3.\n" << endl;
                continue;
        }

        // --- File processing ---
        ifstream inFile("locationsfile.txt");
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
        while (getline(inFile, line))
        {
            stringstream ss(line);
            vector<string> tokens;
            string token;

            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() == 5)
            {
                string city = tokens[0];
                string country = tokens[1];
                string id = tokens[2];

                if (searchKey == city || searchKey == country || searchKey == id)
                {
                    found = true;
                    continue;
                }

            }
            //keep non-matching lines
            tempFile << line << endl;
        }

        inFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Location not found.\n";
            remove("temp.txt");
        }
        else
        {
            remove("locationsfile.txt");
            if (rename("temp.txt", "locationsfile.txt")!= 0)
            {
                cerr << "Error replacing locationsfile.txt\n";
            }
            else{
                cout << "Location updated";
            }

        }

    } while (true);
}


void LocationManager::SearchForLocation()
{
    string searchKey;
    cout << "Enter location Name/ ID: ";
    cin >> searchKey;

    // Open the input file for reading
    ifstream inFile("locationsfile.txt");
    if (!inFile)
    {
        cerr << "Error: Unable to open locations file." << endl;
        return;
    }
    string line;bool found = false;

    // Read each line from the input file and check if it contains the search key
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector <string> tokens;
        string token;
        while(getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // Check if the line contains the search key
        if (tokens.size() == 5 )
        {
           string city = tokens[0];
           string country = tokens[1];
           string id = tokens[2];
           string lat = tokens[3];
           string lon = tokens[4];

            if (searchKey ==id || searchKey ==city || searchKey == country)
            {
                 // Display the location data
                cout << "Location Found:\n";
                cout << "City: " << tokens[0] << endl;
                cout << "Country: " << tokens[1] << endl;
                cout << "ID: " << tokens[2] << endl;
                cout << "Latitude: " << tokens[3] << endl;
                cout << "Longitude: " << tokens[4] << endl;
                found = true;break; // Stop searching after finding the first match
            }
        }

    }

    // Close the input file
    inFile.close();

    // Check if the location was found
    if (!found)
    {
        cout << "Location with specified key not found." << endl;
    }
}


void LocationManager::FavouriteLocation()
{// Variables to store location details string cityName,countryName,id;
    string searchKey;
    cout << "Add Location to Favourites by name or ID:\n";
    cin >> searchKey;

    ifstream inFile("locationsfile.txt");
    ofstream outfile("favourites.txt", ios::app);
    if (!inFile || !outfile)
    {
        cerr << "Error : Unable to open file. \n";
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> tokens;
        string token;

        while(getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() ==5)
        {
            string city = tokens[0];
            string country = tokens[1];
            string id = tokens[2];

            if (searchKey == city || searchKey == country || searchKey ==id)
            {
                outfile << line << endl;
                found = true;
                break;
            }

        }


    }

    inFile.close(); outfile.close();
    if (found) {cout << "Location added to favourites.\n";}
    else {cout << "Location not found.\n";}

}



