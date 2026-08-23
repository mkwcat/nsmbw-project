#pragma once

/**
 * A set node with a pointer to the owning container.
 * @unofficial
 */
class cUnaryTreeNd_c {
    SIZE_ASSERT(0x8);

public:
    void* getOwner() const { return mpOwner; }

    cUnaryTreeNd_c* getNext() const { return mpNext; }

private:
    /* 0x0 */ void*           mpOwner;
    /* 0x4 */ cUnaryTreeNd_c* mpNext;

    friend class cOwnerSetMg_c;
};

/**
 * A set container implemented as a singly-linked list.
 * @unofficial
 */
class cUnaryTreeMg_c {
    SIZE_ASSERT(0x4);

public:
    cUnaryTreeMg_c()
        : mpRoot(nullptr) {}

    ~cUnaryTreeMg_c() { clear(); }

    /**
     * 0x80161890
     * Adds a node to the set.
     *
     * @param nd The node to add.
     * @param owner The owner of the node.
     */
    void add(cUnaryTreeNd_c* nd, void* owner);

    /**
     * 0x80161940
     * Removes a node from the set.
     *
     * @param nd The node to remove.
     * @param owner The owner of the node.
     */
    void remove(cUnaryTreeNd_c* nd, void* owner);

private:
    /**
     * 0x80161A00
     * Clears out the set and unlinks all child nodes.
     */
    void clear();

    /**
     * The first element of the set.
     */
    /* 0x0 */ cUnaryTreeNd_c* mpRoot;
};
