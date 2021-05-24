#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


int InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if(L)
	{
		printf("malloc success!/n");
	}else
	{
		printf("malloc failed!/n");
	}

	return 1;
}


LinkList headInsert(LinkList L)
{
	LNode *s ;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	if(L)
	{
		printf("malloc success!\n");
		L->next = NULL;
	}else
	{
		printf("malloc failed!\n");
	}
	scanf("%d",&x);
	while(x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

LinkList taillInsert(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if(L)
	{
		printf("malloc success!\n");
		L->next = NULL;
	}else
	{
		printf("malloc failed!\n");
	}	
	LNode *r = L;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	} 
	r->next = NULL;
	return L;
}
void printList(LinkList L)
{
	if(!L) return;
	LinkList P = L;
	printf("The list numbers : ");
	fflush(stdout);
	while(P->next)
	{
		P = P->next;
		if(P)
		{
		printf("%d ",P->data);
		}
	}
	printf("\n");
}
int main()
{
	LinkList L;
	//headInsert(L);
	L = taillInsert(L);
	printList(L);
	return 0;
}
