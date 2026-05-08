#pragma once

/**
 * A doubly-linked list node. See cListMg_c.
 * @unofficial
 */
class cListNd_c {
    SIZE_ASSERT(0x8);

public:
    /**
     * Constructs a new list node.
     */
    constexpr cListNd_c()
        : mpPrev(nullptr)
        , mpNext(nullptr) {}

    cListNd_c* getPrev() const { return mpPrev; }

    cListNd_c* getNext() const { return mpNext; }

protected:
    /**
     * The previous node.
     */
    /* 0x0 */ cListNd_c* mpPrev;

    /**
     * The next node.
     */
    /* 0x4 */ cListNd_c* mpNext;

    friend class cListMg_c;
};

/**
 * A doubly-linked list container. See cListNd_c.
 * @unofficial
 */
class cListMg_c {
    SIZE_ASSERT(0x8);

public:
    /**
     * Constructs a new list container.
     */
    constexpr cListMg_c()
        : mpFirst(nullptr)
        , mpLast(nullptr) {}

    /**
     * Inserts a node after the given previous node.
     *
     * @param node The node to insert.
     * @param prevNode The node to insert it after, or @p nullptr to insert it at the beginning.
     * @return If the operation was successful.
     */
    bool insertAfter(cListNd_c* node, cListNd_c* prevNode);

    /**
     * Removes a node from the list.
     *
     * @param node The node to remove.
     * @return If the operation was successful.
     */
    bool remove(cListNd_c* node);

    /**
     * Adds a node to the end of the list.
     *
     * @param node The node to append.
     * @return If the operation was successful.
     */
    bool append(cListNd_c* node);

    /**
     * Adds a node to the beginning of the list.
     *
     * @param node The node to prepend.
     * @return If the operation was successful.
     */
    bool prepend(cListNd_c* node);

    cListNd_c* getFirst() const { return mpFirst; }

    cListNd_c* getLast() const { return mpLast; }

protected:
    /**
     * The first node in the list.
     */
    /* 0x0 */ cListNd_c* mpFirst;

    /**
     * The last node in the list.
     */
    /* 0x4 */ cListNd_c* mpLast;
};
