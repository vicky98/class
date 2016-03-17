// представяме колите с mutex, шофьорът трябва да е нишка, шофирането трябва да отнема време и трябва да има join. Нз

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int i;

void *driver(void* arg)
{
    while(1)
    {
        // tries to get a car
        // drives car
        // returns car
        
        // wait
        
        //  return car;
      
        printf("%d\n", i);
    }
}

int main()
{
    pthread_t cars[3];
    
    int i = 0;
    
    for (i = 0; i < 3; i++)
    {
        pthread_create(&cars[i], NULL, &driver, &i);
        
        int result = pthread_mutex_trylock(&mutex);
        
        if (result == 0)
        {
            sleep(3);
            
            printf("Driver %d\n", i);
        }
    } 
}
