#include"manage.h"
//实现数据处理功能的函数   2022.5.20

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
		printf("请输入您的姓名\n");
		scanf("%s", name);
		printf("输入-1以外的数开始记录您要统计的月份");
		scanf_s("%d", &b);
		for (i = 0; b != -1; i++)
		{
			printf("请输入要统计的月份\n");
			scanf("%d", &month[i]);
			printf("输入-1结束,输入其他数继续计入月份");
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
		printf("您这几个月的工资总和为%.2f(为0可能是未找到您的信息,可能姓名错误)\n", s);
		printf("请选择重新统计(输入1)或返回上一级(输入0)\n");
		scanf("%d", &pan);
	}
		yuanMenu();

}
//员工统计数据
void opchange()
{
	system("cls");
	FILE* fin;
	int a = 1;		//循环条件
	int n = 0;		//员工人数
	char na[20];
	aStaff one[1000];

	
	while (a == 1) {
		n = getStruct(one);
		int s = 0;
		int c = 0;
		system("cls");
		printf("请输入您要修改的数据的员工的名字,月份\n");\
		scanf("%s", na);
		scanf("%d", &c);
		fin = fopen("yuangong.txt", "w");

		for (int i = 0; i < n; i++)
		{
			if (strcmp(na, one[i].name) == 0&&c==one[i].month) {
				printf("请输入他的新的银行卡号,职工号\n");
				scanf("%s%s", one[i].cardID, one[i].staffID);
				printf("请输入他的新应发工资,水电,税金,杂项扣款(请每输入一个数按一次回车)\n");
				scanf("%f%f%f%f", &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other);
				one[i].realWages = one[i].wagesPayable - one[i].tax - one[i].waterElectricity - one[i].other;
				printf("他的新实发工资为%f", one[i].realWages);
				s++;
			}
			fprintf(fin, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fin);
		if (s != 0)printf("修改成功\n");
		else printf("未找到要修改的对象");
		printf("请选择继续修改(输入1)或返回上一级输入(0)");
		scanf("%d", &a);
	}
	dcMenu();
}
//管理员修改数据
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
		printf("请输入您要删除的数据的员工的名字和月份\n");
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
		if (s != 0)printf("删除成功\n");
		else printf("未找到要删除的对象");
		printf("请选择继续删除(输入1)或返回上一级(输入0)\n");
		scanf("%d", &a);
	}
	dcMenu();
}
//管理员删除数据
void opcount()
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  请选择操作             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按1：   统计员工并写入文件       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按2     按姓名浏览已写入的文件   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按3:    返回上一级               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按4:    退出程序                 *\n");
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
			printf("请输入该员工的姓名\n");
			scanf("%s", na);
			printf("输入-1以外的数开始记录您要统计的月份");
			scanf_s("%d", &b);
			for (i = 0; b != -1; i++)
			{
				printf("请输入要统计的月份\n");
				scanf("%d", &a[i]);
				printf("输入-1结束,输入其他数继续计入月份");
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
			printf("该员工这几个月的工资总和为%.2f(为0可能是未找到该员工的信息,可能是姓名错误)\n", s);
			fprintf(fp,"%s ",na);
			fprintf(fp, "%.2f\t ", s);
			for(int i=0;i<c;i++)
			fprintf(fp, "%d ",a[i]);
			char ch = '\n';
			fputc(ch, fp);
			
			printf("请选择继续统计(输入1)或返回上一级(输入0)\n");
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
//管理员统计数据
void opsort()
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  请选择操作             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按1：   进行排序并写入文件       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按2     浏览已写入的文件         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按3:    返回上一级               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按4:    退出程序                 *\n");
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
//管理员处理数据
void countliulan() 
{
	FILE* fp;
	int pan = 5;
	if ((fp = fopen("gongzizong.txt", "r")) == NULL) 
	{
		printf("找不到统计记录请重启程序");
		exit(0);
	}
	printf("所统计的员工如下:\n");
	printf("姓名   工资总和   统计的月份\n");
	char ch;
	ch = fgetc(fp);
	while (ch != EOF) {
		printf("%c", ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	printf("请选择返回上一级(输入1)或退出(输入0)\n");
	scanf("%d", &pan);
	if (pan == 1)
		opcount();
	else
		exit(0);
}
//管理员浏览统计的数据
void writesort() {
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  请选择操作             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按1：   按工资卡号升序写入文件   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按2     按实发工资降序写入文件   *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按3:    返回上一级               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按4:    退出程序                 *\n");
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
			printf("打不开文件\n");
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fp);
		printf("排序并写入成功\n");
		printf("请选择返回前一级(输入1)或退出程序(输入0)\n");
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
			printf("打不开文件\n");
			exit(0);
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "%s %s %s %d %f %f %f %f %f\n", one[i].name, one[i].staffID, one[i].cardID, one[i].month, one[i].wagesPayable, one[i].waterElectricity, one[i].tax, one[i].other, one[i].realWages);
		}
		fclose(fp);
		printf("排序并写入成功\n");
		printf("请选择返回前一级(输入1)或退出程序(输入0)\n");
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
//写入数据
void readsort() 
{
	int n;
	system("cls");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                  请选择操作             *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按1：   按工资卡号升序浏览       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按2     按实发工资降序浏览       *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按3:    返回上一级               *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*        按4:    退出程序                 *\n");
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
			printf("找不到文件");
			exit(0);
		}
		while (fscanf(fp, "%s %s %s %d %f %f %f %f %f", one[i].name, one[i].staffID, one[i].cardID, &one[i].month, &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other, &one[i].realWages) != EOF) {
			i++;
		}
		fclose(fp);
		int s = i;
		printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "姓名", "职工号", "卡号", "应发工资", "水电费", "税金", "杂项扣款", "实发工资", "发放月份");
		for (i = 0; i < s; i++)
			printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", one[i].name, one[i].staffID, one[i].cardID, one[i].wagesPayable, one[i].tax, one[i].tax, one[i].other, one[i].realWages, one[i].month);
		int pan = 0;
		printf("请选择返回前一级(输入1)或退出(输入0)\n");
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
			printf("找不到文件");
			exit(0);
		}
		while (fscanf(fp, "%s %s %s %d %f %f %f %f %f", one[i].name, one[i].staffID, one[i].cardID, &one[i].month, &one[i].wagesPayable, &one[i].waterElectricity, &one[i].tax, &one[i].other, &one[i].realWages) != EOF) {
			i++;
		}
		fclose(fp);
		int s = i;
		printf("%-16s%-12s%-12s%-12s%-12s%-12s%-12s%-12s%-12s\n", "姓名", "职工号", "卡号", "应发工资", "水电费", "税金", "杂项扣款", "实发工资", "发放月份");
		for (i = 0; i < s; i++)
			printf("%-16s%-12s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12d\n", one[i].name, one[i].staffID, one[i].cardID, one[i].wagesPayable, one[i].tax, one[i].tax, one[i].other, one[i].realWages, one[i].month);
		int pan = 0;
		printf("请选择返回前一级(输入1)或退出(输入0)\n");
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
//浏览已写入的数据