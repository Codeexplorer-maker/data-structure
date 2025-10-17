#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next, *prev;
    
        Node(int el, Node *p, Node*n)
        {
            data = el;
            next = n;
            prev = p;
        }
};

class DLL_ADT{
    Node*head, *tail;
    public:
        DLL_ADT(){
            head = NULL;
            tail = NULL;
        }
        void addtohead(int x);
        bool isempty();
        int removefromhead();
        void addtotail(int x);
        void removefromtail();
        void display();
};

void DLL_ADT::addtohead(int x){
    Node* N = new Node(x, NULL,NULL);
    if(isempty()){
        head = tail =  N;
    }
    else{
        head -> prev = N;
        N-> next = head;
        head = N;
    }
};

bool DLL_ADT::isempty(){
    if(head == NULL && tail == NULL){
        return true;
    }
    else{
        return false;
    }
};

int DLL_ADT::removefromhead(){
    if(!isempty()){
        Node*temp = head;
        if(head -> next != NULL){
            head->next->prev = NULL;
        }
        else{
            tail = NULL;
            head = head -> next;
        }
        delete temp;
    }
    else{
        cout<<"Underflow Error";
    }
};

void DLL_ADT::addtotail(int x){
    Node*N = new Node(x, NULL, NULL);
    if(!isempty()){
        tail -> next = N;
        N -> prev = tail;
        tail = N;
    }
    else{
        head = tail = N;
    }
};

void DLL_ADT::removefromtail(){
    if(!isempty()){
        Node*temp = tail;
        if(tail -> prev != NULL){
            tail -> prev -> next = NULL;
        }
        else{
            head = NULL;
            tail = tail -> prev;
        }
        delete temp;
    }
    else{
        cout<<"Underflow Error";
    }
}

void DLL_ADT::display(){
    if(!isempty()){
        Node*temp = head;
        while(temp != NULL){
            cout<<temp-> data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    DLL_ADT list;
    int choice, value;

    do{
        cout<<"\n...Doubly LinkedList Menu...\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at Last\n";
        cout<<"3. Remove from beginning\n";
        cout<<"4. Remove from Last\n";
        cout<<"5. Display List\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the value to insert: ";
                cin>>value;
                list.addtohead(value);
                break;

            case 2:
                cout<<"Enter the value to insert: ";
                cin>>value;
                list.addtotail(value);
                break;

            case 3:
                list.removefromhead();
                break;

            case 4:
                list.removefromtail();
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid Choice! Try again.\n";
        }
    } while(choice != 6);
    return 0;
}