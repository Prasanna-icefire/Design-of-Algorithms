#include<string.h>
#include<stdio.h>
#define MAX 500
int t[MAX];
void main()
{
    char src[100],p[100];
    int pos;
    printf("Enter the text in which pattern is to be searched:\n");
    gets(src);
    printf("Enter the pattern to be searched:\n");
    gets(p);
    shiftable(p);
    pos=horsepool(src,p);
    if(pos>=0)
        printf("The desired pattern was found starting from position %d",pos+1); 
    else 
        printf("The pattern was not found in the given text");
}

void shiftable(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]]=m-1-j;   

}

int horsepool(char src[],char p[])
{
    int i,j,k,m,n;
    n=strlen(src);//Length of String
    m=strlen(p);//Length of Pattern
    i=m-1;
    while(i<n)
    {
        k=0;
        while ((k<m)&&(p[m-1-k]==src[i-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
        {
            i+=t[src[i]];
        }
                
        
    }

}


/*
Enter the text in which pattern is to be searched:
12345678
Enter the pattern to be searched:
67
The desired pattern was found starting from position 6
*/