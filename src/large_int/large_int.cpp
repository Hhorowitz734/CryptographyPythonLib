#include "../../include/large_int/large_int.h"

#include <string>

namespace large_int {

//Constructors
Large_Int::Large_Int(const std::string& value) : is_negative(false) {
    
    //Check if the first character is a minus sign
    size_t start = 0;
    if (value[0] == '-') { is_negative = true; start++; }

    //Ensure the string contains only digits
    if (!std::all_of(value.begin() + start, value.end(), ::isdigit)) {
        throw std::invalid_argument("Invalid character in integer string.");
    }

    //Continues past leading zeroes
    while (value[start] == '0') { start++; }
    
    //Case that the number if 0 is handled below
    if (start == std::string::npos) { 
        digits.push_back(0);
        is_negative = false;
        return;
    }

    //Converts the string to digits base 2^62
    size_t end = value.size();
    const uint64_t MAX_CHUNK_VALUE = 461168601842738800ULL; // 2^62
    size_t chunk_size;
    uint64_t chunk_value;
    int digit;
    while (start < end) {

        chunk_size = 0;
        chunk_value = 0;

        while (start + chunk_size < end && chunk_value < MAX_CHUNK_VALUE){
            digit = value[start + chunk_size] - '0';
            if (chunk_value > (MAX_CHUNK_VALUE - digit) / 10) { break; } // To prevent overflow
            chunk_value = chunk_value * 10 + digit;
            chunk_size++;
        }

        digits.push_back(chunk_value);
        start += chunk_size;


    }

    //Reverse chunks to be in correct order
    std::reverse(digits.begin(), digits.end());

}

//Destructor
Large_Int::~Large_Int() = default;

}; //End of namespace