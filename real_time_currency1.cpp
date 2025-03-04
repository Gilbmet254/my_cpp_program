#include <iostream>
#include <string>
#include <cstring> // Include this for memcpy
#include <curl/curl.h>

// Structure to store the API response
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to handle API response
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    MemoryStruct *mem = (MemoryStruct *)userp;

    mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == nullptr) {
        std::cerr << "Not enough memory (realloc returned NULL)" << std::endl;
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize); // memcpy requires <cstring>
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// Function to fetch exchange rate
double get_exchange_rate(const std::string &currency) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;
    chunk.memory = (char *)malloc(1);  // Initialize memory
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://v6.exchangerate-api.com/v6/43707713c641d57e8c750d93/latest/" + currency;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Parse JSON response to get KES rate
            std::string response(chunk.memory);
            size_t kes_pos = response.find("\"KES\":");
            if (kes_pos != std::string::npos) {
                double kes_rate = std::stod(response.substr(kes_pos + 6));
                curl_easy_cleanup(curl);
                free(chunk.memory);
                curl_global_cleanup();
                return kes_rate;
            }
        }

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();
    return -1; // Return -1 if there's an error
}

int main() {
    std::string currency;
    double amount;

    std::cout << "Enter the currency code (e.g., USD, EUR, GBP): ";
    std::cin >> currency;
    std::cout << "Enter the amount: ";
    std::cin >> amount;

    double rate = get_exchange_rate(currency);
    if (rate > 0) {
        double kshs = amount * rate;
        std::cout << amount << " " << currency << " = " << kshs << " Kshs" << std::endl;
    } else {
        std::cout << "Failed to fetch exchange rate. Please check your input or try again later." << std::endl;
    }

    return 0;
}
