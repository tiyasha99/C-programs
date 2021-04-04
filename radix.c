#include <stdio.h>
int b[100],a[100];
int getmax(int a[],int n)
{
	int max=a[0],i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void countsort(int a[],int n,int pos)
{
	int count[10],i;
	for(i=0;i<10;i++)
	{
		count[i]=0;
		
	}
	for(i=0;i<n;i++)
	{
		++count[(a[i]/pos)%10];
	//	printf("Hi");
	}
	for(i=0;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		b[--count[(a[i]/pos)%10]]=a[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}
void radixsort(int a[],int n)
{
	int pos;
	int max=getmax(a,n);
	 
	for(pos=1;(max/pos)>0;pos=pos*10)
	{
		
		countsort(a,n,pos);
		
	}
}

int main()
{

    int k, num;
    num=0;
    while(num<=0)
    {
    	printf("\nEnter total no. of elements : ");
    	scanf("%d", &num);
    	if(num<=0)
    		printf("\nInvalid number! Please Enter Again.");
    		
	}
    
    //printf("Hi");
   	
    
    printf("\nEnter %d numbers: ", num);

    for (k = 0; k < num; k++)
    {
        scanf("%d", &a[k]);
    }
   
    radixsort(a, num);
    
    printf("\n Sorted array is: ");
    for (k = 0; k < num; k++)
        printf("%d ", a[k]);
    return 0;
}
