
/*
* 동적할당 두 행렬의 합 구하기
* 파일이름 : testmalloc.c
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int Row,Col;
        int i,j;
        int **ptr1=NULL,**ptr2=NULL,**sum=NULL;
	printf("행렬 크기 입력 \n");
        printf("행: "); 
	scanf("%d",&Row);
	printf("열: ");
	scanf("%d",&Col);


	/* 사용자가 입력한 수만큼 메모리 할당 */ 
	ptr1 = (int**)malloc(sizeof(int*)*Row);
        ptr2 = (int**)malloc(sizeof(int*)*Row);
        sum  = (int**)malloc(sizeof(int*)*Row);

	/* 메모리 할당에 실패할 경우 */ 
	if (ptr1 == NULL || ptr2 == NULL)
	{ 
		printf("메모리를 할당하지 못했습니다."); 
		exit(-1); 
	}
        
        printf("----첫번째 행렬값 %d 개 입력-----\n",Row*Col);
        //첫번째 행렬 입력받음
	for( i = 0; i < Row; i++ )
	{	
                ptr1[i] =(int*)malloc(sizeof(int)*Col);
		for(j=0; j<Col; j++)
		{
 
			scanf("%d", &ptr1[i][j]);
		}
	}

        printf("----두번째 행렬값 %d 개 입력-----\n",Row*Col);
        //두번째 행렬 입력받음
	for( i = 0; i < Row; i++ )
	{	
                ptr2[i] =(int*)malloc(sizeof(int)*Col);
		for(j=0; j<Col; j++)
		{
 
			scanf("%d", &ptr2[i][j]);
		}
	}

       printf("----두 행렬의 합 -----\n");
       //합
       for(i=0; i<Row; i++)
       {
		sum[i]=(int*)malloc(sizeof(int)*Col);
        	for(j=0; j < Col; j++)
        	{
            		sum[i][j]= ptr1[i][j] + ptr2[i][j];
            		printf("sum[%d][%d]=%2d \n", i, j, sum[i][j]);
        	}
	}
        printf("------------------\n");
        for(i=0; i<Row; ++i)
  	 {
        	for(j=0; j<Col; ++j)
		{	 
			printf(" %d ", sum[i][j]);
		}
        	printf("\n");
   	}
	printf("\n");
       //할당해제
         for(i=0;i<Row;i++)
	{
		free(ptr1[i]);
                free(ptr2[i]);
                free(sum[i]);  
	} 
	free((int *)ptr1);
	free((int *)ptr2);
        free((int *)sum);

}
