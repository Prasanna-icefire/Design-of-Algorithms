#include<stdio.h>
#include<math.h>
#include<time.h>
void main()
{ int i;
  float s=clock();
    for(i=0;i<100000;i++)
    printf("%d\n",rand()%100000);
  float e=clock();
  printf("Start time %f \n",s/CLOCKS_PER_SEC);
  printf("End time %f \n",s/CLOCKS_PER_SEC);
  printf("\nTime taken to generate 10 random nos is %f seconds",(e-s)/CLOCKS_PER_SEC);  
}
