#include"manage.h"
//������  2022.5.20
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
	printf("\t\t*               ������Ϣ����ϵͳ          *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                        ����������롭�� *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*******************************************\n");
	_getche();
	dengluMenu(); 
	
	return 0;
}

