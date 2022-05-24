#include"manage.h"
//��ȡ�Ͳ�ѯ���ܵĺ���  2022.5.20
int getStruct(aStaff* p) {
	FILE* fp;
	int i=0;

	if ((fp = fopen("yuangong.txt", "r")) == NULL) {
		printf("�Ҳ����ļ�");
			exit(0);
	}
	while (fscanf(fp, "%s %s %s %d %f %f %f %f %f", p[i].name, p[i].staffID, p[i].cardID,&p[i].month,&p[i].wagesPayable,&p[i].waterElectricity,&p[i].tax,&p[i].other,&p[i].realWages) != EOF) {
		i++;
	}
	fclose(fp);
	return i;
}
//��ȡ�ļ�������ṹ��
void nameRead()
{
	int i=0,n;
	aStaff t;

	system("cls");
	printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "ְ����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
	n = getStruct(du);
	for (i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (strcmp(du[i].name, du[j].name) > 0) {
				t = du[i];
				du[i] = du[j];
				du[j] = t;
			}
		}

	}

	for (i = 0; i < n; i++)
		printf("%-16s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", du[i].name, du[i].staffID, du[i].wagesPayable, du[i].tax, du[i].tax, du[i].other, du[i].realWages, du[i].month);
	printf("��ѡ�񷵻���һ��(����1)�����˳�(����0)\n");
	int s=0;
	scanf_s("%d", &s);
	if (s == 1)
		lookMenu();
	else
		exit(0);

}
//���������
void kaRead() 
{
	
		int i = 0, n;
		aStaff t;

		system("cls");
		printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����","ְ����","Ӧ������","ˮ���","˰��","����ۿ�","ʵ������","�����·�");
		n = getStruct(du);
		for (i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++) {
				if (strcmp(du[i].cardID, du[j].cardID) > 0) {
					t = du[i];
					du[i] = du[j];
					du[j] = t;
				}
			}

		}
		for (i = 0; i < n; i++)
		printf("%-16s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", du[i].cardID, du[i].staffID, du[i].wagesPayable, du[i].tax, du[i].tax, du[i].other, du[i].realWages, du[i].month);
		printf("��ѡ�񷵻���һ��(����1)�����˳�(����0)\n");
		int s = 0;
		scanf_s("%d", &s);
		if (s == 1)
			lookMenu();
		else
			exit(0);
}
//���������
void nameSeek() {
	char str[20];
	aStaff linshidu[1000];
	int n = 0;
	int a = 1;

	system("cls");
	while (a == 1) {
		system("cls");
		printf("��������Ҫ��ѯ��Ա��������\n");
		scanf("%s", str);
		int c = 0;
		n = getStruct(linshidu);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(str, linshidu[i].name) == 0)
			{
				if (c == 0)printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "����", "ְ����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
				printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", linshidu[i].name, linshidu[i].cardID, linshidu[i].staffID, linshidu[i].wagesPayable, linshidu[i].tax, linshidu[i].tax, linshidu[i].other, linshidu[i].realWages, linshidu[i].month);
				c++;
			}

		}
		if (c == 0)printf("�ܱ�Ǹ,û���ҵ��й���Ҫ��ѯ����Ϣ\n");
		printf("��ѡ�������ѯ(����1)�򷵻���һ��(����0)\n");
		scanf_s("%d", &a);
	}
		chaxunmenu();
	
}
//����Ա��������ѯ
void nameSeek1() {
	system("cls");
	char str[20];
	aStaff linshidu[1000];
	int n = 0;
	int a = 1;

	while (a == 1) {
		system("cls");
		printf("��������Ҫ��ѯ��Ա��������\n");
		scanf("%s", str);
		int c = 0;
		n = getStruct(linshidu);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(str, linshidu[i].name) == 0)
			{
				if (c == 0)printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "����", "ְ����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
				printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", linshidu[i].name, linshidu[i].cardID, linshidu[i].staffID, linshidu[i].wagesPayable, linshidu[i].tax, linshidu[i].tax, linshidu[i].other, linshidu[i].realWages, linshidu[i].month);
				c++;
			}

		}
		if (c == 0)printf("�ܱ�Ǹ,û���ҵ��й���Ҫ��ѯ����Ϣ\n");
		printf("��ѡ�������ѯ(����1)�򷵻���һ��(����0)\n");
		scanf_s("%d", &a);
	}
	chaxunmenu1();

}
//Ա����������ѯ
void kaSeek() {
	char str[20];
	aStaff linshidu[1000];
	int n = 0;
	int c = 0;int a=1;

	system("cls");
	while (a == 1) {
		system("cls");
		printf("��������Ҫ��ѯ��Ա���Ŀ���\n");
		scanf("%s", str);
		n = getStruct(linshidu);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(str, linshidu[i].cardID) == 0)
			{
				if (c == 0)printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "����", "ְ����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
				printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", linshidu[i].name, linshidu[i].cardID, linshidu[i].staffID, linshidu[i].wagesPayable, linshidu[i].tax, linshidu[i].tax, linshidu[i].other, linshidu[i].realWages, linshidu[i].month);
				c++;
			}

		}
		if (c == 0)printf("�ܱ�Ǹ,û���ҵ��й���Ҫ��ѯ����Ϣ\n");
		printf("��ѡ�������ѯ(����1)�򷵻���һ��(����0)\n");
		scanf_s("%d", &a);
	}
		chaxunmenu();
}
//����Ա�����Ų�ѯ
void kaSeek1() {
	char str[20];
	aStaff linshidu[1000];
	int n = 0;
	int c = 0; int a = 1;

	system("cls");
	while (a == 1) {
		system("cls");
		printf("��������Ҫ��ѯ��Ա���Ŀ���\n");
		scanf("%s", str);
		n = getStruct(linshidu);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(str, linshidu[i].cardID) == 0)
			{
				if (c == 0)printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "����", "����", "ְ����", "Ӧ������", "ˮ���", "˰��", "����ۿ�", "ʵ������", "�����·�");
				printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", linshidu[i].name, linshidu[i].cardID, linshidu[i].staffID, linshidu[i].wagesPayable, linshidu[i].tax, linshidu[i].tax, linshidu[i].other, linshidu[i].realWages, linshidu[i].month);
				c++;
			}

		}
		if (c == 0)printf("�ܱ�Ǹ,û���ҵ��й���Ҫ��ѯ����Ϣ\n");
		printf("��ѡ�������ѯ(����1)�򷵻���һ��(����0)\n");
		scanf_s("%d", &a);
	}
	chaxunmenu1();
}
//Ա�������Ų�ѯ