# include<stdio.h>
# include<conio.h>
# include<string.h>
# define Max 30

int Element;
int top = -1;
char Stack_Array[Max];

int Full();
int Empty();
void Push(char Element);
char Pop();

int main()
{
	char Stack_String[30];
	int count;
	printf("Enter A String\n");
	scanf("%s",&Stack_String);
	for(count=0;count<strlen(Stack_String);count++)
	{
		Push(Stack_String[count]);
	}
	for(count=0;count<strlen(Stack_String);count++)
	{
		Stack_String[count] = Pop();
	}
	printf("The String In The Reverse Order Is : \n");
	printf("%s",Stack_String);
	return 0;
}

int Full()
{
	if(top==Max-1)
	return (1);
	else
	return (0);
}

int Empty()
{
	if(top==-1)
	return (1);
	else
	return (0);
}

void Push(char Element)
{
	if(Full())
	{
		printf("The Stack is Full\n");
	}
	else
	{
		top = top + 1;
		Stack_Array[top] = Element;
	}
}

char Pop()
{
	if(Empty())
	{
		printf("Underflow\n");
	}
	else
	{
		Element = Stack_Array[top];
		top = top - 1;
	}
	return Element;
}


