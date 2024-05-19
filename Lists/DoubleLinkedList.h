#include <bits/stdc++.h>

using namespace std;

template<class T>

struct node {
    T data;
    node<T> *next;
    node<T> *previous;
};

template<class T>

class doubleLinkedList {
private:
    node<T> *head;
    node<T> *tail;
    int length;
public:
    doubleLinkedList();

    ~doubleLinkedList();

    void insertAtHead(T val);

    void insertAtTail(T val);

    void insertAt(T val, int index);

    void removeAtHead();

    void removeAtTail();

    void removeAt(int index);

    T retrieveAt(int index);

    void replaceAt(T newVal, int index);

    bool isExist(T val);

    bool isItemAtEqual(T val, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    bool isEmpty();

    int linkedListSize();

    void clear();

    void print();
};

template<class T>
doubleLinkedList<T>::doubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<class T>
doubleLinkedList<T>::~doubleLinkedList() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        head = temp->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
    length = 0;
}

template<class T>
void doubleLinkedList<T>::insertAtHead(T val) {
    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = head;
    temp->previous = nullptr;
    if (head != nullptr) {
        head->previous = temp;
    }
    head = temp;
    if (tail == nullptr) {
        tail = temp;
    }
    length++;
}

template<class T>
void doubleLinkedList<T>::insertAtTail(T val) {
    if (head == nullptr) {
        insertAtHead(val);
        return;
    }
    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->previous = tail;
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
    length++;
}

template<class T>
void doubleLinkedList<T>::insertAt(T val, int index) {
    if (index < 0 || index > length) {
        cout << "Invalid Index\n";
        return;
    }
    if (index == 0) {
        insertAtHead(val);
    } else if (index == length) {  // Fix to check for appending to the end
        insertAtTail(val);
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node<T>* temp = new Node<T>;
        temp->data = val;
        temp->next = current;
        temp->previous = current->previous;
        current->previous->next = temp;
        current->previous = temp;
        length++;
    }
}

template<class T>
void doubleLinkedList<T>::removeAtHead() {
    if (length == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    Node<T>* temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->previous = nullptr;
    }
    delete temp;
    length--;
}

template<class T>
void doubleLinkedList<T>::removeAtTail() {
    if (length == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    Node<T>* temp = tail;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->previous;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

template<class T>
void doubleLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Invalid Index\n";
        return;
    }
    if (index == 0) {
        removeAtHead();
    } else if (index == length - 1) {
        removeAtTail();
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        length--;
    }
}

template<class T>
void doubleLinkedList<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}