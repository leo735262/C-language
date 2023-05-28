#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Student{

char Id[10];         /*學號*/

char Name[10];       /*姓名*/

int Math_score;      /*數學成績*/

int English_score;   /*英文成績*/

} Student;

Student heap[100];
int n=0,m=0;

void insert_min_heap(Student item, int *n, char t);

int main(){

    Student item = { 0 };

    strcpy(item.Name,"John") ;  item.Math_score = 66;  printf("1");/*insert_min_heap(item, &n, 'M');
    strcpy(item.Name,'Alex') ;  item.Math_score = 77;  insert_min_heap(item, &n, 'M');
    strcpy(item.Name,'Mary') ;  item.Math_score = 88;  insert_min_heap(item, &n, 'M');
    strcpy(item.Name,'Jane') ;  item.Math_score = 99;  insert_min_heap(item, &n, 'M');
    strcpy(item.Name,'Jerry') ; item.Math_score = 55;  insert_min_heap(item, &n, 'M');*/


}

void insert_min_heap(Student item, int *n, char t){

int i;

    i = ++(*n);

    if(t=='M'){
    while ((i != 1) && (item.Math_score < heap[i / 2].Math_score)) {
        heap[i] = heap [i / 2];
        i = i / 2;
     }
     heap[i] = item;
    }

    if(t=='E'){
    while ((i != 1) && (item.English_score < heap[i / 2].English_score)) {
        heap[i] = heap [i / 2];
        i = i / 2;
     }
     heap[i] = item;
    }

}
