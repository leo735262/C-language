#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 50
#define symbol 5

char op[symbol] = {'(','+','-','*','/',};
int op_p[symbol] = {0,1,1,2,2};//與op對應 運算子的優先順序

int priority(char c);
void to_postfix(char infix[], char postfix[]);


char stack[N]; //全域變數
int top=-1;

//  將 k 放入stack

void push(char k){
	if (top>=N-1){
		printf("Stack is full!\n");
		exit(-1);
	}
	stack[++top]=k;
}

// 傳回stack頂端的資料 非取出

int pop(){
	if (top==-1){
		printf("Stack is empty!\n");
		exit(-1);
	}
	return stack[top--];
}


bool Ep(void)
{
	return (top < 0) ? true : false;
}


// 傳回堆疊頂端的data

char top_data()
{
	return stack[top];
}


// 傳回運算子 c 的order

int order(char c)
{
	int i;

	for( i=0; i < symbol; i++)
	if(op[i] == c)
	return op_p[i];
	return -1;
}


// 將infix轉成postfix

void to_postfix(char infix[], char postfix[])
{
	int i=0, j=-1;
	char x, y;

	while((x=infix[i++]) != '\0'){
		switch(x){
			case '(' : push(x);
					   break;
			case ')' : while(! Ep() && (x=pop()) != '(')
						postfix[++j]=x;
						break;
			case '+' :
			case '-' :
			case '*' :
			case '/' : y=top_data();
					while(order(y) >= order(x)){
							postfix[++j]=pop();
							y=top_data();
					}
					push(x);
					break;
			default : postfix[++j]=x;
		}
	}
	while(! Ep())
		postfix[++j]=pop();
	postfix[++j]='\0';
}
bool math(char c)
{
	return c>='0' && c<='9';
}
int calculate(char postfix[])
{
	int point=0;
	while(postfix[point]!='\0')
	{
		while(math(postfix[point]))
			push(postfix[point++]);
	int a=pop()-'0', b=pop()-'0',c=0;
	switch(postfix[point])
	{
		case'+':c=b+a;
				break;
		case'-':c=b-a;
				break;
		case'*':c=b*a;
				break;
		case'/':c=b/a;
				break;
	}
	push(c+'0');
	point++;
	}
	return pop()-'0';
}
int main(void)
{
	char infix[N], postfix[N];

	printf("輸入運算式:");
	scanf("%s",infix);

	printf("\n此運算式之中序式為:");
	to_postfix(infix,postfix);
	printf("%s\n",infix);

	printf("\n此後序式為:");
	printf("%s\n", postfix);

	printf("\n運算結果:");
	printf("%d", calculate(postfix));

	return 0;
}
