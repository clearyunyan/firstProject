#ifndef MANAGE_H
#define MANAGE_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
typedef struct staff {
	char name[20];
	char staffID[20];
	char cardID[20];
	int month;
	float wagesPayable;
	float waterElectricity;
	float tax;
	float other;
	float realWages;

}aStaff;
aStaff yuangong[1000],du[1000];
void inDate(aStaff* p);     //��ȡ����
void save(aStaff* p, int n);//�����ݴ����ļ�
void dengluMenu();       //��ʼ�˵�
void OPmenu();           //����Ա��¼�˵�
void chOPmi();			 //�޸Ĺ���Ա����
int getStruct(aStaff *p);//��ȡ��Ա�ļ�,����Ϊ�������ݵĽṹ������,��������
void nameRead();         //���������
void kaRead();           //���������
void lookMenu();         //����˵�
void chaxunmenu1();      //Ա����ѯ�˵�
void nameSeek();         //����Ա�����ֲ�ѯ
void chaxunmenu();       //����Ա��ѯ�˵�
void kaSeek();           //����Ա�����Ų�ѯ
void yuanMenu();         //Ա���˵�
void yuancount();        //Ա��ͳ������
void kaSeek1();          //Ա�������Ų���
void nameSeek1();        //Ա�������ֲ���
void dcMenu();           //�޸����ݲ˵�
void opchange();         //����Ա��������
void opdelete();         //����Աɾ������
void processMenu();      //���ݴ���˵�
void opcount();          //����Աͳ��
void countliulan();      //��ͳ�ƽ������
void opsort();           //����Ա���ݴ���
void writesort();        //��������д���ļ�
void readsort();         //����������ļ�
#endif