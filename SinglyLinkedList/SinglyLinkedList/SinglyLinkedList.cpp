#include <iostream>
#include <set>
using namespace std;
struct Node {
    int data{};
    Node* next{};
    Node(int data) : data(data){}
};
class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;
public:
    ~LinkedList() {
        while (head) {
            Node* current = head->next;
            delete head;
            head = current;
        }
    }
    void print() {
        for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
       cout << endl;
    }
    void insert_end(int data) {
        Node* cur = new Node(data);
        if (!head) {
            head = tail = cur;
        }
        else{
            tail->next = cur;
            tail = cur;
        }
        length++;
    }
    void insert_front(int data) {
        Node* cur = new Node(data);
        if (!head) {
            head = tail = cur;
        }
        else {
            cur->next = head;
            head = cur;
        }
        length++;
    }
    void delete_node(Node* node) {
        delete node;
        length--;
    }
    void delete_first() {
        if (head) {
            Node* cur = head;
            head = head->next;
            delete_node(cur);
        }
        if (!head) tail = nullptr; 
    }
    void delete_last() {
        if (length <= 1) {
            delete_first();
            return;
        }
        Node* prev = get_nth(length - 1); // Node before tail
        delete_node(tail);
        tail = prev;
        tail->next = nullptr;
    }
    void delete_nth(int node) {
        Node* before_nth = get_nth(node - 1);
        Node* nth = before_nth->next;
        before_nth->next = nth->next;
        bool is_tail = nth == tail;
        if (is_tail) tail = before_nth;
        delete_node(nth);
   }
    Node* get_nth(int n) {
        if (n > length) return nullptr;
        Node* cur = head;
        for (int i = 1; i < n; i++) cur = cur->next;
        return cur;
    }
    int search(int value) {
        int counter = 1;
        for (Node* cur = head; cur; cur = cur->next , counter++) {
            if (cur->data == value) return counter;
        }
        return -1;
    }
    void delete_node_with_key(int value) {
        for (Node* cur = head , *prv = nullptr; cur; prv = cur , cur = cur->next) {
            if (cur->data == value) {
                if (cur == head) {
                    delete_first();
                    return;
                }
                else {
                    prv->next = cur->next;
                    delete_node(cur);
                    return;
                }
            }
        }
    }
    void swap_pairs() {
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->next) {
                swap(cur->data, cur->next->data);
                cur = cur->next;
            }
        }
    }
    void reverseList() {
        Node* temp_tail = tail, * temp_head = head;
        for (Node* cur = head->next, *prv = head; cur;) {
            Node* next = cur->next;
            cur->next = prv;
            prv = cur, cur = next;
        }
        head = temp_tail, tail = temp_head;
        tail->next = nullptr;
    }
    void insert_sorted(int value) {
        if (length == 0 || value <= head->data) {
            insert_front(value);
        }
        else if (value >= tail->data) {
            insert_end(value);
        }
        else {
            Node* item = new Node(value);
            for (Node* cur = head , *prv = nullptr; cur; prv = cur , cur = cur->next) {
                if (value > cur->data)  continue;  
                else {
                    item->next = cur;
                    prv->next = item;
                    length++;
                    return;
                }
            }
        }
    }
    void swap_head_tail() {
        Node* before_tail = get_nth(length - 1);
        tail->next = head->next; // 15 -> 10
        head->next = nullptr; // 6 -> nullptr
        before_tail->next = head; // 8 -> 6
        swap(head, tail);
    }
    void delete_duplicates() {
        set<int>numbers;
        for (Node* cur = head, *prv = nullptr; cur;) {
            if (numbers.count(cur->data)) {
                Node* to_delete = cur;
                prv->next = cur->next;
                if (to_delete == tail) tail = prv;
                cur = cur->next;
                delete_node(to_delete);
            }
            else {
                numbers.insert(cur->data);
                prv = cur, cur = cur->next;
            }
        }
    }
    void remove_last_occurance(int key) {
        int counter = 1 , to_remove;
        for (Node* cur = head; cur; cur = cur->next , counter++) {
            if (cur->data == key) to_remove = counter;
    }
        if (to_remove == 1) {
            delete_first();
            return;
        }
        else if (to_remove == length) {
            delete_last();
            return;
        }
        delete_nth(to_remove);
        return;
    }
    int max_value(Node* cur = nullptr , int max = INT_MIN) {
        if (!cur && max == -1) cur = head;
        else if (!cur) return max;
        if (cur->data > max) max = cur->data;
        max_value(cur->next, max);
    }
};

int main()
{
    LinkedList list;
    list.insert_end(6);
    list.insert_end(26);
    list.insert_end(15);
    list.insert_end(10);
    list.print();
    cout << list.max_value()<<endl;
}

