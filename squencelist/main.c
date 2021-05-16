#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define InitSize 100

typedef int ElemType;

typedef struct {
	ElemType *elem;
	int listsize;
	int length;
}Sqlist;

int InitList (Sqlist* L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)*InitSize);
	if(!L->elem)
	{
		printf("malloc failed!");
		return FALSE;
	}else{
		printf("malloc successful!");
	}
	L->length = 0;
	L->listsize = InitSize;
	return OK;
}
int main()
{
	Sqlist *sqlist = (Sqlist*)malloc(sizeof(Sqlist));
	InitList(sqlist);

	return 0;
}
