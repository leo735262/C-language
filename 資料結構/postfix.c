#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

precedence stack_empty() {
    fprintf(stderr, "error: stack is empty\n");
    return -1;
}

void stack_full() {
    fprintf(stderr, "error: stack is full\n");
}

/* return the top element from the stack */
precedence delete(int *top) {
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
    switch (*symbol) {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case '\0': return eos;
        default  : return operand; /* no error checking, default is operand */
    }
}

void print_token(precedence token) {
    switch (token) {
        case lparen: printf("("); break;
        case rparen: printf(")"); break;
        case plus  : printf("+"); break;
        case minus : printf("-"); break;
        case times : printf("*"); break;
        case divide: printf("/"); break;
        case mod   : printf("%%"); break;
        default    : break;
    }
}

/* output the postfix of the expression. The expression string, the stack, and
 * top are global */
void postfix(void) {
    char symbol;
    precedence token;
    int n = 0;
    int top = 0; /* place eos  on stack */
    stack[0] = eos;
    for (token = get_token(&symbol, &n);
         token != eos;
         token = get_token(&symbol, &n)) {
        if (token == operand)
            printf("%c", symbol);
        else if (token == rparen) {
            /* unstack tokens until left parenthesis */
            while (stack[top] != lparen)
                print_token(delete(&top));
            delete(&top); /* discard the left parenthesis */
        }
        else {
            /* remove and print symbol whose  isp is greater than or equal to
             * the current token’s icp */
            while (isp[stack[top]] >= icp[token])
               print_token(delete(&top));
               /*print_token(token);*/
            add(&top, token);
        }
    }
    while ((token = delete(&top)) != eos)
        print_token(token);
    printf("\n");
}

int main() {
    while (scanf(" %s", expr) != EOF) {
        postfix();
    }
    return 0;
}
