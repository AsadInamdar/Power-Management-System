#include "data_processing.h"
#include "logger.h"

float process_data(float data[], int size) 
{
    float sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
        sum += data[i];
    }
    return sum / size; // Return average value
}

int transmit_data(float processed_data) 
{
    // Simulate successful transmission
    log_info("Transmitting data: %.2f", processed_data);
    return 1; // Return 1 if successful, 0 if failed
}
