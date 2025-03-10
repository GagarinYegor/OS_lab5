#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct mbuf{
  long mtype;
  char mtext[100] = "";
}mobj={5, "server5"};

int main(){
  int fd, key;
  key = ftok("queue", 1);
  fd = msgget(key, IPC_CREAT|0606);
  for(int i = 0; i < 6; i++){
    if (msgsnd(fd, &mobj, strlen(mobj.mtext)+1, 0) == -1){
        perror("Ошибка отправки сообщения");
        exit(EXIT_FAILURE);
      }
  }
  exit(0);
}
