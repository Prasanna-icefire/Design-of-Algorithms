#include<stdio.h>
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