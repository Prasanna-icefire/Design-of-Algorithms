/*
Design and develop a program in C to find solution for Knapsack problem using dynamic programming. 
Determine the time required to find the solution. 
Repeat the experiment for different values of n and plot a graph of the time taken versus n (n=no of items).
*/
#include<stdio.h>
void knapsack(int n,int v[],int w[],int c)
{   int i=0,a[n],it[n],j;//a carries the ascending ordered value
    //Get the value/weight ratio
    printf("Value of n %d\n",n);
    float r[n];
    for(i=0;i<n;i++)
    {   
        r[i]=(float)v[i]/w[i];
        it[i]=i+1;
    }
    //printf("Rates calculated respecticely \n");
    //for(i=0;i<n;i++)
      //  printf("%f ",r[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {   
            if(r[j]>r[j+1])//Arrenged all the items in ascending order of the rate and in the it obtained the values of items + corresponding weights taken down
            {   printf("Executing Swapp");
                int temp=it[j];
                it[j]=it[j+1];
                it[j+1]=temp;
                float t=r[j];
                r[j]=r[j+1];
                r[j+1]=t;
                int we=w[j];
                w[j]=w[j+1];
                w[j+1]=we;
            }
        }
    }
    printf("Following is the data after arrenging in ascending order:\n");
    printf("ITEM_NO         RATE     WEIGHT\n");
    for(i=0;i<n;i++)
    {
        printf("     %d       %f       %d\n",it[i],r[i],w[i]);
    }
    int item[n],correswt[n],pft[n],k=0;
    for(i=n-1;i>=0;i--)
    {
        while(c>=w[i])
        {
            item[k]=it[i];
            correswt[k]=w[i];
            c-=correswt[k];
            pft[k]=r[k]*correswt[k];
            k++;
        } 
        
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
    knapsack(n,v,w,c);
}