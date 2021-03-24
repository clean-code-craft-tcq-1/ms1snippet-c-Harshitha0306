#include "sensor-validate.h"
#include <stdlib.h>
#include <math.h>

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

float validateParameterreadings(double* values, int numOfValues,double maxDelta) {
    int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!IsDifference_GreaterthanThreshold(values[i], values[i + 1],maxDelta)) {
      return 0;
    }
  }
  return 1;
}

float validateSOCreadings(double* values, int numOfValues) {
  if(numOfValues == 0 || values == NULL)
    {
        return NAN;
    }
   return(validateParameterreadings(values,numOfValues,0.05));
    
    }


float validateCurrentreadings(double* values, int numOfValues) {
  if(numOfValues == 0 || values == NULL)
    {
        return NAN;
    }
    return(validateParameterreadings(values,numOfValues,0.1));
}



