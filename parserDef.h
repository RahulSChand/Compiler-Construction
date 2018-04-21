// RAHUL SHIV CHAND
// 2015A7PS0163P
#ifndef var_parserDef
#define var_parserDef

#include "lexer.h"
#include "stack.h"
#include "set.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




struct tuple{
  int l;
  int r;
};

struct table_val{
  int left;
  int right;
};

struct rule{
  symbol* right;
  int len;
};

struct symbol_terminal{
  //Terminal name;
  int first_nikaal;
  struct set* first;
  struct set* follow;
  struct rule* rules;
  int no_rules;
};


struct Grammar{
  struct symbol_terminal* array_rules;
};

struct node_tree{
  symbol sym;
  int is_leaf;
  tk_lex* lex;
  int len;
  int current;
  struct tuple rule_number;
  struct node_tree* parent_ptr;
  struct children_node* head;
};

struct children_node{
  struct node_tree* child;
  struct children_node* next;
};

struct parse_tree{
  struct node_tree* start;
};

struct error_line_head{
  int total;
  struct error_line_node* head;
};
struct error_line_node{
  int line_no;
  struct error_line_node* next;
};


typedef struct symbol_terminal symbol_terminal;
typedef struct rule rule;
typedef struct Grammar grammar;
typedef struct table_val table_val;
typedef struct parse_tree parse_tree;
typedef struct node_tree node_tree;
typedef struct children_node children_node;
typedef struct error_line_head error_line_head;
typedef struct error_line_node error_line_node;
typedef struct rule_number rule_number;


#endif
