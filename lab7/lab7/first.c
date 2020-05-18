#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	sem_t *sem1 = sem_open("first", O_CREAT, 0777, 1);
	sem_t *sem2 = sem_open("second", O_CREAT, 0777, 0);
	sem_t *sem3 = sem_open("asd", O_CREAT, 0777,0);
	sem_t *sem4 = sem_open("qwe", O_CREAT, 0777, 0);
	sem_t *sem5 = sem_open("zxc", O_CREAT, 0777, 0);
	int a, b;
	int z;
	while (1)
	{
		sem_wait(sem1);
		sem_getvalue(sem5, &z);
		if(z != 0)
		{
			printf("Hypotenuse: %d\n", z);
			for (int i = 0; i < z; i++)
			{
				sem_wait(sem5);
			}
			sem_getvalue(sem3, &a);
			for (int i = 0; i < a; i++)
			{
				sem_wait(sem3);
			}
			sem_getvalue(sem4, &b);
			for (int i = 0; i < b; i++)
			{
				sem_wait(sem4);
			}
		}
		printf("Vvdedite katet1: ");
		scanf("%d", &a);
		
		for(int i = 0; i < a; i++)
		{
			sem_post(sem3);
		}

		printf("Vvdedite katet2: ");
		scanf("%d", &b);
		
		for(int i = 0; i < b; i++)
		{
			sem_post(sem4);
		}
        sem_post(sem2);
	}
    
	sem_unlink("first");
	sem_unlink("second");
	return(0);
}
















	