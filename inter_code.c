//reserving symbol SEMICOLON for LABEL
//reserving symbol FUNCTion for goto

//rahul chand
//2015A7PS0163P

#include "inter_code.h"


node_ast* create_temp(int* seed){
  *seed=*seed+1;
  node_ast* node=(node_ast*)malloc(sizeof(node_ast));
  //create new node_ast with new name
  node->tk=ID;
  char name[20];
  sprintf(name,"t%d",*seed);
  strcpy(node->entry,name);

  //printf("created new temp %s\n",name);

  return node;
}

node_ast* create_label(int* seed){
  *seed=*seed+1;
  node_ast* node=(node_ast*)malloc(sizeof(node_ast));
  //create new node_ast with new name
  node->tk=SEMICOLON;
  char name[20];
  sprintf(name,"Label%d",*seed);
  strcpy(node->entry,name);
  return node;
}


list_node_tuple* combine_linked_list(list_node_tuple* tmp1,list_node_tuple* tmp2){
  list_node_tuple* to_return=tmp1;
  list_node_tuple* to_next=tmp1;
  if (to_next==NULL){
    return tmp2;
  }

  while(to_next->next!=NULL){
    to_next=to_next->next;
  }

  to_next->next=tmp2;
  return to_return;
}

list_node_tuple* create_node_tuple(node_ast* var1,node_ast* var2,node_ast* var3,symbol op)
{
  node_tuple* new_tuple=(node_tuple*)malloc(sizeof(node_tuple));
  new_tuple->var1=var1;
  new_tuple->var2=var2;
  new_tuple->var3=var3;
  new_tuple->op=op;
  list_node_tuple* ret=(list_node_tuple*)malloc(sizeof(list_node_tuple));
  ret->next=NULL;
  ret->curr_tuple=new_tuple;
  return ret;
}


arith* inter_arithemetic(node_ast* curr,int* seed)
{

  //print_symbol(curr->tk);printf("\n");

  if (curr->tk==PLUS || curr->tk==MINUS || curr->tk==MUL || curr->tk==DIV)
    {
      //printf("in\n");printf(" ");

     node_ast* node=create_temp(seed);

     node_ast* child1=curr->children->node;
     arith* tmp1=inter_arithemetic(child1,seed);
     node_ast* child2=curr->children->next->node;
     arith* tmp2=inter_arithemetic(child2,seed);
     list_node_tuple* tmp_tuple=create_node_tuple(node,tmp1->node,tmp2->node,curr->tk);

     curr->struct_arith->node=node;

     list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2->all_tuple);

     curr->struct_arith->all_tuple=combine_linked_list(var1,tmp_tuple);

     if (curr->struct_arith->all_tuple==NULL){printf("NO HOPE IS LEFT\n");}

     return curr->struct_arith;
   }


   if (curr->tk==ID || curr->tk==NUM || curr->tk==RNUM || curr->tk==STR || curr->tk==MATRIX)
   {
     //curr->struct_arith=(arith*)malloc(sizeof(arith));
     //printf("yes i am returning from here\n");
     curr->struct_arith->node=curr;
     curr->struct_arith->all_tuple=NULL;
     return curr->struct_arith;
   }
   if (curr->tk==arithmeticExpression){
     return inter_arithemetic(curr->children->node,seed);
   }

   //printf("it came here once\n");printf(" ");

}

arith* inter_print(node_ast* curr,int* seed,symbol_table* curr_table){
  node_ast* child1=curr->children->node;


  //printf("---------------");print_symbol(child1->tk);printf("-----------------\n");
  //printf("---------------");printf("%s\n",child1->entry);
  curr->struct_arith->all_tuple=create_node_tuple(child1,NULL,NULL,PRINT);
  curr->struct_arith->node=NULL;
  return curr->struct_arith;
}

arith* inter_read(node_ast* curr,int* seed,symbol_table* curr_table){
  //curr->struct_arith=(arith*)malloc(sizeof(arith));
  node_ast* child1=curr->children->node;
  curr->struct_arith->all_tuple=create_node_tuple(child1,NULL,NULL,READ);
  curr->struct_arith->node=NULL;
  return curr->struct_arith;
}


arith* inter_bool(node_ast* curr,int* seed,symbol_table* curr_table,node_ast* node_true,node_ast* node_false){
  if (curr->len==2 && curr->tk==OR){
    node_ast* child1=curr->children->node;
    node_ast* child2=curr->children->next->node;
    child1->node_true=node_true;
    child2->node_true=node_true;

    child1->node_false=create_label(seed);
    child2->node_false=node_false;

    arith* tmp1=inter_bool(child1,seed,curr_table,child1->node_true,child1->node_false);

    list_node_tuple* tmp2=create_node_tuple(child1->node_false,NULL,NULL,SEMICOLON);

    arith* tmp3=inter_bool(child2,seed,curr_table,child2->node_true,child2->node_false);

    list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
    list_node_tuple* var2=combine_linked_list(var1,tmp3->all_tuple);

    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var2;

    return curr->struct_arith;
  }

  if (curr->len==2 && curr->tk==AND){
    node_ast* child1=curr->children->node;
    node_ast* child2=curr->children->next->node;
    child1->node_true=create_label(seed);
    child2->node_true=node_true;

    child1->node_false=node_false;
    child2->node_false=node_false;

    arith* tmp1=inter_bool(child1,seed,curr_table,child1->node_true,child1->node_false);

    list_node_tuple* tmp2=create_node_tuple(child1->node_true,NULL,NULL,SEMICOLON);

    arith* tmp3=inter_bool(child2,seed,curr_table,child2->node_true,child2->node_false);

    list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
    list_node_tuple* var2=combine_linked_list(var1,tmp3->all_tuple);

    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var2;

    return curr->struct_arith;
  }

  if (curr->len==1){

    node_ast* child1=curr->children->node;

    child1->node_true=node_false;


    child1->node_false=node_true;

    arith* var1=inter_bool(child1,seed,curr_table,child1->node_true,child1->node_false);


    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var1->all_tuple;

    return curr->struct_arith;
  }

  if (curr->len==2 && (curr->tk==LT || curr->tk==LE || curr->tk==EQ || curr->tk==GT || curr->tk==NE || curr->tk==GE))
  {
    node_ast* child1=curr->children->node;
    node_ast* child2=curr->children->next->node;

    //arith* tmp1=inter_bool(child1,seed,curr_table,NULL,NULL);
    //arith* tmp2=inter_bool(child2,seed,curr_table,NULL,NULL);

    //printf("symbol :");print_symbol(curr->tk);printf(" ");
    //printf("%s %s     ",child1->entry,child2->entry);print_symbol(child2->tk);printf("\n");

    list_node_tuple* tmp1=create_node_tuple(curr->node_true,child1,child2,curr->tk);
    list_node_tuple* tmp2=create_node_tuple(curr->node_false,NULL,NULL,FUNCTION);


    list_node_tuple* var1=combine_linked_list(tmp1,tmp2);


    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var1;

    return curr->struct_arith;
  }


}

arith* inter_all(node_ast* stat1,int* seed,symbol_table* curr_table){
  if (stat1==NULL){return NULL;}

  node_ast* stat2=stat1;
  node_ast* stat3=stat1;
  while(stat1!=NULL){
  if (stat1->tk==ASSIGNOP){
    arith* tmp=inter_arithemetic(stat1->children->next->node->children->node,seed);
    list_node_tuple* tmp2=create_node_tuple(stat1->children->node,tmp->node,NULL,ASSIGNOP);
    list_node_tuple* tmp3=combine_linked_list(tmp->all_tuple,tmp2);
    stat1->struct_arith->all_tuple=tmp3;
    stat1->struct_arith->node=NULL;
    //printf("assignop \n");
  }
  if (stat1->tk==ifStmt){
    inter_if(stat1,seed,curr_table);
  }
  if (stat1->tk==PRINT){
    inter_print(stat1,seed,curr_table);
  }
  if (stat1->tk==READ){
    inter_read(stat1,seed,curr_table);
  }
  stat1=stat1->sibling;
}
  stat2=stat2->sibling;
  while(stat2!=NULL){
    stat3->struct_arith->all_tuple=combine_linked_list(stat3->struct_arith->all_tuple,stat2->struct_arith->all_tuple);
    stat2=stat2->sibling;
  }
  return stat3->struct_arith;
}


arith* inter_if(node_ast* curr,int* seed,symbol_table* curr_table){

  if (curr->children->next->next->next->node==NULL)         //Only If condition
  {
        node_ast* boolnode=curr->children->node;
        node_ast* stat1=curr->children->next->node;
        node_ast* stat2=curr->children->next->next->node;
        curr->next=create_label(seed);
        boolnode->node_true=create_label(seed);
        boolnode->node_false=curr->next;
        stat1->next=curr->next;

        arith* tmp1=inter_bool(boolnode->children->node,seed,curr_table,boolnode->node_true,  boolnode->node_false);

        list_node_tuple* tmp2=create_node_tuple(boolnode->node_true,NULL,NULL,SEMICOLON);

        arith* tmp3=inter_all(stat1,seed,curr_table);
        arith* tmp4=inter_all(stat2,seed,curr_table);
        list_node_tuple* tmp5=create_node_tuple(curr->next,NULL,NULL,SEMICOLON);

        list_node_tuple* tmp3_list;
        list_node_tuple* tmp4_list;
        if(tmp3==NULL){ tmp3_list=NULL;}else{ tmp3_list=tmp3->all_tuple;}
        if(tmp4==NULL){ tmp4_list=NULL;}else{ tmp4_list=tmp4->all_tuple;}

        list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
        list_node_tuple* var2=combine_linked_list(var1,tmp3_list);
        list_node_tuple* var3=combine_linked_list(var2,tmp4_list);
        list_node_tuple* var4=combine_linked_list(var3,tmp5);

        curr->struct_arith->node=NULL;
        curr->struct_arith->all_tuple=var4;

        return curr->struct_arith;
  }
  else{

    node_ast* boolnode=curr->children->node;
    node_ast* stat1=curr->children->next->node;
    node_ast* stat2=curr->children->next->next->node;
    node_ast* stat3=curr->children->next->next->next->node;

    curr->next=create_label(seed);
    boolnode->node_true=create_label(seed);
    boolnode->node_false=create_label(seed);
    stat1->next=curr->next;
    stat3->next=curr->next;

    arith* tmp1=inter_bool(boolnode->children->node,seed,curr_table,boolnode->node_true,boolnode->node_false);

    list_node_tuple* tmp2=create_node_tuple(boolnode->node_true,NULL,NULL,SEMICOLON);

    arith* tmp3=inter_all(stat1,seed,curr_table);
    arith* tmp4=inter_all(stat2,seed,curr_table);
    list_node_tuple* tmp3_list;
    list_node_tuple* tmp4_list;
    if(tmp3==NULL){ tmp3_list=NULL;}else{ tmp3_list=tmp3->all_tuple;}
    if(tmp4==NULL){ tmp4_list=NULL;}else{ tmp4_list=tmp4->all_tuple;}


    list_node_tuple* tmp5=create_node_tuple(curr->next,NULL,NULL,FUNCTION);

    list_node_tuple* tmp6=create_node_tuple(boolnode->node_false,NULL,NULL,SEMICOLON);

    arith* tmp7=inter_all(stat3,seed,curr_table);



    list_node_tuple* tmp8=create_node_tuple(curr->next,NULL,NULL,SEMICOLON);

    list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
    list_node_tuple* var2=combine_linked_list(var1,tmp3_list);
    list_node_tuple* var3=combine_linked_list(var2,tmp4_list);
    list_node_tuple* var4=combine_linked_list(var3,tmp5);
    list_node_tuple* var5=combine_linked_list(var4,tmp6);
    list_node_tuple* var6=combine_linked_list(var5,tmp7->all_tuple);
    list_node_tuple* var7=combine_linked_list(var6,tmp8);

    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var7;

    return curr->struct_arith;
  }

}

arith* inter_main(node_ast* curr,symbol_table* curr_table){
  node_ast* child=curr->children->node;
  int seed=0;
  while(child!=NULL){

    if (child->tk==ASSIGNOP){
      arith* tmp=inter_arithemetic(child->children->next->node->children->node,&seed);

      //if (tmp->node==NULL){printf("how the fuck");}

      //print_symbol(tmp->node->tk);printf("\n");

      list_node_tuple* tmp2=create_node_tuple(child->children->node,tmp->node,NULL,ASSIGNOP);
      list_node_tuple* tmp3=combine_linked_list(tmp->all_tuple,tmp2);
      child->struct_arith->all_tuple=tmp3;
      child->struct_arith->node=NULL;
    }
    if (child->tk==PRINT){
      //printf("2");
      inter_print(child,&seed,curr_table);
    }
    if (child->tk==READ){
      //printf("3");
      inter_read(child,&seed,curr_table);
    }
    if (child->tk==ifStmt)
    {

      //printf("------------START-----------------\n");
      //print_tree(child->children->node);
      //printf("------------END-----------------\n");
      //printf("4\n");
      inter_if(child,&seed,curr_table);
    }
    //print_symbol(child->tk);printf("\n");
    child=child->sibling;
  }

  child=curr->children->node;
  while(child!=NULL){
      curr->struct_arith->all_tuple=combine_linked_list(curr->struct_arith->all_tuple,child->struct_arith->all_tuple);
      child=child->sibling;
  }
  return curr->struct_arith;
}

void print_tuple(node_tuple* tp)
{


      char symbol_name[20];
      get_string(tp->op,symbol_name);
      char a1[20];char a2[20];char a3[20];
      if (tp->var1!=NULL){strcpy(a1,tp->var1->entry);}else{strcpy(a1,"NULL");}
      if (tp->var2!=NULL){strcpy(a2,tp->var2->entry);}else{strcpy(a2,"NULL");}
      if (tp->var3!=NULL){strcpy(a3,tp->var3->entry);}else{strcpy(a3,"NULL");}
      printf("%s %s %s %s\n",a1,a2,a3,symbol_name);
}

symbol_table* return_new_table(symbol_table* curr_table,int offset,node_ast* root_ast)
{
  int x=0;
  arith* tmp=inter_main(root_ast,NULL);
  list_node_tuple* tmp2=tmp->all_tuple;
  while(tmp2!=NULL){
    node_tuple* tp=tmp2->curr_tuple;
    if (tp->var1!=NULL){
      if (strlen(tp->var1->entry)>1){
        int f1=find_in_scope(curr_table,tp->var1->entry,0);
        if (f1==0  && tp->var1->entry[0]=='t'){
          add_symbol_table(curr_table,INT,tp->var1->entry,VAR_attr,NULL,offset,0,2);
          offset=offset+2;
        }
      }
    }
    if (tp->var2!=NULL){
      if (strlen(tp->var2->entry)>1){
        int f1=find_in_scope(curr_table,tp->var2->entry,0);
        if (f1==0 && tp->var2->entry[0]=='t'){
          add_symbol_table(curr_table,INT,tp->var2->entry,VAR_attr,NULL,offset,0,2);
          offset=offset+2;
        }
      }
    }
    if (tp->var3!=NULL){
      if (strlen(tp->var3->entry)>1){
        int f1=find_in_scope(curr_table,tp->var3->entry,0);
        if (f1==0 && tp->var3->entry[0]=='t'){
          add_symbol_table(curr_table,INT,tp->var3->entry,VAR_attr,NULL,offset,0,2);
          offset=offset+2;
        }
      }
    }

  tmp2=tmp2->next;
  }
  return curr_table;
}
symbol_table* return_main(symbol_table* curr_table,node_ast* root){
  symbol_table_entry* curr_entry=curr_table->start;
  int offset=0;
  while(curr_entry!=NULL){
    if (curr_entry->next_table!=NULL){
      //print_symbol_table(curr_entry->next_table);

    }
      offset=offset+curr_entry->size;
    curr_entry=curr_entry->next_entry;
  }

  printf("ths was the offset =====================  %d\n",offset);

  return return_new_table(curr_table,offset,root);
}
