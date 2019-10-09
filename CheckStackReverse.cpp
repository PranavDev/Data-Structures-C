#include< stdio.h>
#include< conio.h>
#include< process.h>
# define MAX 50

typedef struct stack
{
  char data [MAX];
  int top;
}stack;
//----------------------------
int empty (stack *p)
{
 if (p-> top  == -1)
 return (1);
 else
        return (0);
}
//----------------------------
int full (stack *p)
{
 if (p->top == MAX-1)
       return (1);
 else
      return (0);
}
//----------------------------
void push (stack *p, char x)
{
   if(!full (p))
 {
 p -> top = p -> top + 1;
 p -> data [p -> top] = x;
 }
   else
 printf ("n stack is full");
}
//-----------------------------------
char pop (stack *p)
{
 char x;
   if (!empty(p))
   {
   x=p->data[p->top];
   p->top = p->top - 1;
   return (x);
   }
   else
   {
   printf ("n stack is empty:");
   return ('');
   }
}
//--------------------------------------
void main ()
{  stack s;
 char ch;
 s.top = -1;
 printf ("nEnter a string:");

 while ((ch=getchar())!='n')
 {
  if(!full(&s))
     {
     push(&s, ch);
     }
  else
    {
    printf ("n stack is full…");
    exit (0);
    }
 }

 printf ("nReversed String : ");
 while (!empty(&s))
 {
 ch = pop(&s);
 printf("%c",ch);
 }
}
