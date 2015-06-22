#include <stdio.h>
#include <signal.h>
#include <time.h>
 #include <sys/types.h>
 #include <sys/wait.h>

static void AlarmHandler(int signo);
//static void AlarmHandler2(int signo);
/* Global Variables */


char response[255];
int pid;
int ParentPID;
int hasCalled = 0;
int pidArr[4];
int tArr[4];
int v = 0;
int *statusPtr;
int parentNum = 0;
int jkl;
int child1, child2, child3, child4;



/* Prototype functions */
void ParentCode(int);
void ChildCode(int);

struct cProcess
{
  /* data */
  int id;
  int xValue;
};

struct cProcess processArr[4];

main(){
  
  ParentPID = getpid();
  signal(SIGALRM, AlarmHandler);

  int count = 0;
  for (count = 0; count< 5; count++){    

  pid = fork();
  //pidArr[x] = pid;
  if (pid < 0) {
    printf("Unable to fork a process\n");
    exit(1);
  }
  if (pid == 0) {
    /* Child Process*/
    ChildCode(count);
  }

  else {
    ParentCode(count);

  }

  
}

}

/* Code run by the Child Process */
void ChildCode(int count){

  struct cProcess cp;
  int childPID = getpid();
  cp.id = childPID;
  /* Just wait */
  v=0;
    while (v==0){
      }
      int x,y,z;
      for(x = 0; x<50000; x++){

        cp.xValue = x;
        processArr[count] = cp;

        for (y=0; y<200; y++){
          for (z = 0; z< 300;z++){

          }
        }
      }
}

/* Code run by the Parent Process */
void ParentCode(int count){

  int y;
  //if(parentNum < 4){
  //  parentNum++;

  //}
  //else {
  //int pq;
  
  //kill(pid, SIGALRM);
  kill(processArr[count].id, SIGALRM);
  printf("%d\n", processArr[count].id);
  sleep(5);

  int c = 0;
  for(c = 0; c < 5; c++)
  {
  kill(processArr[c].id, SIGALRM);
  //kill(pid, SIGALRM);
  }
  printf("here!!!!!!!!!!!!!!!!!!!!!!\n");
  exit(0);
//}
}

static void AlarmHandler(int signo){
  if (hasCalled ==0){
  hasCalled = 1;
  v=1;
}
else {
  int x;
  //for (x = 0; x<5; x++){
  printf("The x-Value for process %d is %d\n", jkl, processArr[jkl].xValue);
  jkl++;
//}
printf("here\n");
//exit(0);


}
  
}







