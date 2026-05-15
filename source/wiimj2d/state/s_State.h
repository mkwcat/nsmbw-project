#pragma once

#include "s_FStateID.h"

#define __sState_Functions(_virtual, _name)                                                        \
    PRAGMA(clang diagnostic push)                                                                  \
    PRAGMA(clang diagnostic ignored "-Winconsistent-missing-override")                             \
    _virtual void executeState_##_name();                                                          \
    _virtual void initializeState_##_name();                                                       \
    _virtual void finalizeState_##_name();                                                         \
    PRAGMA(clang diagnostic pop)

#define sState(_class, _name)                                                                      \
    __sState_Functions(, _name) static constinit inline const char StateName_##_name[] =           \
        #_class "::StateID_" #_name;                                                               \
    static constinit inline const sFStateID_c<_class> StateID_##_name {                            \
        StateName_##_name, &_class::initializeState_##_name, &_class::executeState_##_name,        \
            &_class::finalizeState_##_name                                                         \
    }

#define sState_Virtual(_class, _name)                                                              \
    __sState_Functions(virtual, _name) static constinit inline const char StateName_##_name[] =    \
        #_class "::StateID_" #_name;                                                               \
    static constinit inline const sFStateID_c<_class> StateID_##_name {                            \
        StateName_##_name, &_class::initializeState_##_name, &_class::executeState_##_name,        \
            &_class::finalizeState_##_name                                                         \
    }

#define sState_Extern(_address, _class, _name)                                                     \
    __sState_Functions(, _name) static const sFStateID_c<_class> StateID_##_name asm(              \
        "ext_" #_address                                                                           \
    )

#define sState_ExternVirtual(_address, _class, _name)                                              \
    __sState_Functions(virtual, _name) static const sFStateID_c<_class> StateID_##_name asm(       \
        "ext_" #_address                                                                           \
    )
