#include<stdio.h>
#include<time.h>
void insertionsort(int a[],int n)
{                                                // 0 1 2 3 4
    int i,j,ele;                                 // 7 5 1 3 6
    for(i=1;i<n;i++)
    {
        ele=a[i];
        j=i-1;
        while(a[j]>ele && j>=0)
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=ele;
    }    
}
void main()
{   
    int i;
    clock_t start,end;
    int a[5]={5,4,3,2,1};
    insertionsort(a,5);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}




































/*#include<stdio.h>
#include<time.h>
void insertionsort(int a[],int n)
{
    int i,j,ele;
    for(i=1;i<n;i++)
    {
        ele=a[i];
        j=i-1;
        while( j>=0 && a[j]>ele)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=ele;
    }
}
void main()
{   
    int i;
    clock_t start,end;
    int a[5]={5,4,3,2,1};
    insertionsort(a,5);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}
*/