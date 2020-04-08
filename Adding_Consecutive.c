#include<stdio.h>
void main()
{
    int a[100],b[100],res[100],na,nb,i,g;
    printf("Enter the number of elements in array a\n");
    scanf("%d",&na);
    printf("Enter the number of elements in array b\n");
    scanf("%d",&nb);
    g=na;
    printf("Enter the elements of a\n");
    for(i=0;i<na;i++)
        scanf("%d",&a[i]);
    printf("Enter the elements of b\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);
    if (nb>na)
    {
     for(i=na;i<nb;i++)
        a[i]=0;
     g=nb;
    }    
    //add
    printf("sum is\n");
    for(i=0;i<g;i++)
    printf("%d\n",res[i]=a[i]+b[i]);
}