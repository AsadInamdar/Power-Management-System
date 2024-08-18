#include <stdio.h>
#include <time.h>
#include "sensor.h"
#include "power_management.h"
#include "data_processing.h"
#include "logger.h"
#include "config.h"

int main() 
{
    printf("Program started...\n");
    fflush(stdout); // Ensure the output is flushed

    init_logger();
    
    for (int cycle = 0; cycle < NUM_CYCLES; cycle++) 
    {

        // Add timestamp to console output
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char time_buffer[26];
        strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("[%s] Starting cycle %d\n", time_buffer, cycle + 1);
        fflush(stdout);  // Ensure the output is flushed

        log_info("Starting cycle %d", cycle + 1);

        // Wake up and collect sensor data
        float sensor_data[NUM_READINGS];
        for (int i = 0; i < NUM_READINGS; i++) 
        {
            sensor_data[i] = read_sensor_data();
            log_info("Sensor reading %d: %.2f", i + 1, sensor_data[i]);
        }

        // Process the sensor data
        float processed_data = process_data(sensor_data, NUM_READINGS);
        log_info("Processed data (average): %.2f", processed_data);

        // Transmit the processed data
        if (transmit_data(processed_data)) 
        {
            log_info("Data transmitted successfully.");
        } 
        else 
        {
            log_error("Data transmission failed.");
        }

        // Enter low-power sleep mode for -- hours (simulated)
        log_info("Entering sleep mode for %d seconds...", SLEEP_DURATION);

        enter_sleep_mode(SLEEP_DURATION);

        // Add a separator for console output
        printf("\n--- End of Cycle %d ---\n\n", cycle + 1);
        fflush(stdout);  // Ensure the output is flushed
    }

    log_info("Simulation complete. Device will now shut down.");
    close_logger();

    printf("Program finished.\n");
    fflush(stdout); // Ensure the output is flushed
    return 0;
}
