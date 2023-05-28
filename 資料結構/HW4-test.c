/* ���ɮ׬���Ƶ��c�Ĥ����u�ϧΡv���d���ɡA�ܽd�`�׷j�M�B�s�׷j�M�C
 *
 * �H�U�]�t��ӥ����ܼơA`graph` �� `visited`�A`visited` ���̩ۨ� graph �����X�O���A�H
 * �U�j�M�禡�Ҧ@�Φ����ܼơA�ϥΤW�ݯS�O�p�ߡC
 */

#include <stdbool.h>    /* bool, true, false */
#include <stdio.h>      /* printf, fprintf */
#include <stdlib.h>     /* malloc, exit */
#include <string.h>     /* memset */

// �Ω��쵲��C
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr)  (!(ptr))

// �Ϫ��I�ƤW���A�i�ۦ�׭q�C
#define MAX_VERTICES 50

typedef struct node * node_ptr;

typedef struct node {

      int vertex;

      int id;    /* �Ǹ� */

   char name[10];     /* �m�W  */

      node_ptr  link;

} node;

int exist;
node_ptr graph[MAX_VERTICES] = {};

// �{�b�ϥΪ��I�C`graph` �����I�� 0...n - 1�C

int n = 0; /*���`�I�Ӽ� ���s�q�ܼ�*/

node_ptr create_node(int vertex, node_ptr link) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->vertex = vertex;
    new_node->link = link;
    return new_node;
}

// ����Ϫ��O����C
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

// MARK: - �Ϫ����X

// ���X�ϮɡA�ΨӼаO���S�����L�I�C
bool visited[MAX_VERTICES] = {};

// �b���X�ϫe�A�I�s����ƨӲM�żаO�C
void reset_visited() {
   // memset(visited, 0, sizeof(visited));
   for (int i =0; i< n; i++) visited[i] = false;
}

// MARK: �`�׷j�M (DFS)

/* �q v �I�}�l��϶i��`�׷j�M�A�|���j�I�s `dfs(int)`�C */
void dfs(int v,int id) {
    visited[v] = true;

    if(graph[v]->id==id){
    exist=1;
    return 0;
    }

    // ���X�P v �۾F�B�L���L���I�C
    for (node_ptr w = graph[v]; w; w = w->link)
        if (!visited[w-> vertex])
            dfs(w->vertex,id);
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
void bfs(int v,char name[10]) {
    // ��C��l��
    queue_ptr front = NULL, rear = NULL;

    // �N�Ĥ@�����X���I�ƶi��C�C
    addq(&front, &rear, v);
    visited[v] = true;
    if(strcmp(graph[v]->name,name)==0){
    exist=1;
    return 0;
    }

    // �̧ǱN�I�q��C�h���A���X�P���I�۾F�B�����L���I�ñƤJ��C�C
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
    // �إ߽d�ҹ�
    create_sample_graph();

    // �L�X�۾F��C
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
 printf("�`���u�� ��J1\n�s���u�� ��J2\n�����{�� ��J3\n");
     while(scanf("%d",&Options)){
            exist=0;
   if(Options==1){
    // �`�׷j�M
    printf("��J�Q�j�M�ǥͤ��Ǹ�:\n");
     scanf("%d",&id);

    reset_visited();

    dfs(0,id);

    (exist==0)?printf("�ǥ͸�Ƥ��b�Ϥ�\n"):printf("��Ʀb�Ϥ�\n");
    }
else if(Options==2){
    // �s�׷j�M
     printf("��J�Q�j�M�ǥͤ��m�W:\n");
    scanf("%s",name);
    reset_visited();
    bfs(0,name);
    (exist==0)?printf("�ǥ͸�Ƥ��b�Ϥ�\n"):printf("��Ʀb�Ϥ�\n");
    }
else
    return 0;

printf("�`���u�� ��J1\n�s���u�� ��J2\n�����{�� ��J3\n");
     }



    // ����O����
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
