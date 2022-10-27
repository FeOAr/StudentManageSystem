/*************************************************************************
		> File Name: function.c
		> Author: FeOAr
		> Mail: esnasc@163.com
		> Created Time: 2022年10月22日 星期六 19时14分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Function.h"
#include <string.h>

void manue()
{
	printf("================================\n");
	printf("\t学生成绩管理系统\n\n");
	printf("\t1.增加学生信息\n");
	printf("\t2.删除学生信息\n");
	printf("\t3.修改学生信息\n");
	printf("\t4.搜索学生信息\n");
	printf("\t5.显示学生信息\n");
	printf("\t6.更新存储文件\n");
	printf("\t7.载入文件数据\n");
	printf("\t输入任意键退出\n");
	printf("================================\n");
}

/*结构体输出*/
void PrintInfo(PSTU Pnow)
{
	printf("------------------------------------------\n");
	printf("姓名： %s", Pnow->name);
	printf("\t年龄:%hd", Pnow->age);
	printf("\t生日:%d-%d-%d\n", Pnow->birth.year, Pnow->birth.month, Pnow->birth.day);
	printf("------------------------------------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("课程：%s\t平时成绩：%d\t最终成绩：%d\n", Pnow->lesson[i].calssName, Pnow->lesson[i].generalScore, Pnow->lesson[i].finalScore);
	}
}

/*结构体输入*/
void InputInfo(PSTU Pnew)
{
	printf("请输入姓名：");
	scanf("%s", Pnew->name);
	printf("请输入年龄：");
	scanf("%hd", &Pnew->age);
	printf("请输入生日：");
	scanf("%d%d%d", &Pnew->birth.year, &Pnew->birth.month, &Pnew->birth.day);
	printf("请输入课程信息\n");
	for (int i = 0; i < 3; i++)
	{
		printf("请输入课程%d名称，平时成绩，最终成绩\n", i + 1);
		scanf("%s%d%d", Pnew->lesson[i].calssName, &Pnew->lesson[i].generalScore, &Pnew->lesson[i].finalScore);
	}
}

/*增加学生信息*/
void addStudent(PSTU SHead)
{
	/*创建尾指针*/
	PSTU Pend = SHead;
	while (Pend->pnext != NULL)
	{
		Pend = Pend->pnext;
	}

	/*新增节点*/
	PSTU Pnew = NULL;
	Pnew = (PSTU)malloc(sizeof(STU)); //
	if (Pnew == NULL)
	{
		printf("分配失败\n");
		exit(1);
	}

	/*添加新节点数据*/
	printf("请补充信息\n");
	InputInfo(Pnew);
	/*将新节点加入链表*/
	Pend->pnext = Pnew;
	Pend = Pnew;
	length_stu++;
	printf("Add-Done!\t 已统计%d位", length_stu);
	getchar();
	getchar();
}

/*删除学生信息*/
void deleteStudent(PSTU SHead)
{
	PSTU Pnow = SHead;		 //查找指针，逐个遍历
	PSTU Pnow_front = SHead; // Pnow的前驱节点
	char name[10];
	char choice;
	printf("输入要删除学生的姓名：");
	scanf("%s", name);
	while (Pnow->pnext != NULL)
	{
		Pnow = Pnow->pnext;
		if (!strcmp(name, Pnow->name))
		{
			printf("找到目标信息：\n");
			PrintInfo(Pnow);
		}
	}
	printf("是否删除？ (Y/y|N/n):\t");
	getchar(); //过滤掉输入时的换行符
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		while (strcmp(Pnow_front->pnext->name, Pnow->name))
		{
			if (Pnow_front->pnext == NULL)
				exit(1);
			Pnow_front = Pnow_front->pnext; //找到目标前驱节点
		}
		if (Pnow->pnext != NULL) //不是最后一个
		{
			Pnow_front->pnext = Pnow->pnext;
			printf("free(Pnow)\n");
			free(Pnow);
			printf("已删除\n");
		}
		else
		{
			Pnow_front->pnext = NULL;
			free(Pnow); //最后一个节点
			printf("已删除\n");
		}
		length_stu--;
	}
	else if (choice == 'n' || choice == 'N')
		printf("已取消\n");
	getchar();
	getchar();
}

/*编辑学生信息*/
void modifyInfo(PSTU SHead)
{
	PSTU Pnow = SHead; //查找指针，逐个遍历
	char name[10];
	int age = 0;
	int choice = 0;

	printf("输入要查找学生的姓名：");
	scanf("%s", name);
	while (Pnow->pnext != NULL)
	{
		Pnow = Pnow->pnext; //头节点不存数据，先后移一位
		if (!strcmp(name, Pnow->name))
		{
			printf("请更新信息：\n");
			InputInfo(Pnow);
			printf("变更完成！\n");
			break;
		}
	}
	getchar();
	getchar();
}

/*搜索学生信息*/
void searchStudent(PSTU SHead)
{
	PSTU Pnow = SHead; //查找指针，逐个遍历
	char name[10];
	int age = 0;
	int choice = 0;

	printf("选择查找方式: 1.姓名 2.年龄\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("输入要查找学生的姓名：");
		scanf("%s", name);
		while (Pnow->pnext != NULL)
		{
			Pnow = Pnow->pnext; //头节点不存数据，先后移一位
			if (!strcmp(name, Pnow->name))
				PrintInfo(Pnow);
		}
		break;
	case 2:
		printf("输入要查找学生的年龄：");
		scanf("%d", &age);
		while (Pnow->pnext != NULL)
		{
			Pnow = Pnow->pnext; //头节点不存数据，先后移一位
			if (age == Pnow->age)
				PrintInfo(Pnow);
		}
		break;
	default:
		printf("非法输入\n");
		break;
	}
	getchar();
	getchar();
}

/*输出所有信息*/
void showAllinfo(PSTU SHead)
{
	PSTU Pnow = SHead;
	while (Pnow->pnext != NULL)
	{
		Pnow = Pnow->pnext; //头节点不存数据，先后移一位
		PrintInfo(Pnow);
	}
	getchar();
	getchar();
}

/*更新信息到存储文件*/
void updateFile(PSTU SHead)
{
	FILE *fp;
	PSTU Pnow = SHead;
	char choice;
	printf("是否（写入）数据？ (Y/y|N/n):\t");
	getchar(); //过滤掉输入时的换行符
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		if ((fp = fopen("StuInfo", "w")) == NULL)
		{
			printf("打开失败\n");
			exit(1);
		}
		while (Pnow->pnext != NULL)
		{
			Pnow = Pnow->pnext;
			fwrite(Pnow, sizeof(STU), 1, fp);
		}
		fclose(fp);
		printf("Done!\n");
	}
	getchar();
	getchar();
}

/*从本地存储文件更新数据*/
void loadDate(PSTU SHead)
{
	FILE *fp;
	char tempName[10];
	char choice;
	PSTU Pnew_1 = (PSTU)malloc(sizeof(STU));
	PSTU Pnew_2 = NULL;
	printf("是否（载入）数据？ (Y/y|N/n):\t");
	getchar(); //过滤掉输入时的换行符
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		if ((fp = fopen("StuInfo", "r")) == NULL)
		{
			printf("打开失败\n");
			exit(1);
		}

		while (!feof(fp))
		{
			fread(Pnew_1, sizeof(STU), 1, fp);
			if (!strcmp(Pnew_1->name, tempName))
			{
				free(Pnew_1);
				break;
			}
			strcpy(tempName, Pnew_1->name);

			/*复制到要插入的节点*/
			Pnew_2 = (PSTU)malloc(sizeof(STU));
			if (Pnew_2 == NULL)
			{
				printf("分配失败\n");
				exit(1);
			}
			if (SHead->pnext != NULL)
				Pnew_2->pnext = SHead->pnext;
			SHead->pnext = Pnew_2; //头插法
			Pnew_2->age = Pnew_1->age;
			Pnew_2->birth = Pnew_1->birth;
			strcpy(Pnew_2->name, Pnew_1->name);
			for (int i = 0; i < 3; i++)
			{
				Pnew_2->lesson[i] = Pnew_1->lesson[i];
			}
		}
		fclose(fp);
		printf("导入数据完成！\n");
		getchar();
		getchar();
	}
}