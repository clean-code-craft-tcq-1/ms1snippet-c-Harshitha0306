#ifndef sensor-validate_h
#define sensor-validate_h

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta);

float validateParameterreadings(double* values, int numOfValues,double maxDelta);

float validateSOCreadings(double* values, int numOfValues);

float validateCurrentreadings(double* values, int numOfValues);

#endif
