#include "Stack_Queue.h"
#include "DoubleLinkedList.h"
#include "CircularLinkedList.h"
#include "ArrayList.h"

using namespace std;

int main() {
    cout << "Example for Array list" << endl;
    ArrayList<int> list(10);
    list.pushFront(5);
    list.pushBack(10);
    list.insert_by_position(1, 7);
    list.insert_by_position(3, 6);
    list.insert_by_position(4, 100);
    list.insert_by_position(2, 12);
    list.pushFront(20);
    list.pushFront(17);

    //17 20 5 7 12 10 6 100

    list.print();

    cout << "Removed front: " << list.remove_front() << endl;    // 20 5 7 12 10 6 100
    list.print();

    cout << "Popped back: " << list.pop_back() << endl;  // 20 5 7 12 10 6
    list.print();

    cout << "Removed by position 5 : " << list.remove_by_position(5) << endl; // 20 5 7 12 10
    list.print();

    cout << list.isEmpty() << endl;

    list.insert_by_position(0, 20); // 20 20 5 7 12 10
    cout << list.isFull() << endl;
    list.print();

    list.insert_by_position(1, 30);
    list.insert_by_position(2, 40);
    list.print();  // 20 30 40 20 5 7 12 10
    cout << list.get_size() << endl; // 8

    cout << "Removed by position 1: " << list.remove_by_position(1) << endl;
    list.print();// 20 40 20 5 7 12 10


    cout << endl;
    cout << endl;
    cout << endl;

    /////////////////////

    //SINGLE_LINKED_LIST

    cout << "Example for Single linked list" << endl;
    Single_Linked_List<int> SLL;

    SLL.insertAtHead(1);
    SLL.insertAtTail(2);
    SLL.insertAtTail(3);
    SLL.insertAtTail(4);
    SLL.insertAt(5, 2);

    cout << "List after inserting 1 at head, 2 at tail, 3 at tail, 4 at tail, and 5 at index 2:" << endl;
    SLL.print();

    cout << "Size of list: " << SLL.linkedListSize() << endl;

    cout << "Is 3 in the list? " << (SLL.isExist(3) ? "Yes" : "No") << endl;

    cout << "Is item at index 2 equal to 5? " << (SLL.isItemAtEqual(5, 2) ? "Yes" : "No") << endl;

    SLL.removeAt(2);
    cout << "List after removing element at index 2:" << endl;
    SLL.print();

    SLL.removeAtHead();
    cout << "List after removing element at head:" << endl;
    SLL.print();

    SLL.removeAtTail();
    cout << "List after removing element at tail:" << endl;
    SLL.print();

    SLL.replaceAt(7, 1);
    cout << "List after replacing element at index 1 with 7:" << endl;
    SLL.print();

    cout << "Element at index 1: " << SLL.retrieveAt(1) << endl;

    SLL.swap(0, 1);
    cout << "List after swapping elements at index 0 and 1:" << endl;
    SLL.print();


    cout << endl;
    cout << endl;
    cout << endl;

    /////////////////////

    //DOUBLE_LINKED_LIST

    cout << "Example for Double linked list" << endl;
    doubleLinkedList<int> DLL;

    DLL.insertAtHead(3);
    DLL.insertAtHead(2);
    DLL.insertAtHead(1);
    cout << "After inserting 1, 2, 3 at head: ";
    DLL.print();

    DLL.insertAtTail(4);
    DLL.insertAtTail(5);
    DLL.insertAtTail(6);
    cout << "After inserting 4, 5, 6 at tail: ";
    DLL.print();

    DLL.insertAt(7, 3);
    cout << "After inserting 7 at index 3: ";
    DLL.print();

    cout << "Element at index 3: " << DLL.retrieveAt(3) << endl;

    DLL.replaceAt(8, 3);
    cout << "After replacing element at index 3 with 8: ";
    DLL.print();

    cout << "Does 8 exist in the list? " << (DLL.isExist(8) ? "Yes" : "No") << endl;

    cout << "Is the element at index 3 equal to 8? " << (DLL.isItemAtEqual(8, 3) ? "Yes" : "No") << endl;

    DLL.swap(0, 5);
    cout << "After swapping elements at index 0 and 5: ";
    DLL.print();

    DLL.removeAtHead();
    cout << "After removing element at the head: ";
    DLL.print();

    DLL.removeAtTail();
    cout << "After removing element at the tail: ";
    DLL.print();

    DLL.removeAt(2);
    cout << "After removing element at index 2: ";
    DLL.print();

    cout << "Is the list empty? " << (DLL.isEmpty() ? "Yes" : "No") << endl;

    cout << "Size of the list: " << DLL.linkedListSize() << endl;

    DLL.clear();
    cout << DLL.isEmpty() <<endl;
    cout << "After clearing the list: ";
    DLL.print();



    cout << endl;
    cout << endl;
    cout << endl;

    /////////////////////

    // CIRCULAR_LINKED_LIST

    cout << "Example for Circular linked list" << endl;
    Circular_Linked_List<int> cll;

    // Insert elements at the head
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtHead(30);

    cout << "List after inserting elements at head: ";
    cll.print(); // Should print: 30 20 10

    // Insert elements at the tail
    cll.insertAtTail(40);
    cll.insertAtTail(50);

    cout << "List after inserting elements at tail: ";
    cll.print(); // Should print: 30 20 10 40 50

    // Insert elements at specific positions
    cll.insertAt(25, 2);
    cll.insertAt(35, 4);

    cout << "List after inserting elements at specific positions: ";
    cll.print(); // Should print: 30 20 25 10 35 40 50

    // Check if elements exist in the list
    cout << "Does 25 exist in the list? " << (cll.isExist(25) ? "Yes" : "No") << endl; // Should print: Yes
    cout << "Does 100 exist in the list? " << (cll.isExist(100) ? "Yes" : "No") << endl; // Should print: No

    // Retrieve element at a specific index
    cout << "Element at index 3: " << cll.retrieveAt(3) << endl; // Should print: 10

    // Replace element at a specific index
    cll.replaceAt(45, 4);
    cout << "List after replacing element at index 4: ";
    cll.print(); // Should print: 30 20 25 10 45 40 50

    // Remove element at a specific index
    cll.removeAt(2);
    cout << "List after removing element at index 2: ";
    cll.print(); // Should print: 30 20 10 45 40 50

    // Swap elements
    cll.swap(1, 4);
    cout << "List after swapping elements at indexes 1 and 4: ";
    cll.print(); // Should print: 30 40 10 45 20 50

    // Get the size of the list
    cout << "Size of the list: " << cll.linkedListSize() << endl; // Should print: 6

    // Clear the list
    cll.clear();
    cout << "List after clearing all elements: ";
    cll.print(); // Should print: LIST IS EMPTY



    cout << endl;
    cout << endl;
    cout << endl;

    /////////////////////

    // STACK

    cout << "Stack Example:\n";
    Stack<int> stack(5);

    cout << "Pushing elements into the stack:\n";
    for (int i = 1; i <= 5; ++i) {
        stack.push(i * 10);
        cout << "Pushed: " << i * 10 << ", Top: " << stack.top() << ", Size: " << stack.stackSize() << endl;
    }

    cout << "\nPopping elements from the stack:\n";
    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.top() << ", Size: " << stack.stackSize() << endl;
        stack.pop();
    }

    cout << "\nStack after popping: ";
    stack.print();

    cout << endl;
    cout << endl;
    cout << endl;

    /////////////////////

    // QUEUE

    cout << "\n\nQueue Example:\n";
    Queue<int> queue;

    cout << "Enqueuing elements into the queue:\n";
    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i * 10);
        cout << "Enqueued: " << i * 10 << ", First: " << queue.first() << endl;
    }

    cout << "\nDequeuing elements from the queue:\n";
    while (!queue.isEmpty()) {
        cout << "Dequeued: " << queue.first() << endl;
        queue.dequeue();
    }

    cout << "\nQueue after dequeuing: ";
    queue.print();
    return 0;
}
