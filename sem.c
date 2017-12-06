#include <sys/type.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 11111

int create_sem(int n){
  int sid = semget(KEY, 4, IPC_CREAT | 600);
  return semctl (sid, 0, SETVAL, n);

}

int get_val(int sid){
  return semctl (sid, 0, GETVAl) ;
}

int rm_sem(int sid){
  return semctl(sid, 0, IPC_RMID);  
}

char ** parse_args(char * s1){
	char ** ret = (char **) calloc (800, sizeof(char*));
	int i = 0;    

	while (s1 && i < 799){
	  char * string = strsep (&s1," ");
	  ret[i] = string;
	  i++;
	}
	ret[i] = NULL;
	return ret;
}

int main(){
  char* input = (char*)  calloc(100 ,sizeof(char));
  fgets(input, 120, stdin);
  
  
}
