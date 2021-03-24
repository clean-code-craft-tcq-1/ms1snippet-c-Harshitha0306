/*
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               24/03/2021
 * Filename:           test-validation.cpp
 *****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"
#include "math.h"


/*
***************************************************************************************
* Testcase to validate noise in SOC sensor readings
***************************************************************************************
*/

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 0);
}

/*
***************************************************************************************
* Testcase to validate noise in Current sensor readings
***************************************************************************************
*/

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 0);
}

/*
***************************************************************************************
* Testcase to validate  whether the SOC sensor readings are empty
***************************************************************************************
*/

TEST_CASE("reports NAN when readings are empty for SOC Readings") {
    double socReadings[] = {};
    int numOfSocReadings = sizeof(socReadings) / sizeof(double);
    float a = validateSOCreadings(socReadings, numOfSocReadings);
    REQUIRE(isnan(a));
}

/*
***************************************************************************************
* Testcase to validate  whether the Current sensor readings are empty
***************************************************************************************
*/

TEST_CASE("reports NAN when readings are empty for Current Readings") {
    double currentReadings[] = {};
    int numOfCurReadings = sizeof(currentReadings) / sizeof(double);
    float a = validateCurrentreadings(currentReadings, numOfCurReadings);
    REQUIRE(isnan(a));
}
