/*
Design and develop a program in C to find the all pair shortest path for a given graph
using Floyd’s algorithm. Determine the time required to find the solution.
Repeat the experiment for different values of n and plot a graph of the time taken versus n (n=no of nodes).
*/

#include<stdio.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
void main()
{
    int n,i,j,k,a[5][5];
    printf("Enter the order of the directed matrix ");
    scanf("%d",&n);
    printf("Enter the directed matrix with paths, Enter 999 if no path exists\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    
    printf("Your entered Matrix is \n");
    for(i=0;i<n;i++)
     {   for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);    
        }  
        printf("\n"); 
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {   
                if(a[i][k]!=999 && a[k][j]!=999)
                a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
    printf("Resultant Matrix is :\n");
    for(i=0;i<n;i++)
     {   for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);    
        }  
        printf("\n"); 
    }

}

/*
Enter the order of the directed matrix 4
Enter the directed matrix with paths, Enter 999 if no path exists
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0
Your entered Matrix is 
0 3 999 7 
8 0 2 999 
5 999 0 1 
2 999 999 0 
Resultant Matrix is :
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
*/
