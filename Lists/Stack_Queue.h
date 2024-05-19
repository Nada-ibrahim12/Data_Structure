#include "SingleLinkedList.h"
using namespace std;

template <class T>
class Stack : public Single_Linked_List<T> {
private:
    int size;

public:
    Stack(int maxSize) : Single_Linked_List<T>(), size(maxSize) {}
    ~Stack(){}

    void push(const T& newItem){
        Single_Linked_List<T>::insertAtHead(newItem);
    }
    void pop(){
        Single_Linked_List<T>::removeAtHead();
    }
    T top(){
        return Single_Linked_List<T>::first();
    }
    bool isEmpty(){
        return Single_Linked_List<T>::isEmpty();
    }
    int stackSize(){
        return Single_Linked_List<T>::linkedListSize();
    }
    void clear(){
        Single_Linked_List<T>::clear();
    }
    void print(){
        Single_Linked_List<T>::print();
    }
    bool isFull(){
        return false;
    }

};

template<class T>
class Queue : Single_Linked_List<T>{
public:
    Queue(){}
    ~Queue(){}
    void enqueue(const T& item){
        Single_Linked_List<T>::insertAtTail(item);
    }
    void dequeue(){
        return (Single_Linked_List<T>::removeAtHead());
    }
    void clear(){
        Single_Linked_List<T>::clear();
    }
    bool isEmpty(){
        return (Single_Linked_List<T>::isEmpty());
    }
    T first(){
        return (Single_Linked_List<T>::first());
    }
    void print(){
        Single_Linked_List<T>::print();
    }
};