#ifndef LARGEINT_H
#define LARGEINT_H

#include <vector>
#include <iostream>
#include <string>

namespace large_int {

class Large_Int {
public:

    //Constructors
    Large_Int();                                     //Default
    Large_Int(const long long value);                //From long long
    Large_Int(const std::string& value);             //From string
    Large_Int(const Large_Int& other);               //Copy constructor
    Large_Int(const Large_Int&& other) noexcept;     //Move constructor

    //Destructor
    ~Large_Int();

    //Assignment operators
    Large_Int& operator=(const Large_Int& other);
    Large_Int& operator=(Large_Int&& other) noexcept;

    //Arithmetic operators
    Large_Int operator+(const Large_Int& other) const;
    Large_Int operator-(const Large_Int& other) const;
    Large_Int operator*(const Large_Int& other) const;
    Large_Int operator/(const Large_Int& other) const;
    Large_Int operator%(const Large_Int& other) const;

    //Arithmetic assigment
    Large_Int& operator+=(const Large_Int& other);
    Large_Int& operator-=(const Large_Int& other);
    Large_Int& operator*=(const Large_Int& other);
    Large_Int& operator/=(const Large_Int& other);
    Large_Int& operator%=(const Large_Int& other);

    // Increment and decrement operators
    Large_Int& operator++();            // Prefix increment
    Large_Int operator++(int);          // Postfix increment
    Large_Int& operator--();            // Prefix decrement
    Large_Int operator--(int);          // Postfix decrement

    //Comparison operators
    bool operator==(const Large_Int& other) const;
    bool operator!=(const Large_Int& other) const;
    bool operator<(const Large_Int& other) const;
    bool operator>(const Large_Int& other) const;
    bool operator<=(const Large_Int& other) const;
    bool operator>=(const Large_Int& other) const;

    //Unary operators
    Large_Int operator+() const;
    Large_Int operator-() const;

    //I/O stream operators
    friend std::ostream& operator<<(std::ostream& out, const Large_Int& value);
    friend std::istream& operator>>(std::istream& in, Large_Int& value);

    //Helper operations
    size_t bitLength() const; // Returns the number of bits
    Large_Int abs() const;       // Returns the absolute value
    void swap(Large_Int& other); // Efficiently swaps two Large_Ints

    //Functions for testing (not accessible outside testing mode)
    #ifdef TESTING
    const std::vector<uint64_t>& get_digits() const { return digits; }
    const bool& get_negative() const { return is_negative; }
    #endif

private:

    std::vector<uint64_t> digits;
    bool is_negative;
};

} //End of namespace

#endif