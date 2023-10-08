#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>



//加
void MyPlus(char* p, int* n, int len, int i);

//减
void MySub(char* p, int* n, int len, int i);

//乘
void MyMul(char* p, int* n, int len, int i);

//除
int MyDiv(char* p, int* n, int len, int i);

//括号
int MyPare(char* p, int* n,int len, int i);