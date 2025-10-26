#include <iostream>
using namespace std;

struct Node {
    int data;      // angka yang dibawa orang itu
    Node* next;    // tangan kanan yang pegang orang di sebelahnya
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk mencari node tengah antara start dan end
Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr;
    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Binary Search di linked list yang terurut
Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;

    do {
        Node* mid = getMiddle(start, end);
        if (mid == nullptr) return nullptr;

        if (mid->data == key)
            return mid;
        else if (mid->data < key)
            start = mid->next;
        else
            end = mid;
    } while (end == nullptr || end != start);

    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 90);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}