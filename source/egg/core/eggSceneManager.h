#pragma once

namespace EGG {

class SceneCreator;

class SceneManager {
    SIZE_ASSERT(0x30);

public:
    [[mkw(0x8023ADDC)]] explicit SceneManager(SceneCreator* pSceneCreator = nullptr);
    ~SceneManager();

    /* VT+0x08 */ [[mkw(0x8023AE60)]] virtual void calc();
    /* VT+0x0C */ [[mkw(0x8023AEAC)]] virtual void draw();

    /* VT+0x10 */ [[mkw(0x8023B588)]] virtual void calcCurrentScene();
    /* VT+0x14 */ [[mkw(0x8023B5A8)]] virtual void calcCurrentFader();

    /* VT+0x18 */ [[mkw(0x8023B800)]] virtual void drawCurrentScene();
    /* VT+0x1C */ [[mkw(0x8023B890)]] virtual void drawCurrentFader();

    /* VT+0x20 */ [[mkw(0x8023B8B0)]] virtual void createDefaultFader();

    [[mkw(0x8023AF84)]] void changeScene(s32 id);

private:
    u8 FILL(0x04, 0x30);
};

} // namespace EGG
