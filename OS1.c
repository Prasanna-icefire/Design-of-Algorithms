//MultiThreading
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

void* myturn(void * arg)
{
    while(1)
    {   
        sleep(1);
        printf("My Turn\n");
    }
    return NULL;

}
void yourturn()
{
     while(1)
    {
        printf("your Turn\n");
        sleep(2);
        
    }

}
void main()
{   
     
    pthread_t newThread;
    pthread_create(&newThread,NULL,myturn,NULL);
    yourturn();

}
