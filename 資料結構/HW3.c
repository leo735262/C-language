#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Student{

char Id[10];         /*�Ǹ�*/

char Name[10];       /*�m�W*/

int Math_score;      /*�ƾǦ��Z*/

int English_score;   /*�^�妨�Z*/

} Student;

Student heap[100];
int n=0,m=0,km=0,ke=0;// km ke ���O�O�����ܼ� �p�⦳�h�ֵ����

void insert_min_heap(Student item, int *n, char t);//�إ̤߳p�ְ�
void print_min_heap(int n);//�L�X�̤p�ְ�
Student delete_min_heap(int *n,char t);//�R���̤p�ְ�ñƧ�

int main(){

    Student item = { 0 };

    strcpy(item.Id,"11001101") ; strcpy(item.Name,"John") ;  item.Math_score = 66; item.English_score = 44; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001102") ; strcpy(item.Name,"Alex") ;  item.Math_score = 77; item.English_score = 22; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001103") ; strcpy(item.Name,"Mary") ;  item.Math_score = 88; item.English_score = 55; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001104") ; strcpy(item.Name,"Jane") ;  item.Math_score = 99; item.English_score = 11; insert_min_heap(item, &n, 'M');
    strcpy(item.Id,"11001105") ; strcpy(item.Name,"Jerry") ; item.Math_score = 55; item.English_score = 33; insert_min_heap(item, &n, 'M');

    // �p�G�n�s�W���(�ƾǬ��D)�A�ШϥΦ��榡 : strcpy(item.Id,"�Ǹ�") ; strcpy(item.Name,"�m�W") ; item.Math_score = �ƾǦ��Z;item.English_score = �^�妨�Z;  insert_min_heap(item, &n, 'M');

    print_min_heap(n);//�L�X�H�ƾǦ��Z���D���̤p�ְ��
    printf("\n");
    // delete_min_heap(n);

    printf("   Id      Name   Math_score   English_score\n");
    for(int i=0;i<km;i++){
        item = delete_min_heap(&n,'M'); //�R���H�ƾǦ��Z���D���̤p�ְ�ñƧ�
    printf("%s   %s      %d             %d   \n", item.Id,item.Name,item.Math_score,item.English_score);
    }
    printf("\n");


    strcpy(item.Id,"11001101") ; strcpy(item.Name,"John") ;  item.English_score = 44; item.Math_score = 66; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001102") ; strcpy(item.Name,"Alex") ;  item.English_score = 22; item.Math_score = 77; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001103") ; strcpy(item.Name,"Mary") ;  item.English_score = 55; item.Math_score = 88; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001104") ; strcpy(item.Name,"Jane") ;  item.English_score = 11; item.Math_score = 99; insert_min_heap(item, &m, 'E');
    strcpy(item.Id,"11001105") ; strcpy(item.Name,"Jerry") ; item.English_score = 33; item.Math_score = 55; insert_min_heap(item, &m, 'E');
    //�p�G�n�s�W���(�^�嬰�D)�A�ШϥΦ��榡 : strcpy(item.Id,"�Ǹ�") ; strcpy(item.Name,"�m�W") ; item.English_score = �^�妨�Z; item.Math_score = �ƾǦ��Z; insert_min_heap(item, &m, 'E');

    print_min_heap(m);//�L�X�H�^�妨�Z���D���̤p�ְ��
    printf("\n");
    //delete_min_heap(m);

    printf("   Id      Name   Math_score   English_score\n");
    for(int i=0;i<ke;i++){
        item = delete_min_heap(&m,'E');//�R���H�^�妨�Z���D���̤p�ְ�ñƧ�
    printf("%s   %s      %d             %d   \n", item.Id,item.Name,item.Math_score,item.English_score);
    }
    printf("\n");

}

void insert_min_heap(Student item, int *n, char t){

int i;

    i = ++(*n); //�I�s���ơAheap[0] �S�����

    if(t=='M'){
            km++; //�H�ƾǦ��Z���D����Ƽƶq�p��
    while ((i != 1) && (item.Math_score < heap[i / 2].Math_score)) {//�p�G���O�Ĥ@����� �B  �n���J����ƪ����Z�p��L�����`�I
        heap[i] = heap [i / 2];//�N���`�I��Ʃ��l�`�I��Ƹ�
        i = i / 2;
     }
     heap[i] = item;//�n���J����Ʃ�J���Ӫ����`�I��Ƹ�
    }

    if(t=='E'){
            ke++;//�H�^�妨�Z���D����Ƽƶq�p��
    while ((i != 1) && (item.English_score < heap[i / 2].English_score)) {//�p�G���O�Ĥ@����� �B  �n���J����ƪ����Z�p��L�����`�I
        heap[i] = heap [i / 2];//�N���`�I��Ʃ��l�`�I��Ƹ�
        i = i / 2;
     }
     heap[i] = item;//�n���J����Ʃ�J���Ӫ����`�I��Ƹ�
    }

}

void print_min_heap(int n) {
    int i, j = 1;
    for (i = 1; i <= n; i++) {
        printf("  %d %3s", i,heap[i].Name);//�Ӷ��ǦL�X���
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



    if(t=='M'){//�R���H�ƾǦ��Z���D���̤p�ְ�ñƧ�

            item = heap[1];//item �O�̤p�����

    temp = heap[(*n)--];// temp�O�̫�@����� �]�N�O�̤j���(�]���q0�}�l�� �ҥHn�n-1 ����-1)
    parent = 1; child = 2;

    while (child <= *n) {
        if ((child < *n) && (heap[child].Math_score > heap [child + 1].Math_score))//�p�G�k�l�`�I>���l�`�I
            child++;//���l�`�I
        if (temp.Math_score <= heap[child].Math_score) break;//�̫�@�����(���Ӫ����`�I)<=�l�`�I��� �����j��
 /* move to the next lower level */
        heap[parent] = heap[child];//�i�J IF �k�l�`�I�ܦ����`�I ELSE �h ���l�`�I�ܦ����`�I
        parent = child;//���U��
        child = child * 2;
    }
    heap[parent] = temp;//�̫�@������ܤ��`�I
    return item;//�^�� item �O�̤p�����
    }

    if(t=='E'){//�R���H�^�妨�Z���D���̤p�ְ�ñƧ�

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
