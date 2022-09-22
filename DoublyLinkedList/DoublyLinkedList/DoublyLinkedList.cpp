#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    Node* next{};
    Node* prev{};
   
    Node(int data) : data(data) {};
};
typedef Node* Lnode;
class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;
public:
    void link(Node* first, Node* second) {
        if (first) first->next = second;
        if (second) second->prev = first;
    }
    void insert_end(int value) {
        Node* item = new Node(value);
        if (!head) head = tail = item;
        else {
            link(tail, item);
            tail = item;
        }
        length++;
    }
    void insert_front(int value) {
        Node* item = new Node(value);
        if (!head) head = tail = item;
        else {
            link(item, head);
            head = item;
        }
        length++;
    }
    void delete_node(Node* node) {
        delete node;
        length--;
    }
    void delete_front() {
        Node* cur = head->next;
        delete_node(head);
        head = cur;
        if (head) head->prev = nullptr;
        else if (!length) tail = nullptr;
    }
    void delete_end() {
        Node* cur = tail->prev;
        delete_node(head);
        tail = cur;
        if (tail) tail->next = nullptr;
        else if (!length) head = nullptr;
    }
    void delete_and_link(Node* node) {
        link(node->prev, node->next);
        delete_node(node);
    }
    void delete_all_nodes_with_key(int key) {
        for (Node* cur = head; cur;) {
            if (cur->data == key) {
                Node* next = cur->next;
                if (cur == head) delete_front();
                else if (cur == tail) delete_end();
                else  delete_and_link(cur);
                cur = next;
            }
            else  cur = cur->next;
        }
    }
    void delete_even_positions() {
        for (Node* cur = head->next; cur; cur = cur->next) {
            Node* nxt = cur->next;
            delete_and_link(cur);
            cur = nxt;
        }
    }
    bool is_paindrome() {
        if (length <= 1) return true;
        int len = length / 2;
        Lnode start = head, end = tail;
        while (len--) {
            if (start->data != end->data) return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
    LinkedList* MergeTowLists(const LinkedList &other) {
        LinkedList* ans = new LinkedList;
        for (Node* cur1 = head, *cur2 = other.head; cur1 || cur2;) {
            if (cur1->data <= cur2->data) {
                //ans->insert_end(cur1->data);
                cur1 = cur1->next;
            }
            else {
                //ans->insert_end(cur2->data);
                cur2 = cur2->next;
            }
        }
        return ans;
    }
    void print() {
        for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
        cout << endl;
    }
};
int main()
{
    LinkedList list1 , list2 ;
    list1.insert_end(1);
    list1.insert_end(2);
    list1.insert_end(4);

    list2.insert_end(1);
    list2.insert_end(3);
    list2.insert_end(4);

    LinkedList* res = list1.MergeTowLists(list2);
    res->print();

    
    
    
}