#include<iostream>
using namespace std;

class cir_queue{

    int rear = -1,front = -1;
    int *Q;

    public :
        int size;

        void create(){
            Q = new int[size];
        }

        bool isEmpty(){

            if( front == -1 && rear == -1 )   return true;
            else    return false;
        }

        bool isFull(){

            if((front == 0 && rear == size-1)||(rear == front-1))   return true;
            else    return false;
        }

        void enqueue(int value){
            
            if(!isFull()){
                if(rear == -1)  front++;
                Q[++rear] = value;
            }   

            else    cout<<"Queue is already full !!"<<endl;
 
        }

        void dequeue(){

            if(!isEmpty()){

                cout<<endl<<"Element to be deleted : "<<Q[front]<<endl;
                front++;

                if(front > rear){
                    front = rear = -1;
                }
                
            }
            else    cout<<endl<<"Queue is already Empty!!"<<endl;
        }

        void display(){

            if((front>0 && rear>0)  && (front <= rear)){
                cout<<"The elements of queue are : "<<endl;
                int temp = front;
                while(temp<=rear){
                    cout<<Q[temp]<<" ";
                    temp++;
                }
                cout<<endl;
            }
            
        }
};


int main(){

    cir_queue Q1;
    cout<<"Enter the size of queue : ";
    cin>>Q1.size;

    Q1.create();

    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);
    Q1.enqueue(60);
    
    Q1.display();
    
    Q1.dequeue();
    Q1.display();
    
    Q1.dequeue();
    Q1.display();
    
    Q1.dequeue();
    Q1.display();
    
    Q1.dequeue();
    Q1.display();
    
    Q1.dequeue();
    Q1.display();
    
    Q1.dequeue();
   

    return 0;
}