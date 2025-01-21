//02_파일IO와 구조체.c
#include <stdio.h>

typedef struct tagmember member;
struct tagmember
{
	int number;
	char name[20];
	char gender;
	float weight;
};

void file_save()
{
	member members[] = {
		{1, "홍길동", 'm', 10.12f},
		{2, "김길순", 'f', 13.16f},
		{3, "고길동", 'm', 14.11f},
	};

	FILE* fp;
	fopen_s(&fp, "members.txt", "w");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return;
	}

	fprintf(fp, "%d\n", 3);	 //헤더

	for (int i = 0; i < 3; i++) //데이터
	{
		member mem = members[i];
		fprintf(fp, "%d %s %c %f\n",
			mem.number, mem.name,
			mem.gender, mem.weight);
	}

	fclose(fp);
}

void file_load()
{
	FILE* fp;
	fopen_s(&fp, "members.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return;
	}

	member members[10];
	int size; 
	fscanf_s(fp, "%d", &size);	 //헤더

	//파일입력
	for (int i = 0; i < size; i++)	{
		member mem;
		fscanf_s(fp, "%d %s %c %f",
			&mem.number,
			mem.name, (int)sizeof(mem.name),
			&mem.gender, (int)sizeof(mem.gender),
			&mem.weight);
		members[i] = mem;	//*********
	}

	//출력
	for (int i = 0; i < size; i++) {
		member mem = members[i];
		fprintf(stdout, "%d %s %c %f\n",
			mem.number, mem.name,
			mem.gender, mem.weight);
	}

	fclose(fp);
}

int main()
{
	//file_save();
	file_load();

	return 0;
}