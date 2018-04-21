// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "parser.h"
int num_terminals=39;
int num_non_terminals=45;
int null_number=84;
int end_marker=85;
//checked
symbol get_symbol(char* token){
  if (strcmp(token,"xstmt")==0){return xstmt;}
  if (strcmp(token,"xifstmt")==0){return xifstmt;}
  if (strcmp(token,"var_list")==0){return var_list;}
  if (strcmp(token,"var_list2")==0){return var_list2;}
  if (strcmp(token,"var")==0){return var;}
  if (strcmp(token,"type")==0){return type;}
  if (strcmp(token,"svar")==0){return svar;}
  if (strcmp(token,"stmtsAndFunctionDefs")==0){return stmtsAndFunctionDefs;}
  if (strcmp(token,"stmtOrFunctionDef")==0){return stmtOrFunctionDef;}
  if (strcmp(token,"stmt")==0){return stmt;}
  if (strcmp(token,"something")==0){return something;}
  if (strcmp(token,"sizeofexpr")==0){return sizeofexpr;}
  if (strcmp(token,"rows_temp")==0){return rows_temp;}
  if (strcmp(token,"rows")==0){return rows;}
  if (strcmp(token,"row")==0){return row;}
  if (strcmp(token,"rightHandSide2")==0){return rightHandSide2;}
  if (strcmp(token,"rightHandSide1")==0){return rightHandSide1;}
  if (strcmp(token,"remainingList")==0){return remainingList;}
  if (strcmp(token,"relationalOp")==0){return relationalOp;}
  if (strcmp(token,"parameter_list")==0){return parameter_list;}
  if (strcmp(token,"otherStmts")==0){return otherStmts;}
  if (strcmp(token,"operator2")==0){return operator2;}
  if (strcmp(token,"operator1")==0){return operator1;}
  if (strcmp(token,"more_vals")==0){return more_vals;}
  if (strcmp(token,"more_ids")==0){return more_ids;}
  if (strcmp(token,"more_ids2")==0){return more_ids2;}
  if (strcmp(token,"matrix")==0){return matrix;}
  if (strcmp(token,"mainFunction")==0){return mainFunction;}
  if (strcmp(token,"logicalOp2")==0){return logicalOp2;}
  if (strcmp(token,"logicalOp1")==0){return logicalOp1;}
  if (strcmp(token,"leftHandSide2")==0){return leftHandSide2;}
  if (strcmp(token,"leftHandSide1")==0){return leftHandSide1;}
  if (strcmp(token,"ioStmt")==0){return ioStmt;}
  if (strcmp(token,"ifStmt")==0){return ifStmt;}
  if (strcmp(token,"functionDef")==0){return functionDef;}
  if (strcmp(token,"functionCall")==0){return functionCall;}
  if (strcmp(token,"funcCallStmt")==0){return funcCallStmt;}
  if (strcmp(token,"declarationStmt")==0){return declarationStmt;}
  if (strcmp(token,"cons_var")==0){return cons_var;}
  if (strcmp(token,"booleanExpression")==0){return booleanExpression;}
  if (strcmp(token,"assignmentStmt")==0){return assignmentStmt;}
  if (strcmp(token,"arithmeticExpression2")==0){return arithmeticExpression2;}
  if (strcmp(token,"arithmeticExpression")==0){return arithmeticExpression;}
  if (strcmp(token,"arithmetic2")==0){return arithmetic2;}
  if (strcmp(token,"arithmetic1")==0){return arithmetic1;}
  if (strcmp(token,"STRING")==0){return STRING;}
  if (strcmp(token,"STR")==0){return STR;}
  if (strcmp(token,"SQO")==0){return SQO;}
  if (strcmp(token,"SQC")==0){return SQC;}
  if (strcmp(token,"SIZE")==0){return SIZE;}
  if (strcmp(token,"SEMICOLON")==0){return SEMICOLON;}
  if (strcmp(token,"RNUM")==0){return RNUM;}
  if (strcmp(token,"REAL")==0){return REAL;}
  if (strcmp(token,"READ")==0){return READ;}
  if (strcmp(token,"PRINT")==0){return PRINT;}
  if (strcmp(token,"PLUS")==0){return PLUS;}
  if (strcmp(token,"OR")==0){return OR;}
  if (strcmp(token,"OP")==0){return OP;}
  if (strcmp(token,"NUM")==0){return NUM;}
  if (strcmp(token,"NOT")==0){return NOT;}
  if (strcmp(token,"NE")==0){return NE;}
  if (strcmp(token,"MUL")==0){return MUL;}
  if (strcmp(token,"MINUS")==0){return MINUS;}
  if (strcmp(token,"MATRIX")==0){return MATRIX;}
  if (strcmp(token,"MAIN")==0){return MAIN;}
  if (strcmp(token,"LT")==0){return LT;}
  if (strcmp(token,"LE")==0){return LE;}
  if (strcmp(token,"INT")==0){return INT;}
  if (strcmp(token,"IF")==0){return IF;}
  if (strcmp(token,"ID")==0){return ID;}
  if (strcmp(token,"GT")==0){return GT;}
  if (strcmp(token,"GE")==0){return GE;}
  if (strcmp(token,"FUNID")==0){return FUNID;}
  if (strcmp(token,"FUNCTION")==0){return FUNCTION;}
  if (strcmp(token,"EQ")==0){return EQ;}
  if (strcmp(token,"EPS")==0){return EPS;}
  if (strcmp(token,"ENDIF")==0){return ENDIF;}
  if (strcmp(token,"END")==0){return END;}
  if (strcmp(token,"ELSE")==0){return ELSE;}
  if (strcmp(token,"DIV")==0){return DIV;}
  if (strcmp(token,"COMMA")==0){return COMMA;}
  if (strcmp(token,"CL")==0){return CL;}
  if (strcmp(token,"ASSIGNOP")==0){return ASSIGNOP;}
  if (strcmp(token,"AND")==0){return AND;}
  if (strcmp(token,"null")==0){return null;}
  if (strcmp(token,"END_MARKER")==0){return END_MARKER;}
}

//checked
void print_symbol(symbol s){
  if (s==xstmt){printf("xstmt");}
if (s==xifstmt){printf("xifstmt");}
if (s==var_list){printf("var_list");}
if (s==var_list2){printf("var_list2");}
if (s==var){printf("var");}
if (s==type){printf("type");}
if (s==svar){printf("svar");}
if (s==stmtsAndFunctionDefs){printf("stmtsAndFunctionDefs");}
if (s==stmtOrFunctionDef){printf("stmtOrFunctionDef");}
if (s==stmt){printf("stmt");}
if (s==something){printf("something");}
if (s==sizeofexpr){printf("sizeofexpr");}
if (s==rows_temp){printf("rows_temp");}
if (s==rows){printf("rows");}
if (s==row){printf("row");}
if (s==rightHandSide2){printf("rightHandSide2");}
if (s==rightHandSide1){printf("rightHandSide1");}
if (s==remainingList){printf("remainingList");}
if (s==relationalOp){printf("relationalOp");}
if (s==parameter_list){printf("parameter_list");}
if (s==otherStmts){printf("otherStmts");}
if (s==operator2){printf("operator2");}
if (s==operator1){printf("operator1");}
if (s==more_vals){printf("more_vals");}
if (s==more_ids){printf("more_ids");}
if (s==more_ids2){printf("more_ids2");}
if (s==matrix){printf("matrix");}
if (s==mainFunction){printf("mainFunction");}
if (s==logicalOp2){printf("logicalOp2");}
if (s==logicalOp1){printf("logicalOp1");}
if (s==leftHandSide2){printf("leftHandSide2");}
if (s==leftHandSide1){printf("leftHandSide1");}
if (s==ioStmt){printf("ioStmt");}
if (s==ifStmt){printf("ifStmt");}
if (s==functionDef){printf("functionDef");}
if (s==functionCall){printf("functionCall");}
if (s==funcCallStmt){printf("funcCallStmt");}
if (s==declarationStmt){printf("declarationStmt");}
if (s==cons_var){printf("cons_var");}
if (s==booleanExpression){printf("booleanExpression");}
if (s==assignmentStmt){printf("assignmentStmt");}
if (s==arithmeticExpression2){printf("arithmeticExpression2");}
if (s==arithmeticExpression){printf("arithmeticExpression");}
if (s==arithmetic2){printf("arithmetic2");}
if (s==arithmetic1){printf("arithmetic1");}
if (s==STRING){printf("STRING");}
if (s==STR){printf("STR");}
if (s==SQO){printf("SQO");}
if (s==SQC){printf("SQC");}
if (s==SIZE){printf("SIZE");}
if (s==SEMICOLON){printf("SEMICOLON");}
if (s==RNUM){printf("RNUM");}
if (s==REAL){printf("REAL");}
if (s==READ){printf("READ");}
if (s==PRINT){printf("PRINT");}
if (s==PLUS){printf("PLUS");}
if (s==OR){printf("OR");}
if (s==OP){printf("OP");}
if (s==NUM){printf("NUM");}
if (s==NOT){printf("NOT");}
if (s==NE){printf("NE");}
if (s==MUL){printf("MUL");}
if (s==MINUS){printf("MINUS");}
if (s==MATRIX){printf("MATRIX");}
if (s==MAIN){printf("MAIN");}
if (s==LT){printf("LT");}
if (s==LE){printf("LE");}
if (s==INT){printf("INT");}
if (s==IF){printf("IF");}
if (s==ID){printf("ID");}
if (s==GT){printf("GT");}
if (s==GE){printf("GE");}
if (s==FUNID){printf("FUNID");}
if (s==FUNCTION){printf("FUNCTION");}
if (s==EQ){printf("EQ");}
if (s==EPS){printf("EPS");}
if (s==ENDIF){printf("ENDIF");}
if (s==END){printf("END");}
if (s==ELSE){printf("ELSE");}
if (s==DIV){printf("DIV");}
if (s==COMMA){printf("COMMA");}
if (s==CL){printf("CL");}
if (s==ASSIGNOP){printf("ASSIGNOP");}
if (s==AND){printf("AND");}
if (s==null){printf("null");}
if (s==END_MARKER){printf("END_MARKER");}
}


grammar* grammar_from_file(FILE* fp){


  char* buffer=(char*)malloc(sizeof(char)*200);
  size_t read;
  size_t size;
  int unique_id=0;
  grammar* G=(grammar*)malloc(sizeof(grammar));
  G->array_rules=(symbol_terminal*)malloc(sizeof(symbol_terminal)*num_non_terminals);

  int i=0;
  int j=0;
  for(;i<num_non_terminals;i++){
    j=0;
    G->array_rules[i].rules=(rule*)malloc(sizeof(rule)*8);
    G->array_rules[i].no_rules=0;
    G->array_rules[i].first=create_empty_set();
    G->array_rules[i].follow=create_empty_set();
    G->array_rules[i].first_nikaal=0;
    for(;j<6;j++){
        G->array_rules[i].rules[j].right=(symbol*)malloc(sizeof(symbol)*12);
        G->array_rules[i].rules[j].len=0;
    }
  }

  int line_count=0;
  while((read=getline(&buffer,&size,fp))!=-1){
    line_count++;
    int len=strlen(buffer);
    char* token;
    token=strtok(buffer," ");
    int term=get_symbol(token);

    int r_num=G->array_rules[term].no_rules;
    int r_num2=0;
    token=strtok(NULL," \n");
    token=strtok(NULL," \n");


    while(token!=NULL){
      //printf("%s ",token);
      if (strcmp(token,"|")==0){

        r_num++;
        G->array_rules[term].no_rules++;
        r_num2=0;
        token=strtok(NULL," \n");
        //printf("%s\n",token);
        continue;
      }


      r_num2=G->array_rules[term].rules[r_num].len;
      G->array_rules[term].rules[r_num].right[r_num2]=get_symbol(token);
      //print_symbol(get_symbol(token));printf("  %s",token);printf("\n");
      G->array_rules[term].rules[r_num].len++;
      token=strtok(NULL," \n");
    }
    //printf("\n");
    G->array_rules[term].no_rules++;

    }

    return G;
  }

void add_everything(set* s,set* tmp,int add_null){
  //set* tmp=g->array_rules[index].first;
  int len=tmp->len;
  set_node* tmp_node=tmp->head;
  int i=0;
  for(;i<len;i++){
    if (tmp_node->member==null_number && add_null==0){tmp_node=tmp_node->next;continue;}
    add_member(s,tmp_node->member);
    tmp_node=tmp_node->next;
  }
}


int rule_first(rule* r,grammar* g,int index,int start){
    if (start==r->len){add_member(g->array_rules[index].first,null_number);return 1;}

    symbol s=r->right[start];
    if (s==null_number){add_member(g->array_rules[index].first,s);return 1;}
    if (is_terminal(s)==1)
    {
      add_member(g->array_rules[index].first,s);return 1;
    }
    if (is_non_terminal(s)==1){

    if (g->array_rules[s].first_nikaal==1){
      if (is_member(g->array_rules[s].first,null_number)==0){
        //add everything in the set write another function
        add_everything(g->array_rules[index].first,g->array_rules[s].first,1);
        return 1;
      }
      else{
        add_everything(g->array_rules[index].first,g->array_rules[s].first,0);
        return rule_first(r,g,index,start+1);
      }
    }
    else{
      return -1;
    }

    }
}

int rule_first2(rule* r,grammar* g,int index,int start,symbol left){
    if (start==r->len){

      add_everything(g->array_rules[index].follow,g->array_rules[left].follow,1);return 1;
    }


    symbol s=r->right[start];
    //printf("%d\n",index);
    //printf(" \n");
    if (is_terminal(s)==1){

      add_member(g->array_rules[index].follow,s);
      return 1;
    }

    if (is_non_terminal(s)==1){
      if (is_member(g->array_rules[s].first,null_number)==0){

        add_everything(g->array_rules[index].follow,g->array_rules[s].first,0);
        return 1;
      }
      else{

        add_everything(g->array_rules[index].follow,g->array_rules[s].first,0);
        return rule_first2(r,g,index,start+1,left);
      }
    }

}


void first(grammar* G){

    int end_base;
    int first_num=0;
    int x=0;
    int kitna_total=0;
    while(1){

      //printf("%d \n",kitna_total);
      int i=0;
      for(;i<num_non_terminals;i++){
        if (G->array_rules[i].first_nikaal!=1){
          int num_rules=G->array_rules[i].no_rules;
          int j=0;
          int kitna=0;
          for(;j<num_rules;j++){
            int status=rule_first(&(G->array_rules[i].rules[j]),G,i,0);
            if (status>0){kitna++;}
            else{break;}
          }
          //printf("%d %d    %d\n",kitna,num_rules,kitna_total);
          if (kitna==num_rules){
            G->array_rules[i].first_nikaal=1;
            kitna_total++;
          }
        }
      }
      //printf("%d BREAK\n",kitna_total);
      if (kitna_total==num_non_terminals){

        break;
      }

  }
}


int is_non_terminal(symbol s){
  if (s<num_non_terminals){
    return 1;
  }
  return 0;
}

int is_terminal(symbol s){
  if (s>=num_non_terminals && s<null_number){
    return 1;
  }
  return 0;
}


void follow(grammar* G){
    add_member(G->array_rules[0].follow,89);  //ADD END MARKER
    int i=0;
    //SETS KEEP CHANGING
    int iter=0;
    int set_change=0;
    int sum=0;
    while (1){
    i=0;
    set_change=0;
    int c=0;
    sum=0;
    for(;c<num_non_terminals;c++){
      sum=sum+(G->array_rules[c].follow)->len;
    }
    for(;i<num_non_terminals;i++){
      int j=0;
      int len_follow=size(G->array_rules[i].follow);
      for(;j<G->array_rules[i].no_rules;j++){
          //symbol tmp_left=i;
          int k=0;
          for(;k<G->array_rules[i].rules[j].len-1;k++)
        {
          symbol curr_symbol=G->array_rules[i].rules[j].right[k];
          if (is_non_terminal(curr_symbol)==1){
          rule_first2(&(G->array_rules[i].rules[j]),G,curr_symbol,k+1,i);
          }
        }

        k=G->array_rules[i]. rules[j].len-1;
        symbol curr_symbol=G->array_rules[i].rules[j].right[k];
        if (is_non_terminal(curr_symbol)==1){
        add_everything(G->array_rules[curr_symbol].follow,G->array_rules[i].follow,1);
      }
    }

  }


  iter++;int sum2=0;
  c=0;
  for(;c<num_non_terminals;c++){
    sum2=sum2+(G->array_rules[c].follow)->len;
  }
  if (sum==sum2){
    //printf("************************");printf(" %d \n",iter);
    break;}
}
}

void print_members(set* s){
  int i=0;
  set_node* tmp=s->head;
  for(;i<s->len;i++){
    print_symbol(tmp->member);printf(" ");
    tmp=tmp->next;
  }
  printf("\n");
}

void print_grammar(grammar* G){
  int i=0;
  for(;i<48;i++){

    printf("%d : ",i);print_symbol(i);printf(" : \n");
    int j=0;
    for(;j<G->array_rules[i].no_rules;j++){
      int k=0;
      printf(" ");
      for(;k<G->array_rules[i].rules[j].len;k++){

      }
    }

  }
}

int is_in_first(rule* r,symbol s,int start,int left_symbol,grammar* G){
  if (start==r->len){
    if (is_member(G->array_rules[left_symbol].follow,s)==1){return 1;}
    else{return 0;}
  }

  symbol tmp=r->right[start];
  if (is_terminal(r->right[start])){
    if (tmp==s){return 1;}
    else{return 0;}
  }
  if (is_non_terminal(tmp)){
    if (is_member(G->array_rules[tmp].first,null_number)==0){
      if (is_member(G->array_rules[tmp].first,s)==1){return 1;}
      else{return 0;}
    }
    else{
      if (is_member(G->array_rules[tmp].first,s)==1){return 1;}
      else{
        return is_in_first(r,s,start,left_symbol,G);
      }
    }
  }
  if (tmp==null_number){
    if (is_member(G->array_rules[left_symbol].follow,s)==1){return 1;}
    else{return 0;}
  }
}





table_val** fill_table(grammar* G){
  table_val** table=(table_val**)malloc(sizeof(table_val*)*num_non_terminals);
  int i=0;
  for(;i<num_non_terminals;i++){
    table[i]=(table_val*)malloc(sizeof(table_val)*num_terminals);
  }
  int j=0;i=0;
  for(;i<num_non_terminals;i++){
    j=0;
    for(;j<num_terminals;j++){
      table[i][j].left=-1;table[i][j].right=-1;
    }
  }
  i=0;
  for(;i<num_non_terminals;i++){
    j=0;
    for(;j<num_terminals;j++){
      int terminal=num_non_terminals+j;
      int k=0;
      for(;k<G->array_rules[i].no_rules;k++){
        if (is_in_first(&(G->array_rules[i].rules[k]),terminal,0,i,G)==1){

          /*
          if (table[i][j].left!=-1){printf("LL1 NAHI HAI ");
          printf("%d %d ",table[i][j].right,k);
          print_symbol(i);printf("  ");print_symbol(terminal);
          printf(" **************************************\n");}
          */

          table[i][j].left=i;
          table[i][j].right=k;
        }
      }
    }
  }
  return table;
}



children_node* new_children_node(){
  children_node* ret=(children_node*)malloc(sizeof(children_node));
  return ret;
}

node_tree* add_node_tree(node_tree* curr_node,symbol s,node_tree* parent){
  curr_node->len++;
  node_tree* new_node=(node_tree*)malloc(sizeof(node_tree));
  new_node->parent_ptr=parent;
  new_node->rule_number.l=-1;
  new_node->rule_number.r=-1;
  new_node->len=0;
  new_node->sym=s;
  new_node->head=NULL;
  children_node* tmp=curr_node->head;
  if (tmp==NULL){
    curr_node->head=new_children_node();
    curr_node->head->child=new_node;
    curr_node->head->next=NULL;
    //curr_node->head=new_node;
    return new_node;
  }
  while(tmp->next!=NULL){
    tmp=tmp->next;
  }
  tmp->next=new_children_node();
  tmp->next->child=new_node;
  tmp->next->next=NULL;
  return new_node;
}


node_tree* parse(grammar *G,stack* stk,table_val** table,tk_node** curr_lex,node_tree* curr_node,head_list* error){

  //if (s->len==0){return void}
  if (*curr_lex==NULL){
    return curr_node;
  }
  symbol top_sym=top(stk);

  //if (top_sym==NULL){printf("it is null\n");}

  symbol tk_name=(*curr_lex)->tk_lexeme->tk_name;
  int line_no=(*curr_lex)->tk_lexeme->line_no;
  char* lexeme_value=(*curr_lex)->tk_lexeme->var_name;
  //print_symbol(top_sym);printf("  ");print_symbol(tk_name);printf(" %d ",line_no);
  //printf(" \n");

  if (top_sym==null){

    pop(stk);
    return curr_node;
  }

  //printf("%d\n",line_no);printf(" ");

  if (top_sym==tk_name){
    pop(stk);
    *curr_lex=(*curr_lex)->next;
    curr_node->is_leaf=1;
    curr_node->sym=top_sym;
    return curr_node;
  }

  if (is_terminal(top_sym)==1)
  {
    //printf("########## error: ");print_symbol(tk_name);printf("  ");print_symbol(top_sym);printf(" \n");
    recovery_node2(error,line_no,0,lexeme_value,top_sym,tk_name,G);
    pop(stk);
    if (*curr_lex==NULL){return curr_node;}
    *curr_lex=(*curr_lex)->next;

    return curr_node;
  }

  int left_arg=top_sym;int right_arg=tk_name;
  if (is_terminal(top_sym)==1){left_arg=top_sym-num_non_terminals;}
  if (is_terminal(tk_name)==1){right_arg=tk_name-num_non_terminals;}


  int left=table[left_arg][right_arg].left;
  int right=table[left_arg][right_arg].right;

  //RECOVERY STEPS BELOW ---------------------------------------------------------------------------

  if (left==-1 && right==-1){
    int cnt=0;
    //printf("########## error: ");print_symbol(tk_name);printf(" ");print_symbol(top_sym);printf("%d \n",cnt);
    recovery_node2(error,line_no,1,lexeme_value,top_sym,tk_name,G);
    tk_name=(*curr_lex)->tk_lexeme->tk_name;
    cnt++;
    while(is_member(G->array_rules[left_arg].follow,tk_name)!=1){
      //printf("### error: ");print_symbol(tk_name);printf(" ");printf("%d \n",cnt);
      if (*curr_lex==NULL){return curr_node;}
      *curr_lex=(*curr_lex)->next;
      if (*curr_lex==NULL){return curr_node;}
      tk_name=(*curr_lex)->tk_lexeme->tk_name;
    }
    pop(stk);return curr_node;
  }



  curr_node->sym=top_sym;
  rule r=G->array_rules[left].rules[right];
  curr_node->rule_number.l=left;
  curr_node->rule_number.r=right;
  int i=r.len-1;
  pop(stk);
  for(;i>=0;i--){
    //printf("-------pushing into stack ");print_symbol(r.right[i]);printf("  %d",r.right[i]);printf("\n");
    push(r.right[i],stk);
  }
  i=0;

  for(;i<r.len;i++){
    node_tree* new_node=add_node_tree(curr_node,r.right[i],curr_node);
    if (is_terminal(r.right[i])==1 ){
      new_node->lex=(*curr_lex)->tk_lexeme;
      new_node->is_leaf=1;
    }
    if (r.right[i]==null_number){
      new_node->is_leaf=1;
    }
    parse(G,stk,table,curr_lex,new_node,error);
    if (*curr_lex==NULL){
      return curr_node;
    }
  }
  return curr_node;
}




tk_lex* recovery_node2(head_list* error,int line_no,int mode,char* string,symbol on_stack,symbol stream,grammar* g){

	//MODE= 0 : LOMGER THAN PRESCRIBED LENGTH;
	//MODE =1 : DOES NOT MATCH ANY PATTERN;



	tk_lex* new_token = (tk_lex*)malloc(sizeof(tk_lex));
	new_token->line_no=line_no;
	new_token->int_val=mode;

  if (mode==1){
  new_token->tk_name=stream;
  new_token->is_num=(int)on_stack;
  }
  else{
    new_token->tk_name=on_stack;
  }
	tk_node* node=(tk_node*)malloc(sizeof(tk_node));
	if (string!=NULL){
	new_token->var_name=(char*)malloc(sizeof(char)*strlen(string));
	strcpy(new_token->var_name,string);
	}
	node->next=NULL;
	node->tk_lexeme=new_token;
	insert_node(error,node);
	return new_token;
}





void isLeafNode(node_tree curr_node){
  if (curr_node.is_leaf==1){
    print_symbol(curr_node.sym);printf("\n");
  }
  else{
    printf("------\n");
  }
}





void print_level(node_tree* root,int lvl){
  int index=0;
  print_symbol(root->sym);printf(" %d\n",lvl);
  children_node* tmp=root->head;
  int i=0;
  for(;i<root->len;i++){
    print_level(tmp->child,lvl+1);tmp=tmp->next;
  }
  return;
}



void create_file(node_tree* root,int is_start,FILE* fp){
  if (is_start==1){
  fprintf(fp,"%-20s %-20s %-20s %-20s %-20s %-20s %-20s \n","Lexeme  node","Line Number","Token","Value","Parent Node ","isLeafNode","Node Symbol");
  }
  //print_symbol(root->sym);printf("\n");
  int left=0;
  children_node* tmp=root->head;
  int num_children=root->len;

  if (root->sym==null_number){
    fprintf(fp, "%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n","------------","----------------","------------------"," ------- ","-------","YES"," null ");
    fprintf(fp,"%s","========================================================================================================================================================\n");
    return;

  }


  if (num_children==0 && (is_terminal(root->sym))){
    //write to file
    //printf("children leaf: ");print_symbol(root->sym);printf("\n");
    symbol token=root->sym;
    char* token_string=(char*)malloc(sizeof(char)*20);
    get_string(token,token_string);
    int val;float val2;
    if (root->lex->is_num>0){
      if (root->lex->is_num==1){val=root->lex->int_val;
        fprintf(fp, "%-20s %-20d %-20s %-20d %-20s %-20s %-20s\n",root->lex->var_name,root->lex->line_no+1,token_string,val," ------- ","YES"," ------ ");
          fprintf(fp,"%s","========================================================================================================================================================\n");
      }
      else{
        val2=root->lex->float_val;
        fprintf(fp, "%-20s %-20d %-20s %-20f %-20s %-20s %-20s\n",root->lex->var_name,root->lex->line_no+1,token_string,val2," -------- ","YES"," ------ ");
          fprintf(fp,"%s","========================================================================================================================================================\n");
      }
    }
    else{
      fprintf(fp, "%-20s %-20d %-20s %-20s %-20s %-20s %-20s\n",root->lex->var_name,root->lex->line_no+1,token_string," ----- "," -------- ","YES"," ------ ");
      fprintf(fp,"%s","========================================================================================================================================================\n");
    }
    //fprintf(fp, "%-20s %-20d %-20s %-20s %-20s %-20s %-20s",root->lex->var_name,root->lex->line_no,token_string,value," NON EXISTENT ","YES"," ------ ");
    return;
  }
  for(;left<root->len;left++){
    create_file(tmp->child,0,fp);
    if (left==0){
    symbol token=root->sym;
    char* token_string=(char*)malloc(sizeof(char)*20);
    get_string(token,token_string);
    char* token_string_par=(char*)malloc(sizeof(char)*20);
    if (root->parent_ptr==NULL){
        fprintf(fp, "%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n","------ "," ------- "," ------ "," ----- "," ROOT ","NO",token_string);
          fprintf(fp,"%s","========================================================================================================================================================\n");
    }
    else{
      get_string(root->parent_ptr->sym,token_string_par);
      fprintf(fp, "%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n","------ "," ------- "," ------ "," ----- ",token_string_par,"NO",token_string);
        fprintf(fp,"%s","========================================================================================================================================================\n");
    }


  }
  tmp=tmp->next;
}
}

void print_file_console(FILE* fp){
  int c;
  while((c=fgetc(fp))!=EOF){
		printf("%c",c);
	}
  fclose(fp);
}


void print_errors_parser(head_list* h,grammar* G){
	tk_node* tmp=h->head;
	while(tmp!=NULL){
		printf("%d",tmp->tk_lexeme->line_no+1);printf(" Parsing error");
    int l=tmp->tk_lexeme->line_no;
    char* name=(char*)malloc(sizeof(char)*20);
    get_string(tmp->tk_lexeme->tk_name,name);
		if (tmp->tk_lexeme->int_val==0){
			//printf(" Identifier is longer than the prescribed length: %s",tmp->tk_lexeme->var_name);

      printf("%d : Expected terminal %s at  line_no %d",l,name,l);
    }
		if (tmp->tk_lexeme->int_val==1){
			printf("%d : The token %s for lexeme %s does not match at line no. %d",l,name,tmp->tk_lexeme->var_name,l);
      printf("\n Expected tokens: Follow set: ");print_members(G->array_rules[tmp->tk_lexeme->is_num].follow);
    }
		printf("\n");
		tmp=tmp->next;
	}
	return;
}
