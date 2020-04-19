/*
Design and develop a program in C to find solution for Knapsack problem using dynamic programming. 
Determine the time required to find the solution. 
Repeat the experiment for different values of n and plot a graph of the time taken versus n (n=no of items).
*/
#include<stdio.h>
void knapsack(int n,int v[],int w[],int c)
{   int i=0,r[n],a[n],it[n],j;//a carries the ascending ordered value
    //Get the value/weight ratio
    for(i=0;i<n;i++)
    {   
        r[i]=v[i]/w[i];
        it[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(r[j]>r[j++])//Arrenged all the items in ascending order of the rate and in the it obtained the values of items
            {
                int temp=it[j];
                it[j]=it[j++];
                it[j++]=temp;
                float t=r[j];
                r[j]=r[j++];
                r[j++]=t;
            }
        }
    }


    while(c>0)
    {
        
    }    
}

void main()
{
    int n,i,c;
    printf("Enter the number of items ");
    scanf("%d",&n);
    int w[n],v[n];
    printf("Enter the correspoding values and weights respectively\n VALUES WEIGHTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&v[i],&w[i]);
    }
    printf("You have entered:\nITEM_NO.  VALUES | | WEIGHTS\n");
        for(i=0;i<n;i++)
    {
        printf("   %d        %d     |   %d\n",i+1,v[i],w[i]);
    }
    printf("Enter the knapsack bag capacity ");
    scanf("%d",&c);
    printf("Calculating best knapsack items with their respective weights to be carried..\n");
    printf("Your expected result for maximising profits \n");
    knapsack(n,v,w,c);
}