#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct mbuf{
  long mtype;
  char mtext[100] = "";
}mobj;

int main(){
  int fd, i, key;
  key = ftok("queue", 1);
  fd = msgget(key, IPC_CREAT|0606);
  for(i = 0; i < 5; i++){
    if(msgrcv(fd, &mobj, 101, -2, 0) > 0)
      printf("%s\n", mobj.mtext);
    else{
      printf("not queue\n");
      exit(0);
    }
  }
}
