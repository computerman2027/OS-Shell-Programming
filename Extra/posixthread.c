#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *car(void *arg)
{
    int id = *(int *)arg;
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        printf("Car[%d]: No fuel. Waiting...\n", id);
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Car[%d]: Got fuel. Now left: %d\n", id, fuel);
    pthread_mutex_unlock(&mutexFuel);
    return NULL;
}

void *fuel_filling(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 30;
        printf("Filler[%d]: Filled fuel... %d\n", id, fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t th[6];
    int ids[6];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (int i = 0; i < 6; i++)
    {
        ids[i] = i + 1;
        if (i == 4 || i == 5)
            pthread_create(&th[i], NULL, &fuel_filling, &ids[i]);
        else
            pthread_create(&th[i], NULL, &car, &ids[i]);
    }

    for (int i = 0; i < 6; i++)
        pthread_join(th[i], NULL);

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}
