
#include<time.h>
#include<stdio.h>
void heapbottomup(int h[],int n)
{
    int i,heap,v,j,k;
    for(i=n/2;i>0;i--)
    {
        k=i;
        v=h[k];
        heap=0;

        while(!heap && (2*k)<=n)
        {
            j = 2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
            if(v>=h[j])
                heap=1;
            else
            {
                h[k]=h[j];
                k=j;
            }
                        
        }
    h[k]= v;
    }   
}
void heaps(int h[],int n)
{
    int temp,last=n;
    if(n<=1)
        return;
    else{    
    heapbottomup(h,n);
    temp = h[last];
    h[last] = h[1];
    h[1] = temp;
    last--;
    heaps(h,n-1);}
}
void main()
{
    clock_t starts,stops;
    int n,i;
    printf("Enter the number of reumes\n");
    scanf("%d",&n);
    int h[n+1];
    //Adding random values in this array
    printf("Before sort ");
    for(i=1;i<=n;i++)
    {
        h[i]=rand()%100;
        printf("%d ",h[i]);
    }
    
    starts = clock();
    heaps(h,n);
    stops = clock();
    double clk = (double)(stops-starts)/CLOCKS_PER_SEC;
    printf("\nAfter  Sort ");
    for(i=1;i<=n;i++)
    {
        printf("%d ",h[i]);
    }
    printf("\nTime taken %f\n",clk);
}


/*


Output
Enter the number of reumes
5
Before sort 83 86 77 15 93 
After  Sort 15 77 83 86 93 
Time taken 0.000005

Enter the number of reumes
100
Before sort 83 86 77 15 93 35 86 92 49 21 62 27 90 59 63 26 40 26 72 36 11 68 67 29 82 30 62 23 67 35 29 2 22 58 69 67 93 56 11 42 29 73 21 19 84 37 98 24 15 70 13 26 91 80 56 73 62 70 96 81 5 25 84 27 36 5 46 29 13 57 24 95 82 45 14 67 34 64 43 50 87 8 76 78 88 84 3 51 54 99 32 60 76 68 39 12 26 86 94 39 
After  Sort 2 3 5 5 8 11 11 12 13 13 14 15 15 19 21 21 22 23 24 24 25 26 26 26 26 27 27 29 29 29 29 30 32 34 35 35 36 36 37 39 39 40 42 43 45 46 49 50 51 54 56 56 57 58 59 60 62 62 62 63 64 67 67 67 67 68 68 69 70 70 72 73 73 76 76 77 78 80 81 82 82 83 84 84 84 86 86 86 87 88 90 91 92 93 93 94 95 96 98 99 
Time taken 0.000163



*/






/*
#include<stdio.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
void heapbottomup(int h[],int n)
{
    int i,heap,v,j,k;
    for(i=n/2;i>0;i--)
    {
        k=i;
        v=h[k];heap=FALSE;
        while(!heap && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
            if(v>=h[j])
                heap=TRUE;
            else
            {
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}
void heapsort(int h[],int n)
{
    int i,temp,last=n;
    if(n<=1)
        return;
    else
    {
        heapbottomup(h,n);
        temp=h[last];
        h[last]=h[1];
        h[1]=temp;
        last--;
        heapsort(h,n-1);
    }
}
main()
{
int h[20],n,i;
double clk;
clock_t starttime,endtime;
printf("\n Enter the number of resumes\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
h[i]=rand()%100;
printf("\t%d",h[i]);
}
starttime=clock();
heapsort(h,n);endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("\n The ranks in sorted order: \n");
for(i=1;i<=n;i++)
printf("\t%d",h[i]);
printf("\nThe run time is %f\n",clk);
}
*/