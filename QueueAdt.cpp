#include<stdio.h>

#include<malloc.h>


struct queue{
	int cap;
	int rear;
	int front;
	int *arr;
};

struct queue* create(int capi){
	struct queue *q;
	
	q=(struct queue*)malloc(sizeof(struct queue));
	
	q->cap=capi;
	q->arr=(int*)malloc(sizeof(int)*q->cap);
	q->rear=q->front=-1;
	return q;
}

int isfull(struct queue *q){
	if(q->front==0&&q->rear==q->cap-1)
	
		return 1;
	    else
	       if(q->rear==q->front-1)	
	         return 1;
	        else 
	   return 0;
	
}

int isempty(struct queue *q){
	if(q->front==-1)
	return 1;
	else
	return 0;
}

void dequeue(struct queue *q){
	int *temp;
	int i,j;
	q->cap=q->cap*2;
	temp=(int*)malloc(sizeof(int)*q->cap);
	for(i=q->front,j=0;i!=q->rear;j++){
		temp[j]=q->arr[i];
		if(i=q->cap/2-1&&q->rear!=i)
			i=0;
		else
		    i++;
		
	}
      q->arr=temp;
      free(q->arr);	
      q->front=0;
      q->rear=q->cap/2-1;
	
	
}

void insert(struct queue *q,int val){
	if(q->front==-1&&q->rear==-1)
	{q->rear=0;
	q->front=0;
	 q->arr[q->rear]=val;
	 } 
	 else
	 if(isfull(q))
	  {dequeue(q);
	  q->rear=q->rear+1;
	  q->arr[q->rear]=val;
	  }
	  else{q->rear=q->rear+1;
	  q->arr[q->rear]=val;
	  }
	  
	  
}

void disp(struct queue *q){
	for(int i=q->front;i<=q->rear;i++){
		printf("  %d ",q->arr[i]);
	}
}

int main(){
	struct queue *q;
	q=create(5);
	insert(q,1);
	insert(q,1);
	insert(q,1);
	insert(q,1);
	insert(q,1);
	insert(q,1);
	disp(q);
	
	return 0;
}
