// RAHUL SHIV CHAND
// 2015A7PS0163P
#ifndef var_parser
#define var_parser

#include "parserDef.h"

  /* data */


tk_lex* recovery_node2(head_list* error,int line_no,int mode,char* string,symbol on_stack,symbol stream,grammar* g);


void print_errors_parser(head_list* h,grammar* G);

void print_members(set* s);

grammar* grammar_from_file(FILE* fp);

symbol get_symbol(char* token);

void print_symbol(symbol s);

void add_everything(set* s,set* tmp,int add_null);

void first(grammar* G);

int is_non_terminal(symbol s);

int is_terminal(symbol s);

void follow(grammar* G);

void print_members(set* s);

void print_grammar(grammar* G);

int is_in_first(rule* r,symbol s,int start,int left_symbol,grammar* G);

table_val** fill_table(grammar* G);

children_node* new_children_node();

node_tree* add_node_tree(node_tree* curr_node,symbol s,node_tree* parent);

node_tree* parse(grammar *G,stack* stk,table_val** table,tk_node** curr_lex,node_tree* curr_node,head_list* error);

void isLeafNode(node_tree curr_node);

void print_level(node_tree* root,int lvl);

void create_file(node_tree* root,int is_start,FILE* fp);

void print_file_console(FILE* fp);

#endif
