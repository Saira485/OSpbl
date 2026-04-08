#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t empty, full;
pthread_mutex_t mutex;
int buffer = 0;

void *producer(void *arg) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer++;
    cout << "Produced: " << buffer << endl;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *arg) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    cout << "Consumed: " << buffer << endl;
    buffer--;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
