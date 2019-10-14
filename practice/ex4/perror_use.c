 /* 
 * 5장 디버깅과 오류 처리
 * 파일 이름: perror_use.c
 */ 
 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 #include <errno.h>
 
void my_perror(const char *s) //my_perror 함수 구현
{
	if(s == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{

		printf(" %s : %s\n",  s, strerror (errno));
	}	
}
int main(int argc, char *argv[]) 
 { 
 	FILE *f; 
 
 	if (argc < 2) { 
 	printf("Usage: perror_use nofilename\n"); 
 	exit(1); 
 	} 
 
	 if ( (f = fopen(argv[1], "r")) == NULL ) { 
 		my_perror(NULL); // perror의 기능을 하는 my_perror 함수호출
 		exit(1); 
 	} 
 
 printf("Open a file \"%s\".\n", argv[1]); 
 
 fclose(f); 
 } 

