#include "BST.h"
#include "AVL.h"
#include "Heap.h"

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
    cout << endl;
    cout << endl;

    Heap<int> heap;

    // Insert elements into the max heap
    int initial_values[] = {30, 10, 20, 7, 1, 5};
    for (int val: initial_values) {
        heap.insert_max(val);
    }

    cout << "Initial Max-Heap: ";
    heap.display();

    // Insert an additional element into the max heap
    heap.insert_max(25);
    cout << "After inserting 25: ";
    heap.display();

    // Extract the maximum element from the max heap
    int maxElement = heap.heap_extract_max();
    cout << "Extracted Max Element: " << maxElement << endl;
    cout << "After extracting max: ";
    heap.display();

    cout << endl;
    cout << endl;
    cout << endl;


    AVL<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder traversal of the constructed AVL tree is:" << endl;
    tree.inOrder();

    tree.remove(40);

    cout << "Inorder traversal after deletion of 40:" << endl;
    tree.inOrder();

    return 0;

}
