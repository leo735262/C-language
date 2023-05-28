#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[10] ;
    int id ;
} student;

typedef struct stack* stack_ptr;
typedef struct stack{
    student people ;
    stack_ptr link ;
}stack;
stack_ptr top;

void add(char name1[10], int id){
   	stack_ptr item=(stack*)malloc(sizeof(stack));
   	strcpy(item->people.name,name1);
   	item->people.id=id;
   	item->link=top;
   	top=item;
}
void main(){
    add("asd",123);
    add("fgh",456);
    printf("%s %d\n",top->people.name,top->people.id);
    printf("%s %d\n",top->link->people.name,top->link->people.id);
}

