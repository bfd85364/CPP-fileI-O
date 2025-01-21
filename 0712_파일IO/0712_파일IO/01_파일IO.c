//01_파일IO.c
/*
스트림 상수
- 바이트(byte) 흐름[시작->끝]
  stdin  : 키보드   ->[입력버퍼] -> 프로그램
           scanf_s
  stdout : 프로그램 ->[출력버퍼] -> 화면
           printf
*/
/*
파일IO
파일로드 : 파일 -> [입력버퍼] -> 프로그램
파일저장 : 프로그램 -> [출력버퍼] -> 파일
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
모드   파일 X                   파일 O
----------------------------------------------
"w"      O[새로만든다]          O[새로만든다]
"r"      X                      O
*/
void exam1()
{
    FILE* fp;
    //스트림 생성
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("파일 open 에러\n");
        return;
    }  

    //스트림 파괴
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
        printf("파일 열기 실패\n");
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
        printf("파일 열기 실패\n");
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