#include<stdio.h>

//to find the miniumm of the given arry
int min(int arr[],int n,int k){
	int min=arr[k],loc=k;//            {22,-2,3,4,-1}
	for(int i=k+1;i<=n-1;i++){

	if(arr[i]<=min){
		min=arr[i];
		loc=i;
	}
	}
	return loc;
}
int main(){
	
	int arr[]={22,2,55,4,55,6},m;
	int temp;
	for(int i=0;i<=5;i++){
	m=min(arr,6,i);

     	temp=arr[i];
     	arr[i]=arr[m];
     	arr[m]=temp;
     	
     	
}
	for(int i=0;i<=5;i++){
		printf("%d  ",arr[i]);
	}
	
	
	return 0;
}
