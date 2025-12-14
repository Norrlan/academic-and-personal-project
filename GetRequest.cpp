#include <iostream>
#include <fstream>
#include <stdexcept>
#include <curl/curl.h>
#include "json.h"
using json = nlohmann::json;
using namespace std;
size_t writeCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t newLength = size * nmemb;
    try {
        output->append(static_cast<char*>(contents), newLength);
    } catch (std::bad_alloc& e) {
        // Handle memory allocation failure
        return 0;
    }
    return newLength;
}
string performGetRequest(const string& url){
    CURL *curl;
    CURLcode res;
    string responseBuffer;
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to make the request to
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Set the callback function to receive the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
        // Perform the request
        res = curl_easy_perform(curl);
        // Check for errors
        if(res != CURLE_OK)
            std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        else {

            return responseBuffer;
        }
        // Cleanup
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Failed to initialize cURL" << std::endl;
    }
}




