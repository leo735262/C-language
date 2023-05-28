#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef struct list_node *list_pointer;

typedef struct list_node

{    int id;

     char name[20];

     list_pointer link;

} list_node;

list_pointer head;
list_pointer per,back;
list_pointer nodeadd;

void add(int addid);
void printlist();
void delete(int deleteid);
void search(int searchid);

void content(){

    int n;
    printf("請輸入數字 1 2 3 4\n");
    scanf("%d",&n);

    if(n<1 || n>4){
        printf("錯誤數字指令，請輸入正確數字指令\n");
        content();
        }

    int id;
    char name[20];
    int deleteid;
    int searchid;

    switch(n){
case 1:
    printf("請輸入新增學號:");
    scanf("%d",&id);
    add(id);
    content();
    break;

case 2:
    printf("請輸入刪除學號:");
    scanf("%d",&deleteid);
    delete(deleteid);
    content();
    break;

case 3:
    printf("請輸入搜尋學號:");
    scanf("%d",&searchid);
    search(searchid);
    content();
    break;

case 4:
    break;

}

}


int main(){

    int n,id,deleteid,searchid;
    char name[20];

    head = (list_pointer)malloc(sizeof(list_node));
    head->link=NULL;

    printf("輸入1是增加\n");
    printf("輸入2是刪除\n");
    printf("輸入3是搜尋\n");
    printf("輸入4是結束選單\n");

    scanf("%d",&n);

    if(n<1 || n>4){
        printf("錯誤數字指令，請輸入正確數字指令\n");
        content();
        }

    switch(n){
case 1:
    printf("請輸入新增學號:");
    scanf("%d",&id);
    add(id);
    content();
    break;

case 2:
    printf("請輸入刪除學號:");
    scanf("%d",&deleteid);
    delete(deleteid);
    content();
    break;

case 3:
    printf("請輸入搜尋學號:");
    scanf("%d",&searchid);
    search(searchid);
    content();
    break;

case 4:
    break;


 }


}

void add(int addid){

nodeadd=(list_pointer)malloc(sizeof(list_node));

nodeadd->id=addid;
printf("請輸入姓名:");
scanf("%s",nodeadd->name);
per=head;
back=per->link;

while((back!=NULL) && (back->id>nodeadd->id)){

  per=back;
  back=back->link;

}

nodeadd->link=back;
per->link=nodeadd;

printlist();

}

void printlist(){

back=head->link;

while(back!=NULL){

    printf("%4d %s\n",back->id,back->name);
    back=back->link;

    }
}

void delete(int deleteid){
per=head;
back=per->link;

while(back!=NULL && back->id>=deleteid){

 if(back->id==deleteid){
    per->link=back->link;
    free(back);
    printlist();
    return 0;
 }

  per=back;
  back=back->link;
    }
    printf("資料不存在\n");
}

void search(int searchid){
per=head;
back=per->link;
while(back!=NULL && back->id>=searchid){
 if(back->id==searchid){
      printf("%d %s\n",back->id,back->name);
    return 0;
 }

  per=back;
  back=back -> link;
    }
    printf("資料不存在\n");
}
