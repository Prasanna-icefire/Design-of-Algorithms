#include<stdio.h>
# define size 20

int a[size],subset[size],r_sum,t_sum=0,count=0;

void backtrack(int sum,int i, int t_sum)
{
    if(sum == r_sum)
    {
        count++;
        printf("\nSolution subset : %d\n",count);

        for(int j=0; j<i; j++)
            if(subset[j]==1)
                printf("\t%d",a[j]);
    }

    else if((sum+a[i] <= r_sum) && (sum + t_sum >=r_sum))
    {   
        subset[i] = 0;
        backtrack(sum, i+1, t_sum-a[i]); //not considering element i.

        subset[i] = 1;
        backtrack(sum+a[i], i+1, t_sum-a[i]);  //considering element i.
    }
}

void main()
{
    int n;
    printf("\nEnter no. of elements :");
    scanf("%d",&n);

    if(n>size)
    {
        printf("\nArray size exceeded!");
        return(0);
    }

    printf("\nEnter %d elements in ascending order : ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

        t_sum = t_sum + a[i];
    }

    printf("\nEnter required sum :");
    scanf("%d",&r_sum);

    if(r_sum > t_sum)
        printf("\nSolution subset does not exist.");

    backtrack(0,0,t_sum);// sum so far, index of current element, total sum of remaining elements.

    printf("\nTotal Solution Subsets : %d",count);
}