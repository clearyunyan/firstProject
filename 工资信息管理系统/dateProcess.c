#include"manage.h"
//ʵ�����ݴ����ܵĺ���   2022.5.20

void yuancount() {
	char name[20];
	int month[12];
	int b = 0;
	int c = 0;
	float s = 0;
	int i = 0;
	int pan = 1;

	system("cls");
	while (pan == 1) {
		c = 0;
		s = 0;
		system("cls");
		printf("��������������\n");
		scanf("%s", name);
		printf("����-1���������ʼ��¼��Ҫͳ�Ƶ��·�");
		scanf_s("%d", &b);
		for (i = 0; b != -1; i++)
		{
			printf("������Ҫͳ�Ƶ��·�\n");
			scanf("%d", &month[i]);
			printf("����-1����,�������������������·�");
			scanf_s("%d", &b);
			c++;
		}
		int n = 0;
		aStaff one[1000];
		n = getStruct(one);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c; j++)
			{
				if ((strcmp(name, one[i].name) == 0) && (one[i].month == month[j]))
				{
					s += one[i].realWages;
				}

			}

		}
		printf("���⼸���µĹ����ܺ�Ϊ%.2f(Ϊ0������δ�ҵ�������Ϣ,������������)\n", s);
		printf("��ѡ������ͳ��(����1)�򷵻���һ��(����0)\n");
		scanf("%d", &pan);
	}
		yuanMenu();

}
//Ա��ͳ������
void opchange()
{
	system("cls");
	FILE* fin;
	int a = 1;		//ѭ������
	int n = 0;		//Ա������
	char na[20];
	aStaff one[1000];

	
	while (a == 1) {
		n = getStruct(one);
		int s = 0;
		int c = 0;
		system("cls");
		printf("��������Ҫ�޸ĵ����ݵ�Ա��������,�·�\n");\
		scanf("%s", na);
		scanf("%d", &c);
		fin = fopen("yuangong.txt", "w");

		for (int i = 0; i < n; i++)
		{
			if (strcmp(na, one[i].name) == 0&&c==one[i].month) {
				printf("�����������µ����п���,ְ����\n");
				scanf("%s%s", one[i].cardID, one[i].staffID);
				printf("������������Ӧ������,ˮ��,˰��,����ۿ�(��ÿ����һ������һ�λس�)\n");
				scanf("%f%f%f%f", &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other);
				one[i].realWages = one[i].wagesPayable - one[i].tax - one[i].waterElectricity - one[i].other;
				printf("������ʵ������Ϊ%f", one[i].realWages);
				s++;
			}
			fprintf(fin, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fin);
		if (s != 0)printf("�޸ĳɹ�\n");
		else printf("δ�ҵ�Ҫ�޸ĵĶ���");
		printf("��ѡ������޸�(����1)�򷵻���һ������(0)");
		scanf("%d", &a);
	}
	dcMenu();
}
//����Ա�޸�����
void opdelete() {
	system("cls");
	FILE* fin;
	int a = 1;
	int n = 0;
	char na[20];
	aStaff one[1000];
	
	while (a == 1) {
		int s = 0;
		int p = 0;
		n = getStruct(one);
		system("cls");
		printf("��������Ҫɾ�������ݵ�Ա�������ֺ��·�\n");
		scanf("%s%d", na,&p);
		fin = fopen("yuangong.txt", "w");
		for (int i = 0; i < n; i++)
		{
			if (strcmp(na, one[i].name) == 0&&p==one[i].month) {
				s++;
				continue;
			}
			fprintf(fin, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fin);
		if (s != 0)printf("ɾ���ɹ�\n");
		else printf("δ�ҵ�Ҫɾ���Ķ���");
		printf("��ѡ�����ɾ��(����1)�򷵻���һ��(����0)\n");
		scanf("%d", &a);
	}
	dcMenu();
}
//����Աɾ������
void opcount()
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   ͳ��Ա����д���ļ�       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �����������д����ļ�   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: { 
		char na[20];
		int a[12];
		int b = 0;
		int c = 0;
		float s = 0;
		int i = 0;
		int pan = 1;
		system("cls");
		while (pan == 1) {
			s = 0;
			c = 0;
			FILE* fp;
			fp = fopen("gongzizong.txt", "a");
			system("cls");
			printf("�������Ա��������\n");
			scanf("%s", na);
			printf("����-1���������ʼ��¼��Ҫͳ�Ƶ��·�");
			scanf_s("%d", &b);
			for (i = 0; b != -1; i++)
			{
				printf("������Ҫͳ�Ƶ��·�\n");
				scanf("%d", &a[i]);
				printf("����-1����,�������������������·�");
				scanf_s("%d", &b);
				c++;
			}
			int n = 0;
			aStaff one[1000];
			n = getStruct(one);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < c; j++)
				{
					if ((strcmp(na, one[i].name) == 0) && (one[i].month == a[j]))
					{
						s += one[i].realWages;
					}

				}

			}
			printf("��Ա���⼸���µĹ����ܺ�Ϊ%.2f(Ϊ0������δ�ҵ���Ա������Ϣ,��������������)\n", s);
			fprintf(fp,"%s ",na);
			fprintf(fp, "%.2f\t ", s);
			for(int i=0;i<c;i++)
			fprintf(fp, "%d ",a[i]);
			char ch = '\n';
			fputc(ch, fp);
			
			printf("��ѡ�����ͳ��(����1)�򷵻���һ��(����0)\n");
			scanf("%d", &pan);
			fclose(fp);
		}
		opcount();
		break;
	}
	case 2: countliulan(); break;
	case 3: processMenu(); break;
	case 4: exit(0); break;
	}
}
//����Աͳ������
void opsort()
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   ��������д���ļ�       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �����д����ļ�         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n) 
	{
	case 1:writesort(); break;
	case 2:readsort(); break;
	case 3:processMenu(); break;
	case 4:exit(0); break;
	}
	opsort();
}
//����Ա��������
void countliulan() 
{
	FILE* fp;
	int pan = 5;
	if ((fp = fopen("gongzizong.txt", "r")) == NULL) 
	{
		printf("�Ҳ���ͳ�Ƽ�¼����������");
		exit(0);
	}
	printf("��ͳ�Ƶ�Ա������:\n");
	printf("����   �����ܺ�   ͳ�Ƶ��·�\n");
	char ch;
	ch = fgetc(fp);
	while (ch != EOF) {
		printf("%c", ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	printf("��ѡ�񷵻���һ��(����1)���˳�(����0)\n");
	scanf("%d", &pan);
	if (pan == 1)
		opcount();
	else
		exit(0);
}
//����Ա���ͳ�Ƶ�����
void writesort() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   �����ʿ�������д���ļ�   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     ��ʵ�����ʽ���д���ļ�   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n) 
	{
	case 1: 
	{
		aStaff one[1000];
		aStaff t;
		int n = getStruct(one);
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i + 1; j < n ; j++) {
				if (strcmp(one[i].cardID, one[j].cardID)>0) {
					t = one[j];
					one[j] = one[i];
					one[i] = t;
				}
			}
		}
		FILE* fp;
		if ((fp = fopen("kahaosort.txt", "w")) == NULL)
		{
			printf("�򲻿��ļ�\n");
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fp);
		printf("����д��ɹ�\n");
		printf("��ѡ�񷵻�ǰһ��(����1)���˳�����(����0)\n");
		int s = 0;
		scanf("%d", &s);
		if (s == 1)
			opsort();
		else if(s==0)
			exit(0);
		break;

	}
	case 2: {
		aStaff one[1000];
		aStaff t;
		int n = getStruct(one);
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++) {
				if (one[i].realWages<one[j].realWages) {
					t = one[j];
					one[j] = one[i];
					one[i] = t;
				}
			}
		}
		FILE* fp;
		if ((fp = fopen("gongzisort.txt", "w")) == NULL)
		{
			printf("�򲻿��ļ�\n");
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fp);
		printf("����д��ɹ�\n");
		printf("��ѡ�񷵻�ǰһ��(����1)���˳�����(����0)\n");
		int s = 0;
		scanf("%d", &s);
		if (s == 1)
			opsort();
		else if (s == 0)
			exit(0);
		break;
	}
	case 3:opsort(); break;
	case 4:exit(0); break;
	}
	exit(0);
}
//д������
void readsort() 
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   �����ʿ����������       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     ��ʵ�����ʽ������       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: {
		system("cls");
		aStaff one[1000];
		FILE* fp;
		int i = 0;
		if ((fp = fopen("kahaosort.txt", "r")) == NULL) {
			printf("�Ҳ����ļ�");
			exit(0);
		}
		while (fscanf(fp, "%s %s %s %d %f %f %f %f %f", one[i].name, one[i].staffID, one[i].cardID, &one[i].month, &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other, &one[i].realWages) != EOF) {
			i++;
		}
		fclose(fp);
		int s = i;
		printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "ְ����", "����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
		for (i = 0; i < s; i++)
			printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", one[i].name, one[i].staffID, one[i].cardID, one[i].wagesPayable, one[i].tax, one[i].tax, one[i].other, one[i].realWages, one[i].month);
		int pan = 0;
		printf("��ѡ�񷵻�ǰһ��(����1)���˳�(����0)\n");
		scanf("%d", &pan);
		if (pan == 1)
			opsort();
		else exit(0);
		break;
	}
	case 2: 
	{
		system("cls");
		aStaff one[1000];
		FILE* fp;
		int i = 0;
		if ((fp = fopen("gongzisort.txt", "r")) == NULL) {
			printf("�Ҳ����ļ�");
			exit(0);
		}
		while (fscanf(fp, "%s %s %s %d %f %f %f %f %f", one[i].name, one[i].staffID, one[i].cardID, &one[i].month, &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other, &one[i].realWages) != EOF) {
			i++;
		}
		fclose(fp);
		int s = i;
		printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "ְ����", "����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
		for (i = 0; i < s; i++)
			printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", one[i].name, one[i].staffID, one[i].cardID, one[i].wagesPayable, one[i].tax, one[i].tax, one[i].other, one[i].realWages, one[i].month);
		int pan = 0;
		printf("��ѡ�񷵻�ǰһ��(����1)���˳�(����0)\n");
		scanf("%d", &pan);
		if (pan == 1)
			opsort();
		else exit(0);
		break;
	}
	case 3: opsort(); break;
	case 4:exit(0); break;
	}
}
//�����д�������