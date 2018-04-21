// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "lexer.h"


#define MAXBUFLEN 4095
//checked
void get_string(symbol token,char* return_string){
	if (token==xstmt){strcpy(return_string,"xstmt");}
	if (token==xifstmt){strcpy(return_string,"xifstmt");}
	if (token==var_list){strcpy(return_string,"var_list");}
	if (token==var){strcpy(return_string,"var");}
	if (token==type){strcpy(return_string,"type");}
	if (token==svar){strcpy(return_string,"svar");}
	if (token==stmtsAndFunctionDefs){strcpy(return_string,"stmtsAndFunctionDefs");}
	if (token==stmtOrFunctionDef){strcpy(return_string,"stmtOrFunctionDef");}
	if (token==stmt){strcpy(return_string,"stmt");}
	if (token==something){strcpy(return_string,"something");}
	if (token==sizeofexpr){strcpy(return_string,"sizeofexpr");}
	if (token==rows_temp){strcpy(return_string,"rows_temp");}
	if (token==rows){strcpy(return_string,"rows");}
	if (token==row){strcpy(return_string,"row");}
	if (token==rightHandSide2){strcpy(return_string,"rightHandSide2");}
	if (token==rightHandSide1){strcpy(return_string,"rightHandSide1");}
	if (token==remainingList){strcpy(return_string,"remainingList");}
	if (token==relationalOp){strcpy(return_string,"relationalOp");}
	if (token==parameter_list){strcpy(return_string,"parameter_list");}
	if (token==otherStmts){strcpy(return_string,"otherStmts");}
	if (token==operator2){strcpy(return_string,"operator2");}
	if (token==operator1){strcpy(return_string,"operator1");}
	if (token==more_vals){strcpy(return_string,"more_vals");}
	if (token==more_ids){strcpy(return_string,"more_ids");}
	if (token==matrix){strcpy(return_string,"matrix");}
	if (token==mainFunction){strcpy(return_string,"mainFunction");}
	if (token==logicalOp2){strcpy(return_string,"logicalOp2");}
	if (token==logicalOp1){strcpy(return_string,"logicalOp1");}
	if (token==leftHandSide2){strcpy(return_string,"leftHandSide2");}
	if (token==leftHandSide1){strcpy(return_string,"leftHandSide1");}
	if (token==ioStmt){strcpy(return_string,"ioStmt");}
	if (token==ifStmt){strcpy(return_string,"ifStmt");}
	if (token==functionDef){strcpy(return_string,"functionDef");}
	if (token==functionCall){strcpy(return_string,"functionCall");}
	if (token==funcCallStmt){strcpy(return_string,"funcCallStmt");}
	if (token==declarationStmt){strcpy(return_string,"declarationStmt");}
	if (token==cons_var){strcpy(return_string,"cons_var");}
	if (token==booleanExpression){strcpy(return_string,"booleanExpression");}
	if (token==assignmentStmt){strcpy(return_string,"assignmentStmt");}
	if (token==arithmeticExpression2){strcpy(return_string,"arithmeticExpression2");}
	if (token==arithmeticExpression){strcpy(return_string,"arithmeticExpression");}
	if (token==arithmetic2){strcpy(return_string,"arithmetic2");}
	if (token==arithmetic1){strcpy(return_string,"arithmetic1");}
	if (token==STRING){strcpy(return_string,"STRING");}
	if (token==STR){strcpy(return_string,"STR");}
	if (token==SQO){strcpy(return_string,"SQO");}
	if (token==SQC){strcpy(return_string,"SQC");}
	if (token==SIZE){strcpy(return_string,"SIZE");}
	if (token==SEMICOLON){strcpy(return_string,"SEMICOLON");}
	if (token==RNUM){strcpy(return_string,"RNUM");}
	if (token==REAL){strcpy(return_string,"REAL");}
	if (token==READ){strcpy(return_string,"READ");}
	if (token==PRINT){strcpy(return_string,"PRINT");}
	if (token==PLUS){strcpy(return_string,"PLUS");}
	if (token==OR){strcpy(return_string,"OR");}
	if (token==OP){strcpy(return_string,"OP");}
	if (token==NUM){strcpy(return_string,"NUM");}
	if (token==NOT){strcpy(return_string,"NOT");}
	if (token==NE){strcpy(return_string,"NE");}
	if (token==MUL){strcpy(return_string,"MUL");}
	if (token==MINUS){strcpy(return_string,"MINUS");}
	if (token==MATRIX){strcpy(return_string,"MATRIX");}
	if (token==MAIN){strcpy(return_string,"MAIN");}
	if (token==LT){strcpy(return_string,"LT");}
	if (token==LE){strcpy(return_string,"LE");}
	if (token==INT){strcpy(return_string,"INT");}
	if (token==IF){strcpy(return_string,"IF");}
	if (token==ID){strcpy(return_string,"ID");}
	if (token==GT){strcpy(return_string,"GT");}
	if (token==GE){strcpy(return_string,"GE");}
	if (token==FUNID){strcpy(return_string,"FUNID");}
	if (token==FUNCTION){strcpy(return_string,"FUNCTION");}
	if (token==EQ){strcpy(return_string,"EQ");}
	if (token==EPS){strcpy(return_string,"EPS");}
	if (token==ENDIF){strcpy(return_string,"ENDIF");}
	if (token==END){strcpy(return_string,"END");}
	if (token==ELSE){strcpy(return_string,"ELSE");}
	if (token==DIV){strcpy(return_string,"DIV");}
	if (token==COMMA){strcpy(return_string,"COMMA");}
	if (token==CL){strcpy(return_string,"CL");}
	if (token==ASSIGNOP){strcpy(return_string,"ASSIGNOP");}
	if (token==AND){strcpy(return_string,"AND");}
	if (token==null){strcpy(return_string,"null");}
	if (token==END_MARKER){strcpy(return_string,"END_MARKER");}
}




//checked
FILE* removeComments(char* testcasefile,char* outputfile){
	FILE* fp=(FILE*)fopen(testcasefile,"r");
	FILE* fp2=(FILE*)fopen(outputfile,"w");
	int c;
	int state_comment=0;
	while((c=fgetc(fp))!=EOF){
		if ((char)c=='#'){
			state_comment=1;
			continue;
		}
		if (state_comment==1){
			if ((char)c=='\n'){state_comment=0;fputc(c,fp2);continue;}
			continue;
		}
		fputc(c,fp2);
	}
	fclose(fp2);
	fclose(fp);
	fp2=(FILE*)fopen(outputfile,"r");
	return fp2;
}

//checked
void print_state(state_name s){
		if (s==start){printf("start");}
	if (s==SIZE_state){printf("SIZE_state");}
	if (s==ID1){printf("ID1");}
	if (s==ID_string){printf("ID_string");}
	if (s==ID_number){printf("ID_number");}
	if (s==ID_number_FINAL){printf("ID_number_FINAL");}
	if (s==NUM1){printf("NUM1");}
	if (s==NUM_END){printf("NUM_END");}
	if (s==NUM_REAL1){printf("NUM_REAL1");}
	if (s==NUM_REAL2){printf("NUM_REAL2");}
	if (s==NUM_REAL3){printf("NUM_REAL3");}
	if (s==NUM_REAL_END_FINAL){printf("NUM_REAL_END_FINAL");}
	if (s==STRING1){printf("STRING1");}
	if (s==STRING2){printf("STRING2");}
	if (s==STRING3){printf("STRING3");}
	if (s==STRING3_FINAL){printf("STRING3_FINAL");}
	if (s==FUNCTION1){printf("FUNCTION1");}
	if (s==FUNCTION2){printf("FUNCTION2");}
	if (s==FUNCTION3){printf("FUNCTION3");}
	if (s==LT1){printf("LT1");}
	if (s==LT_END){printf("LT_END");}
	if (s==LTE_END){printf("LTE_END");}
	if (s==LTE_END_FINAL){printf("LTE_END_FINAL");}
	if (s==EQ1){printf("EQ1");}
	if (s==MT1){printf("MT1");}
	if (s==EQ2){printf("EQ2");}
	if (s==LT_EQ){printf("LT_EQ");}
	if (s==MT_EQ){printf("MT_EQ");}
	if (s==NE2){printf("NE2");}
	if (s==NE1){printf("NE1");}
	if (s==PLUS_state){printf("PLUS_state");}
	if (s==MINUS_state){printf("MINUS_state");}
	if (s==MUL_state){printf("MUL_state");}
	if (s==DIV_state){printf("DIV_state");}
	if (s==OP_BRACK){printf("OP_BRACK");}
	if (s==CL_BRACK){printf("CL_BRACK");}
	if (s==OP_BRACK2){printf("OP_BRACK2");}
	if (s==CL_BRACK2){printf("CL_BRACK2");}
	if (s==SEMICOLON_state){printf("SEMICOLON_state");}
	if (s==COMMA_state){printf("COMMA_state");}
}
//checked
tk_lex* recovery_node(head_list* error,int line_no,int mode,char* string){

	//MODE= 0 : LOMGER THAN PRESCRIBED LENGTH;
	//MODE =1 : DOES NOT MATCH ANY PATTERN;



	tk_lex* new_token = (tk_lex*)malloc(sizeof(tk_lex));
	new_token->line_no=line_no;
	new_token->int_val=mode;
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

//checked
void convert_to_string(tk_lex* new_token,char* buff1,char* buff2,int buffer_switch,int which_buffer,int start,int forward){
	if (buffer_switch==0){
		new_token->var_name=(char*)malloc(sizeof(char)*(forward-(start)+2));
		int i=0;
		for(;i<=forward-start;i++){
			if (which_buffer==0){new_token->var_name[i]=buff1[start+i];}
			else{new_token->var_name[i]=buff2[start+i];}
		}
		new_token->var_name[i]='\0';
	}
	else{
		new_token->var_name=(char*)malloc(sizeof(char)*(forward+2+(4095-start)));
		if (buffer_switch==1){
		int i=start;
		for(;i<4096;i++){
			new_token->var_name[i-start]=buff1[i];
		}
		i=0;
		for(;i<=forward;i++){
			new_token->var_name[4095-start+i]=buff2[i];
		}
		new_token->var_name[4095-start+i]='\0';

		}
		else{
		int i=start;
		for(;i<4096;i++){
			new_token->var_name[i-start]=buff2[i];
		}
		i=0;
		for(;i<=forward;i++){
			new_token->var_name[4095-start+i]=buff1[i];
		}
		new_token->var_name[4095-start+i]='\0';

		}
	}
	//printf("  debugging:   %s\n",new_token->var_name);

}


//checked
void fill_lexeme(symbol tk,tk_lex* new_node){
	new_node->var_name=(char*)malloc(sizeof(char)*10);

	if (tk==ASSIGNOP){strcpy(new_node->var_name,"ASSIGNOP");return;}
	if (tk==SQO){strcpy(new_node->var_name,"[");return;}
	if (tk==SQO){strcpy(new_node->var_name,"[");return;}
	if (tk==SQC){strcpy(new_node->var_name,"]");return;}
	if (tk==OP){strcpy(new_node->var_name,"(");return;}
	if (tk==CL){strcpy(new_node->var_name,")");return;}
	if (tk==PLUS){strcpy(new_node->var_name,"+");return;}
	if (tk==MINUS){strcpy(new_node->var_name,"-");return;}
	if (tk==MUL){strcpy(new_node->var_name,"*");return;}
	if (tk==DIV){strcpy(new_node->var_name,"/");return;}
	if (tk==SIZE){strcpy(new_node->var_name,"@");return;}

	if (tk==LT){strcpy(new_node->var_name,"<");return;}
	if (tk==EQ){strcpy(new_node->var_name,"==");return;}
	if (tk==LE){strcpy(new_node->var_name,"<=");return;}
	if (tk==NE){strcpy(new_node->var_name,"=/=");return;}
	if (tk==GE){strcpy(new_node->var_name,">=");return;}

	if (tk==AND){strcpy(new_node->var_name,".and.");return;}
	if (tk==OR){strcpy(new_node->var_name,".or.");return;}
	if (tk==NOT){strcpy(new_node->var_name,".not.");return;}
	if (tk==SEMICOLON){strcpy(new_node->var_name,";");return;}
	if (tk==COMMA){strcpy(new_node->var_name,",");return;}

}


//checked
void print_func(symbol tk){

		if(tk==ASSIGNOP){printf("ASSIGNOP");}
		if(tk==ID){printf("ID");}
		if(tk==FUNID){printf("FUNID");}
		if(tk==NUM){printf("NUM");}
		if(tk==RNUM){printf("RNUM");}
		if(tk==STR){printf("STR");}
		if(tk==SQO){printf("SQO");}
		if(tk==SQC){printf("SQC");}
		if(tk==OP){printf("OP");}
		if(tk==CL){printf("CL");}

		if(tk==PLUS){printf("PLUS");}
		if(tk==MINUS){printf("MINUS");}
		if(tk==MUL){printf("MUL");}
		if(tk==DIV){printf("DIV");}
		if(tk==SIZE){printf("SIZE");}
		if(tk==LT){printf("LT");}
		if(tk==EQ){printf("EQ");}
		if(tk==LE){printf("LE");}
		if(tk==NE){printf("NE");}
		if(tk==GE){printf("GE");}
		if(tk==GT){printf("GT");}
		if(tk==GE){printf("GE");}

		if(tk==END){printf("END");}
		if(tk==INT){printf("INT");}
		if(tk==REAL){printf("REAL");}
		if(tk==STRING){printf("STRING");}
		if(tk==MATRIX){printf("MATRIX");}
		if(tk==MAIN){printf("MAIN");}
		if(tk==IF){printf("IF");}
		if(tk==ELSE){printf("ELSE");}
		if(tk==ENDIF){printf("ENDIF");}
		if(tk==READ){printf("READ");}
		if(tk==PRINT){printf("PRINT");}
		if(tk==FUNCTION){printf("FUNCTION");}

		if(tk==AND){printf("AND");}
		if(tk==OR){printf("OR");}
		if(tk==NOT){printf("NOT");}
		if(tk==SEMICOLON){printf("SEMICOLON");}
		if(tk==COMMA){printf("COMMA");}
}

symbol get_token(state_name state){
	if (state==ID_number || state==ID1){
		return ID;
	}
	if (state==FUNCTION2){return FUNID;}
	if (state==OP_BRACK){return SQO;}
	if (state==CL_BRACK){return SQC;}
	if (state==OP_BRACK2){return OP;}
	if (state==CL_BRACK2){return CL;}
	if (state==STRING3){return STR;}
	if (state==PLUS_state){return PLUS;}
	if (state==MINUS_state){return MINUS;}
	if (state==MUL_state){return MUL;}
	if (state==DIV_state){return DIV;}
	if (state==SIZE_state){return SIZE;}


	if (state==MT1){return GT;}
	if (state==LT1){return LT;}

	if (state==LT_EQ){return LE;}
	if (state==MT_EQ){return GE;}
	if (state==EQ2){return EQ;}
	if (state==EQ1){return ASSIGNOP;}
	if (state==NE2){return NE;}
	if (state==PLUS_state){return PLUS;}
  if (state==PLUS_state){return PLUS;}
	if (state==NUM_REAL3){return RNUM;}
	if (state==NUM1){return NUM;}
	if (state==SEMICOLON_state){return SEMICOLON;}
	if (state==COMMA_state){return COMMA;}
	if (state==LOGICAL_and_end){return AND;}
	if (state==LOGICAL_not_end){return NOT;}
	if (state==LOGICAL_or_end){return OR;}
}


bool state_final(state_name state){

	if (state==LOGICAL_and_end || state==LOGICAL_or_end || state==LOGICAL_not_end){
		return true;
	}

	if (state==ID_number){
		return true;
	}

	if (state==OP_BRACK || state==OP_BRACK2 || state==CL_BRACK || state==CL_BRACK2){
		return true;
	}
	if (state==STRING3 || state==PLUS_state || state==MINUS_state || state==MUL_state || state==DIV_state){
		return true;
	}
	if (state==SIZE_state){
		return true;
	}
	if (state==LT_EQ || state==MT_EQ || state==EQ2 || state==NE2){
		return true;
	}
	if (state==NUM_REAL3){
		return true;
	}
	if (state==SEMICOLON_state || state==COMMA_state){return true;}
	return false;
}


bool state_final_2(state_name state){
	if (state==ID1){
		return	 true;
	}
	if (state==FUNCTION2 || state==LT1 || state==MT1){
		return true;
	}
	if (state==EQ1 || state==NUM1){
		return true;
	}
	return false;
}

void insert_node(head_list* head_stream,tk_node* node){
	if (head_stream->head==NULL){
		head_stream->head=node;
		return;
	}
	tk_node* tmp=head_stream->head;
	int x=0;
	while(tmp->next!=NULL){




		//print_func(tmp->tk_lexeme->line_no);

		tmp=tmp->next;
		//if (tmp==NULL){printf("IT WAS NULL\n");return;}
	}
	tmp->next=node;
	return;
}



head_list* FUNC_MAIN(FILE* fp,head_list* error){


	head_list* lexer_output=(head_list*)malloc(sizeof(head_list));
	lexer_output->head=NULL;
	hash_head* my_table=return_table();


	char sync_token=';';







	char buff1[4096];
	char buff2[4096];
	int forward=-1;
	int start_int=0;
	int which_buffer=0;
	int buffer_switch=0;
	state_name state=0;
	state_name prev_state=0;
	int match=0;
	int line_no=0;
	//read buff1 from fp




  size_t newLen = fread(buff1, sizeof(char), MAXBUFLEN, fp);
  if ( ferror( fp ) != 0 ) {

  fputs("Error reading file", stderr);
  } else {
  buff1[newLen] = '?'; /* Just to be safe. */
  }
  if (newLen!=4095){
		//ek aagey ! aana chahiyeh
		//printf("THIS HAPPENS--------------------------\n");
	 	buff1[newLen]='!';
  }
	int is_comment=0;
	while(1){


		//printf("HJAJAHSHAHSFHFSAHFAHGS\n");

		forward++;
		match=0;
		char look_ahead;
		if (which_buffer==0){
			look_ahead=buff1[forward];
		}
		else{
			look_ahead=buff2[forward];
		}
		//READ END
		//printf("%c %d\n",look_ahead,forward);
		if (look_ahead=='?'){
			//printf("YAHAN AAYA ***************");
			if (which_buffer==0){
				//read from buff2 from fp
				newLen = fread(buff2, sizeof(char), MAXBUFLEN, fp);

				forward=0;
				buffer_switch=1;
				which_buffer=1;
				look_ahead=buff2[forward];
				buff2[newLen] = '?';
				if (newLen!=4095){
   					buff2[newLen]='!';
   				}
			}
			else{
				//read into first buffer
				newLen = fread(buff1, sizeof(char), MAXBUFLEN, fp);
				buffer_switch=2;
				which_buffer=0;
				look_ahead=buff1[forward];
				buff1[newLen] = '?';
				if (newLen!=4095){
   					buff1[newLen]='!';
   				}
			}
		}
		if (look_ahead=='!'){

			//RETURN EVERYTHING

			//printf("WHAT IS HAPPENDING\n");

			return lexer_output;
			printf("\nIT ENDS ************************  %d\n",forward);

		}

		//if (state==ID_numer_FINAL || state==ID_numer_FINAL )

		if (is_comment==1 && look_ahead!='\n'){start_int++;continue;}
		if (is_comment==1 && look_ahead=='\n'){start_int++;line_no++;is_comment=0;state=start;continue;}
		if (look_ahead=='#' && state==start){
			is_comment=1;
			start_int++;
			continue;
		}

		if (look_ahead=='\n' && state==start){state=start;line_no++;start_int++;printf("\n");match=1;}
		if (look_ahead==' ' && state==start){state=start;start_int++;match=1;}
		if (look_ahead=='\t' && state==start){state=start;start_int++;match=1;}
		//CHARACTER IS a-z or A-Z
		if (look_ahead==13 && state==start){state=start;start_int++;match=1;}
		if (look_ahead==' ' && state==STRING1){if (state=STRING2 && match==0){state=STRING2;match=1;}}


		if (look_ahead==' ' && state==STRING2){if (state==STRING2 && match==0){state=STRING2;match=1;}}

		if (65<=look_ahead && look_ahead<=90){
			if (state==start && match==0){state=ID1;match=1;}
			if (state==ID1 && match==0){state=ID1;match=1;}

			if (state==FUNCTION1 && match==0){state=FUNCTION2;match=1;}
			if (state==FUNCTION2 && match==0){state=FUNCTION2;match=1;}

			//if (state==FUNCTION1 && match==0){state=FUNCTION2;match=1}
		}
		if (97<=look_ahead && look_ahead<=122)
		{
			if (state==STRING1 && match==0){//printf("YAHAN AAYAAA*********\n");
			state=STRING2;match=1;}
			if (state==STRING2 && match==0){state=STRING2;match=1;}
			if (state==start && match==0){state=ID1;match=1;}
			if (state==ID1 && match==0){state=ID1;match=1;}
			if (state==FUNCTION1 && match==0){state=FUNCTION2;match=1;}
			if (state==FUNCTION2 && match==0){state=FUNCTION2;match=1;}

			// .and. .or. .not.

			if (state==LOGICAL_start && match==0 && look_ahead=='a'){state=LOGICAL_and1;match=1;}
			if (state==LOGICAL_and1 && match==0 && look_ahead=='n'){state=LOGICAL_and2;match=1;}
			if (state==LOGICAL_and2 && match==0 && look_ahead=='d'){state=LOGICAL_and3;match=1;}

			if (state==LOGICAL_start && match==0 && look_ahead=='o'){state=LOGICAL_or1;match=1;}
			if (state==LOGICAL_or1 && match==0 && look_ahead=='r'){state=LOGICAL_or2;match=1;}

			if (state==LOGICAL_start && match==0 && look_ahead=='n'){state=LOGICAL_not1;match=1;}
			if (state==LOGICAL_not1 && match==0 && look_ahead=='o'){state=LOGICAL_not2;match=1;}
			if (state==LOGICAL_not2 && match==0 && look_ahead=='t'){state=LOGICAL_not3;match=1;}


		}
		if (look_ahead=='"' && match==0){
			if (state==start && match==0){state=STRING1;match=1;}
			if (state==STRING2 && match==0){state=STRING3;match=1;}
		}
		if (look_ahead=='[' && match==0){
			if (state==start && match==0){state=OP_BRACK;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='.' && match==0){
			if (state==NUM1 && match==0){state=NUM_REAL1;match=1;}
			if (state==start && match==0){state=LOGICAL_start;match=1;}
			if (state==LOGICAL_and3 && match==0){state=LOGICAL_and_end;match=1;}
			if (state==LOGICAL_not3 && match==0){state=LOGICAL_not_end;match=1;}
			if (state==LOGICAL_or2 && match==0){state=LOGICAL_or_end;match=1;}

		}

		if (look_ahead==']' && match==0){
			if (state==start && match==0){state=CL_BRACK;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}
		if (look_ahead=='(' && match==0){
			if (state==start && match==0){state=OP_BRACK2;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead==')' && match==0){
			if (state==start && match==0){state=CL_BRACK2;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='+' && match==0){
			if (state==start && match==0){state=PLUS_state;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='-' && match==0){
			if (state==start && match==0){state=MINUS_state;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='*' && match==0){
			if (state==start && match==0){state=MUL_state;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='/' && match==0){
			if (state==start && match==0){state=DIV_state;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}
		if (look_ahead=='_' && match==0){
			//printf("FIRST\n");
			if (state==start && match==0){state=FUNCTION1;match=1;}
			//if (state==FUNCTION2 && match==0){state=FUNCTION3;match=1;}
		}

		if (look_ahead=='@' && match==0){
			if (state==start && match==0){state=SIZE_state;match=1;}
		}

		if (look_ahead=='<' && match==0){
			if (state==start && match==0){state=LT1;match=1;}
		}

		if (look_ahead=='>' && match==0){
			if (state==start && match==0){state=MT1;match=1;}
		}
		if (look_ahead==';' && match==0){
			if (state==start && match==0){state=SEMICOLON_state;match=1;}
		}
		if (look_ahead==',' && match==0){
			if (state==start && match==0){state=COMMA_state;match=1;}
		}





		if (look_ahead=='='){
			if (state==LT1 && match==0){state=LT_EQ;match=1;}
			if (state==MT1 && match==0){state=MT_EQ;match=1;}
			if (state==start && match==0){state=EQ1;match=1;}
			if (state==EQ1 && match==0){state=EQ2;match=1;}
			if (state==NE1 && match==0){state=NE2;match=1;}
		}

		if (look_ahead=='/'){
			if (state==EQ1 && match==0){state=NE1;match=1;}
		}
		if (48<=look_ahead && look_ahead<=57){
			if (state==start && match==0){state=NUM1;match=1;}
			if (state==NUM1 && match==0){state=NUM1;match=1;}
			if (state==FUNCTION2 && match==0){state=FUNCTION2;match=1;}
			if (state==NUM_REAL1 && match==0){state=NUM_REAL2;match=1;}
			if (state==NUM_REAL2 && match==0){state=NUM_REAL3;match=1;}
			if (state==ID1 && match==0){state=ID_number;match=1;}

		}

		//DUMMY FINAL STATE ACTIONS

		/*
		if (state_final(state)==true || (state_final_2(state)==true && match==0)) {
			tk_lex* new_token = (tk_lex*)malloc(sizeof(tk_lex));
			new_token->line_no=line_no;

			if (state_final_2(state)==true){
				//printf("YAHAN");
				forward--;
			}
			symbol TK=get_token(state);
			print_func(TK);
			printf(" %d\n",line_no);
			state=start;
		}
		*/




		//printf("%c :",look_ahead);print_state(state);printf("\n");







		if (state_final(state)==true || (state_final_2(state)==true && match==0)) {
			int token_assign=0;
			tk_lex* new_token = (tk_lex*)malloc(sizeof(tk_lex));


			//printf(" ENtering now\n");printf(" ");

			/*
			printf("ANDAR AAYA %d %c\n",forward,buff1[forward]);
			//printf("%s",print_state(state));
			print_state(state);
			printf("\n");
			*/


			//CREATE NODE OF LINKED LIST
			new_token->line_no=line_no;
			tk_node* node=(tk_node*)malloc(sizeof(tk_node));
			new_token->is_num=0;

			node->tk_lexeme=new_token;
			node->next=NULL;


			/*
			//INSERT LINKED LIST
			if (return_lexer->head==NULL){
				return_lexer->head=node;
				tmp_linked=node;
			}
			else{
				tmp_linked->next=node;
				tmp_linked=node;
			}
			*/



			if (state_final_2(state)==true){
				forward--;
			}

			symbol TK=get_token(state);

			/*
			print_func(TK);printf("\n");
			*/

			if (TK==ID){
				//BIG CODE HERE
				token_assign=1;
				convert_to_string(new_token,buff1,buff2,buffer_switch,which_buffer,start_int,forward);
				if (buffer_switch!=0){
					buffer_switch=0;
				}

				//printf("******%s %d\n",new_token->var_name,strlen(new_token->var_name));


				if (strlen(new_token->var_name)>20){

					recovery_node(error,line_no,0,new_token->var_name);
					state=start;
					continue;
				}
				insert_node(lexer_output,node);

				hash_node* tmp=find_token(new_token->var_name,my_table);




				if (tmp==NULL){
					new_token->tk_name=ID;
				}
				else{
					//printf("***********************************************\n");
					//print_func(tmp->tk_name);
					//printf("\n");



					new_token->tk_name=tmp->tk_name;
					//print_func(new_token->tk_name);
					//printf("***********************************************\n");
				}


				/*
				symbol table mai store
				dusra token hai ki nahi check
				id hi hai toh uska naam save
				*/

			}
			if (TK==NUM || TK==RNUM){
				//CODE HERE
				//printf("* %d %c\n",forward,buff1[forward]);
				convert_to_string(new_token,buff1,buff2,buffer_switch,which_buffer,start_int,forward);


				insert_node(lexer_output,node);
				if (buffer_switch!=0){
					buffer_switch=0;
				}

				if (TK==NUM){
					new_token->tk_name=NUM;
					char** temp_ptr;
					new_token->is_num=1;
					new_token->int_val=strtol(new_token->var_name,temp_ptr,10);
				}
				else{
					new_token->is_num=2;
					new_token->tk_name=RNUM;
					new_token->float_val=atof(new_token->var_name);
				}
				token_assign=1;
			}


			if (TK==FUNID){

				//READ VARIALBE VALUE USING TWO BUFFERS

				convert_to_string(new_token,buff1,buff2,buffer_switch,which_buffer,start_int,forward);
				if (buffer_switch!=0){
					buffer_switch=0;
				}
				if (strlen(new_token->var_name)>20){



					recovery_node(error,line_no,0,new_token->var_name);
					state=start;
					continue;
				}
				insert_node(lexer_output,node);
				//FUNCTION ENDS HERE

				hash_node* tmp=find_token(new_token->var_name,my_table);
				//CHECK IF MAIN OR NOT
				if (tmp!=NULL){
					//printf("YAHAN AAYA\n");
					new_token->tk_name=MAIN;
					//print_func(new_token->tk_name);
				}
				else{
					new_token->tk_name=FUNID;
				}
				token_assign=1;
			}

			if (TK==STR){
				convert_to_string(new_token,buff1,buff2,buffer_switch,which_buffer,start_int+1,forward-1);
				if (buffer_switch!=0){
					buffer_switch=0;
				}
				if (strlen(new_token->var_name)>20){



					recovery_node(error,line_no,0,new_token->var_name);
					state=start;
					continue;
				}
				new_token->tk_name=STR;
				insert_node(lexer_output,node);
				token_assign=1;
			}

		//printf("%d %c\n",forward,buff1[forward]);

		//IMPORTANT DEBUGGING BELOW





		if (token_assign==0){
			insert_node(lexer_output,node);
			new_token->tk_name=TK;
			fill_lexeme(TK,new_token);
		}
		//print_func(new_token->tk_name);printf("   ");printf("%d",new_token->line_no);printf("\n");
		start_int=forward+1;
		state=start;

		continue;
		}

		if (match==0 && state_final_2(state)==false){
			int which=0;
			if (state==start){
				which=2;
			}
			else{which=1;}

			tk_lex* tmp=recovery_node(error,line_no,which,NULL);
			convert_to_string(tmp,buff1,buff2,buffer_switch,which_buffer,start_int,forward);
			state=start;
			continue;
		}

}
}

//checked
void print_tokens(head_list* h){

	printf("FORMAT: LINE_NO, TOKEN_NAME, LEXEME\n");

	tk_node* tmp=h->head;
	while(tmp!=NULL){
		printf("%d",tmp->tk_lexeme->line_no+1);printf(".  ");print_func(tmp->tk_lexeme->tk_name);
		printf("  ");
		printf("%s",tmp->tk_lexeme->var_name);
		printf("\n");
		tmp=tmp->next;
	}
	return;
}

void print_errors(head_list* h){
	tk_node* tmp=h->head;
	while(tmp!=NULL){
		printf("%d",tmp->tk_lexeme->line_no+1);printf(" Lexical error");
		//printf("%d asdasd \n",tmp->tk_lexeme->int_val);
		if (tmp->tk_lexeme->int_val==0){
			printf(" Identifier is longer than the prescribed length: %s",tmp->tk_lexeme->var_name);
		}
		if (tmp->tk_lexeme->int_val==1){
			printf(" Unknown pattern : %s",tmp->tk_lexeme->var_name);
		}
		if (tmp->tk_lexeme->int_val==2){
			//printf(" Unknown symbol : %s",tmp->tk_lexeme->var_name);
			printf(" Unknown symbol");
		}
		printf("\n");
		tmp=tmp->next;
	}
	return;
}




/*
int main(){

	 //FILE* fp=fopen("code1.txt","r");
	 FILE* fp=removeComments("code1.txt","clean_code.txt");
	 head_list* error=(head_list*)malloc(sizeof(head_list));
	 error->head=NULL;
	 head_list* lexer_output=FUNC_MAIN(fp,error);

	 print_tokens(lexer_output);
	 print_errors(error);

	 return 0;
}
*/
