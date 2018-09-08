#include "codeGen.h"
//rahul chand
//2015A7PS0163P

void file_print(char* name_of_file,arith* main_arith,symbol_table* main_table){
  list_node_tuple* start_tuple=main_arith->all_tuple;

  FILE* fp=fopen(name_of_file,"w");

  //fprintf(fp,"%s","all");




  fprintf(fp,"%s","%include 'asm_file.asm'\n");
  fprintf(fp,"%s","section .bss\n");
  fprintf(fp,"%s","nline RESB 1\n");
  fprintf(fp,"%s","tempIp RESB 20\n");
  fprintf(fp,"%s","baseOfStack RESB 1\n");
  fprintf(fp,"%s","\n");
  fprintf(fp,"%s","section .text\n");
  fprintf(fp,"%s","global _start\n");
  fprintf(fp,"%s","_start:\n");
  fprintf(fp,"%s","MOV EBP,baseOfStack\n");
  fprintf(fp,"%s","MOV AL,0AH\n");
  fprintf(fp,"%s","MOV AL,0AH\n");
  fprintf(fp,"%s","MOV EBX,nline\n");
  fprintf(fp,"%s","MOV [EBX],AL\n");



while(start_tuple!=NULL){



  node_tuple* tp=start_tuple->curr_tuple;
  symbol s=tp->op;

  print_tuple(tp);printf("\n");

if (s==ASSIGNOP){

    if (tp->var2->tk==ID){

      symbol var_type;
      var_type=return_from_table(main_table,tp->var2->entry,0)->type_var;

      if (var_type=INT)
      {

        symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
        symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

        fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
        fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);

      }
      if (var_type==STRING)
      {

        symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
        symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

        int x=e2->size;
        int i=0;
        for(;i<x;i++)
        {
          fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset+i);
          fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+i);
        }

      }
      if (var_type==MATRIX)
      {

        symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
        symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

        int x=(int)e2->size/2;
        int i=0;
        for(;i<x;i++)
        {
          fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset+2*i);
          fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
        }

      }

    }

    if (tp->var2->tk==NUM){

      symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
      //symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

      //fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EAX,%d\n",tp->var2->val_int);
      fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);


      fprintf(fp,"%s","\n");
    }

    if (tp->var2->tk==STR)
    {

      symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
      int i=0;
      int x=strlen(tp->var2->entry);
      for(;i<x;i++){
        fprintf(fp,"MOV EAX,%c\n",tp->var2->entry[i]);
        fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+i);
      }

    }
    if (tp->var2->tk==MATRIX){

      symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
      //fprintf(fp,"%s\n","yahan");
      int i=0;
      node_ast* child1 =tp->var2->children->node;
      node_ast* child2;
      while(child1!=NULL){
        child2=child1->children->node;
      while(child2!=NULL)

      {
        //printf("YAH");
        int a=child2->val_int;
        fprintf(fp,"MOV EAX,%d\n",a);
        fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
        child2=child2->sibling;
        i++;
      }
      child1=child1->sibling;
    }
  }
    fprintf(fp,"%s","\n");
  }


  if (s==PLUS){


    if (tp->var3->tk==ID && tp->var2->tk==ID)

    {

    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
    symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
    symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);


    if (e2->type_var==INT){

      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","ADD EAX EBX\n");
      fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
    }

    if (e2->type_var==MATRIX){

      int i=0;
      int x=(int)e2->size/2;

      for(;i<x;i++)
      {
        fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset+2*i);
        fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset+2*i);
        fprintf(fp,"%s","ADD EAX EBX\n");
        fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
      }
    }

    if (e2->type_var==STRING){
      int i=0;
      int x=strlen(tp->var2->entry);
      int x_prev=x;
      for(;i<x;i++){
        fprintf(fp,"MOV [EBP+%d],%c\n",e2->offset+i,tp->var2->entry[i]);
      }
      i=0;

      x=strlen(tp->var3->entry);
      for(;i<x;i++){
        fprintf(fp,"MOV [EBP+%d],%c\n",e2->offset+i+x_prev,tp->var2->entry[i]);
      }
    }

  }

  if (tp->var3->tk==NUM && tp->var2->tk==NUM)
  {
    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

    fprintf(fp,"MOV EAX,[EBP+%d]\n",tp->var2->val_int);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
    fprintf(fp,"%s","ADD EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
  }

  if (tp->var3->tk==MATRIX && tp->var2->tk==MATRIX)
  {
    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

    int i=0;
    node_ast* child1=tp->var2->children->node;
    node_ast* child2=tp->var3->children->node;

    while(child1!=NULL)
    {
      int a=child1->val_int;
      int b=child2->val_int;
      i++;
      fprintf(fp,"MOV EAX,%d\n",a);
      fprintf(fp,"MOV EBX,%d\n",b);
      fprintf(fp,"%s","ADD EAX EBX\n");
      fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
      child1=child1->sibling;
      child2=child2->sibling;
    }
  }


  if (tp->var3->tk==ID && tp->var2->tk==NUM)

  {
    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
    symbol_table_entry* e2=return_from_table(main_table,tp->var3->entry,0);

    int a=tp->var2->val_int;
    fprintf(fp,"MOV EAX,%d\n",a);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
    fprintf(fp,"%s","ADD EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);



  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)

  {

    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
    symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

    int a=tp->var3->val_int;
    fprintf(fp,"MOV EAX,%d\n",a);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var2->val_int);
    fprintf(fp,"%s","ADD EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);

  }
}
if (s==MINUS){


  if (tp->var3->tk==ID && tp->var2->tk==ID)

  {

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
  symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);


  if (e2->type_var==INT){

    fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
    fprintf(fp,"%s","SUB EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
  }

  if (e2->type_var==MATRIX){

    int i=0;
    int x=(int)e2->size/2;

    for(;i<x;i++)
    {
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset+2*i);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset+2*i);
      fprintf(fp,"%s","ADD EAX EBX\n");
      fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
    }
  }



  }

if (tp->var3->tk==NUM && tp->var2->tk==NUM)
{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

  fprintf(fp,"MOV EAX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","SUB EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
}

if (tp->var3->tk==MATRIX && tp->var2->tk==MATRIX)
{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

  int i=0;
  node_ast* child1=tp->var2->children->node;
  node_ast* child2=tp->var3->children->node;

  while(child1!=NULL)
  {
    int a=child1->val_int;
    int b=child2->val_int;
    i++;
    fprintf(fp,"MOV EAX,%d\n",a);
    fprintf(fp,"MOV EBX,%d\n",b);
    fprintf(fp,"%s","ADD EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset+2*i);
    child1=child1->sibling;
    child2=child2->sibling;
  }
}

if (tp->var3->tk==ID && tp->var2->tk==NUM)

{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var3->entry,0);

  int a=tp->var2->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","SUB EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);



}
if (tp->var2->tk==NUM && tp->var3->tk==ID)

{

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

  int a=tp->var3->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"%s","SUB EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);

}
}

if (s==MUL){


  if (tp->var3->tk==ID && tp->var2->tk==ID)

  {

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
  symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);


  if (e2->type_var==INT){

    fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
    fprintf(fp,"%s","MUL EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
  }


  }

if (tp->var3->tk==NUM && tp->var2->tk==NUM)
{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

  fprintf(fp,"MOV EAX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
}

if (tp->var3->tk==ID && tp->var2->tk==NUM)

{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var3->entry,0);

  int a=tp->var2->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);



}
if (tp->var2->tk==NUM && tp->var3->tk==ID)

{

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

  int a=tp->var3->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);

}
}
if (s==DIV){


  if (tp->var3->tk==ID && tp->var2->tk==ID)

  {

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
  symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);


  if (e2->type_var==INT){

    fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
    fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
    fprintf(fp,"%s","MUL EAX EBX\n");
    fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
  }


  }

if (tp->var3->tk==NUM && tp->var2->tk==NUM)
{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);

  fprintf(fp,"MOV EAX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);
}

if (tp->var3->tk==ID && tp->var2->tk==NUM)

{
  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var3->entry,0);

  int a=tp->var2->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var3->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);



}
if (tp->var2->tk==NUM && tp->var3->tk==ID)

{

  symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
  symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);

  int a=tp->var3->val_int;
  fprintf(fp,"MOV EAX,%d\n",a);
  fprintf(fp,"MOV EBX,[EBP+%d]\n",tp->var2->val_int);
  fprintf(fp,"%s","MUL EAX EBX\n");
  fprintf(fp,"MOV [EBP+%d],EAX\n",e1->offset);

}
}

if (s==LT){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JL %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JL %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JL %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JL %s\n",tp->var1->entry);

  }
}
if (s==LE){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JLE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JLE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JLE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JLE %s\n",tp->var1->entry);

  }
}
if (s==GT){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JG %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JG %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JG %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JG %s\n",tp->var1->entry);

  }
}
if (s==GE){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JGE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JGE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JGE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JGE %s\n",tp->var1->entry);

  }
}
if (s==NE){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JNE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JNE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JNE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JNE %s\n",tp->var1->entry);

  }
}
if (s==EQ){
  if (tp->var2->tk==NUM && tp->var3->tk==NUM)
  {
      int a1=tp->var2->val_int;
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==NUM)
  {
      //int a1=tp->var2->val_int;
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      int a2=tp->var3->val_int;
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,%d\n",a2);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==NUM && tp->var3->tk==ID)
  {
      int a1=tp->var2->val_int;
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,%d\n",a1);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JE %s\n",tp->var1->entry);

  }
  if (tp->var2->tk==ID && tp->var3->tk==ID)
  {
      symbol_table_entry* e2=return_from_table(main_table,tp->var2->entry,0);
      symbol_table_entry* e3=return_from_table(main_table,tp->var3->entry,0);
      fprintf(fp,"MOV EAX,[EBP+%d]\n",e2->offset);
      fprintf(fp,"MOV EBX,[EBP+%d]\n",e3->offset);
      fprintf(fp,"%s","CMP EAX,EBX\n");
      //fprintf(fp,"%s","CMP EAX,EBX\n");
      fprintf(fp,"JE %s\n",tp->var1->entry);

  }

}

if (s==SEMICOLON){
  fprintf(fp,"%s:\n",tp->var1->entry);
}
if (s==FUNCTION){
  fprintf(fp,"JMP %s\n",tp->var1->entry);
}
if (s==PRINT){
    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
    fprintf(fp,"MOV EDX,%d\n",e1->size);
    fprintf(fp,"MOV ECX,[EBP+%d]\n",e1->offset);
    fprintf(fp,"%s\n","MOV EBX,1");
    fprintf(fp,"%s\n","MOV EAX,4");
    //fprintf(fp,"MOV EDX,%d\n",e1->size);
    fprintf(fp,"%s\n","int 80h");
}
if (s==READ){
    symbol_table_entry* e1=return_from_table(main_table,tp->var1->entry,0);
    fprintf(fp,"MOV EDX,%d\n",e1->size);
    fprintf(fp,"MOV ECX,[EBP+%d]\n",e1->offset);
    fprintf(fp,"%s\n","MOV EBX,1");
    fprintf(fp,"%s\n","MOV EAX,4");
    //fprintf(fp,"MOV EDX,%d\n",e1->size);
    fprintf(fp,"%s\n","int 80h");
}
  start_tuple=start_tuple->next;

}
fclose(fp);
}
