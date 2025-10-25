#include <iostream>
using namespace std;

class DoubNode {
public:
    char data;
    DoubNode* prev;
    DoubNode* next;

    DoubNode(char val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubList {
private:
    DoubNode* head;
    DoubNode* tail;

public:
    DoubList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(char val) {
        DoubNode* newNode = new DoubNode(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display() {
        DoubNode* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (head == nullptr) return true; // empty list==palindrome

        DoubNode* left = head;
        DoubNode* right = tail;

        if (tolower(left->data) != tolower(right->data)) return false; {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoubList dl;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    for (char c : s) {
        dl.insert(c);
    }

    cout << "Doubly Linked List: ";
    dl.display();

    if (dl.isPalindrome()) {
        cout << "list is palindrome" << endl;
    } else {
        cout << "list is not palindrome" << endl;
    }

    return 0;
}
