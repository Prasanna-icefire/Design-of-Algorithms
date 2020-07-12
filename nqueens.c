#include<stdio.h>
#include<math.h>
#define n 4

int x[4];

int place(int k, int i) // kth queen at ith column
{
    for(int j=0; j<k ; j++)
    {
        if(x[j]==i || (abs(k-j)==abs(i-x[j])))
        return 0;
    }

    return 1;
}

void nqueen(int k)
{
    for(int i=0; i<n ; i++)
         if(place(k,i))
        {
            x[k] = i;

             if(k == n-1)
            {
            printf("\nNQueens solution : ");
            for(int j=0; j<n ; j++)
            printf("\t%d",x[j]);
             }

             else
             {
                nqueen(k+1);
             }
        
         }
}

void main()
{
    printf("\nNQueens problem for N = 4 \n");

    nqueen(0);
}