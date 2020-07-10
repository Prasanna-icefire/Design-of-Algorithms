#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
int partition(int b[],int l,int h)
{
    int pivot = b[l];
    int i = l+1;
    int j = h;
    while(i<=j)
    {
        while(b[i]<pivot)
            i++;
        while(b[j]>pivot)
            j--;
        if(i<j)
            swap(&b[i],&b[j]);        
    }
    swap(&b[l],&b[j]);
    return j;
}


void quicksort(int b[],int l,int h)    
{
    if(l<h)
{    int mid = partition(b,l,h);
    quicksort(b,l,mid-1);
    quicksort(b,mid+1,h);
}}
void main()
{
    int a[5]={5,4,3,2,1};
    quicksort(a,0,4);
    printf("%d %d %d %d %d ",a[0],a[1],a[2],a[3],a[4]);
}
















































/*#include<stdio.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l+1;
    int j=h;
    while(i<=j)
    {
        while(a[i]<pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
void quicksort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=partition(a,l,h);
        quicksort(a,l,mid-1);
        quicksort(a,mid+1,h);
    }
}
void main()
{   
    int i;
    int a[5]={5,4,3,2,1};
    quicksort(a,0,4);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}
*/