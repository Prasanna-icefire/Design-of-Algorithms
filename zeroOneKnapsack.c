#include<stdio.h>
int n;
int max(int a,int b
{
    return((a>b)?a:b);
}
void main()
{
  int i;
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

}