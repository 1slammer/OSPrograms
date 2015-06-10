#include <stdio.h>
#include <signal.h>


/* Global Variables */




main(){
  int pid;
  int ParentPID;
  char response[255];
  
  ParentPID = getpid();
  pid = fork();
  if (pid < 0) {
    printf("Error\n");
    exit(1);
  }
  if (pid == 0) {
    /* Child Process: Ask*/
    printf("What is the name of the 38th president of the United States? You have 60 seconds to answer.\n");
    gets(response);
}
  else {
    int y = 50;
    for(int x = 0; x<6; x++){
    sleep(10);
    printf("You have %d seconds left to answer. \n", y);
    //fflush(stdout);
    y = y-10;
    
    }

    
    /* Just exit */
    
  }
  //kill the child process
  kill(pid, SIGKILL);
  wait(1);
  exit(0);
 
}











