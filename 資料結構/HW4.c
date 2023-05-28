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

      int id;    /* �Ǹ� */

   char name[10];     /* �m�W  */

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

// �b���X�ϫe�A�I�s����ƨӲM�żаO�C
void reset_visited() {
   // memset(visited, 0, sizeof(visited));
   for (int i =0; i< n; i++) visited[i] = false;
}

// MARK: �`�׷j�M (DFS)

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

// MARK: �s�׷j�M (BFS)

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

/* �q v �I�}�l��϶i��s�׷j�M�A�ϥΦ�C�C */
void BFS(int v,char name[10]) {
    // ��C��l��
    queue_ptr front = NULL, rear = NULL;

    // �N�Ĥ@�����X���I�ƶi��C�C
    addq(&front, &rear, v);
    visited[v] = true;
    if(strcmp(graph[v]->name,name)==0){//����r���strcmp()
    b=true;
    return 0;
    }
    // �̧ǱN�I�q��C�h���A���X�P���I�۾F�B�����L���I�ñƤJ��C�C
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
        printf("(%d,%s)", graph[i]->id,graph[i]->name);//�Ĥ@�����
        for (node_ptr nptr = graph[i]; nptr;) {
            printf("->(%d,%s)", graph[nptr->vertex]->id,graph[nptr->vertex]->name); //�Ĥ@���᪺���
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
        printf("ID���b�Ϥ�\n");
    else printf("ID�b�Ϥ�\n");

    printf("1:ID DFS \n2:NAME BFS \n3:end\n");
    break;

case 2:
    printf("NAME:");
    scanf("%s",name);
    reset_visited();

    BFS(0,name);

    if(b==false)
        printf("NAME���b�Ϥ�\n");
    else printf("NAME�b�Ϥ�\n");

    printf("1:ID DFS \n2:NAME BFS \n3:end\n");
    break;

case 3:
    return 0;

    printf("�`���u�� ��J1\n�s���u�� ��J2\n�����{�� ��J3\n");
    }
    }
    // ����O����
    release_graph();
    return 0;
}

/*
(101,Tom) ��(102,John) ��(103,Mary) ��(104,Amy)
(102,John) �� (101,Tom) ��(105,Joe)
(103,Mary) ��(101,Tom) ��(105,Joe) ��(106,Bob)
(104,Amy) ��(101,Tom) ��(106,Bob) ��(107,Harry)
(105,Joe) ��(102,John) ��(103,Mary) ��(108,Kay)
(106,Bob) ��(103,Mary) ��(104,Amy) ��(107,Harry) ��(108,Kay)
(107,Harry) ��(104,Amy) ��(106,Bob)
(108,Kay) ��(105,Joe) ��(106,Bob)
*/

void create_sample_graph() {
    node_ptr tmp;
    //��create_node�禡�s�����

    //(101,Tom) ��(102,John) ��(103,Mary) ��(104,Amy)��NULL
    tmp=create_node(3,NULL);
    tmp=create_node(2,tmp);
    tmp=create_node(1,tmp);
    graph[0]=tmp;
    graph[0]->id=101;
    strcpy(graph[0]->name,"Tom");

    //(102,John) �� (101,Tom) ��(105,Joe)��NULL
    tmp=create_node(4,NULL);
    tmp=create_node(0,tmp);
    graph[1]=tmp;
    graph[1]->id=102;
    strcpy(graph[1]->name,"John");

    //(103,Mary) ��(101,Tom) ��(105,Joe) ��(106,Bob)��NULL
    tmp=create_node(5,NULL);
    tmp=create_node(4,tmp);
    tmp=create_node(0,tmp);
    graph[2]=tmp;
    graph[2]->id=103;
    strcpy(graph[2]->name,"Mary");

    //(104,Amy) ��(101,Tom) ��(106,Bob) ��(107,Harry)��NULL
    tmp=create_node(6,NULL);
    tmp=create_node(5,tmp);
    tmp=create_node(0,tmp);
    graph[3]=tmp;
    graph[3]->id=104;
    strcpy(graph[3]->name,"Amy");

    //(105,Joe) ��(102,John) ��(103,Mary) ��(108,Kay)��NULL
    tmp=create_node(7,NULL);
    tmp=create_node(2,tmp);
    tmp=create_node(1,tmp);
    graph[4]=tmp;
    graph[4]->id=105;
    strcpy(graph[4]->name,"Joe");

    //(106,Bob) ��(103,Mary) ��(104,Amy) ��(107,Harry) ��(108,Kay)��NULL
    tmp=create_node(7,NULL);
    tmp=create_node(6,tmp);
    tmp=create_node(3,tmp);
    tmp=create_node(2,tmp);
    graph[5]=tmp;
    graph[5]->id=106;
    strcpy(graph[5]->name,"Bob");

    //(107,Harry) ��(104,Amy) ��(106,Bob)��NULL

    tmp=create_node(5,NULL);
    tmp=create_node(3,tmp);
    graph[6]=tmp;
    graph[6]->id=107;
    strcpy(graph[6]->name,"Harry");

    //(108,Kay) ��(105,Joe) ��(106,Bob)��NULL
    tmp=create_node(5,NULL);
    tmp=create_node(4,tmp);
    graph[7]=tmp;
    graph[7]->id=108;
    strcpy(graph[7]->name,"Kay");

    n=8;
}
