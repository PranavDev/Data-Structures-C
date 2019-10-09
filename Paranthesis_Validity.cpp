# include<stdio.h>
# include<conio.h>
# include<string.h>
# define max 20

char stack[max];
char exp[max];
int top = -1;
char x;
int value;
char temp;
void Push(char value);
char Pop();

int main()
{
	int i;
	int count = 0;
	printf(">> Enter an Expression to be Checked for Validity >>\n\n");
	gets(exp);
	
	printf("\n");
	
	for(i=0;i<strlen(exp);i++)
	{
		
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		{
			count = count - 1;
			Push(exp[i]);
		}
		
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(top==-1)
			{
				count = count - 1;
			}
			else
			{
				temp = Pop();
				if((exp[i]==')' && temp=='(') || (exp[i]==']' && temp=='[' )|| (exp[i]=='}' && temp=='{'))
				{	
				    printf("%d if111 \n",count);
					count = count + 1;
					printf("%d \n",count);
				}
				else
				{
				    printf("%d else 222 \n",count);
					count = count - 1;
				}
			}
		}
	}
	if(count==0)
	{
		printf("%d \n",count);
		printf("Valid Expression\n\n");
	}
	else
	{
		printf("%d \n",count);
		printf("Invalid Expression\n\n");
	}
	
	return 0;
}


void Push(char value)
{
	if(top==max-1)
	{
		printf("Empty Full\n");
	}
	else
	{
		top++;
		stack[top] = value;
	}
}


char Pop()
{
	if(top==-1)
	{
		printf("Stack Empty\n");
	}
	else
	{
		char x = stack[top];
		top--;
	}
	return x;
}
