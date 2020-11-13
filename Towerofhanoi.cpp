#include<stdio.h>

void toh(int n,char beg,char aux,char end){
	if(n>=1){
		toh(n-1,beg,end,aux);
		printf(" move %d  disk from  %c to %c \n",n,beg,end);
		toh(n-1,aux,beg,end);
		
	}
}

int main()
{ char A,B,C;
	toh(6,'A','B','C');
	
	return 0;
}

