#include "sensor-validate.h"
#include <stdlib.h>
#include <math.h>

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateParameterreadings(double* values, int numOfValues,double maxDelta) {
    if(values == NULL || numOfValues == 0)
    {
        return NAN;
    }
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!IsDifference_GreaterthanThreshold(values[i], values[i + 1],maxDelta)) {
      return 0;
    }
  }
  return 1;
}

int validateSOCreadings(double* values, int numOfValues) {
    return(validateParameterreadings(values,numOfValues,0.05));
    }

int validateCurrentreadings(double* values, int numOfValues) {
    return(validateParameterreadings(values,numOfValues,0.1));
}



