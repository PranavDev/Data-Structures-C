# include<stdio.h>
# include<conio.h>
# define Max 10000

int Full();
int Empty();
void Push(int Element);
int Pop();
int Stack[Max];
int top = -1;
int Element;


int main()
{
	int Number,n,i;
	int num = Number;
	printf("Enter A No. To Display its Binary\n");
	scanf("%d",&Number);
	while(Number!=0)
	{
		n = Number % 2;
		Push(n);
		Number = Number / 2;
	}
	printf("Displaying The Binary of The Entered Number : \n");
	for(i=Max-1;i>=0;i--)
	{
		Stack[i] = Pop();
		if(Stack[i]==9)
		{
		     break;
		}
		printf("%d ",Stack[i]);
	}
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

void Push(int Element)
{
	if(Full())
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top++;
		Stack[top] = Element;
	}
}

int Pop()
{
	if(Empty())
	{
		printf("\n\nStack Empty\n");
		return 9;
	}
	else
	{
		Element = Stack[top];
		top = top - 1;
		return Element;
	}
}
