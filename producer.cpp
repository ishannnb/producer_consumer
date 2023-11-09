// Name: Ishan Bhandari 
// Date created: Nov 2, 2023

#include <iostream>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pthread.h>

#define SHM_NAME "/shm_example"
#define SEM_FULL_NAME "/sem_full_example"
#define SEM_EMPTY_NAME "/sem_empty_example"

struct Table {
    int items[2];
};

int main() {
    std::cout <<"\n" << std::endl;
    // shm_open() creates or opens a POSIX shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(Table));
    // converts the mapped memory to the Table explicitly
    Table* table = static_cast<Table*>(mmap(0, sizeof(Table), PROT_WRITE, MAP_SHARED, shm_fd, 0));
    sem_t* sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);
    sem_t* sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, 2);

    for (int i = 0; i < 10; ++i) {
        sem_wait(sem_empty);
        table->items[i % 2] = i;
        std::cout << "Produced " <<"(item "<< i <<" )"<< std::endl;
        sleep(1 + rand() % 2);
        sem_post(sem_full);
    }

    sem_close(sem_full);  //close  port
    sem_close(sem_empty); //close  port
    munmap(table, sizeof(Table));
    close(shm_fd); //close shared memory

    return 0;
}