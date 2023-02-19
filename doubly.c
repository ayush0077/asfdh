#include<stdio.h>
#include<stdlib.h>
char garbage_val;
//create node
struct node{
	int info;
	struct node *next,*prev;
};
//initialize head pointer
struct node *head = NULL;
//Funciton to display the linked list
void traverse(){
		struct node *ptr;
	int pos,i;
	if(head == NULL){
		printf("Empty List");
		scanf("%c",&garbage_val);
		
	}else{
		printf("Enter position to traverse to");
		scanf("%d",&pos);
		if(pos == 0){
			ptr = head;
			head = head->next;
			head->prev = NULL;
			printf("node at %d position is %d",pos,ptr->info);
			scanf("%c",&garbage_val);
			free(ptr);
		}else{
			ptr = head;
			for(i=0;i<pos;i++){
				ptr = ptr->next;
				if(ptr == NULL){
					printf("Position not found");
				}
				
			}
			printf("node at %d position is %d",pos,ptr->info);
			scanf("%c",&garbage_val);
		}
	}
}
void display(){
	struct node *ptr;
	ptr = head;
	while(ptr!=NULL){
		printf("%d\n",ptr->info);
		ptr = ptr->next;
	}
}
//Doubly Linked list operations
void insert_begin(){
	int data;
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	newnode->info = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(head == NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}
void insert_end(){
	int data;
	struct node *newnode,*ptr;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	newnode->info = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
	}else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newnode;
		newnode->prev = ptr;
	}
}
void insert_pos(){
	int data,pos,i;
	struct node *newnode,*ptr;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&data);
	printf("Enter position to insert data: ");
	scanf("%d",&pos);
	newnode->info = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	if(pos == 0){
		head = newnode;
	}else{
		ptr = head;
		for(i = 0;i<pos-1;i++){
			ptr = ptr->next;
			if(ptr == NULL){
				printf("position not found");
				scanf("%c",&garbage_val);
			}
		}
		newnode->next = ptr->next;
		newnode->prev = ptr;
		ptr->next->prev = newnode;
		ptr->next = newnode;
	}
	
}
void delete_begin(){
	struct node *ptr;
	if(ptr == NULL){
		printf("Empty list");
		scanf("%c",&garbage_val);
	}else{
		ptr = head;
		head = head->next;
		head->prev = NULL;
		printf("deleted data is %d",ptr->info);
		scanf("%c",&garbage_val);
		free(ptr);
	}
}
void delete_end(){
	struct node *ptr;
	if(ptr == NULL){
		printf("Empty list");
		scanf("%c",&garbage_val);
	}else if(head->next == NULL){
		ptr = head;
		head = NULL;
		printf("Deleted data is %d",ptr->info);
		scanf("%c",&garbage_val);
		free(ptr);
	}else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		printf("Delted data is %d",ptr->info);
		scanf("%c",&garbage_val);
		free(ptr);
	}
}
void delete_pos(){
	struct node *ptr;
	int pos,i;
	if(head == NULL){
		printf("Empty List");
		scanf("%c",&garbage_val);
		
	}else{
		printf("Enter position to delete");
		scanf("%d",&pos);
		if(pos == 0){
			ptr = head;
			head = head->next;
			head->prev = NULL;
			printf("Deleted element is %d",ptr->info);
			scanf("%c",&garbage_val);
			free(ptr);
		}else{
			ptr = head;
			for(i=0;i<pos;i++){
				ptr = ptr->next;
				if(ptr == NULL){
					printf("Position not found");
				}
			}
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			printf("Delete data is : %d",ptr->info);
			free(ptr);
		}
	}
	
}

//Main function

int main(){
	int ch;
	printf("--Doubly Linked List--\n\n\n\n\n");
	while(1){
		printf("Enter choice: ");
		printf("\n1)Insert at start ");
		printf("\n2)Insert at end ");
		printf("\n3)Insert at specified position ");
		printf("\n4)Delete at start ");
		printf("\n5)Delete at end");
		printf("\n6)Delete at specified position ");
		printf("\n7)Traverese:");
		printf("\n8)Display ");
		printf("\n9)End");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			insert_begin();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_pos();
			break;
		case 4:
			delete_begin();
			break;
		case 5:
			delete_end();
			break;
		case 6:
			delete_pos();
			break;
		case 7:
				traverse();
				break;
		case 8:
			display();
			break;
		case 9:
			exit(0);
		default:
			printf("Enter valid choice");
			break;
	}
	}
	
	
}

