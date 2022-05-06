#include"manage.h"
//主函数  2022.5.20
int main() {
	system("cls");
	int password = 777;
	FILE* fp;
	int read = 0;
	
	fp=fopen("opmm.txt", "a+");
	if (fscanf(fp, "%d", &read) == EOF) {
		fprintf(fp, "%d\t", password+900);
	}
	fclose(fp);

	printf("\n\n\n\n\n");
	printf("\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*               工资信息管理系统          *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                        按任意键进入…… *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	_getche();
	dengluMenu(); 
	
	return 0;
}

