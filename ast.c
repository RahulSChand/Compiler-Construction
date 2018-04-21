#include "ast.h"


node_ast* create_node_ast(int children,int tk,int is_leaf,node_ast* parent,int line_number){
  node_ast* curr=(node_ast*)malloc(sizeof(node_ast));
  curr->val_int=-10091;curr->val_float=-1000.0;
  curr->tk=tk;
  curr->line_number=line_number;
  curr->is_leaf=is_leaf;
  curr->len=children;
  int i=0;
  curr->parent=parent;
  curr->struct_arith=(struct arith*)malloc(sizeof(struct arith));
  curr->sibling=NULL;
  if (is_leaf==1){curr->children=NULL;return curr;}
  curr->children=(children_ast*)malloc(sizeof(children_ast));
  children_ast* iter=curr->children;
  for(;i<children-1;i++){
    iter->next=(children_ast*)malloc(sizeof(children_ast));
    iter=iter->next;
  }
  iter->next=NULL;
  return curr;
}

node_ast* step(node_tree* curr_node,node_ast* parent,node_ast* inh){
    if (curr_node->rule_number.l==-1){
      return NULL;
    }
    int left=curr_node->rule_number.l;
    int right=curr_node->rule_number.r;


    char* return_string=(char*)malloc(sizeof(char)*20);

    get_string(curr_node->sym,return_string);

    //printf("%s",return_string);//printf("  ");//printf("%d",curr_node->len);
    //printf("\n");

    if (left==mainFunction && right==0){
      node_ast* curr=create_node_ast(1,MAIN,0,parent,1);
      children_node* children_node_var=curr_node->head->next->next->next;
      curr->children->node=step(children_node_var->child,curr,NULL);
      return curr;
    }

    if (left==stmtsAndFunctionDefs && right==0){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=step(children_node_var   ->child,parent,NULL);
      curr->sibling=step(children_node_var->next->child,parent,NULL);
      return curr;
    }

    if (left==xstmt && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==xstmt && right==1){
      return NULL;
    }

    if (left==stmtOrFunctionDef && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==stmtOrFunctionDef && right==1){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }

    if (left==stmt && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==stmt && right==1){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==stmt && right==2){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==stmt && right==3){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==stmt && right==4){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }

    if (left==functionDef && right==0){
      node_ast* curr_children;
      node_ast* curr=create_node_ast(4,FUNCTION,0,parent,-1);
      children_node* children_node_var=curr_node->head->next->next;
      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next->next;
      int line_number=children_node_var->child->lex->line_no;
      curr->children->next->node=create_node_ast(0,FUNID,1,curr,line_number);
      strcpy(curr->children->next->node->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next->next;
      curr->children->next->next->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next;
      curr->children->next->next->next->node=step(children_node_var->child,curr,NULL);
      return curr;
    }

    if (left==parameter_list && right==0){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=step(children_node_var->child,parent,NULL);
      children_node_var=children_node_var->next;
      int line_number=children_node_var->child->lex->line_no;
      curr->sibling=create_node_ast(0,ID,1,parent,line_number);
      strcpy(curr->sibling->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next;
      curr->sibling->sibling=step(children_node_var->child,parent,NULL);
      return curr;
    }
    if (left==parameter_list && right==1){
      return NULL;
    }

    //Incorporates INT,REAL,MATRIX,STRING all of these.
    if (left==type && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,INT,1,parent,line_number);
      return curr;
    }
    if (left==type && right==1){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,REAL,1,parent,line_number);
      return curr;
    }
    if (left==type && right==2){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,STRING,1,parent,line_number);
      return curr;
    }
    if (left==type && right==3){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,MATRIX,1,parent,line_number);
      return curr;
    }

    if (left==remainingList && right==0){
      children_node* children_node_var=curr_node->head->next;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==remainingList && right==1){
      return NULL;
    }


    if (left==declarationStmt && right==0){
      node_ast* curr_children;
      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(2,declarationStmt,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);

      return curr;
    }

    if (left==var_list && right==0){
      node_ast* curr_children;
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,ID,1,parent,line_number);
      strcpy(curr->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next;
      curr->sibling=step(children_node_var->child,parent,NULL);

      return curr;
    }

    if (left==more_ids && right==0){
      children_node* children_node_var=curr_node->head->next;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==more_ids && right==1){
      return NULL;
    }


    if (left==assignmentStmt && right==0){
      node_ast* curr_children;
      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(2,ASSIGNOP,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);

      return curr;
    }
    if (left==assignmentStmt && right==1){
      node_ast* curr_children;
      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(2,SQO,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);

      return curr;
    }

    if (left==leftHandSide1 && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;

      printf("variable on left: %s %d\n",children_node_var->child->lex->var_name,line_number);

      node_ast* curr=create_node_ast(0,ID,1,parent,line_number);
      strcpy(curr->entry,children_node_var->child->lex->var_name);

      return curr;
    }


    if (left==leftHandSide2 && right==0){
      children_node* children_node_var=curr_node->head->next;
      return step(children_node_var->child,parent,NULL);
    }


    if (left==rightHandSide1 && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==rightHandSide1 && right==1){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }

    if (left==rightHandSide2 && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }

    if (left==rightHandSide2 && right==1){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }


    if (left==sizeofexpr && right==0){
      node_ast* curr=create_node_ast(1,sizeofexpr,0,parent,-1);
      children_node* children_node_var=curr_node->head->next;
      int line_number=children_node_var->child->lex->line_no;
      curr->children->node=create_node_ast(0,ID,1,curr,line_number);
      strcpy(curr->children->node->entry,children_node_var->child->lex->var_name);
      return curr;
    }


    if (left==funcCallStmt && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }


    /*
    if (left==functionCall && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    */

    if (left==functionCall && right==0){
      node_ast* curr_children;
      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(2,functionCall,0,parent,-1);
      printf("-----used this---\n");
      //curr->children->node=step(children_node_var->child,curr,NULL);
      int line_number=children_node_var->child->lex->line_no;
      curr->children->node=create_node_ast(0,FUNCTION,1,curr,line_number);
      strcpy(curr->children->node->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);

      return curr;
    }


    if (left==var_list2 && right==0){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=step(children_node_var->child,parent,NULL);
      curr->sibling=step(children_node_var->next->child,parent,NULL);
      return curr;
    }
    if (left==var_list2 && right==1){
      return NULL;
    }


    if (left==more_ids2 && right==0){
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==more_ids2 && right==1){
      return NULL;
    }


    if (left==ifStmt && right==0){
      node_ast* curr_children;
      node_ast* curr=create_node_ast(4,ifStmt,0,parent,-1);
      children_node* children_node_var=curr_node->head->next->next;
      //curr->children->node=step(children_node_var->child,curr,NULL);
      curr->children->node=create_node_ast(1,booleanExpression,0,curr,-1);
      curr->children->node->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next;
      curr->children->next->next->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next;
      curr->children->next->next->next->node=step(children_node_var->child,curr,NULL);
      return curr;
    }


    if (left==xifstmt && right==0){
      children_node* children_node_var=curr_node->head->next;
      node_ast* curr=step(children_node_var->child,parent,NULL);
      curr->sibling=step(children_node_var->next->child,parent,NULL);
      return curr;
    }
    if (left==xifstmt && right==1){
      return NULL;
    }

    if (left==otherStmts && right==0){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=step(children_node_var->child,parent,NULL);
      curr->sibling=step(children_node_var->next->child,parent,NULL);
      return curr;
    }
    if (left==otherStmts && right==1){
      return NULL;
    }

    if (left==ioStmt && right==0){
      children_node* children_node_var=curr_node->head->next->next;
      node_ast* curr=create_node_ast(1,READ,0,parent,-1);
      int line_number=children_node_var->child->lex->line_no;
      curr->children->node=create_node_ast(0,ID,1,curr,line_number);
      strcpy(curr->children->node->entry,children_node_var->child->lex->var_name);
      return curr;
    }
    if (left==ioStmt && right==1){
      children_node* children_node_var=curr_node->head->next->next;
      node_ast* curr=create_node_ast(1,PRINT,0,parent,-1);
      int line_number=children_node_var->child->lex->line_no;
      curr->children->node=create_node_ast(0,ID,1,curr,line_number);
      printf("print created %d\n",line_number);
      strcpy(curr->children->node->entry,children_node_var->child->lex->var_name);
      return curr;
    }


    if (left==arithmeticExpression && right==0){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=step(children_node_var->child,NULL,NULL);
      children_node_var=children_node_var->next;
      node_ast* curr_return=create_node_ast(1,arithmeticExpression,0,parent,-1);
      curr_return->children->node=step(children_node_var->child,parent,curr);
      curr->parent=curr_return;

      return curr_return;
    }


    if (left==arithmetic1 && right==0){
      children_node* children_node_var=curr_node->head;
      //node_ast* curr=create_node_ast(children_node_var->child->lex->tk_name,inh,)
      node_ast* curr=create_node_ast(2,children_node_var->child->head->child->sym,0,parent,-1);
      children_node_var=children_node_var->next;
      curr->children->node=inh; curr->children->next->node=step(children_node_var->child,NULL,curr);
      children_node_var = children_node_var->next;
      node_ast* curr_return = step(children_node_var->child,parent,curr);

      return curr_return;
    }
    if (left==arithmetic1 && right==1){
      children_node* children_node_var=curr_node->head;
      return inh;
    }


    if (left==arithmeticExpression2 && right==0){
      children_node* children_node_var=curr_node->head;

      char* return_string=(char*)malloc(sizeof(char)*20);

      get_string(children_node_var->child->sym,return_string);

      //printf("-----------------------%s--------------------------",return_string);
      //printf("\n");

      node_ast* curr=step(children_node_var->child,NULL,NULL);
      children_node_var=children_node_var->next;
      node_ast* curr_return=step(children_node_var->child,parent,curr);
      curr->parent=curr_return;
      return curr_return;

    }


    if (left==arithmetic2 && right==0){
      children_node* children_node_var=curr_node->head;
      //node_ast* curr=create_node_ast(children_node_var->child->lex->tk_name,inh,)
      node_ast* curr=create_node_ast(2,children_node_var->child->head->child->sym,0,parent,-1);
      children_node_var=children_node_var->next;
      curr->children->node=inh; curr->children->next->node=step(children_node_var->child,NULL,curr);
      children_node_var = children_node_var->next;
      node_ast* curr_return = step(children_node_var->child,parent,curr);

      return curr_return;
    }
    if (left==arithmetic2 && right==1){
      children_node* children_node_var=curr_node->head;
      return inh;
    }


    if (left==something && right==0){
      //printf("-----------------------1--------------------------\n");
      children_node* children_node_var=curr_node->head->next;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==something && right==1){
        //printf("-----------------------2--------------------------\n");
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==something && right==2){
        //printf("-----------------------3--------------------------\n");
      children_node* children_node_var=curr_node->head;
      return step(children_node_var->child,parent,NULL);
    }


    if (left==booleanExpression && right==0){

      children_node* children_node_var=curr_node->head->next;
      node_ast* curr=create_node_ast(2,children_node_var->next->next->child->sym,0,parent,-1);

      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next->next->next->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);
      return curr;
    }
    if (left==booleanExpression && right==1){
      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(1,AND,0,parent,-1);
      children_node_var=children_node_var->next->next;
      curr->children->node=step(children_node_var->child,curr,NULL);
      return curr;
    }
    if (left==booleanExpression && right==2){

      children_node* children_node_var=curr_node->head;
      node_ast* curr=create_node_ast(2,children_node_var->next->child->sym,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      children_node_var=children_node_var->next;
      curr->children->next->node=step(children_node_var->child,curr,NULL);
      return curr;
    }

    if (left==cons_var && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,ID,1,parent,line_number);
      strcpy(curr->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next;
      curr->sibling=step(children_node_var->child,parent,NULL);
      return curr;
    }
    if (left==cons_var && right==1){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,NUM,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      curr->val_int=children_node_var->child->lex->int_val;
      return curr;
    }
    if (left==cons_var && right==2){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,RNUM,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      curr->val_float=children_node_var->child->lex->float_val;
      return curr;
    }

    if (left==matrix && right==0){
      children_node* children_node_var=curr_node->head->next;
      //printf(" A MATRIX NODE IS CREAED\n");
      node_ast* curr=create_node_ast(1,MATRIX,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      return curr;
    }


    if (left==rows && right==0){
      children_node* children_node_var=curr_node->head;
      //node_ast* curr=step(children_node_var->child,parent,NULL);
      node_ast* curr=create_node_ast(1,row,0,parent,-1);
      curr->children->node=step(children_node_var->child,curr,NULL);
      curr->sibling=step(children_node_var->next->child,parent,NULL);
      return curr;
    }


    if (left==rows_temp && right==0){
      children_node* children_node_var=curr_node->head->next;
      //node_ast* curr=create_node_ast(1,row,0,parent,-1);
      //curr->children->node=step(children_node_var->child,curr,NULL);
      node_ast* curr=step(children_node_var->child,parent,NULL);
      return curr;
    }
    if (left==rows_temp && right==1){
      return NULL;
    }


    if (left==row && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,NUM,1,parent,line_number);
      curr->val_int=children_node_var->child->lex->int_val;
      children_node_var=children_node_var->next;
      curr->sibling=step(children_node_var->child,parent,NULL);
      return curr;
    }

    if (left==more_vals && right==0){
      children_node* children_node_var=curr_node->head->next;
      return step(children_node_var->child,parent,NULL);
    }
    if (left==more_vals && right==1){
      children_node* children_node_var=curr_node->head->next;
      return NULL;
    }


    if (left==var && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,ID,1,parent,line_number);
      strcpy(curr->entry,children_node_var->child->lex->var_name);
      children_node_var=children_node_var->next;
      curr->sibling=step(children_node_var->child,parent,NULL);
      return curr;
    }
    if (left==var && right==1){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,NUM,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      curr->val_int=children_node_var->child->lex->int_val;
      return curr;
    }
    if (left==var && right==2){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,RNUM,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      curr->val_float=children_node_var->child->lex->float_val;
      return curr;
    }
    if (left==var && right==3){


      //printf("I called a string\n");

      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,STR,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      strcpy(curr->entry,children_node_var->child->lex->var_name);
      return curr;
    }

    if (left==var && right==4){
      children_node* children_node_var=curr_node->head;
      //int line_number=children_node_var->child->lex->line_no;
      //node_ast* curr=create_node_ast(0,STR,1,parent,line_number);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      //strcpy(curr->entry,children_node_var->child->lex->var_name);
      //return curr;
      return step(children_node_var->child,parent,NULL);
    }





    if (left==svar && right==0){
      children_node* children_node_var=curr_node->head;
      int line_number=children_node_var->child->lex->line_no;
      node_ast* curr=create_node_ast(0,NUM,1,parent,line_number);
      curr->val_int=children_node_var->child->lex->int_val;
      curr->sibling=create_node_ast(0,NUM,1,parent,line_number);
      children_node_var=children_node_var->next;
      curr->sibling->val_int=children_node_var->child->lex->int_val;
      return curr;
    }
    if (left==svar && right==1){
      return NULL;
    }
}

/*
void print_ast(node_ast* curr){

}
*/
