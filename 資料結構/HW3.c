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
int n=0,m=0,km=0,ke=0;// km ke 分別是全域變數 計算有多少筆資料

void insert_min_heap(Student item, int *n, char t);//建立最小累堆
void print_min_heap(int n);//印出最小累堆
Student delete_min_heap(int *n,char t);//刪除最小累堆並排序

int main(){

    Student item = { 0 };

    strcpy(item.Id,"11001101") ; strcpy(item.Name,"John") ;  item.Math_score = 66; item.English_score = 44; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001102") ; strcpy(item.Name,"Alex") ;  item.Math_score = 77; item.English_score = 22; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001103") ; strcpy(item.Name,"Mary") ;  item.Math_score = 88; item.English_score = 55; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001104") ; strcpy(item.Name,"Jane") ;  item.Math_score = 99; item.English_score = 11; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001105") ; strcpy(item.Name,"Jerry") ; item.Math_score = 55; item.English_score = 33; insert_min_heap(item, &n, 'M');

    // 如果要新增資料(數學為主)，請使用此格式 : strcpy(item.Id,"學號") ; strcpy(item.Name,"姓名") ; item.Math_score = 數學成績;item.English_score = 英文成績;  insert_min_heap(item, &n, 'M');

    print_min_heap(n);//印出以數學成績為主的最小累堆樹
    printf("\n");
    // delete_min_heap(n);

    printf("   Id      Name   Math_score   English_score\n");
    for(int i=0;i<km;i++){
        item = delete_min_heap(&n,'M'); //刪除以數學成績為主的最小累堆並排序
    printf("%s   %s      %d             %d   \n", item.Id,item.Name,item.Math_score,item.English_score);
    }
    printf("\n");


    strcpy(item.Id,"11001101") ; strcpy(item.Name,"John") ;  item.English_score = 44; item.Math_score = 66; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001102") ; strcpy(item.Name,"Alex") ;  item.English_score = 22; item.Math_score = 77; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001103") ; strcpy(item.Name,"Mary") ;  item.English_score = 55; item.Math_score = 88; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001104") ; strcpy(item.Name,"Jane") ;  item.English_score = 11; item.Math_score = 99; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001105") ; strcpy(item.Name,"Jerry") ; item.English_score = 33; item.Math_score = 55; insert_min_heap(item, &m, 'E');
    //如果要新增資料(英文為主)，請使用此格式 : strcpy(item.Id,"學號") ; strcpy(item.Name,"姓名") ; item.English_score = 英文成績; item.Math_score = 數學成績; insert_min_heap(item, &m, 'E');

    print_min_heap(m);//印出以英文成績為主的最小累堆樹
    printf("\n");
    //delete_min_heap(m);

    printf("   Id      Name   Math_score   English_score\n");
    for(int i=0;i<ke;i++){
        item = delete_min_heap(&m,'E');//刪除以英文成績為主的最小累堆並排序
    printf("%s   %s      %d             %d   \n", item.Id,item.Name,item.Math_score,item.English_score);
    }
    printf("\n");

}

void insert_min_heap(Student item, int *n, char t){

int i;

    i = ++(*n); //呼叫次數，heap[0] 沒有資料

    if(t=='M'){
            km++; //以數學成績為主的資料數量計算
    while ((i != 1) && (item.Math_score < heap[i / 2].Math_score)) {//如果不是第一筆資料 且  要插入的資料的成績小於他的父節點
        heap[i] = heap [i / 2];//將父節點資料放到子節點資料裡
        i = i / 2;
     }
     heap[i] = item;//要插入的資料放入本來的父節點資料裡
    }

    if(t=='E'){
            ke++;//以英文成績為主的資料數量計算
    while ((i != 1) && (item.English_score < heap[i / 2].English_score)) {//如果不是第一筆資料 且  要插入的資料的成績小於他的父節點
        heap[i] = heap [i / 2];//將父節點資料放到子節點資料裡
        i = i / 2;
     }
     heap[i] = item;//要插入的資料放入本來的父節點資料裡
    }

}

void print_min_heap(int n) {
    int i, j = 1;
    for (i = 1; i <= n; i++) {
        printf("  %d %3s", i,heap[i].Name);//照順序印出資料
        if (i == 2 * j - 1 && i != n) { // j=1,3,7,15,31,63......
            j *=2;
            printf("\n");
        }
    }
    printf("\n");
}


Student delete_min_heap(int *n,char t) {

int parent, child;
    Student item, temp;



    if(t=='M'){//刪除以數學成績為主的最小累堆並排序

            item = heap[1];//item 是最小的資料

    temp = heap[(*n)--];// temp是最後一筆資料 也就是最大資料(因為從0開始算 所以n要-1 順變-1)
    parent = 1; child = 2;

    while (child <= *n) {
        if ((child < *n) && (heap[child].Math_score > heap [child + 1].Math_score))//如果右子節點>左子節點
            child++;//左子節點
        if (temp.Math_score <= heap[child].Math_score) break;//最後一筆資料(未來的父節點)<=子節點資料 結束迴圈
 /* move to the next lower level */
        heap[parent] = heap[child];//進入 IF 右子節點變成父節點 ELSE 則 左子節點變成父節點
        parent = child;//往下找
        child = child * 2;
    }
    heap[parent] = temp;//最後一筆資料變父節點
    return item;//回傳 item 是最小的資料
    }

    if(t=='E'){//刪除以英文成績為主的最小累堆並排序

            item = heap[1];

    temp = heap[(*n)--];
    parent = 1; child = 2;

    while (child <= *n) {
        if ((child < *n) && (heap[child].English_score > heap [child + 1].English_score))
            child++;
        if (temp.English_score <= heap[child].English_score) break;

        heap[parent] = heap[child];
        parent = child;
        child = child * 2;
    }
    heap[parent] = temp;
    return item;
    }

}
