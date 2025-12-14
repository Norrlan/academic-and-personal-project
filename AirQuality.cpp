
//

#include "AirQuality.h"
#include "HourlyAir.h"
#include "EuropeanAir.h"

void AirQuality::Showmenu() {

    int option;
    do {
        cout << "1.Hourly Air Variables" << endl;
        cout << "2. European Air Quality Index" << endl;
        cout << "3.Mainmenu" << endl;
        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                HourlyAir();
                break;
            case 2:
                EuropeanAir();
                break;
            case 3:
                return; // Return to the main menu
            default:
                cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
                break;
        }
    } while (option != 4); // Continue looping until the user chooses to return to
}

void AirQuality:: HourlyAir()
{
    class HourlyAir aero;
}
void AirQuality::EuropeanAir()
{
    class EuropeanAir euro;
}



/*


*/

/*


void AirQuality::EuropeanAir();
{
cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
}

void AirQuality::DisplayAir() {
    cout << "Wrong choice selected. Pick an option from the menu\n" << endl;
}

 *using json=nlohmann::json;
AirQuality::AirQuality() {// For P
    const string Url="https://air-quality-api.open-meteo.com/v1/air-quality?latitude=52.52&longitude=13.41&hourly=pm10,pm2_5,carbon_monoxide,nitrogen_dioxide,sulphur_dioxide,ozone,aerosol_optical_depth,dust,uv_index,uv_index_clear_sky,ammonia,alder_pollen,birch_pollen,"
                     "grass_pollen,mugwort_pollen,olive_pollen,ragweed_pollen&timezone=America%2FLos_Angeles&past_days=1&forecast_days=1";
    string jsonRes=GetRequest(Url);
    json jsonResponse=json::parse(jsonRes);

    for(int i =0; i < 48; i++)
    {
        cout << "pm10:" << jsonResponse["hourly"]["pm10"][i]<<"\n";
        cout << "pm2_5:" << jsonResponse["hourly"]["pm2_5"][i] << "\n";
        cout << "carbon_monoxide:" <<  jsonResponse["hourly"]["carbon_monoxide"][0] << "\n";
        cout << "nitrogen_dioxide:" <<  jsonResponse["hourly"]["nitrogen_dioxide"][i] << "\n";
        cout << "sulphur_dioxide:" <<  jsonResponse["hourly"]["sulphur_dioxide"][i] << "\n";
        cout << "ozone:" << jsonResponse["hourly"]["ozone"][i] << "\n";
        cout << "aerosol_optical_depth:" <<  jsonResponse["hourly"]["aerosol_optical_depth"][i] << "\n";
        cout << "dust:" << jsonResponse["hourly"]["dust"][i] << "\n";
        cout << "uv_index:" <<  jsonResponse["hourly"]["uv_index"][i] << "\n";
        cout << "uv_index_clear_sky:" << jsonResponse["hourly"]["uv_index_clear_sky"][i] << "\n";
        cout << "ammonia:" << jsonResponse["hourly"]["ammonia"][i] << "\n";
        cout << "alder_pollen:" <<  jsonResponse["hourly"]["alder_pollen"][0] << "\n";
        cout << "birch_pollen:" <<  jsonResponse["hourly"]["birch_pollen"][i] << "\n";
        cout << "grass_pollen:" <<  jsonResponse["hourly"]["grass_pollen"][i] << "\n";
        cout << "mugwort_pollen:" << jsonResponse["hourly"]["mugwort_pollen"][i] << "\n";
        cout << "olive_pollen:" <<  jsonResponse["hourly"]["olive_pollen"][i] << "\n";
        cout << "ragweed_pollen:" << jsonResponse["hourly"]["ragweed_pollen"][i] << "\n";




    }


}*/








