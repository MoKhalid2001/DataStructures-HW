#include <iostream>
using namespace std;
class Queue {
private:
	int size{};
	int front{};
	int rear{};
	int added_elements{};
	int* arr{};
public:
	Queue(int size) : size(size) {
		arr = new int[size];
	}
	bool isEmpty() {
		return added_elements == 0;
	}
	bool isFull(){
		return added_elements == size;
	}
	int next(int pos) {
		pos++;
		if (pos == size) pos = 0;
		return pos;
	}
	void enqueu(int val) {
		if (isFull()) return;
		arr[rear] = val;
		rear = next(rear);
		added_elements++;
	}
	void dequeue() {
		if (isEmpty()) return;
		front = next(front);
		added_elements--;
	}
	int top() {
		return arr[front];
	}
	void display(){
		for (int cur = front, step = 1; step <= added_elements; step++, cur = next(cur))
			cout << arr[cur] << " ";
		cout << endl;
	}
};
int main()
{
   
}

