#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
# define size 10
void sort(int a[],int n);
int interpolation(int a[], int low, int high, int val);
void main()
{
	int a[size],i,n,pos,val;
	//clrscr();
	printf("Exp10\tSIA2\tRoll no.39");
	printf("\nEnter the limit of array: ");
	scanf("%d",&n);
	printf("Enter the array elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("\nSorted array is: ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\nEnter value to be searched: ");
	scanf("%d",&val);
	pos=interpolation(a,0,n-1,val);
	if(pos==-1)
	{
		printf("\nElement not found!");
	}else{
		printf("\nElement found at position: %d",pos+1);
	}
	getch();
}
void sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}
int interpolation(int a[], int low, int high, int val)
{
	int mid;
	while(low<=high)
	{
		mid = low+ (high - low)*((val - a[low])/(a[high] - a[low]));
		if(val == a[mid])
			return mid;
		if(val<a[mid])
			high = mid-1;
		else
			low=mid+1;
	}
	return -1;
}
