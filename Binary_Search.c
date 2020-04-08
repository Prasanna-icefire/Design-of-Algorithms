#include<stdio.h>
#include<time.h>
void main()
{  
      int i,j,n=10,a[n],s,t,mid,flag=0;
      for(i=0;i<n;i++)//stores the random numbers and prints them simultaneously
    { 
        a[i]=rand()%n;
        printf("%d\n",a[i]);
    }

     //Bubble sort::
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
        //printing sorted
    s=rand()%n;
    printf("Random search element generated is %d\n",s);
    //Starting Binary Search
    int low=0;
    int high=n-1;
    float st=clock();
    while(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==s)
        {
            flag=1;
            break;
        }
        else if(a[mid]>s)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;   
        }
     
    }
    float en=clock();
    if(flag)
        printf("Found!!\n");
    else
    {
        printf("not found\n");
    }
        

    printf("Time to search %f\n",(en-st)/CLOCKS_PER_SEC);
}