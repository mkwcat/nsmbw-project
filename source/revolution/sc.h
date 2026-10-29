#pragma once

typedef enum {
    SC_STATUS_OK = 0,
    SC_STATUS_BUSY = 1,
    SC_STATUS_FATAL = 2,
    SC_STATUS_PARSE = 3,
} SCStatus;

enum class SCAspectRatio {
    STANDARD = 0,
    WIDESCREEN = 1,
};

typedef void (*SCFlushCallback)(SCStatus status);
