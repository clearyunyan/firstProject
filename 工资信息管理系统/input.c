#define _CRT_SECURE_NO_WARNINGS
#include"manage.h"
//输入并将数据存入文件中  2022.5.20

void inDate(aStaff* p) {
	int s = 0;
	int n = 0;	//判断
	int d;		//选择
	printf("输入-1结束,输入其他的数开始记录");
	scanf_s("%d", &n);

	for (int  i = 0; n!=-1 ; i++)
	{
		printf("请输入姓名\n");
		scanf("%s",p[i].name);
		printf("请输入职工号\n");
		scanf("%s", p[i].staffID);
		printf("请输入银行卡号\n");
		scanf("%s", p[i].cardID);
		printf("请输入应发工资\n");
		scanf_s("%f", &p[i].wagesPayable);
		printf("请输入水电费\n");
		scanf_s("%f", &p[i].waterElectricity);
		printf("请输入税金\n");
		scanf_s("%f", &p[i].tax);
		printf("请输入杂项扣除金额\n");
		scanf_s("%f", &p[i].other);
		printf("请输入发放的月份\n");
		scanf_s("%d", &p[i].month);
		p[i].realWages = p[i].wagesPayable - p[i].waterElectricity - p[i].tax - p[i].other;
		printf("%s的实发工资为%lf\n",p[i].name, p[i].realWages);
		printf("输入-1结束输入,输入其他继续输入\n");
		scanf_s("%d", &n);
		system("cls");
		s++;
	}
	save(yuangong, s);
	printf("返回上一级(输入1)或者退出(输入0)");
	scanf("%d", &d);
	if (d == 1)
		OPmenu();
	else
		exit(0);
}
//输入数据

void save(aStaff *p, int n)
{
	FILE* fp;
	int count = 0;
	if ((fp = fopen("yuangong.txt","a"))==NULL)
	{
		printf("打不开文件\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(fp,"%s %s %s %d %f %f %f %f %f\n",p[i].name,p[i].staffID,p[i].cardID,p[i].month,p[i].wagesPayable,p[i].waterElectricity,p[i].tax,p[i].other,p[i].realWages);
		count++;
	}
	fclose(fp);
}
//存入文件

void chOPmi() {
	system("cls");
	FILE* fp;
	int newps;
	fp = fopen("opmm.txt", "w");
	printf("请输入要修改密码");
	scanf_s("%d", &newps);
	newps = newps+900;
	fprintf(fp, "%d\t", newps);
	fclose(fp);
	printf("请选择返回上一级(输入1)或者退出(输入0)\n");
	int n;
	scanf_s("%d", &n);
	if (n == 1)
		OPmenu();
	else
		exit(0);

}
//修改密码
