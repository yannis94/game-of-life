#include <stdio.h>

typedef enum LogLevel {
    INFO,
    WARN,
    ERROR,
    DEBUG,
} log_level_t;

void print_log(log_level_t level, char* msg) {
    char* level_str;

    switch (level) {
        case INFO:
            level_str = "INFO";
            break;
        case WARN:
            level_str = "WARN";
            break;
        case ERROR:
            level_str = "ERROR";
            break;
        case DEBUG:
            level_str = "DEBUG";
            break;
        default:
            level_str = "CLASSIFIED";
            break;
    }

    fprintf(stderr, "[%s] %s\n", level_str, msg);
}

void log_info(char* message) {
    print_log(INFO, message);
}

void log_warn(char* message) {
    print_log(WARN, message);
}

void log_error(char* message) {
    print_log(ERROR, message);
}

void log_debug(char* message) {
    print_log(DEBUG, message);
}
