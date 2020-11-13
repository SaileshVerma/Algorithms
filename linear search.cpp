#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	
	
int element,n;
cout<<"enter the size of array : ";
cin>>n;
int arr[n];
cout<<"enter the element of arrays : "<<endl;

for(int i=0;i<n;i++){
	cin>>arr[i];

}


cout<<"enter the element to search = "<<endl;
cin>>element;


int beg=0,end=n-1,loc=-1;

while(beg<=end){
int  mid=(beg+end)/2;
if(arr[mid]==element){
	loc=mid;break;
} else if(arr[mid]<element){
	beg=mid +1;
}else if(arr[mid]>element){
	end=mid-1;
}	
	
	
}

	
cout<<"location of the element is  = "<<loc<<endl;	
	
	
	return 0;
}
