#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

int stack_empty() {
    fprintf(stderr, "error: stack is empty\n");
    return -1;
}

void stack_full() {
    fprintf(stderr, "error: stack is full\n");
}

/* return the top element from the stack */
int delete(int *top) {
    if (*top == -1)
        /* returns an error key */
        return stack_empty();
    return stack[(*top)--];
}

/* add an item to the global stack */
void add(int *top, int item) {
    if (*top >= MAX_STACK_SIZE - 1)
        return stack_full();
    (*top)++;
    stack[*top] = item;
}

/* get the next token, symbol is the character representation, which is
 * returned, the token is represented by its enumerated value, which is
 * returned in the function name */
precedence get_token(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch (*symbol)  {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case '\0': return eos;
        default : return operand; /* no error checking, default is operand */
    }
}

/* evaluate a postfix expression, expr, maintained as a global variable. '\0'
 * is the the end of the expression. The stack and top of the stack are global
 * variables. get_token is used to return the tokentype and the character
 * symbol. Operands are assumed to be single character digits */
int eval(void) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; /* counter for the expression string */
    int top = -1;
    token = get_token(&symbol, &n);

    while (token != eos) {
        if (token == operand)
            add(&top, symbol - '0'); /* stack insert */
        else {
            /* remove two operands, perform operation, and return result to the
             * stack */
            op2 = delete(&top); /* stack delete */
            op1 = delete(&top);
            switch (token) {
                case plus: add(&top, op1 + op2);
                           break;
                case minus: add(&top, op1 - op2);
                            break;
                case times: add(&top, op1 * op2);
                            break;
                case divide: add(&top, op1 / op2);
                             break;
                case mod: add(&top, op1 % op2);
            }
        }
        token = get_token(&symbol, &n);
    }
    return delete(&top); /* return result */
}

int main() {
    while (scanf(" %s", expr) != EOF) {
        printf("%d\n", eval());
    }
    return 0;
}
