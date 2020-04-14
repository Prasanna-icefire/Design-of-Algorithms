/*Design and develop a program in C to Compute the transitive closure of a given 
 directed graph using Warshall’s algorithm.
 Repeat the experiment for different values of n and 
 plot a graph of the time taken versus n (n=no of nodes).*/

#include<stdio.h>
void main()
{
    int n,i,j,k,a[5][5];
    printf("Enter the order of the directed matrix ");
    scanf("%d",&n);
    printf("Enter the directed matrix\n");
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

    //Start of Warshall's algo

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
            }
        }
    }

    //Complete's Warshall's Algorithm
    //Print resultant
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
Enter the directed matrix
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
Your entered Matrix is 
0 1 0 0 
0 0 0 1 
0 0 0 0 
1 0 1 0 
Resultant Matrix is :
1 1 1 1 
1 1 1 1 
0 0 0 0 
1 1 1 1 
*/