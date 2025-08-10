#include<iostream>
#include<string>
using namespace std;
template<typename T>
class QueueADT{
    int front,rear,n;
    T *arr;
public:
    QueueADT(int size){
        n=size;
        arr=new T[n];
        front=rear=-1;
    }
    bool isFull(){
        return(rear==n-1);
    }
    bool isEmpty(){
        return(front==-1 && rear==-1);
    }
    void enqueue(T x){
        if(!isFull()){
            rear++;
            arr[rear]=x;
            if (front==-1)
                front++;
        }
        else{
            cout<<"Queue overflow error\n";
        }
    }
    T dequeue(){
        if(!isEmpty()){
            T x=arr[front];
            if(front==rear){
                front=rear=-1;
            }
            else{
                front++;
            }
            return x;
        }
        else{
            cout<<"Queue underflow error\n";
            return T(); //return default value of type T
        }
    }
    void display(){
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
#include<string>
int main(){
    //integer queue
    QueueADT<int>q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<"after enqueue,integer queue is:\n";
    q1.display();
    q1.dequeue();
    cout<<"after dequeue,queue is:\n";
    q1.display();

   //string queue
    QueueADT<string> q2(5);
    q2.enqueue("Inaya");
    q2.enqueue("Inayash");
    q2.enqueue("akhtar");
    cout<<"after enqueue,string queue is:\n";
    q2.display();
    q2.dequeue();
    cout<<"after dequeue,queue is:\n";
    q2.display();

    return 0;
}
