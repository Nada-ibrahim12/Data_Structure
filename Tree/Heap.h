
#include <iostream>

template<class T>
class Heap {
private:
    T a[100];
    int size;

    void max_heapify(int i);
    void min_heapify(int i);
    void bubble_up_max(int i);
    void bubble_up_min(int i);

public:
    Heap();
    void insert_max(const T& val);
    void insert_min(const T& val);
    T heap_max() const;
    T heap_extract_max();
    T heap_min() const;
    T heap_extract_min();
    void heap_sort_max();
    void heap_sort_min();
    void build_max_heap();
    void build_min_heap();
    void display() const;
};

template<class T>
Heap<T>::Heap() : size(0) {}

template<class T>
void Heap<T>::max_heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < size && a[l] > a[largest]) {
        largest = l;
    }
    if (r < size && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(a[i], a[largest]);
        max_heapify(largest);
    }
}

template<class T>
void Heap<T>::min_heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < size && a[l] < a[smallest]) {
        smallest = l;
    }
    if (r < size && a[r] < a[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        std::swap(a[i], a[smallest]);
        min_heapify(smallest);
    }
}

template<class T>
void Heap<T>::bubble_up_max(int i) {
    while (i > 0 && a[(i - 1) / 2] < a[i]) {
        std::swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

template<class T>
void Heap<T>::bubble_up_min(int i) {
    while (i > 0 && a[(i - 1) / 2] > a[i]) {
        std::swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

template<class T>
void Heap<T>::insert_max(const T& val) {
    if (size < 100) {
        a[size] = val;
        size++;
        bubble_up_max(size - 1);
    } else {
        std::cout << "The Heap is full" << std::endl;
    }
}

template<class T>
void Heap<T>::insert_min(const T& val) {
    if (size < 100) {
        a[size] = val;
        size++;
        bubble_up_min(size - 1);
    } else {
        std::cout << "The Heap is full" << std::endl;
    }
}

template<class T>
T Heap<T>::heap_max() const {
    if (size > 0) {
        return a[0];
    } else {
        throw std::runtime_error("Heap is empty");
    }
}

template<class T>
T Heap<T>::heap_extract_max() {
    if (size < 1) {
        std::cout << "Heap underflow" << std::endl;
        return T();
    }
    T max = a[0];
    a[0] = a[size - 1];
    size--;
    max_heapify(0);
    return max;
}

template<class T>
T Heap<T>::heap_min() const {
    if (size > 0) {
        return a[0];
    } else {
        throw std::runtime_error("Heap is empty");
    }
}

template<class T>
T Heap<T>::heap_extract_min() {
    if (size < 1) {
        std::cout << "Heap underflow" << std::endl;
        return T();
    }
    T min = a[0];
    a[0] = a[size - 1];
    size--;
    min_heapify(0);
    return min;
}

template<class T>
void Heap<T>::heap_sort_max() {
    int original_size = size;
    build_max_heap();
    for (int i = size - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        size--;
        max_heapify(0);
    }
    size = original_size;
}

template<class T>
void Heap<T>::heap_sort_min() {
    int original_size = size;
    build_min_heap();
    for (int i = size - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        size--;
        min_heapify(0);
    }
    size = original_size;
}

template<class T>
void Heap<T>::build_max_heap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        max_heapify(i);
    }
}

template<class T>
void Heap<T>::build_min_heap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        min_heapify(i);
    }
}

template<class T>
void Heap<T>::display() const {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
