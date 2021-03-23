#ifndef sensor-validate_h
#define sensor-validate_h

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta);

int validateParameterreadings(double* values, int numOfValues,double maxDelta);

int validateSOCreadings(double* values, int numOfValues);

int validateCurrentreadings(double* values, int numOfValues);

#endif
