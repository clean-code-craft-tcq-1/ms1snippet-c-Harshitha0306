/*
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               24/03/2021
 * Filename:           sensor-validate.c
 *****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#include "sensor-validate.h"
#include <stdlib.h>
#include <math.h>


/*This Function checks whether the readings from Sensor are empty or the total number of readings from sensor is 0
 * \param       values              input readings from the sensor
 * \param       numOfValues         total number of input readings from the sensor
 *returns NaN if the input readings are empty else returns 0    */

float CheckForNaN(double* values, int numOfValues){
    if(values == NULL  || numOfValues == 0)
      {
          return NAN;
      }
    return 0;
}

/*This Function checks whether the difference between current reading and next reading is greater than threshold
 * \param       values              input readings from the sensor
 * \param       numOfValues         total number of input readings from the sensor
 * \param       maxDelta            threshold value to detect sudden jump in sesnor reading
 *returns 0 when the difference between current reading and next reading is greater than threshold else returns 1   */

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

/*This Function checks whether there is sudden jump in current reading and next reading
 * \param       values              input readings from the sensor
 * \param       numOfValues         total number of input readings from the sensor
 * \param       maxDelta            threshold value to detect sudden jump in sesnor reading
 *returns 1 when there is sudden jump in sensor reading else returns 0    */

float IsSuddenJumpObserved(double* values, int numOfValues,double maxDelta) {
   int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!IsDifference_GreaterthanThreshold(values[i], values[i + 1],maxDelta)) {
      return 0;
    }
  }
  return 1;
}

/*This Function validates whether the SOC readings from the sensor is noisy or noise free by checking the difference between current reading and next reading
 * \param       values              input readings from the sensor
 * \param       numOfValues         total number of input readings from the sensor
 *returns 1 when there is sudden jump in SOC sensor reading else returns 0    */

float validateSOCreadings(double* values, int numOfValues) {
  float NaNCheck = CheckForNaN(values,numOfValues);
    if(NaNCheck==0) {
   return(IsSuddenJumpObserved(values,numOfValues,0.05));
    }
    return NaNCheck;
}

/*This Function validates whether the Current readings from the sensor is noisy or noise free by checking the difference between current reading and next reading
 * \param       values              input readings from the sensor
 * \param       numOfValues         total number of input readings from the sensor
 *returns 1 when there is sudden jump in Current sensor reading else returns 0    */

float validateCurrentreadings(double* values, int numOfValues) {
    float NaNCheck = CheckForNaN(values,numOfValues);
      if(NaNCheck==0) {
    return(IsSuddenJumpObserved(values,numOfValues,0.1));
    }
    return NaNCheck;
}



