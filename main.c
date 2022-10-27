#include <stdio.h>
#include <stdlib.h>
#include "Function.h" 

int length_stu = 0; //链表长度

int main(void)
{
	int choice;
	PSTU StuHead = NULL; //头节点
	StuHead = (PSTU)malloc(sizeof(STU));
	if (StuHead == NULL)
	{
		printf("头节点分配失败!\n");
		exit(1);
	}
	StuHead->pnext = NULL;
	while (1)
	{
		system("clear");
		manue();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			addStudent(StuHead);
			break;
		case 2:
			deleteStudent(StuHead);
			break;
		case 3:
			modifyInfo(StuHead);
			break;
		case 4:
			searchStudent(StuHead);
			break;
		case 5:
			showAllinfo(StuHead);
			break;
		case 6:
			updateFile(StuHead);
			break;
		case 7:
			loadDate(StuHead);
			break;
		default:
			printf("\nEXIT\n");
			exit(1);
		}
		// system("clear");
	}
}
