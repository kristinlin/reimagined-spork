#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 11100

 int main(int argc, char * argv[]) {
   if (!strcmp(argv[1], "-c")) {
     int sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL);
     if (shm) {
       down(sem);
       semctl(shm, 0, SETVAL, argv[2]);
       up(sem);
       printf("Semaphore created: %d\n", KEY);
     } else {
       printf("Semaphore already exists.\n");
     }
   }
   else if (!strcmp(argv[1], "
 }

