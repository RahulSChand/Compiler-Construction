// RAHUL SHIV CHAND
// 2015A7PS0163P
#ifndef var_set
#define var_set

#include<stdlib.h>
#include<stdio.h>


struct set_node{
  int member;
  struct set_node* next;
};


struct set{
  struct set_node* head;
  int len;
  };

typedef struct set set;
typedef struct set_node set_node;
int is_member(set* s,int to_find);
int add_member(set* s,int add_mem);
int size(set* s);

//int add_everything(set* s,)

set* create_empty_set();

#endif
