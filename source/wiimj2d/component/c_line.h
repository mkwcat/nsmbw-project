#pragma once

/**
 * A doubly-linked list node. See cLineMg_c.
 */
class cLineNd_c {
    SIZE_ASSERT(0x8);

public:
    /**
     * Constructs a new line node.
     */
    constexpr cLineNd_c()
        : mPrev(nullptr)
        , mNext(nullptr) {}

    cLineNd_c* getPrev() const { return mPrev; }

    cLineNd_c* getNext() const { return mNext; }

protected:
    /* 0x0 */ cLineNd_c* mPrev; /// The previous node
    /* 0x4 */ cLineNd_c* mNext; /// The next node

    friend class cLineMg_c;
};

/**
 * A doubly-linked list container. See cLineNd_c.
 */
class cLineMg_c {
    SIZE_ASSERT(0x8);

public:
    /**
     * Constructs a new line container.
     */
    constexpr cLineMg_c()
        : mFirst(nullptr)
        , mLast(nullptr) {}

    /**
     * Inserts a node after the given previous node.
     *
     * @param node The node to insert.
     * @param prevNode The node to insert it after, or @p nullptr to insert it at the beginning.
     * @return If the operation was successful.
     */
    bool insertLineNode(cLineNd_c* node, cLineNd_c* prevNode);

    /**
     * Removes a node from the line.
     *
     * @param node The node to remove.
     * @return If the operation was successful.
     */
    bool removeLineNode(cLineNd_c* node);

    /**
     * Adds a node to the end of the line.
     *
     * @param node The node to append.
     * @return If the operation was successful.
     */
    bool addLastLineNode(cLineNd_c* node);

    /**
     * Adds a node to the beginning of the line.
     *
     * @param node The node to prepend.
     * @return If the operation was successful.
     */
    bool addTopLineNode(cLineNd_c* node);

    cLineNd_c* getFirst() const { return mFirst; }

    cLineNd_c* getLast() const { return mLast; }

protected:
    /* 0x0 */ cLineNd_c* mFirst; /// he first node in the line
    /* 0x4 */ cLineNd_c* mLast;  /// The last node in the line
};
