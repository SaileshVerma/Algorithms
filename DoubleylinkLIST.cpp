#include<stdio.h>
#include<malloc.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;


struct node* create(){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
return n;

}


void insbeg(int val){
	struct node *n;
n=create();
n->data=val;
n->prev=NULL;
n->next=NULL;
   if(start==NULL){
   	start=n;
   }
   else{
   n->next=start;
   start->prev=n;
   start=n;
   	
   	
   	
   }
	
}

void insend(int val){
	struct node *n,*ptr;
	n=create();
	
	n->data=val;
	n->next=NULL;
	n->prev=NULL;
	
		
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
                           }

	ptr->next=n;     
	n->prev=ptr;
	
}



void print(){
	struct node *ptr;
	ptr=start;
	
	while(ptr!=NULL){
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
	
}


void delbeg(){
	
	struct node *ptr,*temp;
	if(start==NULL){
		printf("list is empty");
	}else
	{
		ptr=start->next;
		ptr->prev=NULL;
		
		start=ptr;
		
		
		
	}
	
	
}


void delend(){
	struct  node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
		
	}
 
	ptr->prev->next=NULL;
	free(ptr);

}

void delpos(int pos){
	struct node *ptr;
	ptr=start;
	while(ptr->data!=pos){
		ptr=ptr->next;
	}
	
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	
}


int main(){
insbeg(1);
insbeg(2);
insend(77);
insbeg(3);
insend(4);
print();
printf("\n");
delpos(77);
//	delend();
print();	

	return 0;
}
