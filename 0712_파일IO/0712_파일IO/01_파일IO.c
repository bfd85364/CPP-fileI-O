//01_����IO.c
/*
��Ʈ�� ���
- ����Ʈ(byte) �帧[����->��]
  stdin  : Ű����   ->[�Է¹���] -> ���α׷�
           scanf_s
  stdout : ���α׷� ->[��¹���] -> ȭ��
           printf
*/
/*
����IO
���Ϸε� : ���� -> [�Է¹���] -> ���α׷�
�������� : ���α׷� -> [��¹���] -> ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

int main()
{
    exam4();

	return 0;
}

/*
���   ���� X                   ���� O
----------------------------------------------
"w"      O[���θ����]          O[���θ����]
"r"      X                      O
*/
void exam1()
{
    FILE* fp;
    //��Ʈ�� ����
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("���� open ����\n");
        return;
    }  

    //��Ʈ�� �ı�
    fclose(fp);
}

//printf VS fprintf
void exam2()
{
    FILE* fp = fopen("test.txt", "w");

    printf("Hello, World!\n");
    fprintf(stdout, "Hello, World!\n");
    fprintf(fp, "Hello, World!\n");

    fclose(fp);
}

//fprintf
void exam3()
{
    FILE* fp = fopen("test.txt", "w");
    if (fp == NULL)  {
        printf("���� ���� ����\n");
        return;
    }

    printf("%d %s %c %f\n",
        10, "aaa", 'S', 10.234f);

    fprintf(fp, "%d %s %c %f\n",
        10, "aaa", 'S', 10.234f);

    fclose(fp);
}

//fscanf
void exam4()
{
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("���� ���� ����\n");
        return;
    }

    int num;
    char str[20];
    char ch;
    float fnum;

    fscanf_s(fp, "%d", &num);
    fscanf_s(fp, "%s", str, (int)sizeof(str));
    char dummy = fgetc(fp);
    fscanf_s(fp, "%c", &ch, (int)sizeof(ch));
    fscanf_s(fp, "%f", &fnum);

    printf("%d, %s, %c, %f\n", 
        num, str, ch, fnum);

    fclose(fp);
}