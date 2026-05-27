%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern char* yytext;
int yylex(void);
void yyerror(const char* s);

FILE *vm_out;

// ================= TABLA DE SÍMBOLOS =================
typedef enum { SYM_VAR, SYM_FUNC, SYM_MACRO } SymType;

typedef struct {
    char name[50];
    SymType type;
    int arg_count;
} Symbol;

Symbol sym_table[200];
int sym_count = 0;

int add_symbol(char* name, SymType type, int arg_count) {
    for(int i = 0; i < sym_count; i++) {
        if(strcmp(sym_table[i].name, name) == 0) return 0; // Ya existe
    }
    strcpy(sym_table[sym_count].name, name);
    sym_table[sym_count].type = type;
    sym_table[sym_count].arg_count = arg_count;
    sym_count++;
    return 1; // Agregado con éxito
}

Symbol* get_symbol(char* name) {
    for(int i = 0; i < sym_count; i++) {
        if(strcmp(sym_table[i].name, name) == 0) return &sym_table[i];
    }
    return NULL;
}
// =====================================================
%}

%union {
    int ival;
    char* sval;
}

%token INCLUDE DEFINE INT FUNC RETURN IF
%token <sval> ID STRING
%token <ival> NUMBER

%type <ival> param_list param_list_nonempty arg_list arg_list_nonempty

%%
program:
    global_elements { printf("\nCompilacion terminada. Archivo program.txt generado para la VM.\n"); }
    ;

global_elements:
    global_elements element | /* vacio */ ;

element:
    macro_def | var_decl | func_decl | include_def ;

include_def:
    INCLUDE '<' ID '.' ID '>' ;

macro_def:
    DEFINE ID NUMBER {
        if(!add_symbol($2, SYM_MACRO, 0))
            printf("Error semantico: macro '%s' ya definida\n", $2);
    }
    ;

var_decl:
    INT ID ';' {
        if(!add_symbol($2, SYM_VAR, 0))
            printf("Error semantico: redeclaracion de variable '%s'\n", $2);
    }
    ;

func_decl:
    FUNC ID '(' param_list ')' {
        if(!add_symbol($2, SYM_FUNC, $4))
            printf("Error semantico: funcion '%s' ya declarada\n", $2);
    } block
    ;

param_list:
    /* vacio */ { $$ = 0; }
    | param_list_nonempty { $$ = $1; }
    ;

param_list_nonempty:
    ID { $$ = 1; add_symbol($1, SYM_VAR, 0); }
    | param_list_nonempty ',' ID { $$ = $1 + 1; add_symbol($3, SYM_VAR, 0); }
    ;

block:
    '{' statements '}' ;

statements:
    statements statement | /* vacio */ ;

statement:
    var_decl
    | ID '=' expression ';' {
        Symbol* s = get_symbol($1);
        if(!s || s->type != SYM_VAR)
            printf("Error semantico: variable '%s' no declarada\n", $1);
        
        // GENERA CODIGO PARA TU VM
        fprintf(vm_out, "STORE %s\n", $1);
    }
    | ID '(' arg_list ')' ';' {
        Symbol* s = get_symbol($1);
        if(!s || s->type != SYM_FUNC) {
            printf("Error semantico: funcion '%s' no declarada\n", $1);
        } else if(s->arg_count != $3) {
            printf("Error semantico: funcion '%s' espera %d argumento(s), pero recibio %d\n", $1, s->arg_count, $3);
        }
        
        // GENERA CODIGO PARA TU VM
        fprintf(vm_out, "CALL %s\n", $1);
    }
    | RETURN expression ';' {
        fprintf(vm_out, "RET\n");
    }
    | IF '(' ID ')' block {
        Symbol* s = get_symbol($3);
        if(!s) printf("Error semantico: variable '%s' no declarada\n", $3);
    }
    ;

arg_list:
    /* vacio */ { $$ = 0; }
    | arg_list_nonempty { $$ = $1; }
    ;

arg_list_nonempty:
    expression { $$ = 1; }
    | arg_list_nonempty ',' expression { $$ = $1 + 1; }
    ;

expression:
    NUMBER { fprintf(vm_out, "PUSH %d\n", $1); }
    | ID {
        Symbol* s = get_symbol($1);
        if(!s) printf("Error semantico: variable '%s' no declarada\n", $1);
        fprintf(vm_out, "LOAD %s\n", $1);
    }
    | expression '+' expression { fprintf(vm_out, "ADD\n"); }
    | expression '-' expression { fprintf(vm_out, "SUB\n"); }
    ;

%%

void yyerror(const char *s) {
    printf("Error sintactico en linea %d cerca de '%s'\n", yylineno, yytext);
}

int main(void) {
    // Abrimos el archivo que leerá el Loader de tu VM
    vm_out = fopen("program.txt", "w");
    if (!vm_out) {
        printf("Error al crear program.txt\n");
        return 1;
    }
    
    int result = yyparse();
    
    fclose(vm_out);
    return result;
}