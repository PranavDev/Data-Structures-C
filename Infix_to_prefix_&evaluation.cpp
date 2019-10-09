# include <stdio.h>
# include <string.h>
# include <math.h>
# define MAX 20

void push1(int symbol);
int pop1();
int top1 = -1;
void infix_to_prefix(char infix[20],char prefix[20]);
void reverse(char infix[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int priority(char symbol);
int eval_pre(char prefix[20]);
int top = -1;
char stack[MAX];
int stack1[MAX];
int main() 
{
	char infix[20],prefix[20],temp;
	
	printf("Enter infix operation: ");
	gets(infix);
	printf("\n");
	
	infix_to_prefix(infix,prefix);
	
	reverse(prefix);
	printf("The Prefix is : ");
	puts((prefix));
	printf("\n\n");
	
	printf(">>Evaluate the Prefix..\n");
	int value = eval_pre(prefix);
	printf("Value of the Expression is : %d",value);
	return 0;
}

void infix_to_prefix(char infix[20],char prefix[20]) 
{
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(infix);
	for (i=0;i<strlen(infix);i++) 
	{
		symbol=infix[i];
		if (isOperator(symbol)==0) 
		{
			prefix[j]=symbol;
			j++;
		} 
		else 
		{
			if (symbol==')') 
			{
				push(symbol);
			} 
			else if(symbol == '(') 
			{
				while (stack[top]!=')') 
				{
					prefix[j] = pop();
					j++;
				}
				pop();
			} 
			else 
			{
				if (priority(stack[top])<=priority(symbol)) 
				{
					push(symbol);
				} 
				else 
				{
					while(priority(stack[top])>=priority(symbol)) 
					{
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
				//end for else
			}
		}
		//end for else
	}
	//end for for
	while (stack[top]!='#') 
	{
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}

// for reverse of the given expression
void reverse(char infix[30])      
{                                 
	int i,j;
	char temp[100];
	for (i=strlen(infix)-1,j=0;i+1!=0;--i,++j) 
	{
		temp[j]=infix[i];
	}
	temp[j]='\0';
	strcpy(infix,temp);
}

char pop() 
{
	char a;
	a=stack[top];
	top--;
	return a;
}

void push(char symbol) 
{
	top++;
	stack[top]=symbol;
}
	
int pop1() 
{
	int a;
	a=stack1[top1];
	top1--;
	return a;
}

void push1(int symbol) 
{
	top1++;
	stack1[top1]=symbol;
}

// returns the value that helps in the precedence 
int priority(char symbol)
{ 
	switch(symbol) 
	{
		case '+':
		case '-':
		        return 2;
		        break;
		case '*':
		case '/':
		        return 4;
		        break;
		case '$':
		case '^':
		        return 6;
		        return 0;
		        break;
		case '#':
		case '(':
		case ')':
		        return 1;
		        break;
	}
}

int isOperator(char symbol) 
{
	switch(symbol) 
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '$':
		case '&':
		case '(':
		case ')':
		        return 1;
		        break;
		default:
		        return 0;   // returns 0 if the symbol is other than given above
	}
}

int eval_pre(char prefix[20])
{
	int i,value,a,b;
	char temp1;
	int temp;

	for(i=strlen(prefix)-1;i>=0;i--)
	{
		if((prefix[i]>='a' && prefix[i]<='z')||(prefix[i]>='A' && prefix[i]<='Z'))
		{
			printf("Value of %c is : ",prefix[i]);
			scanf("%d",&value);
			push1(value);
			printf("\n");
		}
		else
		{
			a=pop1();
			b=pop1();
			temp1=prefix[i];
			switch(temp1)
			{
				case '+' : 
				           temp = a + b;
				           push1(temp);
				           break;
				case '-' :
					       temp = a - b;
					       push1(temp);
					       break;
				case '*' :
					       temp = a * b;
					       push1(temp);
					       break;
			    case '/' :
					       temp = a / b;
					       push1(temp);
					       break;
				case '%' :
					       temp = a % b;
					       push1(temp);
					       break;
				case '^' :
					       temp = pow(a,b);
					       push1(temp);
					       break;
			}
		}
	}
	return temp;
}
