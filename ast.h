#include "parser.h"

struct node_ast{
  symbol tk;
  //tuple rule_number;
  int is_leaf;
  int len;
  struct node_ast* parent;
  struct children_ast* children;
  struct node_ast* sibling;
  char entry[20];
  int val_int;
  float val_float;
  int line_number;
  struct arith* struct_arith;
  struct node_ast* node_true;
  struct node_ast* node_false;
  struct node_ast* next;
};

struct arith{
  struct node_ast* node;
  struct list_node_tuple* all_tuple;
};

struct node_tuple{
  struct node_ast* var1;
  symbol op;
  struct node_ast* var2;
  struct node_ast* var3;
};

struct list_node_tuple {

  struct node_tuple* curr_tuple;
  struct list_node_tuple* next;
};



struct children_ast{
  struct node_ast* node;
  struct children_ast* next;
};


typedef struct node_ast node_ast;
typedef struct children_ast children_ast;
typedef struct list_node_tuple list_node_tuple;
typedef struct arith arith;
typedef struct node_tuple node_tuple;

node_ast* create_node_ast(int ,int ,int ,node_ast* ,int );
node_ast* step(node_tree* ,node_ast* ,node_ast* );
