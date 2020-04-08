#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int b[],int c[],int n)
{
    int p=n/2;
    int q=n-p;
    int i,j,k;
    for(i=0,j=0,k=0;i<p,j<q;)
    {
        if(b[i]<=c[j])
            a[k++]=b[i++];
        else 
            a[k++]=c[j++];
    }        
        while(i<p)
            a[k++]=b[i++];
        while(j<q)
            a[k++]=c[j++];
}
void divide(int a[],int n)
{   if(n>1)
    {int p=n/2;
    int q=n-p;
    int b[10],c[10];
    int i;
    for(i=0;i<p;i++)
        b[i]=a[i];
    for(int j=0;j<q;j++)
        c[j]=a[i+j];

    divide(b,p);
    divide(c,q);
    merge(a,b,c,n);
}}
void main()
{
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    divide(a,10);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);

}