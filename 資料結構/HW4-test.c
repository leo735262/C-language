/* 此檔案為資料結構第六章「圖形」的範例檔，示範深度搜尋、廣度搜尋。
 *
 * 以下包含兩個全域變數，`graph` 及 `visited`，`visited` 為相依於 graph 的走訪記錄，以
 * 下搜尋函式皆共用此兩變數，使用上需特別小心。
 */

#include <stdbool.h>    /* bool, true, false */
#include <stdio.h>      /* printf, fprintf */
#include <stdlib.h>     /* malloc, exit */
#include <string.h>     /* memset */

// 用於鏈結串列
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr)  (!(ptr))

// 圖的點數上限，可自行修訂。
#define MAX_VERTICES 50

typedef struct node * node_ptr;

typedef struct node {

      int vertex;

      int id;    /* 學號 */

   char name[10];     /* 姓名  */

      node_ptr  link;

} node;

int exist;
node_ptr graph[MAX_VERTICES] = {};

// 現在使用的點。`graph` 中的點為 0...n - 1。

int n = 0; /*為節點個數 為廣義變數*/

node_ptr create_node(int vertex, node_ptr link) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->vertex = vertex;
    new_node->link = link;
    return new_node;
}

// 釋放圖的記憶體。
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

// MARK: - 圖的走訪

// 走訪圖時，用來標記有沒有走過點。
bool visited[MAX_VERTICES] = {};

// 在走訪圖前，呼叫此函數來清空標記。
void reset_visited() {
   // memset(visited, 0, sizeof(visited));
   for (int i =0; i< n; i++) visited[i] = false;
}

// MARK: 深度搜尋 (DFS)

/* 從 v 點開始對圖進行深度搜尋，會遞迴呼叫 `dfs(int)`。 */
void dfs(int v,int id) {
    visited[v] = true;

    if(graph[v]->id==id){
    exist=1;
    return 0;
    }

    // 走訪與 v 相鄰且無走過的點。
    for (node_ptr w = graph[v]; w; w = w->link)
        if (!visited[w-> vertex])
            dfs(w->vertex,id);
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
void bfs(int v,char name[10]) {
    // 佇列初始化
    queue_ptr front = NULL, rear = NULL;

    // 將第一次走訪的點排進佇列。
    addq(&front, &rear, v);
    visited[v] = true;
    if(strcmp(graph[v]->name,name)==0){
    exist=1;
    return 0;
    }

    // 依序將點從佇列去除，走訪與該點相鄰且未走過的點並排入佇列。
    while (front) {
        v = deleteq(&front);
        for (node_ptr w = graph[v]; w; w = w->link)
            if (!visited[w->vertex]) {
                addq(&front, &rear, w->vertex);
                visited[w->vertex] =1;
                if(strcmp(graph[w->vertex]->name,name)==0){
    exist=true;
    return 0;
    }


            }
    }
}



void create_sample_graph();

int main() {
    int Options,id;
    char name[10]={};
    // 建立範例圖
    create_sample_graph();

    // 印出相鄰串列
    printf("Graph:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d %s)", graph[i]->id,graph[i]->name);
        for (node_ptr nptr = graph[i]; nptr; nptr = nptr->link) {
            printf(" -> (%d %s)", graph[nptr->vertex]->id,graph[nptr->vertex]->name);
        }
        printf("\n");
    }
    printf("\n");
    printf("");
 printf("深度優先 輸入1\n廣度優先 輸入2\n結束程式 輸入3\n");
     while(scanf("%d",&Options)){
            exist=0;
   if(Options==1){
    // 深度搜尋
    printf("輸入想搜尋學生之學號:\n");
     scanf("%d",&id);

    reset_visited();

    dfs(0,id);

    (exist==0)?printf("學生資料不在圖中\n"):printf("資料在圖中\n");
    }
else if(Options==2){
    // 廣度搜尋
     printf("輸入想搜尋學生之姓名:\n");
    scanf("%s",name);
    reset_visited();
    bfs(0,name);
    (exist==0)?printf("學生資料不在圖中\n"):printf("資料在圖中\n");
    }
else
    return 0;

printf("深度優先 輸入1\n廣度優先 輸入2\n結束程式 輸入3\n");
     }



    // 釋放記憶體
    release_graph();

    return 0;
}

void create_sample_graph() {
    node_ptr temp;
    //v1->v2->v3->v4
    temp=create_node(3,NULL);
    temp=create_node(2,temp);
    temp=create_node(1,temp);
    graph[0]=temp;
    graph[0]->id=101; strcpy(graph[0]->name,"Tom");
   // v2->v1->v5
    temp=create_node(4,NULL);
    temp=create_node(0,temp);
    graph[1]=temp;
    graph[1]->id=102; strcpy(graph[1]->name,"John");
    //v3->v1->v5->v6
    temp=create_node(5,NULL);
    temp=create_node(4,temp);
    temp=create_node(0,temp);
    graph[2]=temp;
    graph[2]->id=103; strcpy(graph[2]->name,"Mary");
    //v4->v1->v6->v7
    temp=create_node(6,NULL);
    temp=create_node(5,temp);
    temp=create_node(0,temp);
    graph[3]=temp;
    graph[3]->id=104; strcpy(graph[3]->name,"Amy");
    //v5->v2->v3->v8
    temp=create_node(7,NULL);
    temp=create_node(2,temp);
    temp=create_node(1,temp);
    graph[4]=temp;
    graph[4]->id=105; strcpy(graph[4]->name,"Joe");
    //v6->v3->v4->v7->v8
    temp=create_node(7,NULL);
    temp=create_node(6,temp);
    temp=create_node(3,temp);
    temp=create_node(2,temp);
    graph[5]=temp;
    graph[5]->id=106; strcpy(graph[5]->name,"Bob");
    //v7->v4->v6
    temp=create_node(5,NULL);
    temp=create_node(3,temp);
    graph[6]=temp;
    graph[6]->id=107; strcpy(graph[6]->name,"Harry");
    //v8->v5->v6
    temp=create_node(5,NULL);
    temp=create_node(4,temp);
    graph[7]=temp;
    graph[7]->id=108; strcpy(graph[7]->name,"Kay");
    n=8;
}
