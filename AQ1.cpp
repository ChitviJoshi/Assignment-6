#include <iostream>
using namespace std;

class CircNode {
public:
    int data;       
    CircNode* next; 

    CircNode(int val) {
        data = val;
        next = nullptr; 
    }
};

class DoubNode{
public:
    int data;
    DoubNode* prev;
    DoubNode* next;

    DoubNode(int val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};


class CircList {
private:
    CircNode* head;
    CircNode* tail;

public:
    CircList(){
        head=nullptr;
        tail=nullptr; }

    void insertNode(int value, int pos) {
        CircNode* newNode = new CircNode(value);
        if (pos<=0){
            cout<<"invalid pos"<<endl;
            return;
        }
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head; 
            return;
        }

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            tail->next = head; 
            return;
        }

        CircNode* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != head; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        if (curr == tail) {
            tail = newNode;
        }
    }

    void delnode(int val){
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        CircNode* curr = head;
        CircNode* prev = tail; 

        if (head->data == val) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                return;
            }

            head = head->next;
            tail->next = head;
            delete curr;
            return;
        }

        curr = head;
        do {
            if (curr->data == val) {
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev; 
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Value not found in list." << endl;
    }
        void search(int val){
        CircNode* curr=head;
        int indx=1;
        if (head == nullptr) {
        cout << "List is empty." << endl;
        return;}
        do {
            if (curr->data == val) {
                cout << val << " found at node " << indx << endl;
                return;
            }
            curr = curr->next;
            indx++;
        } while (curr != head);
        cout<<"value not found in list\n";
        }
        void display() {
            if (head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }

            CircNode* curr = head;
            cout << "Circular List: ";
            do {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);
            cout << endl;}
};

class DoubList{
private:
    DoubNode* head;
    DoubNode* tail;
public:
    DoubList() {
        head=nullptr;
        tail=nullptr;
    }
    void insertNode(int val, int pos){
    DoubNode* newNode= new DoubNode(val);
    if (pos<=0){
        cout<<"invalid pos"<<endl;
        return;
    }
    if(head==NULL){
        head=newNode;
        tail=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
        return;
    }
    if (pos==1){
        newNode->next=head;
        newNode->prev=NULL;
        head->prev=newNode;
        head=newNode;
        return;
    }
    DoubNode* curr=head;
    for (int i=1; i<pos-1 && curr->next!=head; i++){
        curr=curr->next;
    }
    newNode->next=curr->next;
    curr->next=newNode;
    newNode->prev=curr;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    } else {
        tail = newNode; 
    }
    return;
}

    void delnode(int val){
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        DoubNode* curr = head;

        if (head->data == val) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr; 
            delete curr;
            return;
        }

        while (curr != nullptr && curr->data != val) {
            curr = curr->next;
        }

        if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    void search(int val){
        DoubNode* curr=head;
        int indx=1;
        if (head == nullptr) {
        cout << "List is empty." << endl;
        return;}
        while(curr!=nullptr){
            if(curr->data==val){
                cout<<val<<"found at node"<<indx<<endl;;
                return;
            }
            curr=curr->next;
            indx++;
        }
        cout<<"value not found in list\n";
        }
    void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    DoubNode* curr = head;
    cout << "Doubly Linked List: ";
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    };
    cout << endl;
}
};

int main() {
    cout << "CIRCULAR LL\n" << endl;
    CircList cl;
    cl.insertNode(10, 1);
    cl.insertNode(20, 2);
    cl.insertNode(30, 3);
    cl.insertNode(5, 1);   
    cl.insertNode(25, 3); 
    cout<<"after insertions\n";
    cl.display();
    cl.search(20);  
    cl.search(99);   

    cl.delnode(5);   
    cl.delnode(30); 
    cl.delnode(25); 
    cl.search(10);  
    cl.search(25);   
    cout<<"after deletions\n";
    cl.display();

    cout << "\nDOUBLY LL\n" << endl;
    DoubList dl;
    
    dl.insertNode(10, 1);
    dl.insertNode(20, 2);
    dl.insertNode(30, 3);
    dl.insertNode(5, 1);   
    dl.insertNode(25, 3);  
    cout<<"after insertions\n";
    dl.display();
    dl.search(20); 
    dl.search(50);  

    dl.delnode(5);
    dl.delnode(30);
    dl.delnode(25);
    dl.search(10);   
    dl.search(25);  
    cout<<"after deletions\n";
    dl.display();

    return 0;
}
