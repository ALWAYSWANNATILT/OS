#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int main(void) {
	sem_t *sem1 = sem_open("first", 0);
	sem_t *sem2 = sem_open("second", 0);
	sem_t *sem3 = sem_open("asd",0);
	sem_t *sem4 = sem_open("qwe",0);
	sem_t *sem5 = sem_open("zxc",0);

	int a, b;
	int gepot;
	while (1) {
		sem_wait(sem2);
		sem_getvalue(sem3,&a);
		sem_getvalue(sem4,&b);
		int gepot1 = (pow(a, 2)+ pow(b,2));
		gepot = sqrt(gepot1);
		printf ("Hypotenuse: %d\n", gepot);
		for (int i = 0; i < gepot; i++)
		{	
			sem_post(sem5);
		} 
		sem_post(sem1);
	}
	sem_unlink("first");
	sem_unlink("second");
	return 0;
}