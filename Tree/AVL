#include <iostream>
#include <algorithm> // for max function

using namespace std;

template<class T>
class AVLNode {
public:
    T key;
    AVLNode<T> *left;
    AVLNode<T> *right;
    int height;

    AVLNode(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

template<class T>
class AVL {
private:
    AVLNode<T> *root;

    AVLNode<T> *insertNode(AVLNode<T> *node, T key);
    AVLNode<T> *deleteNode(AVLNode<T> *node, T key);
    int height(AVLNode<T> *N);
    int getBalanceFactor(AVLNode<T> *N);
    AVLNode<T> *balance(AVLNode<T> *node);
    AVLNode<T> *rotateRight(AVLNode<T> *y);
    AVLNode<T> *rotateLeft(AVLNode<T> *x);
    AVLNode<T> *minNode(AVLNode<T> *node);
    void inOrderTraversal(AVLNode<T> *root);

public:
    AVL() : root(nullptr) {}

    void insert(T key) {
        root = insertNode(root, key);
    }

    void remove(T key) {
        root = deleteNode(root, key);
    }

    AVLNode<T> *getRoot() { return root; }

    void setRoot(AVLNode<T> *root) {
        this->root = root;
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

template<class T>
int AVL<T>::height(AVLNode<T> *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

template<class T>
int AVL<T>::getBalanceFactor(AVLNode<T> *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

template<class T>
AVLNode<T> *AVL<T>::insertNode(AVLNode<T> *node, T val) {
    if (node == nullptr)
        return new AVLNode<T>(val);

    if (val < node->key)
        node->left = insertNode(node->left, val);
    else if (val > node->key)
        node->right = insertNode(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    return balance(node);
}

template<class T>
AVLNode<T> *AVL<T>::deleteNode(AVLNode<T> *node, T val) {
    if (node == nullptr)
        return node;

    if (val < node->key)
        node->left = deleteNode(node->left, val);
    else if (val > node->key)
        node->right = deleteNode(node->right, val);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode<T> *temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            AVLNode<T> *temp = minNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    return balance(node);
}

template<class T>
AVLNode<T>* AVL<T>::balance(AVLNode<T> *node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) >= 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

template<class T>
AVLNode<T> *AVL<T>::rotateRight(AVLNode<T> *y) {
    AVLNode<T> *x = y->left;
    AVLNode<T> *z = x->right;
    x->right = y;
    y->left = z;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

template<class T>
AVLNode<T> *AVL<T>::rotateLeft(AVLNode<T> *x)  {
    AVLNode<T> *y = x->right;
    AVLNode<T> *z = y->left;
    x->right = z;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

template<class T>
AVLNode<T> *AVL<T>::minNode(AVLNode<T> *node) {
    AVLNode<T> *current = node;
    while (current->left != nullptr){
        current = current->left;
    }
    return current;
}

template <class T>
void AVL<T>::inOrderTraversal(AVLNode<T> *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        cout << root->key << "  ";
        inOrderTraversal(root->right);
    }
}
