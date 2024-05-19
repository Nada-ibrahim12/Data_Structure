#include <bits/stdc++.h>

using namespace std;

template<class T>
class node {
public:
    T data;
    node<T> *next;
    node<T> *previous;

    node(T d) {
        data = d;
        previous = nullptr;
        next = nullptr;
    }
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
    node<T> *temp = head;
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
    node<T> *temp = new node<T>(val);
    temp->next = head;
    if (head != nullptr) {
        head->previous = temp;
    } else {
        tail = temp;  // if head is null, this is the first node, so update tail
    }
    head = temp;
    length++;
}

template<class T>
void doubleLinkedList<T>::insertAtTail(T val) {
    if (head == nullptr) {
        insertAtHead(val);
        return;
    }
    node<T> *temp = new node<T>(val);
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
    } else if (index == length) {
        insertAtTail(val);
    } else {
        node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        node<T> *temp = new node<T>(val);
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
    node<T> *temp = head;
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
    node<T> *temp = tail;
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
        node<T> *current = head;
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
    node<T> *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template<class T>
T doubleLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range\n";
        return -1;  // Assuming T can be compared with -1. This may not be appropriate for all types of T.
    } else {
        node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
}

template<class T>
void doubleLinkedList<T>::replaceAt(T newVal, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range\n";
        return;
    } else {
        node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newVal;
    }
}

template<class T>
bool doubleLinkedList<T>::isEmpty() {
    return (length == 0);
}

template<class T>
int doubleLinkedList<T>::linkedListSize() {
    return length;
}

template<class T>
void doubleLinkedList<T>::clear() {
    while (!isEmpty()) {
        removeAtHead();
    }
}

template<class T>
bool doubleLinkedList<T>::isExist(T val) {
    node<T> *temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
bool doubleLinkedList<T>::isItemAtEqual(T val, int index) {
    if (index < 0 || index >= length) {
        cout << "Invalid Index\n";
        return false;
    }
    node<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return (temp->data == val);
}

template<class T>
void doubleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx >= count || secondItemIdx < 0 || secondItemIdx >= count) {
        cout << "Invalid indexes\n";
        return;
    } else if (firstItemIdx == secondItemIdx) {
        return;
    } else {
        node<T> *node1 = head;
        node<T> *node2 = head;
        node<T> *prev_node1 = nullptr;
        node<T> *prev_node2 = nullptr;

        //access the node<T> that wanted to swap
        for (int i = 0; i < firstItemIdx; ++i) {
            node1 = node1->next;
        }
        for (int i = 0; i < secondItemIdx; ++i) {
            node2 = node2->next;
        }

        prev_node1 = node1->previous;
        prev_node2 = node2->previous;

        //check if element in first or not
        if (prev_node1 != nullptr) {
            prev_node1->next = node2;
        } else {
            head = node2;
        }

        //check if element in last or not
        if (node1->next != nullptr) {
            node1->next->previous = node2;
        } else {
            tail = node2;
        }

        if (prev_node2 != nullptr) {
            prev_node2->next = node1;
        } else {
            head = node1;
        }

        if (node2->next != nullptr) {
            node2->next->previous = node1;
        } else {
            tail = node1;
        }

        node<T> *tmp_next = node2->next;
        node<T> *tmp_pre = node2->previous;
        node2->next = node1->next;
        node2->previous = node1->previous;
        node1->next = tmp_next;
        node1->previous = tmp_pre;
    }
}
