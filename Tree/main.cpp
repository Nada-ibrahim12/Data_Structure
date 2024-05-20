#include "BST.h"
using namespace std;

int main() {
    BST<int> bst;
    bst.insert(5);
    bst.insert(2);
    bst.insert(8);
    bst.insert(1);
    bst.insert(3);
    bst.insert(7);
    bst.insert(9);

    cout << "Pre-order traversal: ";
    bst.preOrderCall();
    cout << endl;

    cout << "In-order traversal: ";
    bst.inOrderCall();
    cout << endl;

    cout << "Post-order traversal: ";
    bst.postOrderCall();
    cout << endl;

    int searchKey = 7;
    if (bst.search(searchKey) != nullptr) {
        cout << "Found key: " << searchKey << endl;
    } else {
        cout << "Key not found: " << searchKey << endl;
    }

    int removeKey = 5;
    bst.remove(removeKey);
    cout << "In-order traversal after removing " << removeKey << ": ";
    bst.inOrderCall();
    cout << endl;

    return 0;
}
