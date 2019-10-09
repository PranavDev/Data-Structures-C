# include<stdio.h>
# include<string.h>
# include<math.h>
# include<stdlib.h>
# define Max 50

void push(int symbol);
void push1(int symbol);
int pop();
char pop1();
void infix_to_postfix();
int eval_post();
int priority(char symbol);
int isEmpty();
int isEmpty1();
int white_space(char symbol);
char infix[Max],postfix[Max];
int Stack[Max];
char Stack1[Max];
int top,top1;

int main()
{
	int value;
	top = -1;
	top1 = -1;
	printf("Enter the Infix : ");
	gets(infix);
	infix_to_postfix();
	printf("\n");
	printf("Postfix form is : ");
	puts((postfix));
    value = eval_post();
	printf("Value of the Expression is : %d\n",value);
	return 0;
}

void infix_to_postfix()
{
	int i,p=0;
	char next;
	char symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol = infix[i];
		if(!white_space(symbol))
		{
			switch(symbol)
			{
				case '(' : 
				           push(symbol);
				           break;
				case ')' : 
				           while((next = pop())!='(')
				           {
				           	    postfix[p++] = next;
						   }
				           break;
				case '+' :
				case '-' :
				case '*' :
				case '/' :
				case '%' :
				case '^' :
				case '$' :
							while(!isEmpty() && priority(Stack[top]) >= priority(symbol))
						    {
							    postfix[p++] = pop();
							}
				            push(symbol);
				            break;
				
				default : postfix[p++] = symbol;
			}
		}
	}
	while(!isEmpty())
	{
		postfix[p++] = pop();
		postfix[p] = '\0';
	}
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '(' :
		case ')' :
		case '#' :
		           return 0;
		case '+' :
		case '-' :
			       return 1;
		case '*' : 
		case '/' :
		case '%' :
			       return 2;
		case '^' :
		case '$' :
		           return 3;
		default :
			       return 0;
	}
}

void push(int symbol)
{
	if(top>Max-1)
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	Stack[++top] = symbol;
}

void push1(int symbol)
{
	if(top1>Max-1)
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	Stack1[++top1] = symbol;
}

int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return (Stack[top--]);
}

char pop1()
{
	if(isEmpty1())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return (Stack1[top1--]);
}

int white_space(char symbol)
{
	if(symbol==' ' || symbol=='\t')
		return 1;
	else
	    return 0;
}

int eval_post()
{
	int a,b,i,temp,result,value;

	for(i=0;i<strlen(postfix);i++)
	{
		if((postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z'))
		{
			printf("Enter the value of %c : ",postfix[i]);
			scanf("%d",&value);
			push1(value);
			printf("\n");
		}
		else
		{
			a = pop1();
			b = pop1();
			switch(postfix[i])
			{
				case '+' : 
				           temp = b + a;
				           break;
				case '-' :
					       temp = b - a;
					       break;
				case '*' :
					       temp = b * a;
					       break;
			    case '/' :
					       temp = b / a;
					       break;
				case '%' :
					       temp = b % a;
					       break;
				case '^' :
					       temp = pow(b,a);
					       break;
			}
			push1(temp);
		}
	}
	result = pop1();
	return result;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isEmpty1()
{
	if(top1 == -1)
        return 1;
    else
        return 0;
}

