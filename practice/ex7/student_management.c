/*
* 파일이름: student_management.c
*/
#include <search.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define TABLESIZE 50
struct student {
	char *name;
	int Middle_score;
        int Final_score;
};

char nametable[TABLESIZE * 20];     /* 이름을 저장할 테이블 */
struct student nodetable[TABLESIZE]; /* 저장할 노드 테이블 */
struct student *root = NULL;         /* 루트 노드 */

/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *stu, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("이름 = %s, 중간점수 = %d, 기말점수 = %d\n",
			(*(struct student **)stu)->name,
			(*(struct student **)stu)->Middle_score,
			(*(struct student **)stu)->Final_score);
}

int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct student *)cp1)->name, ((struct student *)cp2)->name);
}

int main()
{
	int stu_num;
	int i = 0;
        int j = 0;
	printf("학생수를 입력하세요\n ");
 	scanf("%d",&stu_num);
	struct student *stu = malloc(sizeof(struct student)*stu_num); //구조체 동적할당
	struct student **ret;
	char *nameptr = nametable;
	
	while (scanf("%s %d %d", nameptr, &stu->Middle_score, &stu->Final_score ) 
								!= EOF && i++ <= TABLESIZE) 
	{
		stu->name = nameptr;
		/* 트리에 넣기 */
		ret = (struct student **) tsearch((void *) stu,(void **) &root, compare);
		printf("\"%s\" 님 ", (*ret)->name);
		if (*ret == stu)
		{
			printf("트리에 추가되었습니다.\n");
                        j++;
		}
		else
			printf("트리에 이미 존재합니다.\n");

		nameptr += strlen(nameptr) + 1;
		stu++;
		if(j == stu_num) 
		{
			break;
		}
	}
	twalk((void *) root, print_node);
 
}

