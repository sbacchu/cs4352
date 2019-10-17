#include "buffer.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *producer(void *arg);
void *consumer(void *arg);
pthread_mtx_t mtx = pthread_mtx_INITIALIZER;
pthread_cond_t Buff_Nt_F = pthread_COND_INITIALIZER;
pthread_cond_t Buff_N_Emp = pthread_COND_INITIALIZER;

sem_t sem, emp, full;
sem_t sem_mtx;
pthread_t own_id;
int MAXIUMUM_SLEEP_TIME;
bool var = true;
int main(int argc, char *argv[])
{
    int simulationTime, pthread, cthread;
    char opt[4];
    int i = 0;
    /* generate the mutex lock */
    pthread_mtx_init(&mtx, NULL);
    printf("Provide the time taken to simulate: ");
    scanf("%d", &simulationTime);
    MAXIUMUM_SLEEP_TIME = 10;
    pthread = 5; //no. of producers threads
    cthread = 5; //no. of consumer threads
    /* generate the semaphore */
    pthread_t producer_thread;
    pthread_t consumer_thread;

    //Accept the command line parameters like argv[0],argv[1]
    printf("Lets us start to generate the threads\n");
    for (i = 0; i < pthread; i++)
    {
        pthread_create(&producer_thread, NULL, producer, NULL);
    }
    for (i = 0; i < cthread; i++)
    {
        pthread_create(&consumer_thread, NULL, consumer, NULL);
    }

    sleep(simulationTime);

    for (i = 0; i < pthread; i++)
    {
        pthread_join(producer_thread, NULL);
    }
    for (i = 0; i < cthread; i++)
    {
        pthread_join(consumer_thread, NULL);
    }
    exit(0);
}

void *producer(void *arg)
{

    buffer_item item;
    unsigned int seed = 10;
    while (var)
    {
        sleep(MAXIUMUM_SLEEP_TIME); // used to sleep for 1 sec
        itm = rand_r(&seed) % 100;  // make a random number

        if (buffer_insert_item(itm))
        {
            printf("error");
        }
        else
        {
            own_id = pthread_self();
        }
        printf("The producer %d produced one item\n", own_id);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{

    buffer_item itm;
    while (var)
    {
        sleep(MAXIUMUM_SLEEP_TIME); // used to sleep for 1 second
        if (buff_delete_item(&itm))
        {
            printf("error");
        }
        else
        {
            own_id = pthread_self();
        }
        printf("The consumer %d consumed one item\n", own_id);
    }
    pthread_exit(NULL);
}

intbuffer_add_item(buffer_item itm)
{
    int nxtPrdcd = itm;
    while (var)
    {
        pthread_mtx_lock(&mtx);
        while (counter == BUFF_SZ)
            ;
        buffer[in] = nxtPrdcd;
        input = (in + 1) % BUFF_SZ;
        counter++;
        pthread_mtx_unlock(&mtx);
        pthread_cond_signal(&Buff_N_Emp);
    }
}

int buff_delete_item(buffer_itm *item)
{
    int nextConsumed = *itm;
    while (var)
    {
        pthread_mtx_lock(&mtx);
        while (counter == 0)
            ;
        nextConsumed = buffer[out];
        output = (out + 1) % BUFF_SZ;
        counter--;
        pthread_mtx_unlock(&mtx);
        pthread_cond_signal(&Buff_Nt_F);
    }
}