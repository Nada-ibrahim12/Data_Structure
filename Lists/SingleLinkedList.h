#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T> *next;
};

template<class T>
class Single_Linked_List {
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    Single_Linked_List();
    ~Single_Linked_List();
    bool isEmpty();
    void clear();
    void insertAtHead(T val);
    void insertAtTail(T val);
    void insertAt(T val, int index);
    bool isExist(T val);
    bool isItemAtEqual(T val, int index);
    int linkedListSize();
    void removeAt(int index);
    void removeAtHead();
    void removeAtTail();
    void replaceAt(T newVal, int index);
    T retrieveAt(int index);
    void swap(int firstItemIdx, int secondItemIdx);
    void print();
    T first();
};


template<class T>
Single_Linked_List<T>::Single_Linked_List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<class T>
Single_Linked_List<T>::~Single_Linked_List() {
    clear();
}

template<class T>
bool Single_Linked_List<T>::isEmpty() {
    return length == 0;
}

template<class T>
void Single_Linked_List<T>::clear() {
    Node<T> *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}

template<class T>
void Single_Linked_List<T>::insertAtHead(T val) {
    Node<T> *temp = new Node<T>;
    temp->data = val;
    temp->next = head;
    head = temp;
    if (tail == nullptr) {
        tail = temp;
    }
    length++;
}

template<class T>
void Single_Linked_List<T>::insertAtTail(T val) {
    Node<T> *temp = new Node<T>;
    temp->data = val;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    length++;
}

template<class T>
void Single_Linked_List<T>::insertAt(T val, int index) {
    if (index < 0 || index > length) {
        cout << "Invalid index" << endl;
        return;
    }
    if (index == 0) {
        insertAtHead(val);
    } else if (index == length) {
        insertAtTail(val);
    } else {
        Node<T> *newNode = new Node<T>;
        newNode->data = val;
        Node<T> *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
}

template<class T>
bool Single_Linked_List<T>::isExist(T val) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
bool Single_Linked_List<T>::isItemAtEqual(T val, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range" << endl;
        return false;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data == val;
}

template<class T>
int Single_Linked_List<T>::linkedListSize() {
    return length;
}

template<class T>
void Single_Linked_List<T>::removeAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0) {
        removeAtHead();
    } else if (index == length - 1) {
        removeAtTail();
    } else {
        Node<T> *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T> *temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }
}

template<class T>
void Single_Linked_List<T>::removeAtHead() {
    if (length == 0) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    length--;
    if (length == 0) {
        tail = nullptr;
    }
}

template<class T>
void Single_Linked_List<T>::removeAtTail() {
    if (length == 0) {
        cout << "List is empty" << endl;
        return;
    }
    if (length == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T> *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    length--;
}

template<class T>
void Single_Linked_List<T>::replaceAt(T newVal, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range" << endl;
        return;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = newVal;
}

template<class T>
T Single_Linked_List<T>::retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range" << endl;
        return T();  // Return default value of T
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<class T>
void Single_Linked_List<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= length || secondItemIdx < 0 || secondItemIdx >= length) {
        cout << "Invalid indexes" << endl;
        return;
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    }

    Node<T> *node1 = head;
    Node<T> *node2 = head;
    Node<T> *prevNode1 = nullptr;
    Node<T> *prevNode2 = nullptr;

    for (int i = 0; i < firstItemIdx; i++) {
        prevNode1 = node1;
        node1 = node1->next;
    }
    for (int i = 0; i < secondItemIdx; i++) {
        prevNode2 = node2;
        node2 = node2->next;
    }

    if (prevNode1 != nullptr) {
        prevNode1->next = node2;
    } else {
        head = node2;
    }

    if (prevNode2 != nullptr) {
        prevNode2->next = node1;
    } else {
        head = node1;
    }

    Node<T> *temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;

    if (node1->next == nullptr) {
        tail = node1;
    }
    if (node2->next == nullptr) {
        tail = node2;
    }
}

template<class T>
void Single_Linked_List<T>::print() {
    if (length == 0) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    Node<T> *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
T Single_Linked_List<T>::first() {
    return head->data;
}
