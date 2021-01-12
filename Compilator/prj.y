%{
#include <stdio.h>
#include <string.h>
enum {
	DECLARATION,
	DECLARATION_VALUE,
	ID_NAME,
	LIST_COMMANDS,
	BLOCK,
	VALUE_INT,
	VALUE_FLOAT,
	VALUE_CHAR,
	VALUE_STRING,
	INTS,
	FLOATS,
	STRINGS,
	CHARS,
	ASSIGNMENT,
	ASSIGNMENT_VALUE,
	ARITHMETIC_VALUE,
	EXPRESSION,
	VALUES,
	SIGN_PLUS,
	SIGN_MINUS,
	SIGN_DIVISION,
	SIGN_MULTIPLY,
	SIGN_BIGGER,
	SIGN_LESS,
	SIGN_BOE,
	SIGN_LOE,
	SIGN_EQUALS,
	SIGN_NOE,
	SIGN_AND,
	SIGN_OR,
	SIGN_XOR,
	LOOP_WHILE,
	STATE_IF,
	STATE_IF_ELSE,
	EXPRESSION_LOGIC,
	FUNCTION,
	FUNCTION_BLOCK,
	RETURN_VAL,
	VOIDS,
	VALUE_RETURN
};
typedef struct node{
	char *token;
	struct node *left;
	struct node *right;
	int type; 
}node;
typedef struct symbol {
	char *type;
	char *id;
	char *value;
}symbol;
symbol TableSymbol[700];
node *mknode(char *token, node *left, node *right, int type);

void printTree(node *tree);
int checkedID(char *identifier);
void error(char *error, char *token);
void printTable();
int checkedVal(int element, int value);
int checkedLogicExpr(char *token, int num_one, int num_two);
int checkedLogicTypes(int left, int right);

int cell = 0;
int check = 0;
int checkIF_WHILE = 0;
int mainCount = 0;

int yyerror(char *str)
{
	printf("Error %s\n", str);
}

#define YYSTYPE struct node*
#include "lex.yy.c"
%}

%token IF WHILE FOR ELSE RETURN VOID

%token INTEGER_VAL
%token FLOAT_VAL
%token CHAR_VAL
%token STRING_VAL

%token IDENTIFIER 

%token INT FLOAT STRING CHAR
%token ASSIGN SEMICOLON QUOTE COMMA BRACKET_OPEN BRACKET_CLOSE BRACE_OPEN BRACE_CLOSE ARRAY_BRACKET_OPEN ARRAY_BRACKET_CLOSE ARRAY																		

%token PLUS MINUS DIVISION MULTIPLY
%token BIGGER LESS BOE LOE EQUALS NOE AND OR XOR

%left BIGGER LESS BOE LOE EQUALS NOE AND OR XOR
%left PLUS MINUS
%left DIVISION MULTIPLY

%%


/*
It is start all program.
*/

begin:
		program																											{printTree($1); printTable();}						
		;


// declaration:
// 		types id																										{$$ = mknode("DECL", $1, $2);}	
// 		;

program:
		block
		| recursion_function
// 		//declaration BRACKET_OPEN arguments BRACKET_CLOSE body			{$$ = mknode($1->token, $3, $5);}					
		;
// 		;	



// arguments:	
// 		types id																										{$$ = mknode("ARGS", $1, $2);}
// 		|
// 		;


// void_fund: VOID id (int x) {}
// type_fund: type id (int x) { return value_num;} 

recursion_function:
		| function recursion_function																					{$$ = mknode("LIST", $1, $2, LIST_COMMANDS);}					
		;	

function:
		types id BRACKET_OPEN BRACKET_CLOSE block																		{$$ = mknode("Function", mknode("DECL", $1, $2, DECLARATION), $5, FUNCTION);}
		| type_void id BRACKET_OPEN BRACKET_CLOSE block_return															{$$ = mknode("Function", mknode("DECL", $1, $2, DECLARATION), $5, FUNCTION);}
		;


type_void:
		VOID																											{$$ = mknode(yytext, NULL, NULL, VOIDS);} 																											
		;

block:
		BRACE_OPEN recursion BRACE_CLOSE																				{$$ = mknode("BLOCK", $2, NULL, BLOCK);}
		;

block_return:		
		BRACE_OPEN recursion BRACE_CLOSE																				{$$ = mknode("BLOCK", $2, NULL, BLOCK);}
		;



recursion: 
		| semicolon recursion																							{$$ = mknode("LIST", $1, $2, LIST_COMMANDS);}
		| value_return																									{$$ = mknode("RETURN", $1, NULL, VALUE_RETURN);}			
		;


// command:
// 		| inizilization						
		// | statement							
		// | loop_statement				
		;	


/*
Rule is id token, which it is displayed names.
*/
id:
		IDENTIFIER																										{$$ = mknode(yytext, NULL, NULL, ID_NAME);}
		;	


/*
Rule is equal sign
*/
assign:
		ASSIGN								//																			{$$ = mknode(yytext, NULL, NULL);}
		;

		
/*
Rule consists of all arithmetic operators
*/
operator:
		PLUS																											{$$ = mknode(yytext, NULL, NULL, SIGN_PLUS);}
		| MINUS																											{$$ = mknode(yytext, NULL, NULL, SIGN_MINUS);}
		| DIVISION																										{$$ = mknode(yytext, NULL, NULL, SIGN_DIVISION);}
		| MULTIPLY																										{$$ = mknode(yytext, NULL, NULL, SIGN_MULTIPLY);}
		;


logic:
		BIGGER																											{$$ = mknode(yytext, NULL, NULL, SIGN_BIGGER);}
		| LESS																											{$$ = mknode(yytext, NULL, NULL, SIGN_LESS);}
		| BOE																											{$$ = mknode(yytext, NULL, NULL, SIGN_BOE);}
		| LOE																											{$$ = mknode(yytext, NULL, NULL, SIGN_LOE);}
		| EQUALS																										{$$ = mknode(yytext, NULL, NULL, SIGN_EQUALS);}
		| NOE																											{$$ = mknode(yytext, NULL, NULL, SIGN_NOE);}
		| AND																											{$$ = mknode(yytext, NULL, NULL, SIGN_AND);}
		| OR																											{$$ = mknode(yytext, NULL, NULL, SIGN_OR);}
		| XOR																											{$$ = mknode(yytext, NULL, NULL, SIGN_XOR);}
		;


/*
Rule consists of all types from languages
*/
types:
		INT																												{$$ = mknode(yytext, NULL, NULL, INTS);}
		| FLOAT																											{$$ = mknode(yytext, NULL, NULL, FLOATS);}
		| STRING																										{$$ = mknode(yytext, NULL, NULL, STRINGS);}
		| CHAR																											{$$ = mknode(yytext, NULL, NULL, CHARS);}
		;


value_num:
		INTEGER_VAL																										{$$ = mknode(yytext, NULL, NULL, VALUE_INT);}
		| FLOAT_VAL																										{$$ = mknode(yytext, NULL, NULL, VALUE_FLOAT);}
		| CHAR_VAL																										{$$ = mknode(yytext, NULL, NULL, VALUE_CHAR);}
		| STRING_VAL																									{$$ = mknode(yytext, NULL, NULL, VALUE_STRING);}
		| IDENTIFIER																									{$$ = mknode(yytext, NULL, NULL, ID_NAME);}
		;


math_expr:
		value_num operator value_num																					{$$ = mknode($2->token, $1, $3, EXPRESSION);}
		;


logic_expr:
		value_num logic value_num																						{$$ = mknode($2->token, $1, $3, EXPRESSION_LOGIC);}
		;


semicolon:
			inizilization SEMICOLON																						{$$ = $1;}
			| assignment SEMICOLON																						{$$ = $1;}
			| statement																									{$$ = $1;}
			;

value_return:
			RETURN value_num																							{$$ = mknode("RETURN", $2, NULL, RETURN_VAL);}
			;


assignment:
			| id assign value_num																						{$$ = mknode("ASSIG_VAL", $1, $3, ASSIGNMENT_VALUE);}
			;


inizilization:
			types id																									{$$ = mknode("DECL", $1, $2, DECLARATION);}
			| type_void id																								{$$ = mknode("DECL", $1, $2, DECLARATION);}
			| types id assign value_num			  																		{$$ = mknode("DECL_VALUE", mknode("DECL", $1, $2, DECLARATION), $4, DECLARATION_VALUE);}
			| types id assign math_expr																					{$$ = mknode("ARITH_VALUE", mknode("DECL", $1, $2, DECLARATION), $4, ARITHMETIC_VALUE);}
			// | id assign value_num																					{$$ = mknode("ASSIGN_VALUE", $1, $3, DECLARATION_VALUE);}						
			;
		// types id assign definition																					{$$ = mknode($3->token, $2, $4);}
		// | id assign definition																						{$$ = mknode($2->token, $1, $3);}
		// ;


// definition:
// 		math_expr SEMICOLON																								{$$ = $1;}
// 		| value_num SEMICOLON																							{$$ = $1;}
// 		;



statement:
		WHILE BRACKET_OPEN logic_expr BRACKET_CLOSE block																{$$ = mknode("while", $3, $5, LOOP_WHILE);}
		| IF BRACKET_OPEN logic_expr BRACKET_CLOSE block																{$$ = mknode("if", $3, $5, STATE_IF);}
		| IF BRACKET_OPEN logic_expr BRACKET_CLOSE block ELSE block														{$$ = mknode("if_else", mknode("if", $3, $5, STATE_IF), $7, STATE_IF_ELSE);}
		;




// for:
// 		FOR																												{$$ = mknode(yytext, NULL, NULL);}
// 		;


// loop_statement:
// 		for BRACKET_OPEN inizilization loop																				{$$ = mknode($1->token, $3, $4);}
// 		;


// loop:
// 		loop_expr BRACKET_CLOSE block																					{$$ = mknode("", $1, $3);}
// 		;


// loop_expr:
// 		logic_expr SEMICOLON math_expr																					{$$ = mknode("", $1, $3);}
// 		;


%%

int main()
{
	yyparse();
	return 0;
}

int yywrap() 
{
	return 1;
}

node *mknode(char *token, node *left, node *right, int type) 
{
	node *newnode = (node *)malloc(sizeof(node));
	char *newstr = (char *)malloc(sizeof(token) + 1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	newnode->type = type;
	return newnode;
}

void printTree(node *tree)
{	
	int element = 0;
	int value = 0;
	int num_one = 0;
	int num_two = 0;
	char sym_one = ' ';
	char sym_two = ' ';
	int result = 0;
	int left = 0;
	int right = 0;
	switch (tree->type) {
			case BLOCK:
				if (tree->left != NULL) printTree(tree->left);
				if (tree->right != NULL) printTree(tree->right);
				break;

			case LIST_COMMANDS:
				if (tree->left != NULL) printTree(tree->left);
				if (tree->right != NULL) printTree(tree->right);
				break;

			case DECLARATION_VALUE:
				if (tree->right != NULL) printTree(tree->right);
				if (tree->left != NULL) printTree(tree->left);
				element = checkedID(tree->left->right->token);
				value = checkedVal(element, tree->right->type);
				if (value == 1) TableSymbol[element].value = tree->right->token;
				else error("Error: value is other type: ", tree->right->token);
				break;

			case ASSIGNMENT_VALUE:
				element = checkedID(tree->left->token);
				if (element == -1) error("Error: identifier has not existed yet: ", tree->left->token);
				value = checkedVal(element, tree->right->type);
				if (value == 1) TableSymbol[element].value = tree->right->token;
				else error("Error: value isn't other type: ", tree->right->token);
				TableSymbol[element].value = tree->right->token;	
				break;

			case ARITHMETIC_VALUE:
				if (tree->right != NULL) printTree(tree->right);
				if (tree->left != NULL) printTree(tree->left);
				element = checkedID(tree->left->right->token);
				num_one = atoi(tree->right->left->token);
				num_two = atoi(tree->right->right->token);
				TableSymbol[element].value = 0;
				break;

			case DECLARATION:
				element = checkedID(tree->right->token);
				if (element != -1) error("Error: identifier has already existed: ", tree->right->token);
				else {
					TableSymbol[cell].id = tree->right->token;
					TableSymbol[cell].type = tree->left->token;
					cell++;
				}
				break;
			
			case STATE_IF:
				checkIF_WHILE = 1;
				if (tree->left != NULL) printTree(tree->left);
				if (tree->right != NULL && check == 1) printTree(tree->right);
				// if (checkIF_WHILE == 1) STATE_IF_ELSE;
				break;

			case LOOP_WHILE:
				checkIF_WHILE = -1;
				if (tree->left != NULL) printTree(tree->left);
				if (tree->right != NULL && check == 1) printTree(tree->right);
				// if (checkIF_WHILE == 1) STATE_IF_ELSE;
				break;

			case STATE_IF_ELSE:
				checkIF_WHILE = 1; 
				if (tree->left != NULL) printTree(tree->left);
				if (tree->right != NULL && check == -1) printTree(tree->right);
				break;

			case EXPRESSION_LOGIC:
				if (tree->left->type == ID_NAME && tree->right->type == ID_NAME) {
					left = checkedID(tree->left->token);
					right = checkedID(tree->right->token);
					if (left != -1 || right != -1) checkedLogicTypes(left, right);
					else if ( left == -1 ) error("Error: ", tree->left->token);
					else if ( right == -1 ) error("Error: ", tree->right->token);
				}
				if ( (tree->left->type == ID_NAME) ) left = checkedID(tree->left->token);
				if ( (tree->right->type == ID_NAME) ) right = checkedID(tree->left->token);
				if ( (!strcmp(TableSymbol[left].type, "int") && tree->right->type != VALUE_INT && tree->right->type != ID_NAME) ||
						(!strcmp(TableSymbol[right].type, "int") && tree->left->type != VALUE_INT && tree->left->type != ID_NAME) ||
							(!strcmp(TableSymbol[left].type, "float") && tree->right->type != VALUE_FLOAT && tree->right->type != ID_NAME) ||
								(!strcmp(TableSymbol[right].type, "float") && tree->left->type != VALUE_FLOAT && tree->left->type != ID_NAME) ||
									(!strcmp(TableSymbol[left].type, "char") && tree->right->type != VALUE_CHAR && tree->right->type != ID_NAME) ||
										(!strcmp(TableSymbol[right].type, "char") && tree->left->type != VALUE_CHAR && tree->left->type != ID_NAME) ||
											(!strcmp(TableSymbol[left].type, "String") && tree->right->type != VALUE_STRING && tree->right->type != ID_NAME) ||
												(!strcmp(TableSymbol[right].type, "String") && tree->left->type != VALUE_STRING && tree->left->type != ID_NAME)
					) error("Error: values of variables aren't the same type in the condition of \"if\"!", "");
				else if ( (tree->left->type == VALUE_INT && tree->right->type != VALUE_INT && tree->right->type != ID_NAME) ||
						(tree->left->type != VALUE_INT && tree->left->type != ID_NAME && tree->right->type == VALUE_INT) ||
							(tree->left->type == VALUE_FLOAT && tree->right->type != VALUE_FLOAT && tree->right->type != ID_NAME) ||
								(tree->left->type != VALUE_FLOAT && tree->left->type != ID_NAME && tree->right->type == VALUE_FLOAT) ||
									(tree->left->type == VALUE_CHAR && tree->right->type != VALUE_CHAR && tree->right->type != ID_NAME) ||
										(tree->left->type != VALUE_CHAR && tree->left->type != ID_NAME && tree->right->type == VALUE_CHAR) ||
											( tree->left->type == VALUE_STRING && tree->right->type != VALUE_STRING && tree->right->type != ID_NAME) ||
												(tree->left->type != VALUE_STRING && tree->left->type != ID_NAME && tree->right->type == VALUE_STRING)
					) error("Error: values of variables aren't the same type in the condition of \"if\"!", "");
				else {
					if (checkIF_WHILE == 1) printf("Condition of \"if\" is correct!\n");
					else printf("Condition of \"while\" is correct!\n");
				}
				// check = checkedLogicExpr(tree->token, num_one, num_two);
				break;

				case FUNCTION:
					if ( !strcmp(tree->left->right->token, "main") ) mainCount++;
					if (mainCount == 1 && (tree->left->left->type == INTS || tree->left->left->type == VOIDS) ) {
						printf("%s: %s %s\n", "Function",tree->left->left->token, tree->left->right->token);
						printTree(tree->right);
					}
					else error("Error: function \"main\" doesn't exist or function \"main\" is wrong type!", "");
					break;
				case VALUE_RETURN:
					printf("%s\n", tree->left->right->token);
					printf("%s\n", tree->left->left->token);
	}
}

int checkedID(char *identifier) 
{
	for (int i = 0; i < cell; i++) if ( !strcmp(TableSymbol[i].id, identifier) ) return i;
	return -1;
}

int checkedVal(int element, int value) 
{
	if ( (!strcmp(TableSymbol[element].type, "int") && value != VALUE_INT) || 
		(!strcmp(TableSymbol[element].type, "float") && value != VALUE_FLOAT) ||
		(!strcmp(TableSymbol[element].type, "String") && value != VALUE_STRING) ||
		(!strcmp(TableSymbol[element].type, "char") && value != VALUE_CHAR) ) {
		return -1;
	}
	else return 1;
}


void error(char *error, char *token) 
{
	printf("%s %s\n", error, token);
	exit(1);
}

void printTable() 
{
	for (int i = 0; i < cell; i++) printf("%s %s = %s\n", TableSymbol[i].type, TableSymbol[i].id, TableSymbol[i].value);
}

int checkedLogicExpr(char *token, int num_one, int num_two)
{
	if ( !strcmp(">", token) ) {
		if (num_one > num_two) return 1;
		else return -1;
	}
	else if ( !strcmp("<", token) ) {
		if (num_one < num_two) return 1;
		else return -1;
	}
	else if ( !strcmp(">=", token) ) {
		if (num_one >= num_two) return 1;
		else return -1;
	}
	else if ( !strcmp("<=", token) ) {
		if (num_one <= num_two) return 1;
		else return -1;
	}
	else if ( !strcmp("==", token) ) {
		if (num_one == num_two) return 1;
		else return -1;
	}
	else if ( !strcmp("!=", token) ) {
		if (num_one != num_two) return 1;
		else return -1;
	}
	else if ( !strcmp("^", token) ) {
		if ( num_one ^ num_two ) return 1;
		else return -1;
	}
}

int checkedLogicTypes(int left, int right)
{	
		if ( !strcmp(TableSymbol[left].type, "int") && !strcmp(TableSymbol[right].type, "int") ) printf("Condition of \"if\" is right!\n");
		else if ( !strcmp(TableSymbol[left].type, "char") && !strcmp(TableSymbol[right].type, "char") ) printf("Condition of \"if\" is right!\n");
		else if ( !strcmp(TableSymbol[left].type, "float") && !strcmp(TableSymbol[right].type, "float") ) printf("Condition of \"if\" is right!\n");
		else if ( !strcmp(TableSymbol[left].type, "String") && !strcmp(TableSymbol[right].type, "String") ) printf("Condition of \"if\" is right!\n");
		else error("Error: the condition of \"if\" is incorrect!", "");
}