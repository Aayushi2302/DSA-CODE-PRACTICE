#include<iostream>
using namespace std;

//Node Class --
class node{
	public:
		int data;
		node *next;
		
		//Parametrixe Constructor to create node
		node(int num){
			data = num;
			next = NULL;
		}	
};

//Function 1 :  To create node at end of head node
void insertAtTail(node *&head,int newValue){
	
	node *ptr = head;
	node *newNode = new node(newValue);
	
	if(head->next == NULL)
	head->next = newNode;
	
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
	
}

void display(node *&head){
	node *ptr = head;
	while(ptr != NULL){
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	if(ptr == NULL)
		cout<<"NULL"<<endl;
}

void separate(node *head){

    int even=0,odd=0;
    node *temp = head;
    while(temp != NULL){

        if(temp == head && temp->data%2 == 0){
            even++;
            temp = temp->next;
        }
        
        if(temp == head && temp->data%2 != 0){
            odd++;
            temp = temp->next;
        }
        else if(even >0){
            if(temp->data%2==0)
            {
                while(temp->data%2!=0){
                    
                }
            }
        }
}

}

int main(){

    node *n1;
    n1= new node(1);
    insertAtTail(n1,3);
    insertAtTail(n1,2);
    insertAtTail(n1,5);
    insertAtTail(n1,4);
    insertAtTail(n1,6);
    insertAtTail(n1,7);
    display(n1);


    return 0;
    

}