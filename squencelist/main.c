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
		printf("malloc failed!\n");
		return FALSE;
	}else{
		printf("malloc successful!\n");
	}
	L->length = 0;
	L->listsize = InitSize;
	return OK;
}

int ValueList(Sqlist *L)
{
	int length = 0;
	printf("please enter the length of elements:\n");
	scanf("%d",&length);
	printf("you will enter %d elements\n",length);
	for(int i = 0;i<length;i++)
	{
		scanf("%d",&L->elem[i]);
	}
	L->length = length;
	return OK;
}	

int InsertValue(Sqlist* L,int i,ElemType e)
{
	for(int j = L->length;j>=i-1 ;--j)
	{
		L->elem[j] = L->elem[j-1];
	}
	L->elem[i-1] = e;
	L->length+=1;
	int PrintList(Sqlist*);
	PrintList(L);
}
int PrintList(Sqlist *L)
{
	int i = 0;
	printf("the elements are:");
	fflush(stdout);
	while(i<L->length)
	{
		printf("%d ",L->elem[i]);
		i++;
	}
	printf("\n");
	return OK;
}


int main()
{
	Sqlist *sqlist = (Sqlist*)malloc(sizeof(Sqlist));
	InitList(sqlist);
	ValueList(sqlist);
	PrintList(sqlist);
	InsertValue(sqlist,2,4);
	return 0;
}
