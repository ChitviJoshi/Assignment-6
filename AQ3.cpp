#include<iostream>
using namespace std;

class CircNode{
public:
    int data;
    CircNode* next;

    CircNode(int val){
        data=val;
        next=nullptr;
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

class CircList{
private:
    CircNode* head;
    CircNode* tail;
public:
    CircList(){
    head=nullptr;
    tail=nullptr;}
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
    void size(){
        if(head==nullptr){
            cout<<"list is empty"<<endl;
            return;
        }
        CircNode* curr=head;
        int indx=0;
        do{
            indx++;
            curr=curr->next;
        }while(curr!=head);
        cout<<"\nsize of CLL="<<indx<<endl;
    }
    void display(){
        CircNode* curr=head;
        cout << "Circular Linked List: ";
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }while(curr!=head);}
        
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
    void size(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    DoubNode* curr=head;
    int indx=0;
    while(curr!=nullptr){
        indx++;
        curr=curr->next;
    }
    cout<<"size of DLL="<<indx<<endl;
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
    CircList cl;
    DoubList dl;

    cl.insertNode(3,1);
    cl.insertNode(7,2);
    cl.insertNode(2,3);
    cl.insertNode(7,4);
    cl.insertNode(9,5);
    cl.display();
    cl.size();

    dl.insertNode(4,1);
    dl.insertNode(0,2);
    dl.insertNode(1,3);
    dl.display();
    dl.size();



    return 0;
}