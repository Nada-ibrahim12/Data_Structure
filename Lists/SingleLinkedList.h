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
    Node<T> *head, *tail;
    int maxSize;
    int length;

public:
    Single_Linked_List();

    ~Single_Linked_List();

    bool isEmpty();

    void clear();

    void print();

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

};


template<class T>
Single_Linked_List<T>::Single_Linked_List() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<class T>
Single_Linked_List<T>::~Single_Linked_List() {
    Node<T> *temp = new Node<T>;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}


template<class T>
bool Single_Linked_List<T>::isEmpty() {
    return (length == 0);
}

template<class T>
void Single_Linked_List<T>::clear() {
    Node<T> temp = new Node<T>;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    length = 0;
}


template<class T>
void Single_Linked_List<T>::print() {}


template<class T>
void Single_Linked_List<T>::insertAtHead(T val) {
    Node<T> temp = new Node<T>;
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
    Node<T> temp = new Node<T>;
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
    Node<T> newnode = new Node<T>;
    newnode->data = val;
    newnode->next = nullptr;
    if (index == 0) {
        insertAtHead(val);
    } else if (index == length) {
        insertAtTail(val);
    } else {
        Node<T> *current = head;
        int pos = 0;    // we can use for loop
        while (current != nullptr && pos < index - 1) {
            current = current->next;
            pos++;
        }
        if (current == nullptr) {
            cout << "invalid index" << endl;
            return;
        } else {
            newnode->next = current->next;
            current->next = newnode;
        }

    }
    length++;
}


template<class T>
bool Single_Linked_List<T>::isExist(T val) {
    if (length >= 1 && (tail->data == val || head->data == val))
        return true;
    else {
        Node<T> *current = head;
        while (current != nullptr) {
            for (int i = 0; i < length; i++) {
                if (current->data = val) {
                    return true;
                }
                current = current->next;
            }
        }
    }
    return false;
}


template<class T>
bool Single_Linked_List<T>::isItemAtEqual(T val, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range ";
        return false;
    } else if (index == 0) {
        return head->data == val;
    } else if (index == length - 1) {
        return tail->data == val;
    } else {
        Node<T> *current = head;
        while (current != nullptr) {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data = val;
        }
    }
    return false;
}


template<class T>
int Single_Linked_List<T>::linkedListSize() {
    return length;
}


template<class T>
void Single_Linked_List<T>::removeAt(int index) {
    Node<T> *temp = new Node<T>;
    if (index < 0 || index >= length) {
        cout << "Index out of range ";
        return;
    }
    if (length == 0) {
        cout << "LIST IS Empty";
        return;
    } else if (length == 1 || index == 1) {
        removeAtHead();
    } else if (index == length - 1) {
        removeAtTail();
    } else {
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            temp = current;
            current = current->next;
        }
        temp->next = current->next;
        delete current;
        length--;
    }
}


template<class T>
void Single_Linked_List<T>::removeAtHead() {
    Node<T> *temp = head;
    if (length == 0) {
        cout << "LIST IS Empty";
        return;
    } else if (length == 1) {
        head = nullptr;
        tail = nullptr;
        delete temp;
    } else {
        head = head->next;
        delete temp;
    }
    length--;
}


template<class T>
void Single_Linked_List<T>::removeAtTail() {
    Node<T> *temp = head;
    if (length == 0) {
        cout << "LIST IS Empty";
        return;
    } else if (length == 1) {
        head = nullptr;
        tail = nullptr;
        delete temp;
    } else {
        Node<T> *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = nullptr;
        tail = current;
        delete temp;
    }
    length--;
}


template<class T>
void Single_Linked_List<T>::replaceAt(T newVal, int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range ";
        return;
    } else if (index == 0) {
        head->data = newVal;
    } else if (index = length - 1) {
        tail->data = newVal;
    } else {
        Node<T> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = newVal;
    }
}


template<class T>
T Single_Linked_List<T>::retrieveAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of range ";
        return -1;
    } else if (index == 0) {
        return head->data;
    } else if (index == length - 1) {
        return tail->data;
    } else {
        Node<T> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}


template<class T>
void Single_Linked_List<T>::swap(int firstItemIdx, int secondItemIdx) {}
