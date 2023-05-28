#include<stdio.h>
int s1[7] = {2, 5, 7, 9, 3, 1, 2};
int s2[5] = {3, 5, 3, 2, 8};
int length[8][6];

int max(int a, int b) {
  if (a>b)
    return a;
  else
    return b;
}


void main() {
    // ��l�ơG�� s1 �� s2 ���Ŷ��X�A�h LCS ���Ŷ��X�C
    for (int i = 0; i <= 7; ++i)
        length[i][0] = 0;
    for (int j = 0; j <= 5; ++j)
        length[0][j] = 0;

    // �̷ӻ��j��������
    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= 7; ++j) {
            if (s1[i - 1] == s2[j - 1])
                // �]�� e1 �����׬� 1�A�G�n +1
                length[i][j] = length[i - 1][j - 1] + 1;
            else
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);
        }
    }

    // Print the result
    printf("LCS length: %d\n", length[7][5]);
    for(int i=0;i<8;i++){
             printf("\n");
        for(int j=0;j<6;j++)
            printf("%d ",length[i][j]);
            }
}
