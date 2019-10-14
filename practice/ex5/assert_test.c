 /* 
 * 5장 디버깅과 오류 처리
 * 파일 이름: assert_test.c
 */ 
 
 #include <stdio.h> 
 #include <assert.h> 
 #include <stdlib.h> 

void my_assert(int expression)//assert함수와 동일하게 수행하는 my_assert함수 구현
{
    

    if( expression == 0 )
    {
    	fprintf(stdout, " assert_test : %s : %d: %s Assertion '((num >= 0) && (num <= 100)) failed' \n"
			,__FILE__, __LINE__, __ASSERT_FUNCTION);
    	abort();
    }
}
 void foo(int num) 
 { 

     my_assert(((num >= 0) && (num <= 100)));//my_assert()함수호출 
     printf("foo: num = %d\n", num); 
 } 
 
int main(int argc, char *argv[]) 
 { 
 	int num; 
 
 	if (argc < 2) { 
 	fprintf(stderr,"Usage: assert_test aNumber\n(0 <= aNumber<= 100)\n");
 	exit(1); 
 	} 
 
 	num = atoi(argv[1]); 
 	foo(num); 
 }
