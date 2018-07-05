//
// Created by ma on 18-6-29.
//

#ifndef _UTIL_H_
#define _UTIL_H_

#include "sqList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 编写一个函数将字符串转为线性表
// s为需要转换的字符串
// 逐位转换, 时间复杂度为O(n)
sqList ConvertCharArrayToSqList(char* s);

// 编写一个函数判断一个大整数是否为奇数
// L为需要判断的线性表, 只需要访问最后一位即可判断
// 在我的GCD算法中每一次迭代都需要判断奇偶, 使用线性
// 表可以方便地访问最后一位元素,进行判断.
int greatIsUneven(sqList L);

// 编写函数返回读取的字符串
char* readFromFile(char* filename);

// 格式化输出结果
void generateResult(sqList result, int steps, double cost);

sqList ConvertCharArrayToSqList(char *s) {
    sqList result;
    initList(&result);
    int len = strlen(s);
    // 正序转换, result中的顺序和s一样
    int i;
    for (i=0; i < len; i ++) appendList(&result, s[i] - '0');
    return result;
}

int greatIsUneven(sqList L) {
    return L.elem[L.length-1]%2;
}

char* readFromFile(char* filename){
    FILE*fp=fopen(filename, "r");//打开文件

    char*line = (char*)calloc(1, sizeof(char));

    char c;
    int len = 0;
    if(fp == NULL)//判断是否成功打开文件
    {
        printf("Can't open file!");
        exit(1);
    }
    while ( (c = fgetc(fp) ) != EOF && c != '\n')//直到遇到换行符或者文件结束停止
    {
        line = (char*) realloc(line, sizeof(char) * (len + 2) );//改变line的内存空间
        line[len++] = c;
        line[len] = '\0';
    }
    fclose(fp);//关闭文件
    return line;
}

void generateResult(sqList result, int steps, double cost){
    printf("After %d steps, the result is ", steps);
    tightPrint(result);
    printf(". Time consuming: %lf seconds.\n", cost);
    printf("And the result has been written into file \"out.txt\".\n");
    FILE* fp = fopen("../out.txt", "a+");
    fprintf(fp, "%s", "After ");
    fprintf(fp, "%d", steps);
    fprintf(fp, "%s", " steps, the result is: ");
    int i;
    for(i=0; i<result.length; i++)
        fprintf(fp, "%d", result.elem[i]);
    fprintf(fp, "%s", ". Time consuming: ");
    fprintf(fp, "%lf", cost);
    fprintf(fp, "%s", " seconds.\n");
    fclose(fp);
}

#endif //PROJECT_UTIL_H
