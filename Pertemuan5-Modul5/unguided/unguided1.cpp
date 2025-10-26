#include <iostream>
using namespace std;

struct Node {
    int data; // angka yang dibawa orang itu
    Node* next; // tangan kanan yang pegang orang di sebelahnya
};

void append(Node*& head, int value) {
    Node* nodeBaru = new Node{value, nullptr};
    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    Node* bantu = head;
    while (bantu->next != nullptr)
        bantu = bantu->next;
    bantu->next = nodeBaru;
}

// Fungsi untuk mencari node tengah antara start dan end
Node* getMiddle(Node* start, Node* end) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->data;
        if (p->next) cout << " -> ";
        else cout << " -> NULL\n";
        p = p->next;
    }
}

// Binary Search di linked list yang terurut
Node* binarySearch(Node* head, int key) {
    Node* start = head;
    Node* end = nullptr;
    int langkah = 1;

    cout << "\nProses pencarian:\n";
    while (start != end && start != nullptr) {
        Node* mid = getMiddle(start, end);
        if (!mid) break;

        cout << "Iterasi " << langkah++ << ": Mid = " << mid->data << " (indeks tengah)";

        if (mid->data == key) {
            cout << " -> DITEMUKAN!\n" << endl;
            cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << mid << endl;
            cout << "Node berikutnya: " << (mid->next ? to_string(mid->next->data) : "NULL") << endl;
            cout << "Mencari nilai: 25\n";
            return mid;
        } else if (mid->data < key) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next;
        } else {
            cout << " -> Cari di bagian kiri\n";
            end = mid;
        }

        if (start == end || (start && start->next == end)) break;
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list\n";
    return nullptr;
}


int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    cout << "Mencari nilai: 40\n";
    binarySearch(head, 40);
    cout << endl;

    binarySearch(head, 25);
    return 0;
}
