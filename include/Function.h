/*************************************************************************
		> File Name: Function.h
		> Author: FeOAr
		> Mail: esnasc@163.com
		> Created Time: 2022年10月22日 星期六 19时15分19秒
 ************************************************************************/

#ifndef _FUNCTION_H
#define _FUNCTION_H
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
	int year;
	int month;
	int day;
} DATE;

typedef struct Lesson
{
	char calssName[20];
	int generalScore;
	int finalScore;
}LES,*PLES;//差异化课程

typedef struct Student
{
	char name[10];
	short int age;
	DATE birth;
	LES lesson[3];
	struct Student *pnext;
} STU, *PSTU;

extern void manue();
extern void addStudent(PSTU);
extern void deleteStudent(PSTU);
extern void modifyInfo(PSTU);
extern void searchStudent(PSTU);
extern void showAllinfo(PSTU);
extern void updateFile(PSTU);
extern void loadDate(PSTU);
extern int length_stu;  //统计当前链表长度