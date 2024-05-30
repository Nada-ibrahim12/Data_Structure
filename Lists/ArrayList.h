#include <bits/stdc++.h>
using namespace std;

template<typename T>
class ArrayList {
private:
    T *array;
    int capacity;
    int size;

public:
    ArrayList(int initialCapacity);
    ~ArrayList();
    void print() const;
    void pushFront (const T &val);
    void pushBack(const T &val);
    void insert_by_position(int index, const T &val);
    T remove_front();
    T pop_back();
    T remove_by_position(int index);
    int get_size() const;
    bool isEmpty() const;
    bool isFull() const;
    void resize(int newCap);
};

template<typename T>
ArrayList<T>::ArrayList(int initialCapacity) : size(0) {
    if (initialCapacity < 0) {
        cout << "You entered an invalid size, setting default capacity to 10" << endl;
        initialCapacity = 10;
    }
    capacity = initialCapacity;
    array = new T[capacity];
    assert(array != nullptr);
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] array;
}

template<typename T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

template<typename T>
void ArrayList<T>::pushFront(const T &val) {
    insert_by_position(0, val);
}

template<typename T>
void ArrayList<T>::pushBack(const T &val) {
    insert_by_position(size, val);
}

template<typename T>
void ArrayList<T>::insert_by_position(int index, const T &val) {
    if (index < 0 || index > size) {
        cout << "Index out of range" << endl;
        return;
    }
    if (size == capacity) {
        cout << "The list is full, we will resize it" << endl;
        resize(2*capacity);
        return;
    }

    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = val;
    size++;
}

template<typename T>
T ArrayList<T>::remove_front() {
    if (size == 0) {
        cout << "The list is empty" << endl;
        return T(); // Return default constructed T
    }
    T val = array[0];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return val;
}

template<typename T>
T ArrayList<T>::pop_back() {
    if (size == 0) {
        cout << "The list is empty" << endl;
        return T(); // Return default constructed T
    }
    T val = array[size - 1];
    size--;
    return val;
}

template<typename T>
T ArrayList<T>::remove_by_position(int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
        return T(); // Return default constructed T
    }
    T val = array[index];
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return val;
}

template<typename T>
int ArrayList<T>::get_size() const {
    return size;
}

template<typename T>
bool ArrayList<T>::isEmpty() const {
    return (size == 0);
}

template<typename T>
bool ArrayList<T>::isFull() const {
    return (size == capacity);
}

template<typename T>
void ArrayList<T>::resize(int newCapacity) {
    if (newCapacity < size) {
        cout << "New capacity must be larger than the current size" << endl;
        return;
    }
    T* newArray = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}