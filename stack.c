// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "stack.h"



stack* create_empty_stack(){
  stack* s=(stack*)malloc(sizeof(stack));
  s->len=0;
  s->head=NULL;
}

stack_node* create_empty_node(){
  stack_node* tmp=(stack_node*)malloc(sizeof(stack_node));
  return tmp;
}

int push(symbol curr_symbol,stack* stk){
  if (stk->head==NULL){
    stk->head=create_empty_node();
    stk->head->next=NULL;
    stk->head->s=curr_symbol;
    stk->len++;
    return 1;
  }
  stack_node* tmp=create_empty_node();
  tmp->s=curr_symbol;
  tmp->next=stk->head;
  stk->len++;
  stk->head=tmp;
  return 1;
}

int empty(stack* stk){
  if (stk->len==0){return 1;}
  else{return 0;}
}

int top(stack* stk){
  return stk->head->s;
}


int pop(stack* stk){
  stack_node* tmp=stk->head;
  stk->head=stk->head->next;
  stk->len--;
  return 1;
}
