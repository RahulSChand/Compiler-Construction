#ifndef var_lexer
#define var_lexer

#include "lexerDef.h"
#include "hash_table.h"
FILE* removeComments(char* testcasefile,char* outputfile);
void print_state(state_name s);
void convert_to_string(tk_lex* new_token,char* buff1,char* buff2,int buffer_switch,int which_buffer,int start,int forward);
void print_func(symbol tk);
symbol get_token(state_name state);
bool state_final(state_name state);
bool state_final_2(state_name state);
void insert_node(head_list* head_stream,tk_node* node);
head_list* FUNC_MAIN(FILE* fp,head_list* error);

void get_string(symbol token,char* return_string);

tk_lex* recovery_node(head_list* error,int line_no,int mode,char* string);

void fill_lexeme(symbol tk,tk_lex* new_node);

void print_tokens(head_list* h);

void print_errors(head_list* h);





#endif
