#include<stdio.h>
int w[100],p[100],n,i,cap;
int max(int a, int b)
{
	return (a>b)?a:b;
}
int knapsack(int cap, int w[], int p[], int n)
{
	int i,j,k[n+1][cap+1];
	for(i=0;i<=n;i++){
		for(j=0;j<=cap;j++){
			if(i==0 || w==0)
				k[i][j]=0;
			else if(w[i-1]<=j)
				k[i][j]=max(p[i-1]+k[i-1][j-w[i-1]],k[i-1][j]);
			else
				k[i][j]=k[i-1][j];
		}
	}
	return k[n][cap];
}
int main()
{
	printf("\n Knapsack Problem");
	printf("\n Enter Knapsack Capacity:");
	scanf("%d",&cap);
	printf("Enter number of Item \n");
	scanf("%d",&n);
	printf("Enter Weights \n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter Profits \n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("%d",knapsack(cap,w,p,n));
	return 0;
}

