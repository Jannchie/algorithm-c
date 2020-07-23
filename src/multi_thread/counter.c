// 需要在gcc编译时加上 -pthread
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define P sem_wait
#define V sem_post
#define b &sem_b
#define c &sem_c
sem_t sem_b;
sem_t sem_c;
int m = 1;

void *A(void *p)
{
    for (int i = 0; i < 100; i++)
    {
        P(b);
        m++;
        V(c);
    }
}

void *B(void *p)
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", m);
        V(b);
        P(c);
    }
}

int main()
{

    sem_init(b, 0, 0);
    sem_init(c, 0, 0);

    pthread_t tid0;
    pthread_t tid1;
    pthread_create(&tid0, NULL, A, NULL);
    pthread_create(&tid1, NULL, B, NULL);
    getchar();
    pthread_exit(0);
    return 0;
}
