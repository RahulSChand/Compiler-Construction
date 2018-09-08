#include "symbol_table.h"
//rahul chand
//2015A7PS0163P

node_ast* create_temp(int* seed);

node_ast* create_label(int* seed);

list_node_tuple* combine_linked_list(list_node_tuple* tmp1,list_node_tuple* tmp2);

list_node_tuple* create_node_tuple(node_ast* var1,node_ast* var2,node_ast* var3,symbol op);

arith* inter_arithemetic(node_ast* curr,int* seed);

arith* inter_print(node_ast* curr,int* seed,symbol_table* curr_table);

arith* inter_read(node_ast* curr,int* seed,symbol_table* curr_table);

arith* inter_bool(node_ast* ,int* ,symbol_table* ,node_ast*,node_ast* );

arith* inter_if(node_ast* curr,int* seed,symbol_table* curr_table);

arith* inter_all(node_ast* curr,int*,symbol_table* curr_table);

arith* inter_main(node_ast* ,symbol_table*);

void print_tuple(node_tuple* tp);


symbol_table* return_main(symbol_table* curr_table,node_ast* root);
