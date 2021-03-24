/*
 *
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               24/03/2021
 * Filename:           sensor-validate.h
 *
 ****************************************************************************************************
 *
 ***************************************************************************************
 * Function declarations
 ***************************************************************************************
 */

float CheckForNaN(double* values, int numOfValues);

int IsDifference_GreaterthanThreshold(double value, double nextValue, double maxDelta);

float IsSuddenJumpObserved(double* values, int numOfValues,double maxDelta);

float validateSOCreadings(double* values, int numOfValues);

float validateCurrentreadings(double* values, int numOfValues);

