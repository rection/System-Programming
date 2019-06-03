#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  pid_t pid;
  
  if((pid = fork()) > 0){
    printf("pid no : %d",getpid());
    execlp("ls","ls","-l",(char *) 0);
  }else if( pid < 0 ){
    printf("Fork duzgun calismadi\n");
    return(34);
  }else if(pid == 0){
    printf("child process no : %d\n",getpid());
    execlp("date","date",(char *) 0);
  }
}
