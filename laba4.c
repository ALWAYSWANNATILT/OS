#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
        printf("Процесс 1:\n\tPID - %d,\n\tPPID - %d\n", getpid(), getppid());
        pid_t pid;
	if((pid = fork()) == -1){
           printf("Ошибка! \n");
	}
        else if(pid == 0){
		printf("Порождение процесса 2: \n\tPID - %d, \n\tPPID - %d\n", getpid(), getppid());
           	if((pid = fork()) == -1){
			printf("Ошибка!\n");
		}
		else if(pid == 0){
                        printf("Порождение процесса 4:\n\tPID = %d,\n\tPPID = %d\n", getpid(), getppid());
			if((pid = fork()) == -1){
				printf("Ошибка\n");
			}
                        else if(pid == 0){
                        	printf("Порождение процесса 5:\n\tPID - %d,\n\tPPID - %d\n", getpid(), getppid());
                        	printf("Завершение процесса 5.\n");
                        	exit(0);
                	} 
               		else sleep(2);  
               		if((pid = fork()) == -1){
                   		printf("Ошибка\n");
               		}
               		else if(pid == 0){
                   		printf("Порождение процесса 6:\n\tPID - %d,\n\tPPID - %d\n", getpid(), getppid());
                   		if((pid = fork()) == -1){
                       			printf("Ошибка\n");
                    		}
                    		else if(pid == 0){
                        		printf("Порождение процесса 7:\n\tPID - %d,\n\tPPID - %d\n", getpid(), getppid());
                        		printf("Завершение процесса 7.\n");
                        		exit(0);
                    		}	
                    		else sleep(1);
                    		printf("Завершение процесса 6.\n");		        
                    		exit(0);
                	}
                	else sleep(4);
                	printf("Завершение процесса 4.\n");
                        execl("/bin/pwd","pwd", NULL);
                	exit(0);        
           	}  
           	else sleep(8);
           	printf("Завершение процесса 2.\n");
           	exit(0);
	}
	else sleep(10);
    	if((pid = fork()) == -1){
           printf("Ошибка! \n");
       	}
       	else if(pid == 0){
		printf("Порождение процесса 3:\n\tPID - %d,\n\tPPID - %d\n", getpid(), getppid());
		printf("Завершение процесса 3.\n");
		exit(0);
	}  
        else sleep(10); 
        printf("Завершение процесса 1.\n");
       	exit(0);
       	return 0;
}
