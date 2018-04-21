// RAHUL SHIV CHAND
// 2015A7PS0163P
#ifndef stack_var
#define stack_var

#include<stdio.h>
#include "lexerDef.h"
#include<stdlib.h>
#include<string.h>


struct stack_node{
  symbol s;
  struct stack_node* next;
};

struct stack{
  int len;
  struct stack_node* head;
};


typedef struct stack_node stack_node;
typedef struct stack stack;


int top(stack* stk);
int push(symbol curr_symbol,stack* stk);
int pop(stack* stk);
int empty(stack* stk);
stack* create_empty_stack();
stack_node* create_empty_node();

#endif
