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

list_pointer head,per,back;
list_pointer nodeadd;


void add(int addid){

nodeadd=(list_pointer)malloc(sizeof(list_node));

nodeadd->id=addid;
printf("�п�J�m�W:");
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


void search(int number){
per=head;
back=per->link;
while(back!=NULL&&back->id>=number){
 if(back->id==number){
      printf("%d %s\n",back->id,back->name);
    return 0;
 }

  per=back;
  back=back->link;
    }
    printf("�ǥ͸�Ƥ��s�b\n");
}
void delete(int number){
per=head;
back=per->link;

while(back!=NULL&&back->id>=number){

 if(back->id==number){
    per->link=back->link;
    free(back);
    printlist();
    return 0;
 }

  per=back;
  back=back->link;
    }
    printf("�ǥ͸�Ƥ��s�b\n");
}

void printlist(){

back=head->link;
while(back!=NULL){
    printf("%d %s\n",back->id,back->name);
    back=back->link;
    }
}

int main()
{
    int  a,number;
    char name[20];
    head = (list_pointer)malloc(sizeof(list_node));
    head->link=NULL;
    printf("�п�J�Ʀr 1 2 3 4\n��J1�O�W�[\n��J2�O�R��\n��J3�O�j�M\n��J4�O�������\n");
 while(scanf("%d",&a)){
 assert(a<=4&&a>0);
 if(a==1)
{
    printf("�п�J�s�W�Ǹ�:");
    scanf("%d",&number);
   add(number);
}

  else if(a==2)
{
    printf("�п�J�R���Ǹ�:");
        scanf("%d",&number);
    delete(number);
}
 else if(a==3)
{
    printf("�п�J�j�M�Ǹ�:");
    scanf("%d",&number);
    search(number);

}
else
    break;
    printf("�п�J�Ʀr 1 2 3 4\n");

 }

    return 0;
}
