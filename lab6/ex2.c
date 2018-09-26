#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int len(char * str){
	char* c = str;
	while(*c) ++c;
	return c - str;
}
char* string_one = "OS lab now here.";
char* string_two ="";
int main(){
	int fd[2];
	pipe(fd);
	pid_t p;
	p = fork();

	if ( p == 0 ) {
		close(fd[1]);
		char str[len(string_one)];
		read(fd[0], str, 20);
		printf(str);
		close(fd[0]);
	exit(1);


}
	else if(p > 0){
		close(fd[0]);
		write(fd[1], string_one, 20);
		close(fd[1]);
	exit(1);
	}
return 0;
}