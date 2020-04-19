

//Knapsack prog using pthread of c
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 

void *knapsack(int n,int v[],int w[],int c,void *vargp)
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
    
    return NULL;

}
   
int main() 
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
    
    pthread_t thread_id; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id, NULL, knapsack(n,v,w,c,NULL), NULL); 
    //pthread_join(thread_id, NULL); 
    printf("After Thread\n"); 
    
}