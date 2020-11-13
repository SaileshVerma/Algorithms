#include<stdio.h>
#include<iostream>
using namespace std;

void merge(int arr[],int *L,int *R,int leftcount,int rightcount){
	int i=0,j=0,k=0;
	
	while(i<leftcount&&j<rightcount){
		if(L[i]<=R[j]){
			arr[k]=L[i];i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i < leftcount) arr[k++] = L[i++]
	while(j < rightcount) arr[k++] = R[j++];
	
}


 void mergesort(int arr[],int n){
  if(n<2)return;
int mid=n/2;


int L[mid],R[n-mid];

	for(int i = 0;i<mid;i++) 
	{L[i] = arr[i]; 
	}
	for( int i = mid;i<n;i++)
	{R[i-mid] = arr[i];
	 } 
	
	
	mergesort(L,mid); 
	mergesort(R,n-mid);  
	merge(arr,L,R,mid,n-mid); 
}

int main(){
int n;
cout<<"enter the size of the array : ";
cin>>n;

int arr[n];
cout<<"enter the elements of the arrays : "<<endl;
for(int i=0;i<n;i++){
	cin>>arr[i];
}	
	
mergesort(arr,n);
cout<<"Sorted array is : ";	
for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}	
	

	return 0;
}
