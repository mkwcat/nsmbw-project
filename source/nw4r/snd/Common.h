#pragma once

namespace nw4r::snd::detail {

enum class PanMode {
    PAN_MODE_DUAL    = 0,
    PAN_MODE_BALANCE = 1,
};

enum PanCurve {
    PAN_CURVE_SQRT             = 0,
    PAN_CURVE_SQRT_0DB         = 1,
    PAN_CURVE_SQRT_0DB_CLAMP   = 2,
    PAN_CURVE_SINCOS           = 3,
    PAN_CURVE_SINCOS_0DB       = 4,
    PAN_CURVE_SINCOS_0DB_CLAMP = 5,
    PAN_CURVE_LINEAR           = 6,
    PAN_CURVE_LINEAR_0DB       = 7,
    PAN_CURVE_LINEAR_0DB_CLAMP = 8,
};

} // namespace nw4r::snd::detail
