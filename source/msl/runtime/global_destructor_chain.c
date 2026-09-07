// global_destructor_chain.c
// NSMBW .text: 0x802DCA70 - 0x802DCAD0

struct DestructorChain {
    void* next;
    void* destructor;
    void* object;
};

DestructorChain* __global_destructor_chain = nullptr;

/* 0x000DA178 - override for rel */
extern "C" void* __register_global_object(
    void* object, void* dtor, DestructorChain* entry
) {
    entry->next               = __global_destructor_chain;
    entry->destructor         = dtor;
    entry->object             = object;
    __global_destructor_chain = entry;

    return object;
};
