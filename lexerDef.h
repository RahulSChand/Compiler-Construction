#ifndef var_lexer_def
#define var_lexer_def

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef enum{
	false,
	true
}bool;



typedef enum{
xstmt,
xifstmt,
var_list,
var_list2,
var,
type,
svar,
stmtsAndFunctionDefs,
stmtOrFunctionDef,
stmt,
something,
sizeofexpr,
rows_temp,
rows,
row,
rightHandSide2,
rightHandSide1,
remainingList,
relationalOp,
parameter_list,
otherStmts,
operator2,
operator1,
more_vals,
more_ids,
more_ids2,
matrix,
mainFunction,
logicalOp2,
logicalOp1,
leftHandSide2,
leftHandSide1,
ioStmt,
ifStmt,
functionDef,
functionCall,
funcCallStmt,
declarationStmt,
cons_var,
booleanExpression,
assignmentStmt,
arithmeticExpression2,
arithmeticExpression,
arithmetic2,
arithmetic1,
STRING,
STR,
SQO,
SQC,
SIZE,
SEMICOLON,
RNUM,
REAL,
READ,
PRINT,
PLUS,
OR,
OP,
NUM,
NOT,
NE,
MUL,
MINUS,
MATRIX,
MAIN,
LT,
LE,
INT,
IF,
ID,
GT,
GE,
FUNID,
FUNCTION,
EQ,
EPS,
ENDIF,
END,
ELSE,
DIV,
COMMA,
CL,
ASSIGNOP,
AND,
null,
END_MARKER
}symbol;



typedef enum{
	start,
	SIZE_state,
	ID1,
	ID_string,
	ID_number,
	ID_number_FINAL,
	NUM1,
	NUM_END,
	NUM_REAL1,
	NUM_REAL2,
	NUM_REAL3,
	NUM_REAL_END_FINAL,
	STRING1,
	STRING2,
	STRING3,
	STRING3_FINAL,
	FUNCTION1,
	FUNCTION2,
	FUNCTION3,
	LT1,
	LT_END,
	LTE_END,
	LTE_END_FINAL,
	EQ1,
	MT1,
	EQ2,
	LT_EQ,
	MT_EQ,
	NE2,
	NE1,
	PLUS_state,
	MINUS_state,
	MUL_state,
	DIV_state,
	OP_BRACK,
	CL_BRACK,
	OP_BRACK2,
	CL_BRACK2,
	SEMICOLON_state,
	COMMA_state,
	COMMENT,
	LOGICAL_start,
	LOGICAL_and1,
	LOGICAL_and2,
	LOGICAL_and3,
	LOGICAL_or1,
	LOGICAL_or2,
	LOGICAL_not1,
	LOGICAL_not2,
	LOGICAL_not3,
	LOGICAL_and_end,
	LOGICAL_or_end,
	LOGICAL_not_end
}state_name;

struct Token_lexeme{
	int line_no;
	int is_num;
	symbol tk_name;
	int int_val;
	float float_val;
	char* var_name;
};

struct Token_stream{
	struct Token_lexeme* tk_lexeme;
	struct Token_stream* next;
};

struct head_list{
	struct Token_stream* head;
};

typedef struct Token_stream tk_node;
typedef struct head_list head_list;
typedef struct Token_lexeme tk_lex;

#endif
