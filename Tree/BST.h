
#include <iostream>

using namespace std;

template<class T>
class BSTNode {
private:
    T key;
    BSTNode<T> *left;
    BSTNode<T> *right;

public:
    BSTNode() : left(nullptr), right(nullptr) {}

    BSTNode(const T &k, BSTNode *l = nullptr, BSTNode *r = nullptr) : key(k), left(l), right(r) {}

    ~BSTNode() {
        left = right = nullptr;
    }

    T &getKey() {
        return key;
    }

    BSTNode *getLeft() {
        return left;
    }

    BSTNode *getRight() {
        return right;
    }

    void setLeft(BSTNode *node) {
        left = node;
    }

    void setRight(BSTNode *node) {
        right = node;
    }
};

template<class T>
class BST {
private:
    BSTNode<T> *root;

    BSTNode<T> *remove(BSTNode<T> *p, const T &el);

public:
    BST() : root(nullptr) {}

    void clear() {
        root = nullptr;
    }

    bool isEmpty() {
        return (root == nullptr);
    }

    T *search(T &val);

    void insert(const T &val);

    void remove(const T &el) {
        root = remove(root, el);
    }

    void preOrder(BSTNode<T> *p);

    void preOrderCall();

    void postOrder(BSTNode<T> *p);

    void postOrderCall();

    void inOrder(BSTNode<T> *p);

    void inOrderCall();
};

template<class T>
T *BST<T>::search(T &val) {
    BSTNode<T> *p = root;
    while (p != nullptr) {
        if (val == p->getKey()) {
            return &(p->getKey());
        } else if (val < p->getKey()) {
            p = p->getLeft();
        } else {
            p = p->getRight();
        }
    }
    return nullptr;
}

template<class T>
void BST<T>::insert(const T &val) {
    BSTNode<T> *p = root, *prev = nullptr;
    while (p != nullptr) {
        prev = p;
        if (val < p->getKey()) {
            p = p->getLeft();
        } else if (val > p->getKey()) {
            p = p->getRight();
        } else {
            return; // Value already exists in the tree
        }
    }
    if (root == nullptr) {
        root = new BSTNode<T>(val);
    } else if (val < prev->getKey()) {
        prev->setLeft(new BSTNode<T>(val));
    } else {
        prev->setRight(new BSTNode<T>(val));
    }
}

template<class T>
BSTNode<T> *BST<T>::remove(BSTNode<T> *p, const T &el) {
    if (p == nullptr) {
        return nullptr;
    }
    if (el < p->getKey()) {
        p->setLeft(remove(p->getLeft(), el));
    } else if (p->getKey() < el) {
        p->setRight(remove(p->getRight(), el));
    } else {
        if (p->getLeft() == nullptr) {
            BSTNode<T> *temp = p->getRight();
            delete p;
            return temp;
        } else if (p->getRight() == nullptr) {
            BSTNode<T> *temp = p->getLeft();
            delete p;
            return temp;
        } else {
            BSTNode<T> *successorParent = p;
            BSTNode<T> *successor = p->getRight();
            while (successor->getLeft() != nullptr) {
                successorParent = successor;
                successor = successor->getLeft();
            }
            if (successorParent != p) {
                successorParent->setLeft(successor->getRight());
            } else {
                p->setRight(successor->getRight());
            }
            p->getKey() = successor->getKey();
            delete successor;
        }
    }
    return p;
}

template<class T>
void BST<T>::preOrder(BSTNode<T> *p) {
    if (p != nullptr) {
        cout << p->getKey() << " ";
        preOrder(p->getLeft());
        preOrder(p->getRight());
    }
}

template<class T>
void BST<T>::preOrderCall() {
    preOrder(root);
}

template<class T>
void BST<T>::inOrder(BSTNode<T> *p) {
    if (p != nullptr) {
        inOrder(p->getLeft());
        cout << p->getKey() << " ";
        inOrder(p->getRight());
    }
}

template<class T>
void BST<T>::inOrderCall() {
    inOrder(root);
}

template<class T>
void BST<T>::postOrder(BSTNode<T> *p) {
    if (p != nullptr) {
        postOrder(p->getLeft());
        postOrder(p->getRight());
        cout << p->getKey() << " ";
    }
}

template<class T>
void BST<T>::postOrderCall() {
    postOrder(root);
}
