#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

static FILE *log_file;

void init_logger() 
{
    log_file = fopen("system.log", "a");
    if (log_file == NULL) 
    {
        printf("Error opening log file!\n");
        exit(1);
    }
}

void log_info(const char *format, ...) 
{
    // Get current time
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char time_buffer[26];
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Start variadic argument processing
    va_list args;
    va_start(args, format);

    fprintf(log_file, "%s INFO: ", time_buffer);
    vfprintf(log_file, format, args);

    // Print a newline at the end
    fprintf(log_file, "\n");
    va_end(args);
    
    // Flush to ensure all output is written to the file
    fflush(log_file);
}

void log_error(const char *format, ...) {
    // Get current time
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char time_buffer[26];
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Start variadic argument processing
    va_list args;
    va_start(args, format);

    fprintf(log_file, "%s ERROR: ", time_buffer);
    vfprintf(log_file, format, args);

    // Print a newline at the end
    fprintf(log_file, "\n");
    va_end(args);
    
    // Flush to ensure all output is written to the file
    fflush(log_file);
}

void log_custom(const char *message) {
    // Write a custom message to the log file
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fflush(log_file); // Ensure the message is written to the file immediately
    }
}

void close_logger() {
    if (log_file) {
        fclose(log_file);
    }
}
