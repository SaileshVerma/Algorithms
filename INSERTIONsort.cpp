#include<stdio.h>

//inserton sort
void sort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){  //{5,2,23,3,441,1,5}
		temp=arr[i];   // 2,5,23,3,441,1,5
		              //                        temp=3,j=23
		                                    
	  for(j=i-1;j>=0&&arr[j]>temp;j--){
	  	 
		    arr[j+1]=arr[j];
	  	  
	  }
	  arr[j+1]=temp;	
	
	}
	
	 
	
	
	
	
	
	
}
int main(){
	int arr[]={5,2,23,3,441,1,55};
	
	sort(arr,7);
	for(int i=0;i<7;i++){
	
	printf("%d ",arr[i]);
}
	
	return 0;
}
