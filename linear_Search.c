#include<stdio.h>
#include<math.h>
#include<time.h>
void main()
{   
    int i,s,flag=0;
    int n=10;
    int a[n];
    for(i=0;i<n;i++)
    {
      a[i]=rand()%n;
    }
    s=rand()%n;
   //printing elements
    printf("Elements are: \n");
    for(i=0;i<n;i++)
    {
     printf("%d\n",a[i]);
    }
    printf("Element to be searched generated is %d\n",s);
   //linear search starts here
   float st=clock();
    for(i=0;i<n;i++)
    {
        if(s==a[i])
        {
          flag=1;
          break;
        }
    }
    float en=clock();
    //linear search stops here
    if(flag==1)
        printf("Element present!\n");
    else
    {
        printf("Element not found\n");
     }
     printf("Time for execution %f\n",(en-st)/CLOCKS_PER_SEC);

}