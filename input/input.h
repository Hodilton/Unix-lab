#ifndef INPUT_H
#define INPUT_H

int getInt(const char* prompt, int min, int max, int useMinBound, int useMaxBound);

float getFloat(const char* prompt, float min, float max, int useMinBound, int useMaxBound);

double getDouble(const char* prompt, double min, double max, int useMinBound, int useMaxBound);

void getString(const char* prompt, char* buffer, int maxLength);


void getIntArray(const char* prompt, int* array, int size);

void getFloatArray(const char* prompt, float* array, int size);

#endif // INPUT_H
