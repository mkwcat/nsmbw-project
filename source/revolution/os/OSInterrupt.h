#pragma once

EXTERN_C_START

bool OSDisableInterrupts();
bool OSEnableInterrupts();
bool OSRestoreInterrupts(bool status);

EXTERN_C_END
