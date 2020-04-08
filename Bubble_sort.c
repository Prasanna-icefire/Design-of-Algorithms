#include<stdio.h>
#include<time.h>
void main()
{  
      int i,j,n=10,a[n],t;
      for(i=0;i<n;i++)//stores the random numbers and prints them simultaneously
    { 
        a[i]=rand()%n;
        printf("%d\n",a[i]);
    }

     //Bubble sort::
     float st=clock();
      for(i=0;i<n;i++)
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
     float en=clock();   
        //printing sorted
    printf("Printing sorted\n");
    for(i=0;i<n;i++)
    { 
        printf("%d\n",a[i]);
    }
    printf("Time to sort \n %f",(en-st)/CLOCKS_PER_SEC);
}