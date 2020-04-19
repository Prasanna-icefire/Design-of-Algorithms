/*
Design and develop a program in C to find solution for Knapsack problem using dynamic programming. 
Determine the time required to find the solution. 
Repeat the experiment for different values of n and plot a graph of the time taken versus n (n=no of items).
*/
#include<stdio.h>
void knapsack(int n,int v[],int w[],int c)
{   int i=0,a[n],it[n],j;//a carries the ascending ordered value
    //Get the value/weight ratio
    
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
            {   
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
    printf("Following is the data after arrenging in ascending order based on value per weight:\n");
    printf("ITEM_NO         RATE     WEIGHT\n");
    for(i=0;i<n;i++)
    {
        printf("     %d       %f       %d\n",it[i],r[i],w[i]);
    }
    int item[n],correswt[n],k=0;
    float pft[n];

    for(i=n-1;i>=0;i--)
    {
        if(c-w[i]>0)
        {
            item[k]=it[i];
            correswt[k]=w[i];
            pft[k]=v[i];
            c=c-w[i];
            k=k+1;
        }
        else
        {
            
             if(c>0)
            {
                item[k]=it[i];
                correswt[k]=c;
                pft[k]=r[i]*c;
                k=k+1;
                break;
            }
        }
        

    }


    printf("Folllowing table represents what needs to be taken\n");
    float profit=0.0;
    printf("ITEM_NO       WEIGHT     PROFIT\n");
    for(i=0;i<k;i++)
    {
        printf("     %d          %d       %f\n",item[i],correswt[i],pft[i]);
        profit+=pft[i];
    }  
    printf("Net Proft %f \n",profit);

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
/*
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 5
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 1
5 1
4 2
4 1
6 7
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   1
   2        5     |   1
   3        4     |   2
   4        4     |   1
   5        6     |   7
Enter the knapsack bag capacity 10
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     5       0.857143       7
     1       1.000000       1
     3       2.000000       2
     4       4.000000       1
     2       5.000000       1
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     2          1       6.000000
     4          1       4.000000
     3          2       4.000000
     1          1       5.000000
     5          5       4.285714
Net Proft 23.285713 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 1
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          1       0.500000
     2          1       0.333333
     3          1       0.200000
Net Proft 1.033333 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ gcc knapsack.c 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 1
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          1       0.500000
Net Proft 0.500000 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5 
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 2
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          2       1.000000
Net Proft 1.000000 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 3
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          2       1.000000
     2          1       0.333333
Net Proft 1.333333 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3 
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 5
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          2       1.000000
     2          3       1.000000
Net Proft 2.000000 
(base) icefire@icefire-TUF-GAMING-FX504GM-FX80GM:~/Academics/Sem-4/DAA$ ./a.out
Enter the number of items 3
Enter the correspoding values and weights respectively
 VALUES WEIGHTS
1 2 1 3 1 5
You have entered:
ITEM_NO.  VALUES | | WEIGHTS
   1        1     |   2
   2        1     |   3
   3        1     |   5
Enter the knapsack bag capacity 6
Calculating best knapsack items with their respective weights to be carried..
Following is the data after arrenging in ascending order based on value per weight:
ITEM_NO         RATE     WEIGHT
     3       0.200000       5
     2       0.333333       3
     1       0.500000       2
Folllowing table represents what needs to be taken
ITEM_NO       WEIGHT     PROFIT
     1          2       1.000000
     2          3       1.000000
     3          1       0.200000
Net Proft 2.200000 */