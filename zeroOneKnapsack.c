#include<stdio.h>
int n;
int table[10][10];
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
  for(i=0;i<=n;i++)
    {
        for(j=0;j<=nw;j++)
            printf("%d ",table[i][j]);
        printf("\n");    
    }
}