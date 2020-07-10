##INCOMPLETE

#include<stdio.h>
#include<time.h>
int min(int a,int b)
{
    return((a<b)?a:b);
}
void prims(int n,int cost[10][10])
{
    int i,j,k,u,v,min,source;

}
int main()
{
    int cost[10][10],n,i,j;
    double clk;
    clock_t starttime,endtime;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix :");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    starttime=clock();
    
    prims(n,cost);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("The time taken is %f\n",clk);
    }