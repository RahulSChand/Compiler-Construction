// RAHUL SHIV CHAND
// 2015A7PS0163P
#ifndef var_hash_table
#define var_hash_table

#include "lexerDef.h"
#include<string.h>
#include <stdlib.h>

struct hash_node{
	char token_string[10];
	symbol tk_name;
	struct hash_node* next;
};

struct hash_head{
	struct hash_node* head;
};

typedef struct hash_node hash_node;
typedef struct hash_head hash_head;

void add_node(char* token_string,symbol tk,struct hash_head* table);
hash_node* find_token(char* string,hash_head* );
hash_head* return_table();


#endif
