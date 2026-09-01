#define DEBOUNCE_TIME_MS 500U

static uint16_t pressure_raw = 0U;
static uint32_t off_time_ms = 0U;
static bool previous_flag = false;

uint16_t calculate_pressure_raw(bool pressure_flag, uint32_t cycle_time_ms)
{
    if (pressure_flag == true)
    {
        pressure_raw = 5000U;
        off_time_ms = 0U;
    }
    else
    {
        if (previous_flag == true)
        {
            off_time_ms = 0U;
        }

        off_time_ms += cycle_time_ms;

        if (off_time_ms > DEBOUNCE_TIME_MS)
        {
            pressure_raw = 1000U;
        }

    }

    previous_flag = pressure_flag;

    return pressure_raw;
}
