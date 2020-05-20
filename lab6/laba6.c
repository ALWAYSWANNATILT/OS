#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#define SHMNAME "my_shm"

void dochernij();
int main() {
    int rod = getpid();
    printf("PID процесса: %d\n", rod);
    int SIZE = 2048;
    int fd;
    void *memory;
    fd = shm_open(SHMNAME, O_CREAT | O_RDWR, 0777);
    if(fd < 0)
    {
        printf("cant open file\n");
        return -1;
    }
    ftruncate(fd, SIZE);
    memory = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    int pid = fork();
    if (pid == 0) {
        signal(SIGUSR1, dochernij);
        pause();
    } else {
        char chislo[100];
        printf("Введите число: ");
        scanf("%s", chislo);
        strcat(memory, chislo);
        printf("Родителль отправил: %s\n", (char *)memory);
        kill(pid, SIGUSR1);
        waitpid(pid, NULL, 0);
        printf("Родитель принял: %s\n", (char *)memory);
        shm_unlink(SHMNAME);
    }
    return 0;
}

void dochernij() {
    int doch = getpid();
    printf("PID процесса: %d\n", doch); 
    int SIZE = 1000;
    int fd;
    void *memory;
    fd = shm_open(SHMNAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    memory = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    printf("Ребёнок принял: %s\n", (char *)memory);
    int zadannoe = atoi(memory);
    // printf("Оно целое число???????%lu\n", sizeof(zadannoe));
    int first = 1;
    int second = 0;
    int temp = 0; 
    int rezult;
    for(int i = 0; i<1000; i++) // Нахождение последующего числа Фибоначчи
    {
        if(zadannoe < second){
            printf("Следующее число Фибоначчи %d\n", second);
            rezult = second;
            break; 
        }
        first +=second;
        second = first - second;
        // printf(" %d ",second);
    }
    char rez[100];
    sprintf(rez, "%d", rezult);
    strcpy(memory,rez);
    printf("Процесс %d отправил число: %d\n", getpid(), rezult);
    printf("Процесс %d завершается\n", getpid());
}
