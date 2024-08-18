#include "power_management.h"
#include <unistd.h>
#include "logger.h"

void enter_sleep_mode(int seconds) 
{
    log_info("Entering sleep mode for %d seconds...", seconds);
    sleep(seconds); // Simulate low-power sleep (in seconds)
}
