// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "codeGen.h"

int ast_total=0;

int main(int argc,char* argv[]){

  int option;

  printf("LEVEL 3: AST/SEMANTIC RULES/INTERMEDIATE CODE/CODE GENERATION MODEULS WORK\n");



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
  symbol_table* n;
  node_ast* root_ast;
  error_node* e_node;

  int parse_treechild=0;
  int compressionsize=0;
  option=100;
  int phase2=1;
  all_return* ret;
  while(option!=0){

  printf("SELECT OPTION, PRESS 0 TO EXIT\n");
  scanf("%d",&option);



  if (option==1){
    fp2=(FILE*)removeComments(argv[1],"clean_code.txt");
    print_file_console(fp2);

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


  if (option==2){

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



    printf("\n CREATING PARSE TREE.........\n");

    create_file(root,1,fp_write);



    printf("PARSE TREE Successfully CREATED \n");
  }
  if (option==3){

    if (phase2==1){


      printf("Tree printing starting \n");
      root_ast=step(root,NULL,NULL);




      parse_treechild=total_nodes(root);
      compressionsize=ast_total;
      printf("Tree printed \n");


      //printf("Parse tree number of nodes: %d   Memory allocated %d\n",parse_treechild,parse_treechild*sizeof(node_tree));
      //printf("AST number of nodes: %d          Memory allocated %d\n",compressionsize,compressionsize*sizeof(node_ast));
    }
    else{

      printf("Cannot continue to semantic phase due to syntatic error in code\n");
      break;
    }




  }
  if (option==4){

    if (phase2==1){

      long int a1=parse_treechild*sizeof(node_tree);
      long int a2=compressionsize*sizeof(node_ast);
      printf("Parse tree number of nodes: %d   Memory allocated %lu\n",parse_treechild,a1);
      printf("AST number of nodes: %d          Memory allocated %lu\n",compressionsize,a2);

      printf("Compression : %f\n",(float)a1/a2);

    }
    else{

      printf("Cannot continue to semantic phase due to syntatic error in code\n");
      break;
    }

  }


  if (option==5)
  {

    if (phase2==1){
    ret=symbol_function_all(root_ast);
    print_symbol_table(ret->t,1,NULL);
  }
  }

  if (option==6){
    if (error2->head!=NULL){
    printf(" Parser detected errors \n");
    printf("...Printing errors.....\n");
    print_errors_parser(error2,G);
    printf("----END OF ERRORS-----\n");
    }
    else{
      semantic_errors(ret->e);
    }
  }

  if (option==7){
    n=return_main(ret->t,root_ast);
      arith* tmp=inter_main(root_ast,NULL);

      printf("Intermediate code genearted Successfully\n");
      file_print(argv[2],tmp,n);
  }

  /*
  if (option==7)
  {

    n=return_main(ret->t,root_ast);
    print_symbol_table(n);
  }

  if (option==8){
    arith* tmp=inter_main(root_ast,NULL);
    file_print("please.txt",tmp,n);
  }*/









  /*
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

  if (option==9){

  }


  if (option==8){
    if (phase2==1){
      printf("we did something\n");

      arith* tmp=inter_main(root_ast,NULL);
      list_node_tuple* tmp2=tmp->all_tuple;
      if (tmp2==NULL){
        printf("this is null\n");
      }

      while(tmp2!=NULL){
        print_tuple(tmp2->curr_tuple);
        tmp2=tmp2->next;
      }
    }
  }
  */
}

  return 0;

}
