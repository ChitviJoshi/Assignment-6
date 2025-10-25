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
    void display(){
        CircNode* curr=head;
        do{
            cout<<curr->data<<" ";
            curr=curr->next;
        }while(curr!=head);
        cout << head->data;}
        
};

int main(){
    CircList l1;
    l1.insertNode(20,1);
    l1.insertNode(100,2);
    l1.insertNode(40,3);
    l1.insertNode(80,4);
    l1.insertNode(60,5);
    l1.display();
    return 0;
}
