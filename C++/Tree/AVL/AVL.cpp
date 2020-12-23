#include "AVL.h"
#include <iostream>
#include <queue>
using namespace std;

AVLNode* createAVLNode(const int& key) {
    AVLNode* p = new AVLNode;
    p->_key = key;
    p->_left = p->_right = nullptr;
    p->_height = 1;
    return p;
}

AVL::AVL() : _root(nullptr) {}

AVL::~AVL() {
    this->removeTree(_root);
}


AVL::AVL(const int& key) {
    _root = createAVLNode(key);
}

AVL::AVL(const AVL& tree) {
    if (!tree._root) {
        _root = nullptr;
        return;
    }
    queue<AVLNode*> q;
    q.push(tree._root);
    while (q.size() != 0) {
        AVLNode* front = q.front();
        if (front->_left)
            q.push(front->_left);
        if (front->_right)
            q.push(front->_right);
        this->insertRecursive(front->_key);
        q.pop();
    }
}


bool AVL::searchRecursive(const int& key) {
    AVLNode* s = this->searchRecursive(_root, key);
    return (!s) ? false : true;
}

bool AVL::searchIterative(const int& key) {
    AVLNode* s = this->searchIterative(_root, key);
    return (!s) ? false : true;
}


void AVL::insertRecursive(const int& key) {
    this->insertRecursive(_root, key);
}

void AVL::insertIterative(const int& key) {
    this->insertIterative(_root, key);
}


void AVL::removeNode(const int& key) {
    this->removeNode(_root, key);
}


void AVL::NLR() {
    this->NLR(_root);
}

void AVL::LNR() {
    this->LNR(_root);
}

void AVL::LRN() {
    this->LRN(_root);
}

void AVL::levelOrder() {
    this->levelOrder(_root);
}


//----------------------------------------------------------------------------------------------------------

AVLNode* AVL::searchRecursive(AVLNode* root, const int& key) {
    if (!root)
        return nullptr;
    if (key == root->_key)
        return root;
    return (key < root->_key) ? this->searchRecursive(root->_left, key) : this->searchRecursive(root->_right, key);
}

AVLNode* AVL::searchIterative(AVLNode* root, const int& key) {
    if (!root)
        return nullptr;
    AVLNode* p = root;
    while (p) {
        if (p->_key == key)
            return p;
        p = (key < p->_key) ? p->_left : p->_right;
    }
    return nullptr;
}


void AVL::insertRecursive(AVLNode*& root, const int& key) {
    if (!root)
        root = createAVLNode(key);
    else {
        if (key == root->_key)
            return;
        else if (key < root->_key)
            this->insertRecursive(root->_left, key);
        else 
            this->insertRecursive(root->_right, key);
    }

    if (!root)
        return;
    this->fixHeightNode(root);
    this->rotate(root);
}

void AVL::insertIterative(AVLNode*& root, const int& key) {
    // if (!root) {
    //     root= createAVLNode(key);
    //     return;
    // }

    // AVLNode* prev = nullptr;
    // AVLNode* curr = root;

    // while (curr) {
    //     prev = curr;
    //     if (curr->_key == key)
    //         return;
    //     curr = (key < curr->_key) ? curr->_left : curr->_right;
    // }

    // if (key < prev->_key)
    //     prev = createAVLNode(key);
    // if (key > prev->_key)
    //     prev = createAVLNode(key);
}

AVLNode* AVL::findPrecessor(AVLNode* root) {
    if (!root)
        return nullptr;
    AVLNode* p = root;
    while (p->_right)
        p = p->_right;
    return p;
}

void AVL::removeNode(AVLNode*& root, const int& key) {
    if (!root)
        return;
    
    if (key < root->_key)
        this->removeNode(root->_left, key);
    else if (key > root->_key)
        this->removeNode(root->_right, key);
    else {
        if (!root->_left && !root->_right) {
            delete root;
            root = nullptr;
        }
        else if (!root->_left || !root->_right) {
            AVLNode* p = root;
            root = (root->_left) ? root->_left : root->_right;
            delete p;
        }
        else if (root->_left && root->_right) {
            AVLNode* pre = this->findPrecessor(root->_left);
            root->_key = pre->_key;
            this->removeNode(root->_left, pre->_key);
        }
    }
}


void AVL::rotateLeft(AVLNode*& root) {
    if (!root)
        return;
    AVLNode* right = root->_right;

    root->_right = right->_left;
    this->fixHeightNode(root);

    right->_left = root;
    root = right;
    this->fixHeightNode(root);
    this->fixHeightNode(root->_right);
}

void AVL::rotateRight(AVLNode*& root) {
    if (!root)
        return;
    AVLNode* left = root->_left;

    root->_left = left->_right;
    this->fixHeightNode(root);

    left->_right = root;
    root = left;
    this->fixHeightNode(root);
    this->fixHeightNode(root->_left);
}

void AVL::rotate(AVLNode*& root) {
    if (!root)
        return;
    
    int balance = 0; //Check left or right case
    int sbalance = 0; //Continue from balance, check left-right or right-left

    balance = this->heightNode(root->_left) - this->heightNode(root->_right);
    if (balance > 1) {
        sbalance = (!root->_left) ? 0 : this->heightNode(root->_left->_left) - this->heightNode(root->_left->_right);

        if (sbalance >= 0)
            this->rotateRight(root);
        else {
            this->rotateLeft(root->_right);
            this->rotateRight(root);
        }
    }
    else if (balance < -1) {
        sbalance = (!root->_right) ? 0 : this->heightNode(root->_right->_right) - this->heightNode(root->_right->_left);
        
        if (sbalance >= 0)
            this->rotateLeft(root);
        else {
            this->rotateRight(root->_left);
            this->rotateLeft(root);
        }
    }
}

void AVL::removeTree(AVLNode*& root) {
    if (!root)
        return;
    this->removeTree(root->_left);
    this->removeTree(root->_right);
    delete root;
}

void AVL::fixHeightNode(AVLNode*& root) {
    if (!root)
        return;
    root->_height = 1 + max(this->heightNode(root->_left), this->heightNode(root->_right));
}

int AVL::heightNode(AVLNode* root) {
    if (!root)
        return 0;
    return root->_height;
}

void AVL::NLR(AVLNode* root) {
    if (!root)
        return;
    cout << "key: " << root->_key << " " << "height: " <<  root->_height << endl;
    this->NLR(root->_left);
    this->NLR(root->_right);
}

void AVL::LNR(AVLNode* root) {
    if (!root)
        return;
    this->LNR(root->_left);
    cout << "key: " << root->_key << " " << "height: " <<  root->_height << endl;
    this->LNR(root->_right);
}

void AVL::LRN(AVLNode* root) {
    if (!root)
        return;
    this->LRN(root->_left);
    this->LRN(root->_right);
    cout << "key: " << root->_key << " " << "height: " <<  root->_height << endl;
}

void AVL::levelOrder(AVLNode* root) {
    if (!root)
        return;
    queue<AVLNode*> q;

    q.push(root);
    while (!q.empty()) {
        AVLNode* fr = q.front();
        cout << "_key: " << fr->_key << " " << "_height: " <<  fr->_height << endl;
        if (fr->_left)
            q.push(fr->_left);
        if (fr->_right)
            q.push(fr->_right);
        q.pop();
    }
}