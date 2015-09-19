#include<errno.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
        char com[10];
        char path[15]="/bin/";
	int i;
        pid_t pid;

	while(strcmp(com,"exit")!=0){
		printf("> ");
	        gets(com);
		for(i=0;(path[5+i]=com[i])!='\0';i++);
		pid=fork();
		if(pid<0)
			printf("error\n");
		else if(pid==0)
			execlp(path,com,NULL);
		else
		waitpid(pid);
	}

	return 0;

}

