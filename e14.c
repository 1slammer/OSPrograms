#include <stdio.h>
#include <signal.h>
#include <time.h>

static void AlarmHandler(int signo);
static void AlarmHandler2(int signo);
/* Global Variables */
int fd[2]; /* Pointers to the pipe 
	      - fd[0] points on the output of the pipe 
              - fd[1] points on the input of the pipe  
	   */
int starttime;
clock_t start, end;
double cpu_time_used;
char response[255];
int pid;
int ParentPID;
/* Prototype functions */
void ParentCode(void);
void ChildCode(void);

main(){
  
  ParentPID = getpid();

  if (pipe(fd) < 0) {
    printf("Unable to establish a pipe\n");
    exit(0);
  }
    

  pid = fork();
  if (pid < 0) {
    printf("Unable to fork a process\n");
    exit(1);
  }
  if (pid == 0) {
    /* Child Process*/
    ChildCode();
  }
  else {
    /* Parent Process*/
    ParentCode();
  }
}

/* Code run by the Child Process */
void ChildCode(void){
  starttime = time(NULL);
  signal(SIGALRM, AlarmHandler);
  close(fd[0]); /* Child will not read from pipe */

  /* Just wait */
    while (1){
      sleep(60);
      kill(ParentPID,SIGALRM);

  }
  // printf("What is your age? ");
  // scanf("%d",&AgeFromUser);
  // write(fd[1],&AgeFromUser,sizeof(AgeFromUser)); /* write to the pipe */
  // exit(0);
}

/* Code run by the Parent Process */
void ParentCode(void){

  close(fd[1]); /* Parent will not write to the pipe */

  signal(SIGALRM, AlarmHandler2);
  printf("What is the name of the 38th president of the United States? You have 60 seconds to answer.\n");
  gets(response);
  /* Send signal to Child to tell him that user answered */
  kill(pid,SIGALRM);
  int TimeFromPipe;
  int nbcar;

  nbcar = read(fd[0],&TimeFromPipe,sizeof(TimeFromPipe)); /* read from the pipe */

  if (nbcar == sizeof(TimeFromPipe))
    printf("It took: %d seconds to answer.",TimeFromPipe);
  else
    printf("Pipe does not contain a valid time!\n");

  exit(0);
}

static void AlarmHandler(int signo){
  int TimeItTook;
  TimeItTook =  time(NULL) - starttime;
  write(fd[1],&TimeItTook,sizeof(TimeItTook));
  exit(0);
}

static void AlarmHandler2(int signo){
  printf("Time Over!!!\n");
  exit(0);
}






