#pragma once

/**
 * A tree node. See cTreeMg_c.
 * The tree is represented as a doubly-linked LCRS tree.
 */
class cTreeNd_c {
    SIZE_ASSERT(0x10);

public:
    /**
     * Constructs a new tree node.
     */
    cTreeNd_c();

    /**
     * Gets the next node in preorder traversal order.
     */
    cTreeNd_c* getTreeNext() const;

    /**
     * Gets the next node in preorder traversal order, excluding the node's children.
     */
    cTreeNd_c* getTreeNextNotChild() const;

    cTreeNd_c* getParent() const { return mpParent; }

    cTreeNd_c* getChild() const { return mpChild; }

    cTreeNd_c* getBrPrev() const { return mpPrev; }

    cTreeNd_c* getBrNext() const { return mpNext; }

protected:
    /**
     * Clears all fields.
     */
    void forcedClear();

    /* 0x00 */ cTreeNd_c* mpParent; // Parent node.
    /* 0x04 */ cTreeNd_c* mpChild;  // Child node.
    /* 0x08 */ cTreeNd_c* mpPrev;   // Previous sibling node.
    /* 0x0C */ cTreeNd_c* mpNext;   // Next sibling node.

    friend class cTreeMg_c;
};

/**
 * A tree container. See cTreeNd_c.
 */
class cTreeMg_c {
    SIZE_ASSERT(0x4);

public:
    /**
     * Constructs a new tree container.
     */
    constexpr cTreeMg_c()
        : mpRootNode(nullptr) {}

    /**
     * Adds a node to the tree, either to the root node or to a specified parent node.
     *
     * @param node The node to add.
     * @param parent The parent node to attach it to, or @p nullptr to attach it to the tree root.
     * @return If the operation was successful.
     */
    bool addTreeNode(cTreeNd_c* node, cTreeNd_c* parent);

    /**
     * Removes a node from the tree.
     *
     * @param node The node to remove.
     * @return If the operation was successful.
     */
    bool removeTreeNode(cTreeNd_c* node);

    constexpr cTreeNd_c* getRootNode() const { return mpRootNode; }

protected:
    /* 0x0 */ cTreeNd_c* mpRootNode; // Root node of the tree.
};
