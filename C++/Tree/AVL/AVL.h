#ifndef _AVL_H_
#define _AVL_H_

struct AVLNode
{
    int _key;
    AVLNode* _left;
    AVLNode* _right;
    int _height;
};

AVLNode* createAVLNode(const int& key);

class AVL
{
private:
    AVLNode* _root;
public:
    AVL();
    ~AVL();

    AVL(const int& key);
    AVL(const AVL& tree);

    bool searchRecursive(const int& key);
    bool searchIterative(const int& key);

    void insertRecursive(const int& key);
    void insertIterative(const int& key);

    void removeNode(const int& key);

    void NLR();
    void LNR();
    void LRN();
    void levelOrder();

private: 
    AVLNode* searchRecursive(AVLNode* root, const int& key);
    AVLNode* searchIterative(AVLNode* root, const int& key);

    void insertRecursive(AVLNode*& root, const int& key);
    void insertIterative(AVLNode*& root, const int& key);

    void removeNode(AVLNode*& root, const int& key);

    void rotateLeft(AVLNode*& root);
    void rotateRight(AVLNode*& root);
    void rotate(AVLNode*& root);

    AVLNode* findPrecessor(AVLNode* root);
    void removeTree(AVLNode*& root);

    void fixHeightNode(AVLNode*& root);

    int heightNode(AVLNode* root);

    void NLR(AVLNode* root);
    void LNR(AVLNode* root);
    void LRN(AVLNode* root);
    void levelOrder(AVLNode* root);
};

#endif