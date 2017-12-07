#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <errno.h>
#define KEY 11100

//for determining errors
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int errcheck(int op) {
  if (op == -1) {
    printf("error: %s\n",strerror(errno));
  }
  return op;
}

//for creating semaphores
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void create(int n) {
  //create only if nonexistant, semaphore permissions
  int sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
  if (sem == -1) {
    printf("Semaphore already exists.\n");
    errcheck(sem);
  } else {
    //set the first sem as n
    int set = errcheck(semctl(sem, 0, SETVAL, n));
    printf("Semaphore created: %d\n", KEY);
    printf("Value set: %d\n", set);
  }
}

//for viewing/removing semaphores; only key is needed
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int access(int flag) {
  int sem = semget(KEY, 0, 0);
  return errcheck( semctl(sem, 0, flag) );
}


int main(int argc, char * argv[]) {
  int val;
  //create; procure int from string using sscanf
  if (!strcmp(argv[1], "-c")) {
     sscanf(argv[2], "%xd\n", &val);
     create(val);
   }
  //remove
   else if (!strcmp(argv[1], "-r")) {
     val = access(IPC_RMID);
     printf("semaphore removed: %d\n", val);
   }
  //view
   else if (!strcmp(argv[1], "-v")) {
     val = access(GETVAL);
     printf("semaphore value: %d\n", val);
   }
}
