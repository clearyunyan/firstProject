#define _CRT_SECURE_NO_WARNINGS
#include"manage.h"
//���벢�����ݴ����ļ���  2022.5.20

void inDate(aStaff* p) {
	int s = 0;
	int n = 0;	//�ж�
	int d;		//ѡ��
	printf("����-1����,��������������ʼ��¼");
	scanf_s("%d", &n);

	for (int  i = 0; n!=-1 ; i++)
	{
		printf("����������\n");
		scanf("%s",p[i].name);
		printf("������ְ����\n");
		scanf("%s", p[i].staffID);
		printf("���������п���\n");
		scanf("%s", p[i].cardID);
		printf("������Ӧ������\n");
		scanf_s("%f", &p[i].wagesPayable);
		printf("������ˮ���\n");
		scanf_s("%f", &p[i].waterElectricity);
		printf("������˰��\n");
		scanf_s("%f", &p[i].tax);
		printf("����������۳����\n");
		scanf_s("%f", &p[i].other);
		printf("�����뷢�ŵ��·�\n");
		scanf_s("%d", &p[i].month);
		p[i].realWages = p[i].wagesPayable - p[i].waterElectricity - p[i].tax - p[i].other;
		printf("%s��ʵ������Ϊ%lf\n",p[i].name, p[i].realWages);
		printf("����-1��������,����������������\n");
		scanf_s("%d", &n);
		system("cls");
		s++;
	}
	save(yuangong, s);
	printf("������һ��(����1)�����˳�(����0)");
	scanf("%d", &d);
	if (d == 1)
		OPmenu();
	else
		exit(0);
}
//��������

void save(aStaff *p, int n)
{
	FILE* fp;
	int count = 0;
	if ((fp = fopen("yuangong.txt","a"))==NULL)
	{
		printf("�򲻿��ļ�\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(fp,"%s %s %s %d %f %f %f %f %f\n",p[i].name,p[i].staffID,p[i].cardID,p[i].month,p[i].wagesPayable,p[i].waterElectricity,p[i].tax,p[i].other,p[i].realWages);
		count++;
	}
	fclose(fp);
}
//�����ļ�

void chOPmi() {
	system("cls");
	FILE* fp;
	int newps;
	fp = fopen("opmm.txt", "w");
	printf("������Ҫ�޸�����");
	scanf_s("%d", &newps);
	newps = newps+900;
	fprintf(fp, "%d\t", newps);
	fclose(fp);
	printf("��ѡ�񷵻���һ��(����1)�����˳�(����0)\n");
	int n;
	scanf_s("%d", &n);
	if (n == 1)
		OPmenu();
	else
		exit(0);

}
//�޸�����
