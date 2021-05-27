#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 50

typedef int Elemtype;


typedef struct{
	int top;
	Elemtype data[MAXSIZE];
} sqStack;



sqStack* initStack(sqStack *S)
{
	S = (sqStack*)malloc(sizeof(sqStack));
	if(S)
	{
		printf("sqStack malloc successed!\n");
		fflush(stdout);
		S->top = -1;
		return S;
	}else{
		printf("sqStack malloc failed!\n");
		fflush(stdout);
		return 0;
	}
}

bool emptyStack(sqStack* S)
{
	if(S->top == -1)
	   	return 1;
	   else
	   	return 0;
}
bool push(sqStack* S ,Elemtype e)
{
	if(S->top == (MAXSIZE - 1))
		return 0;
	S->top +=1;
	S->data[S->top] = e;
	return 1;
}

bool pop(sqStack* S ,Elemtype *e)
{
	if(emptyStack(S)) return 0;
	*e = S->data[S->top--];
	return 1;
}

bool getTop(sqStack* S,Elemtype *e)
{
	if(emptyStack(S)) return 0;
	*e = S->data[S->top];
	return 1;
}

void printStack(sqStack* S)
{
	
	if(emptyStack(S)) printf("The stack is empty\n") ;
	printf("The stack numbers:");
	fflush(stdout);
	for(int i = 0;i <= S->top; i++)
	{
		printf("%d",S->data[i]);
	}

	printf("\n");

}
int main()
{
	sqStack *S = initStack(S);
	for(int i = 0 ; i<5 ; i++)
	{
		push(S,i);
	}	
	printStack(S);

	for(int i = 0; i<3 ; i++)
	{
		int *e = (int*)malloc(sizeof(int));  
		pop(S,e);
	}

	printStack(S);
}
