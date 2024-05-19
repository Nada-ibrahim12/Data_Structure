#include <iostream>
using namespace std;

template <class T>
struct NodeC
{
    T data;
    NodeC<T> *next;
};

template <class T>
class Circular_Linked_List
{
private:
    NodeC<T> *head;
    NodeC<T> *tail;
    int length;

public:
    Circular_Linked_List();
    ~Circular_Linked_List();
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

template <class T>
Circular_Linked_List<T>::Circular_Linked_List()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
Circular_Linked_List<T>::~Circular_Linked_List()
{
    clear();
}

template <class T>
bool Circular_Linked_List<T>::isEmpty()
{
    return length == 0;
}

template <class T>
void Circular_Linked_List<T>::clear()
{
    while (length > 0)
    {
        removeAtHead();
    }
}

template <class T>
void Circular_Linked_List<T>::insertAtHead(T val)
{
    NodeC<T> *temp = new NodeC<T>;
    temp->data = val;
    if (length == 0)
    {
        head = tail = temp;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
    length++;
}

template <class T>
void Circular_Linked_List<T>::insertAtTail(T val)
{
    NodeC<T> *temp = new NodeC<T>;
    temp->data = val;
    if (length == 0)
    {
        head = tail = temp;
        temp->next = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
    length++;
}

template <class T>
void Circular_Linked_List<T>::insertAt(T val, int index)
{
    if (index < 0 || index > length)
    {
        cout << "Invalid index" << endl;
        return;
    }
    if (index == 0)
    {
        insertAtHead(val);
    }
    else if (index == length)
    {
        insertAtTail(val);
    }
    else
    {
        NodeC<T> *newNodeC = new NodeC<T>;
        newNodeC->data = val;
        NodeC<T> *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNodeC->next = current->next;
        current->next = newNodeC;
        length++;
    }
}

template <class T>
bool Circular_Linked_List<T>::isExist(T val)
{
    if (length == 0) return false;

    NodeC<T> *current = head;
    do
    {
        if (current->data == val)
        {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}

template <class T>
bool Circular_Linked_List<T>::isItemAtEqual(T val, int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Index out of range" << endl;
        return false;
    }
    NodeC<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data == val;
}

template <class T>
int Circular_Linked_List<T>::linkedListSize()
{
    return length;
}

template <class T>
void Circular_Linked_List<T>::removeAt(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0)
    {
        removeAtHead();
    }
    else if (index == length - 1)
    {
        removeAtTail();
    }
    else
    {
        NodeC<T> *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        NodeC<T> *temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }
}

template <class T>
void Circular_Linked_List<T>::removeAtHead()
{
    if (length == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    NodeC<T> *temp = head;
    if (length == 1)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    length--;
}

template <class T>
void Circular_Linked_List<T>::removeAtTail()
{
    if (length == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (length == 1)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        NodeC<T> *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = head;
    }
    length--;
}

template <class T>
void Circular_Linked_List<T>::replaceAt(T newVal, int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Index out of range" << endl;
        return;
    }
    NodeC<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->data = newVal;
}

template <class T>
T Circular_Linked_List<T>::retrieveAt(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Index out of range" << endl;
        return T(); // Return default value of T
    }
    NodeC<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
void Circular_Linked_List<T>::swap(int firstItemIdx, int secondItemIdx)
{
    if (firstItemIdx < 0 || firstItemIdx >= length || secondItemIdx < 0 || secondItemIdx >= length)
    {
        cout << "Invalid indexes" << endl;
        return;
    }
    if (firstItemIdx == secondItemIdx)
    {
        return;
    }

    NodeC<T> *NodeC1 = head;
    NodeC<T> *NodeC2 = head;
    NodeC<T> *prevNodeC1 = nullptr;
    NodeC<T> *prevNodeC2 = nullptr;

    for (int i = 0; i < firstItemIdx; i++)
    {
        prevNodeC1 = NodeC1;
        NodeC1 = NodeC1->next;
    }
    for (int i = 0; i < secondItemIdx; i++)
    {
        prevNodeC2 = NodeC2;
        NodeC2 = NodeC2->next;
    }

    if (prevNodeC1 != nullptr)
    {
        prevNodeC1->next = NodeC2;
    }
    else
    {
        head = NodeC2;
    }

    if (prevNodeC2 != nullptr)
    {
        prevNodeC2->next = NodeC1;
    }
    else
    {
        head = NodeC1;
    }

    NodeC<T> *temp = NodeC2->next;
    NodeC2->next = NodeC1->next;
    NodeC1->next = temp;

    if (NodeC1->next == head)
    {
        tail = NodeC1;
    }
    if (NodeC2->next == head)
    {
        tail = NodeC2;
    }
}

template <class T>
void Circular_Linked_List<T>::print()
{
    if (length == 0)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    NodeC<T> *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

template <class T>
T Circular_Linked_List<T>::first()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return T(); // Return default value of T
    }
    return head->data;
}
