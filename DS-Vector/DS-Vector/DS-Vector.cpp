#include <iostream>
using namespace std;
class Vector {
private: 
    int* arr = nullptr;
    int size = 0; // user size
    int capacity; // Actual size
public:
    Vector(int size) : size(size) {
        capacity = size + 10;
        arr = new int[capacity] {};
    }
    ~Vector() {
        delete [] arr;
        arr = nullptr;
    }
    void print() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
    int get(int idx) {
        return arr[idx];
    }
    void set(int idx, int val) {
        arr[idx] = val;
    }
    int find(int val) {
        for (int i = 0; i < size; i++) if (arr[i] == val) return i;
        return -1;
    }
    void push_back(int val) {
        if (size == capacity) expand_capacity();
        arr[size++] = val;
    }
    void expand_capacity() {
        capacity *= 2;
        int* arr2 = new int[capacity];
        for (int i = 0; i < size; i++) arr2[i] = arr[i];
        swap(arr2, arr);
        delete[] arr2;
    }
    void insert(int idx, int val) {
        if (size + 1 == capacity) expand_capacity();
        for (int i = size - 1; i >= idx; i--) arr[i + 1] = arr[i];
        arr[idx] = val , size++;
    }
    void right_rotation() {
        int temp = arr[size - 1];
        // Shift right : 
        for (int i = size - 1; i >= 0; i--) arr[i] = arr[i - 1];
        arr[0] = temp;
    }
    void left_rotation(int times) {
        if (times) {
            int temp = arr[0];
            // left right : 
            for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
            arr[size - 1] = temp;
            times--;
            left_rotation(times);
        }
    }
    int pop(int idx) {
        int temp = arr[idx];
        //Shifting
        for (int i = idx; i < size - 1; i++) arr[i] = arr[i + 1];
        arr[size - 1] = 0, size--;
        return temp;
    }
};

int main()
{
    Vector v(0);
    v.push_back(4);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.print();
    cout << v.pop(2)<<endl;
    v.print();

   
    
}
