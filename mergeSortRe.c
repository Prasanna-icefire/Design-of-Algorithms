#include<stdio.h>
void Merge(int b[],int c[],int a[],int n)
{   
    int p=n/2,q=n-p,i=0,j=0,k=0;
    while(i<p && j<q)
    {
        if(b[i]<c[j])
            a[k++]=b[i++];      //Compare the elements of the array which are pointed....Remember comparism happens linearly and Sequentially
                                //between 2 arrays.....only in forward direction
        else
            a[k++]=c[j++];             
    }
    if(i==p)
        for(;j<q;j++)
            a[k++]=c[j];
    else
        for(;i<p;i++)
            a[k++]=b[i];                    
}
void Divide(int a[],int n)
{   
    int p=n/2,q=n-p,i,j;
    int b[p],c[q];
  

    if(n>1)
    {
        for(i=0;i<p;i++)    //Recursively divide the array until there is only one element in each array
            b[i]=a[i];
        
        for(j=0;j<q;j++)
            c[j]=a[j+i]; 
        Divide(b,p);
        Divide(c,q);
        Merge(b,c,a,n);
    }

}
void main()
{
    int i,n,a[20];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Divide(a,n);
    printf("After Arrengement:");
    for(i=0;i<n;i++)
     printf("%d ",a[i]);
}

/*
Enter the number of elements: 5
Enter the elements: 5 4 3 2 1
After Arrengement:1 2 3 4 5 
*/