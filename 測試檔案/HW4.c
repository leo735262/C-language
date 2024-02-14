#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr)  (!(ptr))
#define MAX_VERTICES 50

typedef struct node * node_ptr;

typedef struct node {

      int vertex;

      int id;    /* 學號 */

   char name[10];     /* 姓名  */

      node_ptr  link;

} node;

int d=false,b=false;//flag
node_ptr graph[MAX_VERTICES] = {};

int n = 0;

node_ptr create_node(int vertex, node_ptr link) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->vertex = vertex;
    new_node->link = link;
    return new_node;
}

void release_graph() {
    for (int i = 0; i < n; i++) {
        node_ptr deleted_node;
        while (graph[i]) {
            deleted_node = graph[i];
            graph[i] = deleted_node->link;
            free(deleted_node);
        }
        graph[i] = NULL;
    }
    n = 0;
}
bool visited[MAX_VERTICES] = {};

// 在走訪圖前，呼叫此函數來清空標記。
void reset_visited() {
   // memset(visited, 0, sizeof(visited));
   for (int i =0; i< n; i++) visited[i] = false;
}

// MARK: 深度搜尋 (DFS)

void DFS(int v,int id) {
    visited[v] = true;
    if(graph[v]->id==id){
    d=true;
    return 0;
    }
    for (node_ptr w = graph[v]; w; w = w->link)
        if (!visited[w-> vertex])
            DFS(w->vertex,id);
}

// MARK: 廣度搜尋 (BFS)

typedef struct queue *queue_ptr;
typedef struct queue {
    int vertex;
    queue_ptr link;
} queue;

void addq(queue_ptr *front, queue_ptr *rear, int vertex) {
    queue_ptr new_node = (queue_ptr)malloc(sizeof(queue));
    if (IS_FULL(new_node)) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    new_node->vertex = vertex;
    new_node->link = NULL;
    if (*front) {
        (*rear)->link = new_node;
    }
    else {
        *front = new_node;
    }
    *rear = new_node;
}

int deleteq(queue_ptr *front) {
    if (IS_EMPTY(*front)) {
        fprintf (stderr, "The queue is empty\n");
        exit(1);
    }
    queue_ptr deleted_node = *front;
    int vertex = deleted_node->vertex;
    *front = deleted_node->link;
    free(deleted_node);
    return vertex;
}

/* 從 v 點開始對圖進行廣度搜尋，使用佇列。 */
void BFS(int v,char name[10]) {
    // 佇列初始化
    queue_ptr front = NULL, rear = NULL;

    // 將第一次走訪的點排進佇列。
    addq(&front, &rear, v);
    visited[v] = true;
    if(strcmp(graph[v]->name,name)==0){//比較字串用strcmp()
    b=true;
    return 0;
    }
    // 依序將點從佇列去除，走訪與該點相鄰且未走過的點並排入佇列。
    while (front) {
        v = deleteq(&front);
        for (node_ptr w = graph[v]; w; w = w->link)
            if (!visited[w->vertex]) {
                addq(&front, &rear, w->vertex);
                visited[w->vertex] =true;
        if(strcmp(graph[w->vertex]->name,name)==0){
            b=1;
            return 0;
        }
            }
    }
}

void create_sample_graph();

int main()
{
    int c,id;
    char name[10];

    create_sample_graph();

    for (int i=0;i<n;i++) {//n=8
        printf("(%d,%s)", graph[i]->id,graph[i]->name);//第一筆資料
        for (node_ptr nptr = graph[i]; nptr;) {
            printf("->(%d,%s)", graph[nptr->vertex]->id,graph[nptr->vertex]->name); //第一筆後的資料
            nptr = nptr->link;
        }
        printf("\n");
    }

    printf("1:ID DFS \n2:NAME BFS \n3:end\n");

    while(scanf("%d",&c)!=EOF){
            d=false;//flag
            b=false;
    switch(c){

case 1:
    printf("ID:");
    scanf("%d",&id);
    reset_visited();

    DFS(0,id);

    if(d==false)
        printf("ID不在圖中\n");
    else printf("ID在圖中\n");

    printf("1:ID DFS \n2:NAME BFS \n3:end\n");
    break;

case 2:
    printf("NAME:");
    scanf("%s",name);
    reset_visited();

    BFS(0,name);

    if(b==false)
        printf("NAME不在圖中\n");
    else printf("NAME在圖中\n");

    printf("1:ID DFS \n2:NAME BFS \n3:end\n");
    break;

case 3:
    return 0;

    printf("深度優先 輸入1\n廣度優先 輸入2\n結束程式 輸入3\n");
    }
    }
    // 釋放記憶體
    release_graph();
    return 0;
}

/*
(101,Tom) →(102,John) →(103,Mary) →(104,Amy)
(102,John) → (101,Tom) →(105,Joe)
(103,Mary) →(101,Tom) →(105,Joe) →(106,Bob)
(104,Amy) →(101,Tom) →(106,Bob) →(107,Harry)
(105,Joe) →(102,John) →(103,Mary) →(108,Kay)
(106,Bob) →(103,Mary) →(104,Amy) →(107,Harry) →(108,Kay)
(107,Harry) →(104,Amy) →(106,Bob)
(108,Kay) →(105,Joe) →(106,Bob)
*/

void create_sample_graph() {
    node_ptr tmp;
    //用create_node函式連接資料

    //(101,Tom) →(102,John) →(103,Mary) →(104,Amy)→NULL
    tmp=create_node(3,NULL);
    tmp=create_node(2,tmp);
    tmp=create_node(1,tmp);
    graph[0]=tmp;
    graph[0]->id=101;
    strcpy(graph[0]->name,"Tom");

    //(102,John) → (101,Tom) →(105,Joe)→NULL
    tmp=create_node(4,NULL);
    tmp=create_node(0,tmp);
    graph[1]=tmp;
    graph[1]->id=102;
    strcpy(graph[1]->name,"John");

    //(103,Mary) →(101,Tom) →(105,Joe) →(106,Bob)→NULL
    tmp=create_node(5,NULL);
    tmp=create_node(4,tmp);
    tmp=create_node(0,tmp);
    graph[2]=tmp;
    graph[2]->id=103;
    strcpy(graph[2]->name,"Mary");

    //(104,Amy) →(101,Tom) →(106,Bob) →(107,Harry)→NULL
    tmp=create_node(6,NULL);
    tmp=create_node(5,tmp);
    tmp=create_node(0,tmp);
    graph[3]=tmp;
    graph[3]->id=104;
    strcpy(graph[3]->name,"Amy");

    //(105,Joe) →(102,John) →(103,Mary) →(108,Kay)→NULL
    tmp=create_node(7,NULL);
    tmp=create_node(2,tmp);
    tmp=create_node(1,tmp);
    graph[4]=tmp;
    graph[4]->id=105;
    strcpy(graph[4]->name,"Joe");

    //(106,Bob) →(103,Mary) →(104,Amy) →(107,Harry) →(108,Kay)→NULL
    tmp=create_node(7,NULL);
    tmp=create_node(6,tmp);
    tmp=create_node(3,tmp);
    tmp=create_node(2,tmp);
    graph[5]=tmp;
    graph[5]->id=106;
    strcpy(graph[5]->name,"Bob");

    //(107,Harry) →(104,Amy) →(106,Bob)→NULL

    tmp=create_node(5,NULL);
    tmp=create_node(3,tmp);
    graph[6]=tmp;
    graph[6]->id=107;
    strcpy(graph[6]->name,"Harry");

    //(108,Kay) →(105,Joe) →(106,Bob)→NULL
    tmp=create_node(5,NULL);
    tmp=create_node(4,tmp);
    graph[7]=tmp;
    graph[7]->id=108;
    strcpy(graph[7]->name,"Kay");

    n=8;
}
