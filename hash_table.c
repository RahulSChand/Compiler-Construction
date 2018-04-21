// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "hash_table.h"



void add_node(char* token_string,symbol tk,struct hash_head* table){
	int key=0,i=0;
	int l=strlen(token_string);
	for(;i<l;i++){
		key+=token_string[i]-'0';
	}
	key=key%(31);
	//printf("%d\n",key);
	hash_node* tmp=table[key].head;
	hash_node* node=(hash_node*)malloc(sizeof(hash_node));
	strcpy(node->token_string,token_string);
	node->tk_name=tk;
	node->next=NULL;
	if (tmp==NULL){

		table[key].head=node;

		return;
	}
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=node;
	return;
}
hash_node* find_token(char* string,hash_head* table){
	int key=0,i=0;
	int l=strlen(string);
	for(;i<l;i++){
		key+=string[i]-'0';
	}
	key=key%(31);
	//printf("this is --- %d\n",key);
	hash_node* tmp=table[key].head;
	if (tmp==NULL){
		//printf("SAB KUCH NULL");
		return NULL;
	}
	while(tmp!=NULL){
		////printf("check kar raha hai\n");
		if (strcmp(tmp->token_string,string)==0){
			return tmp;
		}
		tmp=tmp->next;
	}
	return NULL;
}




hash_head* return_table(){
	hash_head* h=(hash_head*)malloc(sizeof(hash_head)*31);
	int i=0;
	for(;i<31;i++){
		h[i].head=NULL;
	}
	add_node("end",END,h);
	add_node("if",IF,h);
	add_node("else", ELSE,h);
	add_node("endif", ENDIF,h);
	add_node("string",STRING,h);
	add_node("matrix", MATRIX,h);
	add_node("read", READ,h);
	add_node("print", PRINT,h);
	add_node("int", INT,h);
	add_node("real", REAL,h);
	add_node("_main", MAIN,h);
	add_node("function", FUNCTION,h);
	return h;
}
