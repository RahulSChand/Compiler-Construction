#include "ast.h"


typedef enum{
  VAR_attr,
  FUNCTION_attr,
  FUNCTION_attr_int,
  FUNCTION_attr_str,
  FUNCTION_attr_real
}attribute;

struct fun_param{
  symbol left[10];
  symbol right[10];
  int l;
  int r;
};


struct symbol_table_entry{
  symbol type_var;
  char name_var[20];
  attribute attr_var;
  int offset;
  int size;
  int matrix_row;
  int matrix_col;
  int init;
  struct fun_param* param;
  struct symbol_table* next_table;
  struct symbol_table_entry* next_entry;
};

struct symbol_table{
  struct symbol_table_entry* start;
  struct symbol_table_entry* curr;
  struct symbol_table* parent;
};

struct error_node{
  char var_name[20];
  int error_type;
  int line_number;
  struct error_node* next;
};

typedef struct symbol_table_entry symbol_table_entry;
typedef struct symbol_table symbol_table;
typedef struct error_node error_node;
typedef struct fun_param fun_param;


symbol_table_entry* return_from_table(symbol_table* ,char* ,int );
symbol recursive_check(node_ast* ,error_node* ,symbol_table* ,int ,int,char*);
void recursive_check2(node_ast*,error_node* ,symbol_table* );
error_node* add_error(error_node* ,char* ,int ,int);
symbol_table* create_symbol_table(symbol_table*);
void add_symbol_table(symbol_table* ,symbol ,char* ,attribute ,symbol_table* ,int,int,int);
int find_in_table(symbol_table* ,char* ,int);
int find_in_scope(symbol_table* ,char* ,int);
void symbol_function(node_ast* ,symbol_table* ,error_node* ,int*);
error_node* symbol_function_all(node_ast* );
void semantic_errors(error_node*);
symbol_table_entry* return_from_scope(symbol_table*,char*,int);
void sizeofmatrix(node_ast* ,symbol_table_entry* );
void print_tree(node_ast*);
void print_symbol_table(symbol_table*);
