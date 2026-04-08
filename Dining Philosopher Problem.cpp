#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t chopstick[5];

void *philosopher(void *num) {
    int id = *(int *)num;

    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id + 1) % 5]);

    cout << "Philosopher " << id << " is Eating\n";

    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % 5]);
}

int main() {
    pthread_t p[5];
    int id[5];

    for (int i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(p[i], NULL);

    return 0;
}
