#include"manage.h"
//�������ڵĲ˵�  2022.5.20

void dengluMenu() {
	FILE* fp;
	int password=0;
	fp=fopen("opmm.txt", "r+");
	fscanf(fp, "%d", &password);
	fclose(fp);
	int n;
	int s;

	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*               ��ѡ��������            *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*    ��1:����Ա              ��2:Ա��     *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*             �������������˳�            *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("���������Ա����\n");
		printf("���������������ѡ�����\n");
		scanf_s("%d", &s);
		if (s == password - 900)
		{
			printf("������ȷ\n");
			OPmenu();
		}
		else
		{
			denglumenu();
		}

	}
	else if (n == 2) {
		yuanMenu();
	}
	else
		exit(0);


}   
//��¼�˵�
void OPmenu() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*        ��1��     ������������           *\n");
	printf("\t\t*        ��2��     �����������           *\n");
	printf("\t\t*        ��3��     ���в�ѯ����           *\n");
	printf("\t\t*        ��4       ���������޸�           *\n");
	printf("\t\t*        ��5       �������ݴ���           *\n");
	printf("\t\t*        ��6       �����޸�����           *\n");
	printf("\t\t*        ��7       ������һ��             *\n");
	printf("\t\t*        ��8       �˳�ϵͳ               *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:system("cls"); inDate(yuangong); break;//����
	case 2:system("cls"); lookMenu(); break;//���
	case 3:system("cls"); chaxunmenu(); break;//��ѯ
	case 4:system("cls"); dcMenu(); break;//ɾ��
	case 5:system("cls");; processMenu();//���ݴ���
	case 6:system("cls");chOPmi(); break;//�޸�����
	case 7:denglumenu(); break;
	case 8:exit(0);  break;
	}
	
	OPmenu();
}
//����Ա�˵�
void lookMenu() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   �������������           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �������������           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
		
	switch (n)
	{
	case 1: nameRead(); break;
	case 2: kaRead(); break;
	case 3: OPmenu(); break;
	case 4: exit(0); break;
	}
	lookMenu();
}
//����Ա����˵�
void chaxunmenu() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   ��������ѯ����           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �����Ų�ѯ����           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: nameSeek(); break;
	case 2: kaSeek(); break;
	case 3: OPmenu(); break;
	case 4: exit(0); break;
	}

	chaxunmenu();
}
//����Ա��ѯ�˵�
void yuanMenu() 
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*        ��1��   ���в�ѯ����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     ���·�ͳ�������ŵĹ���   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3     ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4     �˳�ϵͳ                 *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:system("cls"); chaxunmenu1(); break;
	case 2:system("cls"); yuancount(); break;
	case 3:system("cls"); denglumenu(); break;
	case 4:exit(0); break;
	}
	yuanMenu();
}
//Ա���˵�
void chaxunmenu1() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   ��������ѯ����           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �����Ų�ѯ����           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: nameSeek1(); break;
	case 2: kaSeek1(); break;
	case 3: yuanMenu(); break;
	case 4: exit(0); break;
	}
	chaxunmenu1();
}
//Ա����ѯ�˵�
void dcMenu(){
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   �޸�ָ��Ա��������       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     ɾ��ָ��Ա��������       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: opchange(); break;
	case 2: opdelete(); break;
	case 3: OPmenu(); break;
	case 4: exit(0); break;
	}
}
//�����޸Ĳ˵�
void processMenu()
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  ��ѡ�����             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��1��   ͳ��Ա��ĳʱ�ι����ܺ�   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��2     �����ݽ�������           *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��3:    ������һ��               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        ��4:    �˳�����                 *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        �������������ٴ�����             *\n");
	printf("\t\t*******************************************\n");
	scanf_s("%d", &n);
	switch (n)
	{
	case 1: opcount(); break;
	case 2: opsort(); break;
	case 3: OPmenu(); break;
	case 4: exit(0); break;
	}
	processMenu();
}
//���ݴ���˵�