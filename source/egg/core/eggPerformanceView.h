#pragma once

namespace EGG {

class PerformanceView {
public:
    /* VT+0x08 */ virtual void measureBeginFrame() ABSTRACT;
    /* VT+0x0C */ virtual void measureEndFrame() ABSTRACT;
    /* VT+0x10 */ virtual void measureBeginRender() ABSTRACT;
    /* VT+0x14 */ virtual void measureEndRender() ABSTRACT;
    /* VT+0x18 */ virtual void callbackDrawSync(u16) ABSTRACT;
    /* VT+0x1C */ virtual void vfunc1C() ABSTRACT;
    /* VT+0x20 */ virtual void draw() ABSTRACT;
    /* VT+0x24 */ virtual void setVisible(bool visible) ABSTRACT;
    /* VT+0x28 */ virtual bool isVisible() ABSTRACT;
};

} // namespace EGG
