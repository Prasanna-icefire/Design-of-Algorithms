#include<stdio.h>
int rev(int num)
{
    int temp = num;
    int digit,n=0;
    while(temp>0)
    {
        digit=temp%10;
        n = n*10 + digit;
        temp=temp/10;
    }
    return(n);

}
void main()
{
    int i,n,a[100];
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Entered Elements are\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    for(i=0;i<n;i++)
        a[i]=rev(a[i]);
    printf("Reversed Elements are\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);        
}