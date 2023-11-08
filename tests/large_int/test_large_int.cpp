#define TESTING
#include "../../include/large_int/large_int.h"
#include <gtest/gtest.h>
#include <vector>

using namespace large_int;

//Test suite for Large_Int(const std::string& value);
TEST(LargeIntStringConstructor, BaseTest) {
    
    //Sets up instance of Large_Int
    Large_Int num("4611686018427388001");
    const std::vector<uint64_t>& digits = num.get_digits();
    
    //Sets up expected vector
    std::vector<uint64_t> expected_digits = {1, 461168601842738800};
    
    //Confirms the sign of the number
    EXPECT_FALSE(num.get_negative());
    
    //Confirms the two vectors are the same size
    EXPECT_EQ(digits.size(), expected_digits.size());

    //Checks each element in the vector are the same
    for (size_t i = 0; i < expected_digits.size(); i++){
        EXPECT_EQ(digits[i], expected_digits[i]) << "Vectors differ at index " << i;
    }

}

TEST(LargeIntStringConstructor, VeryLargeNumberTest) {

    //Sets up instance of Large_Int
    Large_Int num("123456789123456789123456789");
    const std::vector<uint64_t>& digits = num.get_digits();
    
    //Sets up expected vector
    std::vector<uint64_t> expected_digits = {123456789, 123456789123456789};
    
    //Confirms the two vectors are the same size
    EXPECT_EQ(digits.size(), expected_digits.size());

    //Confirms the sign of the number
    EXPECT_FALSE(num.get_negative());

    //Checks each element in the vector are the same
    for (size_t i = 0; i < expected_digits.size(); i++){
        EXPECT_EQ(digits[i], expected_digits[i]) << "Vectors differ at index " << i;
    }

}

TEST(LargeIntStringConstructor, NegativeTest) {

    //Sets up instance of Large_Int
    Large_Int num("-4611686018427388001");
    const std::vector<uint64_t>& digits = num.get_digits();
    
    //Sets up expected vector
    std::vector<uint64_t> expected_digits = {1, 461168601842738800};
    
    //Confirms the two vectors are the same size
    EXPECT_EQ(digits.size(), expected_digits.size());

    //Confirms the sign of the number
    EXPECT_TRUE(num.get_negative());

    //Checks each element in the vector are the same
    for (size_t i = 0; i < expected_digits.size(); i++){
        EXPECT_EQ(digits[i], expected_digits[i]) << "Vectors differ at index " << i;
    }

}