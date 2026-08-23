#pragma once

namespace EGG {

class Scene {
    SIZE_ASSERT(0x30);

public:
    Scene();
    virtual ~Scene();
    virtual void calc();
    virtual void draw();
    virtual void enter();
    virtual void exit();
    virtual void reinit();
    virtual void incoming_childDestroy();
    virtual void outgoing_childCreate();

private:
    u8 _04[0x30 - 0x04];
};

} // namespace EGG
