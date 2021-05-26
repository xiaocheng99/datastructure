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

LNode *getElem(LinkList L,int i)
{
	int j = 0;
	LNode *p = L;

	while((p->next != NULL) && (j<i))
	{
		p = p->next;
		++j;
	}
	printf("the numer is %d\n",p->data);
	return p;
}

LNode *locateElem(LinkList L,int e)
{
	LNode *p = L->next;
	while(p != NULL && p->data != e)
	{
		p = p->next;
	}

	printf("the numbers is %d\n",p->data);
	return p;
}

int insertValue(LinkList L, int i, int e )
{	
	LinkList p = getElem(L,i-1);
	LNode *s =(LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 1;
}

int deleteValue(LinkList L, int i)
{
	LNode *p = getElem(L,i-1);
	LNode *q = p->next;
	p->next = q->next;
	free(q);

	return 1;
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
	getElem(L,2);
	locateElem(L,2);
	insertValue(L,2,99);
	printList(L);
	deleteValue(L,2);
	printList(L);
	return 0;
}
