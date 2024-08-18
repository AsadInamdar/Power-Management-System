#ifndef LOGGER_H
#define LOGGER_H

void init_logger();
void log_info(const char *format, ...);
void log_error(const char *format, ...);
void log_custom(const char *message);  // Declaration for the custom log function
void close_logger();

#endif // LOGGER_H
