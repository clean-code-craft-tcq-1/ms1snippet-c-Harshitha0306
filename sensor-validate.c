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
  int i=0;
  while(i < lastButOneIndex) {
    if(!IsDifference_GreaterthanThreshold(values[i], values[i + 1],maxDelta)) {
      return 0;
    }
      i++;
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



