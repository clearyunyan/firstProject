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
void inDate(aStaff* p);     //读取数据
void save(aStaff* p, int n);//将数据存入文件
void dengluMenu();       //起始菜单
void OPmenu();           //管理员登录菜单
void chOPmi();			 //修改管理员密码
int getStruct(aStaff *p);//读取人员文件,参数为接受数据的结构体数组,返回人数
void nameRead();         //按姓名浏览
void kaRead();           //按卡号浏览
void lookMenu();         //浏览菜单
void chaxunmenu1();      //员工查询菜单
void nameSeek();         //管理员按名字查询
void chaxunmenu();       //管理员查询菜单
void kaSeek();           //管理员按卡号查询
void yuanMenu();         //员工菜单
void yuancount();        //员工统计数据
void kaSeek1();          //员工按卡号查找
void nameSeek1();        //员工按名字查找
void dcMenu();           //修改数据菜单
void opchange();         //管理员更改数据
void opdelete();         //管理员删除数据
void processMenu();      //数据处理菜单
void opcount();          //管理员统计
void countliulan();      //对统计进行浏览
void opsort();           //管理员数据处理
void writesort();        //处理数据写入文件
void readsort();         //浏览处理后的文件
#endif