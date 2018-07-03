//
// Created by ma on 18-6-29.
//

#ifndef __SQLIST__H__
#define __SQLIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define True 1
#define False 0
#define OVERFLOW -2
#define INIT_SIE 2048
#define EXTRA_SIZE 2048
typedef int Status;

// 定义数据结构线性表
typedef struct{
	int* elem;
	int length;
	int list_size;
	}sqList;

//初始化线性表
// L为线性表
// 时间复杂度为O(1)
Status initList(sqList *L);

// 创建线性表
// L为线性表, e为元素值.
// 时间复杂度为O(1)
void appendList(sqList *L, int e);


// 插入元素, 在位置i之前.
// 位置为下标+1
// 时间复杂度为O(n)
Status insertElem(sqList *L, int i, int e);

// 删除元素
// i为下标+1
// 时间复杂度为O(n)
void deleteElem(sqList *L, int i);

// 打印整个列表, 带有空格便于在控制台调试
// L为线性表
// 时间复杂度为O(n)
void print(sqList L);

// 没有空格地打印
// L为线性表
// 时间复杂度为O(n)
void tightPrint(sqList L);

// 比较两个线性表表示的数的大小
// m, n为需要比较的两个线性表
// 时间复杂度为O(1)~O(n)
Status isMGreaterThanN(sqList m, sqList n);

// 比较两个列表是否完全相等
// L1, L2为需要比较的两个线性表
// 时间复杂度为O(1)~O(n)
Status isEqual(sqList L1, sqList L2);

// 交换两个线性表
// m, n为两个需要交换的线性表
// 时间复杂度为O(1)
void SwapSqList(sqList *m, sqList *n);

Status initList(sqList *L) {
    (*L).elem = (int*)malloc(INIT_SIE*sizeof(int));
    if (!(*L).elem) exit(OVERFLOW);
    (*L).length = 0;
    (*L).list_size = INIT_SIE;
    return True;
}

void appendList(sqList *L, int e) {
    (*L).elem[(*L).length++] = e;
}

void deleteElem(sqList *L, int i) {
    int j;
    for (j = i-1;j < (*L).length;j++)
        (*L).elem[j] = (*L).elem[j+1];
    (*L).length--;
}

Status insertElem(sqList *L, int i, int e) {
    // 两种异常的处理
    if (i<1||i>(*L).length + 1){return False;}
    if ((*L).length>=(*L).list_size){
        int* newbase = (int*)realloc((*L).elem,
                                     ((*L).list_size + EXTRA_SIZE)*sizeof(int));
        (*L).elem = newbase;
        (*L).list_size += EXTRA_SIZE;
    }
    //为新元素腾出空间
    (*L).length ++;
    // 为新元素挪位置
    int j;
    for (j = (*L).length;j >= i;j--) (*L).elem[j] = (*L).elem[j-1];
    (*L).elem[i-1] = e;
    return True;
}

void print(sqList L) {
    int i;
    for (i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
    printf("\n");
}

void tightPrint(sqList L) {
    int i;
    for (i=0; i < L.length; i ++)
        printf("%d", L.elem[i]);
}


Status isMGreaterThanN(sqList m, sqList n) {
    int i;
    if (m.length > n.length)
        return True;
    else if (m.length < n.length)
        return False;
    else
        for(i=0; i<m.length; i++)
            if (m.elem[i] > n.elem[i])
                return True;
            else if (m.elem[i] == n.elem[i])
                continue;
            else
                return False;
}

Status isEqual(sqList L1, sqList L2) {
    if (L1.length != L2.length) return False;
    else{
        int iterRound = L1.length;
        int i;
        for(i=0; i < iterRound; i ++){
            if (L1.elem[i] != L2.elem[i])
                return False;
        }
        return True;
    }
}

void SwapSqList(sqList *m, sqList *n) {
    sqList temp;
    initList(&temp);
    temp = *m;
    *m = *n;
    *n = temp;
}

#endif
