#pragma once

#include "egg/core/eggPerformanceView.h"
#include "egg/core/eggThread.h"

namespace EGG {

class ProcessMeter : public Thread, public PerformanceView {
    SIZE_ASSERT(0x154);

public:
    [[mkw(0x8023883C)]] ProcessMeter(bool);

public:
    /* VT+0x24, VT+0x2C */ virtual void setVisible(bool visible) override;
    /* VT+0x28, VT+0x30 */ virtual bool isVisible() override;
    /* VT+0x18, VT+0x34 */ virtual void callbackDrawSync(u16) override;
    /* VT+0x08, VT+0x38 */ virtual void measureBeginFrame() override;
    /* VT+0x0C, VT+0x3C */ virtual void measureEndFrame() override;
    /* VT+0x10, VT+0x40 */ virtual void measureBeginRender() override;
    /* VT+0x14, VT+0x44 */ virtual void measureEndRender() override;
    /* VT+0x20, VT+0x48 */ virtual void draw() override;

private:
    u8 FILL(0x04C, 0x154);
};

} // namespace EGG
