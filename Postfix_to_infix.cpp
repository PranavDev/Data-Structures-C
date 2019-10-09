# include <stdio.h>
# include <string.h>
# include <math.h>
# define max 50

int top,top1;
//int intStack[max];
char charStack[max];
//void push(int symbol);
void push1(char symbol);
//int pop();
char pop1();
void postfix_to_infix();
char postfix[max],infix[max];

int main()
{
	//int top = -1;
	int top1 = -1;
	printf("Enter an Expression in the Postfix Form : ");
	gets(postfix);
	printf("\n");
	printf("The Infix is : ");
	postfix_to_infix();
	return 0;
}

void postfix_to_infix()
{
	int i,temp1,temp2,j=0;
	char output;
	char op,m;
	for(i=0;i<strlen(postfix);i++)
	{
		if((postfix[i]>='a' && postfix[i]<='z')||(postfix[i]>='A' && postfix[i]<='Z'))
		{
			push1(postfix[i]);
		}
		else
		{
			temp1 = pop1();
			temp2 = pop1();
			op = postfix[i];
            switch (op)
            {
            	case '+' : output = temp2 + temp1;
            	           printf("%c %c %c",temp2,op,temp1);
            	           break;
            	           
            	case '-' : output = temp2 - temp1;
            	           printf("%c %c %c",temp2,op,temp1);
            	           break;
            	           
            	case '*' : output = temp2 * temp1;
            	           printf("%c %c %c",temp2,op,temp1);
            	           break;
            	           
            	case '/' : output = temp2 / temp1;
            	           printf("%c %c %c",temp2,op,temp1);
            	           break;
            	           
            	default : printf("Invalid Operator\n");
            	          break;
			}
		}
	}
}

void push1(char symbol)
{
	top1++;
	charStack[top1] = symbol;
}

char pop1()
{
	char x;
	x = charStack[top1];
	top1--; 
	return x;
}

