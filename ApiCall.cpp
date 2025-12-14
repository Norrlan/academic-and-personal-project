#include <iostream>
#include <fstream>
#include <stdexcept>
#include <curl/curl.h>
#include "json.h"
#include "ApiCall.h"
using json = nlohmann::json;
using namespace std;
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t newLength = size * nmemb;
    try {
        output->append(static_cast<char*>(contents), newLength);
    } catch (std::bad_alloc& e) {
        // Handle memory allocation failure
        return 0;
    }
    return newLength;
}
//make GET request to the specified url and retrieve response data.
string GetRequest(const string& url){
    CURL *curl;
    CURLcode res;
    string responseBuffer;
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to make the request to
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Set the callback function to receive the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
        // Perform the request
        res = curl_easy_perform(curl);
        // Check for errors
        if(res != CURLE_OK)
            std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        else {

//
//            try {
//                json jsonResponse = json::parse(responseBuffer);
//                ofstream  outfile("C:/Users/takunda/CLionProjects/untitled1/jsonResponse.txt",std::ios::out|std::ios::trunc);
//                if (outfile.is_open()) {
//                    outfile << jsonResponse;
//                    outfile.close();
//                } else {
//                    throw runtime_error("Unable to open file for writing.");
//                }
//            } catch (const exception& e) {
//                cerr << "Error: " << e.what() << std::endl;
//            }
            //return the responseBuffer
            return responseBuffer;
        }
        // Cleanup
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Failed to initialize cURL" << std::endl;
        }
}
