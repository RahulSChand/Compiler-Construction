//reserving symbol SEMICOLON for LABEL
//reserving symbol FUNCTion for goto

node_ast* create_temp(int* seed){
  *seed=*seed+1;
  node_ast* node=(node_ast*)malloc(sizeof(node_ast));
  //create new node_ast with new name
  return node;
}

node_ast* create_label(int* seed){
  *seed=*seed+1;
  node_ast* node=(node_ast*)malloc(sizeof(node_ast));
  //create new node_ast with new name
  return node;
}


list_node_tuple* combine_linked_list(list_node_tuple* tmp1,list_node_tuple* tmp2){
  list_node_tuple* to_return=tmp1;
  list_node_tuple* to_next=tmp1;
  while(to_next->next!=NULL){
    to_next=to_next->next;
  }

  to_next->next=tmp2->all_tuple;
  return to_return;
}

list_node_tuple* create_node_tuple(node_ast* var1,node_ast* var2,node_ast* var3,symbol op){
  node_tuple* new_tuple=(new_tuple*)malloc(sizeof(node_tuple));
  new_tuple->var1=var1;
  new_tuple->var1=var2;
  new_tuple->var1=var3;
  new_tuple->op=op;
  list_node_tuple* ret=(list_node_tuple*)malloc(sizeof(list_node_tuple));
  ret->next=NULL;
  ret->curr_tuple=new_tuple;
  return ret;
}

   if (curr->tk==PLUS || curr->tk==MINUS || curr->tk==MUL || curr->tk==DIV)
   {
     node_ast* node=create_temp(seed);
     curr->struct_arith=(arith*)malloc(sizeof(arith));
     node_ast* child1=curr->children->node;
     arith* tmp1=inter_arithemetic(child1,seed);
     node_ast* child2=curr->children->next->node;
     arith* tmp2=inter_arithemetic(child2,seed);
     arith* inter_arithemetic(node_ast* curr,int* seed){

     list_node_tuple* tmp_tuple=create_node_tuple(node,tmp1->node,tmp2->node,curr->tk);

     curr->struct_arith->node=node;

     list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2->all_tuple);

     curr->struct_arith->all_tuple=combine_linked_list(var1,tmp_tuple);

     return curr->struct_arith;
   }


   if (curr->tk==ID || curr->tk==NUM || curr->tk==RNUM || curr->tk==STR || curr->tk==MATRIX)
   {
     curr->struct_arith=(arith*)malloc(sizeof(arith));
     curr->struct_arith->node=curr;
     curr->struct_arith->all_tuple=NULL;
     return curr->struct_arith;
   }

}

arith* inter_print(node_ast* curr,int* seed,symbol_table* curr_table){
  node_ast* child1=curr->children->node;
  curr->struct_arith->all_tuple=create_node_tuple(child1,NULL,NULL,PRINT);
  curr->struct_arith->node=NULL;
  return curr->struct_arith;
}

arith* inter_sizeexpr(node_ast* curr,int* seed,symbol_table* curr_table){
  curr->struct_arith=(arith*)malloc(sizeof(arith));
  curr->struct_arith->all_tuple=create_node_tuple(child1,NULL,NULL,READ);
  curr->struct_arith->node=NULL;
  return curr->struct_arith;
}


arith* inter_bool(node_ast* curr,int* seed,symbol_table* curr_table,node_ast* node_true,node_ast* node_false){
  if (curr->len==2 && curr->tk==OR){
    node_ast* child1=curr->chidren->node;
    node_ast* child2=curr->chidren->next->node;
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
    node_ast* child1=curr->chidren->node;
    node_ast* child2=curr->chidren->next->node;
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

    node_ast* child1=curr->chidren->node;

    child1->node_true=node_false;


    child1->node_false=node_true;

    var1=inter_bool(child1,seed,curr_table,child1->node_true,child1->node_false);


    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var1->all_tuple;

    return curr->struct_arith;
  }

  if (curr->len==2 && (curr->tk==LT || curr->tk==LE || curr->tk==EQ || curr->tk==GT || curr->tk==NE || curr->tk==GE))
  {
    node_ast* child1=curr->chidren->node;
    node_ast* child2=curr->chidren->next->node;

    //arith* tmp1=inter_bool(child1,seed,curr_table,NULL,NULL);
    //arith* tmp2=inter_bool(child2,seed,curr_table,NULL,NULL);

    list_node_tuple* tmp1=create_node_tuple(curr->node_true,child1,child2,curr->tk);
    list_node_tuple* tmp2=create_node_tuple(curr->node_false,NULL,NULL,FUNCTION);


    list_node_tuple* var1=combine_linked_list(tmp1,tmp2);


    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var1;

    return curr->struct_arith;
  }


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

        arith* tmp1=inter_bool(boolnode);
        list_node_tuple* tmp2=create_node_tuple(boolnode->node_true,NULL,NULL,SEMICOLON);

        arith* tmp3=inter_all(stat1);
        arith* tmp4=inter_all(stat2);
        list_node_tuple* tmp5=create_node_tuple(curr->next,NULL,NULL,SEMICOLON);

        list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
        list_node_tuple* var2=combine_linked_list(var1,tmp3->all_tuple);
        list_node_tuple* var3=combine_linked_list(var2,tmp4->all_tuple);
        list_node_tuple* var4=combine_linked_list(var3,tmp5);

        curr->struct_arith->node=NULL;
        curr->struct_arith->all_tuple=var4;

        return curr->struct_arith;
  }
  else{

    node_ast* boolnode=curr->children->node;
    node_ast* stat1=curr->children->next->node;
    node_ast* stat2=curr->children->next->next->node;
    node_ast* stat3=curr->children->next->next->node;

    curr->next=create_label(seed);
    boolnode->node_true=create_label(seed);
    boolnode->node_false=create_label(seed);
    stat1->next=curr->next;
    stat3->next=curr->next;

    arith* tmp1=inter_bool(boolnode);
    list_node_tuple* tmp2=create_node_tuple(boolnode->node_true,NULL,NULL,SEMICOLON);

    arith* tmp3=inter_all(stat1);
    arith* tmp4=inter_all(stat2);

    list_node_tuple* tmp5=create_node_tuple(curr->next,NULL,NULL,FUNCTION);

    list_node_tuple* tmp6=create_node_tuple(boolnode->node_false,NULL,NULL,SEMICOLON);

    arith* tmp7=inter_all(stat3);

    list_node_tuple* var1=combine_linked_list(tmp1->all_tuple,tmp2);
    list_node_tuple* var2=combine_linked_list(var1,tmp3->all_tuple);
    list_node_tuple* var3=combine_linked_list(var2,tmp4->all_tuple);
    list_node_tuple* var4=combine_linked_list(var3,tmp5);
    list_node_tuple* var5=combine_linked_list(var4,tmp6);
    list_node_tuple* var6=combine_linked_list(var5,tmp7);


    curr->struct_arith->node=NULL;
    curr->struct_arith->all_tuple=var6;

    return curr->struct_arith;
  }

}
