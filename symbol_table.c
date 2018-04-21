#include "symbol_table.h"


//We return function as a don't care type.
symbol recursive_check(node_ast* child,error_node* curr_error,symbol_table* curr_table, int line_no,int offset_cal,char* parameter){


  if (child->len==2 && child->tk==functionCall)
  {
    node_ast* child1=child->children->node;
    int line_number=child1->line_number;
    symbol return_value=FUNCTION;

    if (find_in_scope(curr_table,child1->entry,1)==0){

      printf("*****function went inside here****     %s\n",child1->entry);

      curr_error=add_error(curr_error,child1->entry,1,line_number);

    }




    else{
      symbol_table_entry* fun_def=return_from_scope(curr_table,child1->entry,1);
      attribute attr=fun_def->attr_var;

      if (attr==FUNCTION_attr){
        curr_error=add_error(curr_error,child1->entry,4,line_number);
        return_value=FUNCTION;

        //if (in_param->tk==INT && fun_def->param.right[i]==INT)
        }

      else if (attr==FUNCTION_attr_int){
        return_value=INT;
      }
      else if (attr==FUNCTION_attr_real){
        return_value=REAL;
      }
      else if (attr==FUNCTION_attr_str){
        return_value=STRING;
      }




    node_ast* var=child->children->next->node;
    int x=0;
    while(var!=NULL){
      int line_number=child1->line_number;
      if (find_in_scope(curr_table,var->entry,0)==0){

        curr_error=add_error(curr_error,var->entry,1,line_number);
        return_value=FUNCTION;
      }
      else{
        symbol t;
        if (var->tk==ID){
          t=return_from_scope(curr_table,var->entry,0)->type_var;
          printf("$$$$$$$$$ got from here\n");
        }
        else{
          t=var->tk;
        }
        char s[20];
        get_string(t,s);
        printf("##########  %s\n",s);
        if (x>=fun_def->param->r || t!=fun_def->param->right[x]){

          curr_error=add_error(curr_error,var->entry,6,line_number);
          return_value=FUNCTION;
        }
      }

        var=var->sibling;
        x++;
      }
      if (x>fun_def->param->r){curr_error=add_error(curr_error,var->entry,6,line_number);}
      return return_value;
    }

  }






  if (child->len==0 || child->tk==MATRIX){
    symbol return_value=FUNCTION;
    if (child->tk==ID){
    int line_number=child->line_number;

    //printf(" printing id%s\n",child->entry);

    if (find_in_scope(curr_table,child->entry,0)==0){
    curr_error=add_error(curr_error,child->entry,1,line_number);
      }
    else{
        return_value=return_from_scope(curr_table,child->entry,0)->type_var;
    }
      //char p1[20];get_string(return_value,p1);
      //printf(" printing id  %s %s\n",child->entry,p1);
      return return_value;
    }

    if (child->tk==STR){
      //printf("string\n");
      if (offset_cal==1){
        symbol_table_entry* ent1=return_from_scope(curr_table,parameter,0);
        if(ent1!=NULL){ent1->size=strlen(child->entry);}
        printf("--------------------we calculated offset\n");
      }
      return_value=STRING;
      char p1[20];get_string(return_value,p1);
      //printf(" printing id  %s %s\n",child->entry,p1);
      return return_value;

    }
    if (child->tk==NUM){
      //printf("------int\n");
      return_value=INT;
      char p1[20];get_string(return_value,p1);
      //printf(" printing id  %s %s\n",child->entry,p1);
      return return_value;
    }
    if (child->tk==REAL){
      //printf("real\n");
      return_value=REAL;
      char p1[20];get_string(return_value,p1);
      //printf(" printing id  %s %s\n",child->entry,p1);
      return return_value;
    }
    if (child->tk==MATRIX){
      //printf("-----matrix\n");
      if (offset_cal==1){
        symbol_table_entry* ent1=return_from_scope(curr_table,parameter,0);
        if(ent1!=NULL){
          sizeofmatrix(child,ent1);
        }
      }
      return_value=MATRIX;
      char p1[20];get_string(return_value,p1);
      printf(" printing id  %s %s\n",child->entry,p1);
      return return_value;
    }


    return return_value;
  }

  if (child->len==1){
    child=child->children->node;
    return recursive_check(child,curr_error,curr_table,line_no,offset_cal,parameter);
  }
  if (child->len==2){
    symbol operator_node=child->tk;
    node_ast* child1=child->children->node;
    symbol return1=recursive_check(child1,curr_error,curr_table,line_no,offset_cal,parameter) ;
    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    node_ast* child2=child->children->next->node;
    symbol return2=recursive_check(child2,curr_error,curr_table,line_no,offset_cal,parameter);
    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    if (return1==FUNCTION || return2==FUNCTION){
      return FUNCTION;
    }

    if (return1!=return2){
      curr_error=add_error(curr_error,"type",4,line_no);
      return FUNCTION;
    }

    if (operator_node==PLUS){
      if (return1==STRING){return STRING;}
      if (return1==INT){return INT;}
      if (return1==REAL){return REAL;}
      if (return1==MATRIX){return MATRIX;}

    }
    if (operator_node==MINUS){
      if (return1==STRING){curr_error=add_error(curr_error,"type",4,line_no);return FUNCTION;}
      if (return1==INT){return INT;}
      if (return1==REAL){return REAL;}
      if (return1==MATRIX){return MATRIX;}
    }
    if (operator_node==MUL){
      if (return1==STRING){curr_error=add_error(curr_error,"type",4,line_no);return FUNCTION;}
      if (return1==INT){return INT;}
      if (return1==REAL){return REAL;}
      if (return1==MATRIX){curr_error=add_error(curr_error,"type",4,line_no);return FUNCTION;}
    }
    if (operator_node==DIV){
      if (return1==STRING){curr_error=add_error(curr_error,"type",4,line_no);return FUNCTION;}
      if (return1==INT){return INT;}
      if (return1==REAL){return REAL;}
      if (return1==MATRIX){curr_error=add_error(curr_error,"type",4,line_no);return FUNCTION;}
    }
    return FUNCTION;
  }




}


void recursive_check2(node_ast* child,error_node* curr_error,symbol_table* curr_table)
{

  if (child->len==2 && (child->tk==LT || child->tk==LE || child->tk==EQ || child->tk==GT || child->tk==NE || child->tk==GE)){
    node_ast* child1=child->children->node;
    node_ast* child2=child->children->next->node;
    int line_number=child1->line_number;
    if (find_in_scope(curr_table,child1->entry,0)==0){
      curr_error=add_error(curr_error,child1->entry,1,line_number);
    }
    line_number=child2->line_number;
    if (find_in_scope(curr_table,child2->entry,0)==0){
    curr_error=add_error(curr_error,child2->entry,1,line_number);


  }

  return;

  }





if (child->len==2 && (child->tk==AND || child->tk==OR)){
    node_ast* child1=child->children->node;
    recursive_check2(child1,curr_error,curr_table);
    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    node_ast* child2=child->children->next->node;
    recursive_check2(child2,curr_error,curr_table);
    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    return;

}


  if (child->len==1){
    node_ast* child1=child->children->node;
    recursive_check2(child1,curr_error,curr_table);
    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    return;
  }



  return;
}


void semantic_errors(error_node* curr_error){
  while(curr_error!=NULL){
    printf("%d   %s\n",curr_error->line_number,curr_error->var_name);
    curr_error=curr_error->next;
  }
}



error_node* add_error(error_node* curr_error,char* var_name,int error_type,int line_number){
  error_node* new_error=(error_node*)malloc(sizeof(error_node));
  strcpy(new_error->var_name,var_name);
  new_error->error_type=error_type;
  new_error->line_number=line_number;
  new_error->next=NULL;
  printf("\n**************THis is the current error Error %s  %d\n",var_name,line_number);
  //printf("\nTHis is the previous error Error %s  %d\n",curr_error->var_name,curr_error->line_number);
  curr_error->next=new_error;
  return new_error;
}


symbol_table* create_symbol_table(symbol_table* parent_table){
  symbol_table* new_table=(symbol_table*)malloc(sizeof(struct symbol_table));
  new_table->start=NULL;
  new_table->parent=parent_table;
  new_table->curr=NULL;
  return new_table;
}

void add_symbol_table(symbol_table* table,symbol type_var,char* name_var,attribute attr_var,symbol_table* next_table,int offset,int init,int size){

  if (table->curr==NULL){

    printf("Adding first variable %s\n",name_var);

    table->curr=(struct symbol_table_entry*)malloc(sizeof(symbol_table_entry));
    table->curr->type_var=type_var;
    table->curr->attr_var=attr_var;
    table->curr->offset=offset;
    table->curr->size=size;
    table->curr->init=init;
    table->curr->param=(fun_param*)malloc(sizeof(fun_param));
    table->curr->next_entry=NULL;
    table->curr->next_table=next_table;
    strcpy(table->curr->name_var,name_var);
    table->start=table->curr;
    return;
  }



  table->curr->next_entry=(struct symbol_table_entry*)malloc(sizeof(symbol_table_entry));
  table->curr->next_entry->type_var=type_var;

  printf("****** Addding new variable: %s\n",name_var);

  strcpy(table->curr->next_entry->name_var,name_var);
  table->curr->next_entry->attr_var=attr_var;
  table->curr->next_entry->offset=offset;
  table->curr->next_entry->init=init;
  table->curr->next_entry->param=(fun_param*)malloc(sizeof(fun_param));
  table->curr->next_entry->size=size;
  table->curr->next_entry->next_entry=NULL;
  table->curr->next_entry->next_table=next_table;
  table->curr=table->curr->next_entry;
}




int find_in_table(symbol_table* table,char* name,int which){
  symbol_table_entry* start=table->start;



  while(start!=NULL){

    if (strcmp(name,start->name_var)==0 && ((which==0 && start->attr_var==VAR_attr) || (which==1 && start->attr_var>=1)))
    {
      return 1;
    }

    start=start->next_entry;
  }
  //printf("\n");
  return 0;
}


symbol_table_entry* return_from_table(symbol_table* table,char* name,int which){
  symbol_table_entry* start=table->start;
  //&& ((which==0 && start->attr_var==VAR_attr) || (which==1 && start->attr_var==FUNCTION_attr))
  while(start!=NULL){
    if (strcmp(name,start->name_var)==0 ){
      return start;
    }
    start=start->next_entry;
  }
  return NULL;
}




symbol_table_entry* return_from_scope(symbol_table* table,char* name,int which){
  if (table==NULL){return 0;}
  symbol_table_entry* tmp=return_from_table(table,name,which);
  if (tmp!=NULL){
    return tmp;
  }
  else{
  return return_from_scope(table->parent,name,which);
}
}

int find_in_scope(symbol_table* table,char* name,int which){
  if (table==NULL){return 0;}
  if (find_in_table(table,name,which)==1){
    return 1;
  }
  else{
    //printf("------------------------------------------WE USED parent\n");
    return find_in_scope(table->parent,name,which);
  }

}
error_node* symbol_function_all(node_ast* curr){


  printf("TUCK IT BROTHA\n");printf("IT IS IN\n");

  error_node* curr_error1=(error_node*)malloc(sizeof(error_node));
  strcpy(curr_error1->var_name,"!START");
  curr_error1->error_type=-1;
  curr_error1->line_number=-1;
  curr_error1->next=NULL;
  error_node* tmp_error=curr_error1;
  symbol_table* curr_table=create_symbol_table(NULL);

  node_ast* child=curr->children->node;
  int x=0;

  /*

  tmp_error=add_error(tmp_error,"first",1,10);
  tmp_error=add_error(tmp_error,"second",1,20);
  tmp_error=add_error(tmp_error,"third",1,30);
  tmp_error=add_error(tmp_error,"fourth",1,40);
  */

  int offset=0;

  while(child!=NULL){

    printf("Iteration %d\n",x);
    x++;

    symbol_function(child,curr_table,tmp_error,&offset);
    //printf("After end of one %s %d\n",tmp_error->var_name,tmp_error->line_number);
    //printf("just ended\n");
    while (tmp_error->next!=NULL){tmp_error=tmp_error->next;}
    child=child->sibling;
  }

  printf("--------------------------------------Symbol table--------------------\n");

  print_symbol_table(curr_table);

  return curr_error1;
}


void sizeofmatrix(node_ast* var,symbol_table_entry* ent1){
  node_ast* child_node=var->children->node;
  int total=0;
  int r=0;
  int l=0;
  while(child_node!=NULL){
    node_ast* child2=child_node->children->node;
    l=0;
    while(child2!=NULL){
      child2=child2->sibling;
      l++;
    }
    child_node=child_node->sibling;
    r++;
  }

  //printf("&&&&&&&&&&&&&&&&& %d\n",total);
  ent1->size=(l*r*2);
  ent1->matrix_col=l;
  ent1->matrix_col=r;
  return;
}


void symbol_function(node_ast* curr,symbol_table* curr_table,error_node* curr_error,int* offset){




      //declaration statement

      if (curr->tk==declarationStmt){

        printf("IN DECLARATION\n");
        char* string_print=(char*)malloc(sizeof(char)*20);

        symbol t=curr->children->node->tk;

        node_ast* var=curr->children->next->node;



        int add_offset=0;
        if (t==INT){add_offset=2;}
        if (t==STRING){add_offset=0;}
        if (t==REAL){add_offset=4;}
        if (t==MATRIX){add_offset=0;printf("yes it was a matrix\n");}

        get_string(t,string_print);
        printf("Variable %s is %s\n",var->entry,string_print);
        while(var!=NULL){
          int line_number=var->line_number;
          get_string(t,string_print);
          printf("Variable %s is %s\n",var->entry,string_print);
          int f=find_in_scope(curr_table,var->entry,0);
          if (f==1)
          {
            curr_error=add_error(curr_error,var->entry,1,line_number);
          }
          else
          {
          add_symbol_table(curr_table,t,var->entry,VAR_attr,NULL,(*offset),0,add_offset);
          (*offset)=(*offset)+add_offset;
          printf("*******offset %d\n",*offset);
          }
          var=var->sibling;
        }
      }

      //Assignment statement


      if (curr->tk==ASSIGNOP){



      //assigning to sizeof
      if (curr->children->next->node->tk==sizeofexpr){

      printf("IN ASSIGN SIZE\n");

      node_ast* left=curr->children->node;
      node_ast* size_right=curr->children->next->node->children->node;
      int line_number=left->line_number;
      int f1=find_in_scope(curr_table,left->entry,0);
      int f2=find_in_scope(curr_table,size_right->entry,0);




      if (f1==0){curr_error=add_error(curr_error,left->entry,1,line_number);}

      if (f2==0){

        curr_error=add_error(curr_error,size_right->entry,2,line_number);
      }
      else{
        symbol_table_entry* tmp=  return_from_scope(curr_table,size_right->entry,0);
        if (!(tmp->type_var==STRING || tmp->type_var==MATRIX)){

           curr_error=add_error(curr_error,"sizeexpression",3,line_number);
        }
      }



    }

    //assigning arithmetic arithmeticExpression

    // assigning to function
    if (curr->children->next->node->tk==arithmeticExpression){


    printf("Arithemetic \n");

    char* name_function=(char*)malloc(sizeof(char)*20);
    node_ast* left=curr->children->node;
    int line_number=left->line_number;


    //printf("IN arithemetic ------> %s  %d\n",left->entry,line_number);
    int f1=find_in_scope(curr_table,left->entry,0);
    symbol left_type=FUNCTION;
    if (f1==0){
      curr_error=add_error(curr_error,left->entry,1,line_number);
      printf("%s: Variable not found\n",left->entry);
    }
    else{
      symbol_table_entry* tmp=return_from_scope(curr_table,left->entry,0);
      if (tmp!=NULL){
        left_type=tmp->type_var;

      }
    int offset_cal=0;
    if (tmp->init==0){
      tmp->init=1;
      if (tmp->type_var==STRING || tmp->type_var==MATRIX){
        offset_cal=1;
      }
    }
    node_ast* child = curr->children->next->node->children->node;

    /*
    printf("----------printing tree----------------------------\n");

    print_tree(child);

    printf("----------printing tree end----------------------------\n");
    */


    symbol tk=recursive_check(child,curr_error,curr_table,line_number,offset_cal,left->entry);

    if (offset_cal==1){
      symbol_table_entry* left_en=return_from_scope(curr_table,left->entry,0);
      left_en->offset= *offset;
      *(offset)=*(offset)+left_en->size;

    }


    char p1[20];get_string(tk,p1);
    printf("^^^^^^ returned type %s %d\n",p1,line_number);

    while (curr_error->next!=NULL){curr_error=curr_error->next;}
    if (tk==FUNCTION){
      return;
    }
    else{
      if (tk!=left_type){

      printf("Error because of mistmatch\n");

      char* string_print=(char*)malloc(sizeof(char)*20);
      char* string_print2=(char*)malloc(sizeof(char)*20);
      get_string(tk,string_print);
      get_string(left_type,string_print2);

      printf("tk: %s left_type: %s\n",string_print,string_print2);

      curr_error=add_error(curr_error,"type",4,line_number);
    }
  }
  }
}


  //assigning to function call statement
  /*
  if (curr->children->next->node->tk==funcCallStmt){

  char* name_function=(char*)malloc(sizeof(char)*20);
  node_ast* left=curr->children->node;
  while(left!=NULL){
    int f1=find_in_scope(curr_table,left->entry);
    if (f1==0){curr_error=add_error(curr_error,left->entry,1,line_number);}
    left=left->sibling;
  }
  node_ast* function_name=curr->children->next->node->children->node;
  int line_number=left->line_number;

  int f2=find_in_scope(curr_table,function_name->entry);

  if (f2==0){curr_error=add_error(curr_error,function_name->entry,2,line_number);}
  node_ast* var=curr->children->next->node->children->next->node;
  while(var!=NULL){
    if (find_in_scope(curr_table,var->entry)==0){
      curr_error=add_error(curr_error,var->entry,1,line_number);
    }
      var=var->sibling;
    }
  }
  */

}


    if (curr->tk==SQO)
    {

    if (curr->children->next->node->tk==functionCall)
    {

      printf("multi assign statement\n");

      //chceck if function exists

      node_ast* right_node=curr->children->next->node->children->node;

      char* function_name=right_node->entry;

      int line_number=right_node->line_number;

      int f2=find_in_scope(curr_table,function_name,1);
      if (f2==0){curr_error=add_error(curr_error,function_name,2,line_number);}


      else{

      symbol_table_entry* fun_def=return_from_scope(curr_table,function_name,1);


      //char* name_function=(char*)malloc(sizeof(char)*20);


      node_ast* left=curr->children->node;


      int x=0;
      while(left!=NULL){
        int line_number=left->line_number;
        int f1=find_in_scope(curr_table,left->entry,0);
        if (f1==0){curr_error=add_error(curr_error,left->entry,1,line_number);}
        else{
        if (x>=fun_def->param->l  || return_from_scope(curr_table,left->entry,0)->type_var!=fun_def->param->left[x]){
          curr_error=add_error(curr_error,left->entry,6,line_number);
        }
        }
        left=left->sibling;

      }
      if (x!=fun_def->param->l){
          curr_error=add_error(curr_error,"function incomp",6,line_number);
      }


      x=0;
      node_ast* var=curr->children->next->node->children->next->node;
      while(var!=NULL){
        if (find_in_scope(curr_table,var->entry,0)==0){
          curr_error=add_error(curr_error,var->entry,1,line_number);
        }
        else{
          symbol t;
          if (var->tk==ID){
            t=return_from_scope(curr_table,var->entry,0)->type_var;
          }
          else{
            t=var->tk;
          }
          if (x>=fun_def->param->r || t!=fun_def->param->right[x]){
            curr_error=add_error(curr_error,var->entry,6,line_number);
            //return_value=FUNCTION;
          }
        }
          var=var->sibling;
        }
      }


      }

      else

      {
        int num_child=0;

        node_ast* child1=curr->children->node;
        int line_number=child1->line_number;
        while(child1!=NULL){
          if (find_in_scope(curr_table,child1->entry,0)!=1)
          {
            curr_error=add_error(curr_error,child1->entry,1,line_number);
          }
          else{
            if (return_from_scope(curr_table,child1->entry,0)->type_var!=INT){
              curr_error=add_error(curr_error,child1->entry,2,line_number);
            }
          }
          child1=child1->sibling;
          num_child++;
        }
        if (num_child!=2){
          curr_error=add_error(curr_error,"matrix size",8,line_number);
        }
        node_ast* nameofmatrix=curr->children->next->node->children->node;
        if (return_from_scope(curr_table,nameofmatrix->entry,0)->type_var!=MATRIX){
          curr_error=add_error(curr_error,nameofmatrix->entry,7,line_number);
        }

      }

    }


    // assigning to function


      //IOSTMT
      if (curr->tk==READ){
        node_ast* var=curr->children->node;
        int line_number=var->line_number;
      if (find_in_scope(curr_table,var->entry,0)==0){
          curr_error=add_error(curr_error,var->entry,1,line_number);

      }
      }
      if (curr->tk==PRINT){
        node_ast* var=curr->children->node;
        int line_number=var->line_number;
      if (find_in_scope(curr_table,var->entry,0)==0){
          curr_error=add_error(curr_error,var->entry,1,line_number);
          //printf("Before end %s %d\n",curr_error->var_name,curr_error->line_number);
      }
      }


      if (curr->tk==FUNCTION)
      {

        printf("==================================================declaring function\n");

        node_ast* child=curr->children->next->node;
        char* name_of_function=child->entry;
        int line_number=child->line_number;
        int already_there=0;
        if (find_in_scope(curr_table,name_of_function,0) || find_in_scope(curr_table,name_of_function,1)==1){
          curr_error=add_error(curr_error,name_of_function,3,line_number);
          already_there=1;
        }
        symbol_table* new_symbol_table=create_symbol_table(curr_table);


        //curr_error=add_error(curr_error,name_of_function,2,line_number);

        symbol arr1[10];
        symbol  arr2[10];
        int arr1_len=0;
        int arr2_len=0;


        child=curr->children->node;

        int num_child=0;
        symbol function_return;
        while(child!=NULL){

          symbol t=child->tk;
          arr1[arr1_len]=t;
          if (num_child==0){function_return=t;}
          child=child->sibling;
          char* name_of_var=child->entry;


          //add_symbol_table(new_symbol_table,t,name_of_var,VAR_attr,NULL,0,0,);
          if (find_in_scope(curr_table,name_of_var,0)==1 || find_in_scope(curr_table,name_of_var,1)==1){
            curr_error=add_error(curr_error,name_of_var,3,line_number);
          }
          else{
            //printf("---this----\n");
            add_symbol_table(new_symbol_table,t,name_of_var,VAR_attr,NULL,0,0,0);
          }
          arr1_len++;
          child=child->sibling;
          num_child++;

        }

        child=curr->children->next->next->node;

        printf("This is different\n");
        while(child!=NULL){

          symbol t=child->tk;
          arr2[arr2_len]=t;
          child=child->sibling;
          char* name_of_var=child->entry;

          if (find_in_scope(curr_table,name_of_var,0)==1 || find_in_scope(curr_table,name_of_var,1)==1){
            curr_error=add_error(curr_error,name_of_var,3,line_number);
          }
          else{
          add_symbol_table(new_symbol_table,t,name_of_var,VAR_attr,NULL,0,0,0);
          }
          child=child->sibling;
          arr2_len++;
        }

        if (already_there==0){



        if (num_child==1 && function_return==STRING){
          add_symbol_table(curr_table,FUNCTION,name_of_function,FUNCTION_attr_str,new_symbol_table,0,0,0);
        }
        else if (num_child==1 && function_return==INT){
          add_symbol_table(curr_table,FUNCTION,name_of_function,FUNCTION_attr_int,new_symbol_table,0,0,0);
        }
        else if (num_child==1 && function_return==REAL){
          add_symbol_table(curr_table,FUNCTION,name_of_function,FUNCTION_attr_real,new_symbol_table,0,0,0);
        }
        else{
          add_symbol_table(curr_table,FUNCTION,name_of_function,FUNCTION_attr,new_symbol_table,0,0,0);
        }

        symbol_table_entry* fun_entry=return_from_scope(curr_table,name_of_function,1);
        int i=0;
        fun_entry->param->l=arr1_len;
        fun_entry->param->r=arr2_len;
        for(;i<arr1_len;i++){
          fun_entry->param->left[i]=arr1[i];
        }
        i=0;
        for(;i<arr2_len;i++){
          fun_entry->param->right[i]=arr2[i];
        }

      }

        child=curr->children->next->next->next->node;
        int offset2=0;


        while(child!=NULL){
        symbol_function(child,new_symbol_table,curr_error,&offset2);
        while(curr_error->next!=NULL){curr_error=curr_error->next;}
        child=child->sibling;
        }

        }




      if (curr->tk==IF){
      node_ast* var=curr->children->node;
      recursive_check2(var->children->node,curr_error,curr_table);
      while (curr_error->next!=NULL){curr_error=curr_error->next;}
      var=curr->children->next->node;
      symbol_function(var,curr_table,curr_error,offset);
      var=curr->children->next->next->node;
      while(var!=NULL){
      symbol_function(var,curr_table,curr_error,offset);
      var=var->sibling;
      }
      var=curr->children->next->next->next->node;
      while(var!=NULL){
      symbol_function(var,curr_table,curr_error,offset);
      var=var->sibling;
      }
    }


}
void print_tree(node_ast* child){
  int l=child->len;
  char p1[20];
  if (l==0){
    get_string(child->tk,p1);printf("%s\n",p1);
    return;
  }
  if (l==1){
    print_tree(child->children->node);
    return;
  }
  if (l==2){
    get_string(child->tk,p1);printf("%s\n",p1);
    print_tree(child->children->node);
    print_tree(child->children->next->node);
    return;
  }
}
void print_symbol_table(symbol_table* curr){
  symbol_table_entry* curr_entry=curr->start;
  while(curr_entry!=NULL){
    char p1[20];get_string(curr_entry->type_var,p1);
    printf("%s %d %s\n",curr_entry->name_var,curr_entry->offset,p1);
    if (curr_entry->next_table!=NULL){
      print_symbol_table(curr_entry->next_table);
    }
    curr_entry=curr_entry->next_entry;
  }
}
