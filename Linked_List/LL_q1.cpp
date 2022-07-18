#include<iostream>
using namespace std;

class node{
   public:
    int data;
    node *next;

        node(int d){
            data = d;
            next = NULL;
        }
};

node* insertInMiddle(node* head, int x)
{
	node *temp = head;
	node *mid = head;
	node *new_node = new node(x);
	//cout<<new_node->data<<endl;
	while(temp->next != NULL && temp != NULL){
	    temp = temp->next->next;
	    mid = mid->next;
	}
	new_node->next = mid->next;
	mid->next = new_node;
    //cout<<head->data;
	return head;
}
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

void deleteAlt(node *head){
    
    node *ptr = head;
    node *prev =  head;
    int i=1;
    while(ptr != NULL){
        if(i%2 == 0){
            prev->next = ptr->next;
            ptr = ptr->next;
        }
        else{
            prev = ptr;
            ptr = ptr->next;
        }
        i++;
    }

    delete ptr;
}

int middle(node *head){
    int count = 0;
   node *temp = head;
   
   while(temp != NULL){
       count++;
       temp = temp->next;
   }
   
   temp = head;
   
   if(temp == NULL)
    return -1;
   
    else if(count%2 == 0){
       for(int i=1;i<(count/2+1);i++){
           temp = temp->next;
       }
       return temp->data;
   }
   
   else{
       for(int i=1;i<(count+1)/2;i++){
           temp = temp->next;
       }
       return temp->data;
   }
}

int main(){

    node *n1,*temp;
    n1 = new node(1);
    insertAtTail(n1,2);
    insertAtTail(n1,3);
    insertAtTail(n1,4);
    insertAtTail(n1,5);
    insertAtTail(n1,6);
    insertAtTail(n1,7);
    insertAtTail(n1,8);
    display(n1);

    n1 = insertInMiddle(n1,0);
    display(n1);
    /* temp = n1;
    int count=0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout<<"Total Number of Nodes are : "<<count<<endl;

    deleteAlt(n1);
    display(n1);
    cout<<"@@@@"; */
   // cout<<middle(n1)<<endl;


    return 0;
}



