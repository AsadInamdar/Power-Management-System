#include "sensor.h"
#include <stdlib.h>

float read_sensor_data() 
{
    return ((float)rand() / (float)(RAND_MAX)) * 100.0; // Random value between 0 and 100
}
