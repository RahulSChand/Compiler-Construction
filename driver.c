// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "symbol_table.h"

int main(int argc,char* argv[]){

  int option;

  FILE* fp=fopen("my_grammar.txt","r");
  grammar* G=grammar_from_file(fp);
  first(G);follow(G);
  FILE* fp2;
  option=0;
  head_list* error=(head_list*)malloc(sizeof(head_list));
  head_list* lexer_output;
  error->head=NULL;
  node_tree* root=(node_tree*)malloc(sizeof(node_tree));
  root->sym=mainFunction;
  root->len=0;root->head=NULL;
  root->parent_ptr=NULL;
  tk_node** curr_lex;
  head_list* error2=(head_list*)malloc(sizeof(head_list));
  table_val** table=fill_table(G);
  stack* s=create_empty_stack();
  push(END_MARKER,s);push(mainFunction,s);

  FILE* fp_write=fopen("out.txt","w");

  node_ast* root_ast;
  error_node* e_node;

  int phase2=1;

  while(option!=-1){

  printf("SELECT OPTION, PRESS -1 TO EXIT\n");
  scanf("%d",&option);



  if (option==1){
    fp2=(FILE*)removeComments("c2.txt","clean_code.txt");
    print_file_console(fp2);
  }
  if (option==2){
    FILE* fp3=fopen("clean_code.txt","r");

    if (fp3!=NULL){
      printf("opened file\n");
      printf(" \n");
    }

    lexer_output=FUNC_MAIN(fp3,error);
    print_tokens(lexer_output);

    if (error->head==NULL){
      printf("\n NO LEXICAL ERROS DETECTED...\n");
    }
    else{
      print_errors(error);
    }

    printf("\n END OF LEXER TOKEN PRINTING PROCESS .......... \n");
  }
  if (option==3){

    printf("FIRST AND FOLLOW SET AUTOMATED: USING FUNCTIONS first() and follow()\n");



    curr_lex=(tk_node**)(&(lexer_output->head));
    root=parse(G,s,table,curr_lex,root,error2);
    if (error2->head==NULL){
      printf(" Successfully parsed \n");
    }
    else{
      phase2=0;
      printf(" Parser detected errors \n");
      printf("...Printing errors.....\n");
      print_errors_parser(error2,G);
      printf("----END OF ERRORS-----\n");
    }
  }
  if (option==4){

    printf("\n CREATING PARSE TREE.........\n");

    create_file(root,1,fp_write);

    printf("PARSE TREE Successfully CREATED \n");
  }
  if (option==5){

    if (phase2==1){root_ast=step(root,NULL,NULL);}
    else{

      printf("Cannot continue to semantic phase due to syntatic error in code\n");
      break;
    }




  }
  if (option==6){

    if (phase2==1){e_node=symbol_function_all(root_ast);}
    else{
      printf("Cannot continue to semantic phase due to syntatic error in code\n");
      break;
    }
  }
  if (option==7){
    if(phase2==1){semantic_errors(e_node);}
    else{
      printf("Cannot continue to semantic phase due to syntatic error in code\n");
      break;
    }
  }

}

  return 0;

}
