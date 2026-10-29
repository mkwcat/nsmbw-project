#pragma once

namespace EGG {

class Scene;

class SceneCreator {
public:
    /* VT+0x8 */ virtual Scene* create(s32 id) ABSTRACT;
    /* VT+0xC */ virtual void destroy(s32 id) ABSTRACT;
};

} // namespace EGG
