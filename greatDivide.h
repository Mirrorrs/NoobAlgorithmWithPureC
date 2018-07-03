//
// Created by ma on 18-6-29.
//

#ifndef _GREATDIVIDE_H__
#define _GREATDIVIDE_H__

#include "sqList.h"

// 大整数除以int,这个函数的除数默认是2
// L为待减半的线性表
// 逐位减半, 时间复杂度为O(n)
sqList greatDivide(sqList L);

sqList greatDivide(sqList L) {
    int i;
    int temp = 0;
    sqList result;
    initList(&result);
    // 先将用于表示结果的线性表用0填满, 该操作的复杂度为O(n)
    for(i=0; i<L.length; i++) appendList(&result, 0);
    int len = L.length;
    // 不管该位的被除数是否小于2, 一律先整除得到结果加到下一位,
    // 取余数保存到该位.
    for(i=0; i<len; i++){
        result.elem[i] += L.elem[i] / 2;
        result.elem[i+1] = L.elem[i]%2*10 / 2;
    }
    // 因为是减半所以至多只会在最高位有一个0,若有删除即可.
    if(result.elem[0]==0) deleteElem(&result, 1);
    return result;
}

#endif
