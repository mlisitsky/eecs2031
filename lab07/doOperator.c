#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "doOperator.h"

#include "tokenStack.h"

#include "lexical.h"

struct lexToken *token;

static int op_quit(struct tokenStack *stack);
static int op_print(struct tokenStack *stack);
static int op_dump(struct tokenStack *stack);
static int op_add(struct tokenStack *stack);
/*10 Added Operations */
static int op_diff(struct tokenStack *stack); /*Operation 1*/
static int op_product(struct tokenStack *stack); /*Operation 2*/
static int op_quotient(struct tokenStack *stack);/*Operation 3*/
static int op_gt(struct tokenStack *stack); /*Operation 4*/
static int op_lt(struct tokenStack *stack); /*Operation 5*/
static int op_ge(struct tokenStack *stack); /*Operation 6*/
static int op_le(struct tokenStack *stack); /*Operation 7*/
static int op_eq(struct tokenStack *stack); /*Operation 8*/
static int op_swap(struct tokenStack *stack);/*Operation 9*/
static int op_rem(struct tokenStack *stack);/*Operation 10*/
static int op_rot(struct tokenStack *stack);/*Operation 11*/
static int op_rotmin(struct tokenStack *stack);/*Operation 12*/
static int op_help(struct tokenStack *stack);/*Operation 13*/

static struct operator_struct {
  char *name;
  int (*fn_ptr)(struct tokenStack *);
} ops[] = {
  {"QUIT", op_quit},
  {"PRINT", op_print},
  {"DUMP", op_dump},
  {"+", op_add},
  {"-", op_diff},
  {"*", op_product},
  {"/", op_quotient},
  {"GT", op_gt},
  {"LT", op_lt},
  {"GE", op_ge},
  {"LE", op_le},
  {"EQ", op_eq},
  {"SWAP", op_swap},
  {"MOD", op_rem},
  {"ROT", op_rot},
  {"ROTMINUS", op_rotmin},
  {"HELP", op_help},
  {(char *)NULL, (int(*)(struct tokenStack *)) NULL}
};


/* YOU WRITE THIS */
static int popInt(struct tokenStack *s)
{
  int result = 0;
  if(s->top == 0) {
    fprintf(stderr,"popTokenStack: popping an empty stack, aborting\n");
    exit(1);
  }
  else{
    result =atoi(popTokenStack(s)->symbol);
  }
  return result;
}

/* YOU WRITE THIS */
static void pushInt(struct tokenStack *s, int v)
{
  struct lexToken *token;
  token = allocToken();
  token->kind = LEX_TOKEN_NUMBER;

  sprintf(token->symbol, "%d\n", v);
  pushTokenStack(s,token);

}

int doOperator(struct tokenStack *stack, char *o)
{
  struct operator_struct *op = ops;
  for(op=ops;op->name != (char *)NULL; op++) {
    if(!strcmp(op->name, o))
      return op->fn_ptr(stack);
  }
  return(-1);
}

/*ARGSUSED*/
static int op_quit(struct tokenStack *stack)
{
  printf("[quit]\n");
  exit(0);
  /*NOTREACHED*/
}

static int op_print(struct tokenStack *stack)
{
  struct lexToken *t = popTokenStack(stack);
  printToken(stdout, t);
  freeToken(t);
  return(0);
}

static int op_dump(struct tokenStack *stack)
{
  struct lexToken *t = popTokenStack(stack);
  dumpToken(stdout, t);
  freeToken(t);
  return(0);
}

static int op_add(struct tokenStack *stack)
{
  int v1, v2;
  v1 = popInt(stack);
  v2 = popInt(stack);
  pushInt(stack, v1+v2);
  return(0);
}

static int op_diff(struct tokenStack *stack)
{
  int v1, v2;
  v1 = popInt(stack);
  v2 = popInt(stack);
  pushInt(stack, v2-v1);
  return(0);
}

static int op_product(struct tokenStack *stack)
{
  int v1, v2;
  v1 = popInt(stack);
  v2 = popInt(stack);
  pushInt(stack, v1*v2);
  return(0);
}

static int op_quotient(struct tokenStack *stack)
{
  int v1, v2;
  v1 = popInt(stack);
  v2 = popInt(stack);
  if (v1 == 0)
  {
	printf("Cannot divide by zero! \n");
  }
  else
  {
  	pushInt(stack, v2/v1);
  }
  return(0);
}

static int op_gt(struct tokenStack *stack)
{
  int v1, v2,result;
  v1 = popInt(stack);
  v2 = popInt(stack);
  if (v2 > v1)
     result = 1;
  else
     result = 0;
  pushInt(stack, result);
  return(0);
}

static int op_lt(struct tokenStack *stack)
{
  int v1, v2,result;
  v1 = popInt(stack);
  v2 = popInt(stack);
  if (v2 <  v1)
     result = 1;
  else
     result = 0;
  pushInt(stack, result);
  return(0);
}

static int op_ge(struct tokenStack *stack)
{
  int v1, v2,result;
  v1 = popInt(stack);
  v2 = popInt(stack);
  if (v2 >= v1)
     result = 1;
  else
     result = 0;
  pushInt(stack, result);
  return(0);
}


static int op_le(struct tokenStack *stack)
{
  int v1, v2,result;
  v1 = popInt(stack);
  v2 = popInt(stack);

  if (v2 <=  v1)
     result = 1;
  else
     result = 0;

  pushInt(stack, result);
  return(0);
}

static int op_eq(struct tokenStack *stack)
{
  int v1, v2,result;
  v1 = popInt(stack);
  v2 = popInt(stack);

  if (v1 ==  v2)
     result = 1;
  else
     result = 0;

  pushInt(stack, result);
  return(0);
}


static int op_swap(struct tokenStack *stack)
{
  int v1, v2,temp;
  v1 = popInt(stack);
  temp = v1;

  v2 = popInt(stack);
  v1 = v2;
  v2 = temp;

  pushInt(stack, v2);
  pushInt(stack, v1);

  return(0);
}

static int op_rem(struct tokenStack *stack)
{
  int v1, v2;
  v1 = popInt(stack);
  v2 = popInt(stack);
  pushInt(stack, v1%v2);
  pushInt(stack, v1/v2);
  return(0);
}

static int op_rot(struct tokenStack *stack)
{
  int v1, v2, v3;
  v1 = popInt(stack);
  v2 = popInt(stack);
  v3 = popInt(stack);
  pushInt(stack, v2);
  pushInt(stack, v1);
  pushInt(stack, v3);
  return(0);
}

static int op_rotmin(struct tokenStack *stack)
{
  int v1, v2, v3;
  v1 = popInt(stack);
  v2 = popInt(stack);
  v3 = popInt(stack);
  pushInt(stack, v1);
  pushInt(stack, v3);
  pushInt(stack, v2);
  return(0);
}

static int op_help(struct tokenStack *stack)
{

	printf("HELP (—) - print out all commands plus a line of documentation.\n\n");

	printf("+   (n1 n2 — product) - push n1 + n2 \n");
	printf("-   (n1 n2  — quotient) - push n1 - n2 \n");
	printf("*   (n1 n2 — product) - push n1*n2 \n");
	printf("/   (n1 n2  — quotient) - push n1/n2 \n");
	printf("GT  (n1 n2  —  gt)  -push 1 if n1 > n2 and 0 otherwise \n");
	printf("LT  (n1 n2 — lt) -push 1 if n1 < n2 and 0 otherwise \n");
	printf("GE (n1 n2  —  ge)  -push 1 if n1 >= n2 and 0 otherwise \n");
	printf("LE (n1 n2 — le) -push 1 if n1 <= n2 and 0 otherwise \n");
	printf("EQ (n1 n2 — eq) -push 1 if n1 == n2 and 0 otherwise \n");
	printf("SWAP   (n1 n2 — n2 n1) - swap the order of the top two elements on the stack \n");
	printf("ROT (n1 n2 n3 — n2 n3 n1) - rotate top 3 elements on the stack \n");
	printf("ROTMINUS (n1 n2 n3 — n3 n1 n2) - rotate top 3 elements on the stack \n\n");

	printf("Type PRINT to return answer\n");
	return(0);
}
