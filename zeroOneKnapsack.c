#include<stdio.h>
int n;
int table[10][10];
int sol[10];
int max(int a,int b)
{
    return((a>b)?a:b);
}
void knapsack(int p[],int w[],int nw)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=nw;j++)
        {
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if(w[i-1]<=j) 
                table[i][j] = max(table[i-1][j],p[i-1]+table[i-1][j-w[i-1]]);
            else
            {
                table[i][j] = table[i-1][j];
            }
                
        }
    }
}
void main()
{
  int i,nw,j;
  int p[10],w[10];
  printf("Enter the number of items ");
  scanf("%d",&n);
  printf("Enter the weights and profits respectively for each of the objects\n");
  for(i=0;i<n;i++)
  {
      printf("Profit : ");
      scanf("%d",&p[i]);
      printf("Weight : ");
      scanf("%d",&w[i]);      
  }
  printf("Enter the max weight capacity of the bag : ");
  scanf("%d",&nw);
  //Here we go ahead and start filling the table
  knapsack(p,w,nw);
  //Printing Table
  printf("Obtained Table:\n");
  for(i=0;i<=n;i++)
    {
        for(j=0;j<=nw;j++)
            printf("%d ",table[i][j]);
        printf("\n");    
    }
  generateSol(n,nw,p);
  
}
void generateSol(int n,int nw,int p[])
{
    int rp = table[n][nw],i,j,flag=1;//Remaining Profit,initial value stored in the last cell
    for(i=n-1;i>=0;i--)//To check the previous row
    {
        for(j=0;j<=nw;j++)//Checked all the elements of the previous row
        {
            if(table[i][j] == rp)
            {
                flag = 0;
                break;
            }
        }
        if(flag==0)
            sol[i]=0;
        else
        {
            sol[i]=1;
            rp = rp - p[i];
        } 
        flag = 1;//Reset flag value       
    }
    printf("Generated Solution : ");
    for(i=0;i<n;i++)
        printf("%d ",sol[i]);
}



/*
Explanation of KnapSack:



Sample Input :
_______________________________________________
|Object Number :              | 1   2   3   4 |
-----------------------------------------------
|Profit of respective OBJECT :| 1   2   5   6 |
-----------------------------------------------
|Weight of respective OBJECT :| 2   3   4   5 |
_______________________________________________

Knapsack capacity = 8                          rm = 8
                                                   rm 8-6 = 2 
TABLE:
                BAG WEIGHT CAPACITY
        OB  0   1   2   3   4   5   6   7   8
Pi  Wi  0   0   0   0   0   0   0   0   0   0
1   2   1   0   0   1   1   1   1   1   1   1   
2   3   2   0   0   1   2   2   3   3   3   3
5   4   3   0   0   1   2   5   5   6   7   7
6   5   4   0   0   1   2   5   6   6   7   8                0    1    0  1

TABLE[i][j]: 
            = 0 when either of i or j = 0

            = max(TABLE[i-1][j]  OR  Profit_of_same_object + The Previous rows profit, Column obtained by j - weight_of_object) 
                    if Wi is less than or equal to Bag Weight Capacity




OBTAIN the 0-1 Array: Demonstrate in the code itself...



Complexity Analysis:
    Each entry of the table requires constant time θ(1) for its computation.
    It takes θ(nw) time to fill (n+1)(w+1) table entries.
    It takes θ(n) time for tracing the solution since tracing process traces the n rows.
    Thus, overall θ(nw) time is taken to solve 0/1 knapsack problem using dynamic programming.





*/