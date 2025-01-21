//02_����IO�� ����ü.c
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
		{1, "ȫ�浿", 'm', 10.12f},
		{2, "����", 'f', 13.16f},
		{3, "��浿", 'm', 14.11f},
	};

	FILE* fp;
	fopen_s(&fp, "members.txt", "w");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return;
	}

	fprintf(fp, "%d\n", 3);	 //���

	for (int i = 0; i < 3; i++) //������
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
		printf("���� ���� ����\n");
		return;
	}

	member members[10];
	int size; 
	fscanf_s(fp, "%d", &size);	 //���

	//�����Է�
	for (int i = 0; i < size; i++)	{
		member mem;
		fscanf_s(fp, "%d %s %c %f",
			&mem.number,
			mem.name, (int)sizeof(mem.name),
			&mem.gender, (int)sizeof(mem.gender),
			&mem.weight);
		members[i] = mem;	//*********
	}

	//���
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