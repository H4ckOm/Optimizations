#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
int main(){
	struct node* head=NULL;
	struct node* first=NULL;
	struct node* second=NULL;
	struct node* third=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=3;
	head->next=first;
	first->data=7;
	first->next=second;
	second->data=27;
	second->next=third;
	third->data=25;
	third->next=NULL;
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	return 0;
}
