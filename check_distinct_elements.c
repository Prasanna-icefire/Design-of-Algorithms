#include<stdio.h>
void main()
{   int i,j,n,a[100],flag=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
       { 
           for(j=i;j<n-1;j++)
            {
                if(a[i]==a[j+1])
                {
                    flag=1;
                    break;
                }
            }
        }
    if(flag)
    printf("Repeated elements present\n");
    else
    {
        printf("Elements Distinct");
    }
        
}