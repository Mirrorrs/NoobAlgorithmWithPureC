#include <stdio.h>
#include <time.h>
#include "greatMinus.h"
#include "sqList.h"
#include "util.h"
#include "greatMultiple.h"
#include "greatDivide.h"
extern int steps;

// 大整数求最大公约数的优化算法
// 优化普通辗转相减中较差的情况比如10^100和1
int steps=0;
sqList greaterGCD(sqList m, sqList n){
    while(!isEqual(m, n)) {
        steps++;
        if (!greatIsUneven(m) && greatIsUneven(n))
            return greaterGCD(greatDivide(m), n);
        if (greatIsUneven(m) && !greatIsUneven(n))
            return greaterGCD(m, greatDivide(n));
        if (!greatIsUneven(m) && !greatIsUneven(n))
            return greatMultiple(greaterGCD(greatDivide(m), greatDivide(n)));
        else {
            if (!isMGreaterThanN(m, n))
                SwapSqList(&m, &n);
            return greaterGCD(greatMinus(m, n), n);
        }
    }
    return m;
}


int main(){
    // 声明变量以及初始化
    char* s1; char* s2;
	clock_t start, end;
	double cost;
    sqList m, n, result;
    initList(&m); initList(&n); initList(&result);

    // 读取文件并赋值给待操作数
    char in1[20] = {"../in1.txt"};
    char in2[20] = {"../in2.txt"};
    s1 = readFromFile(in1);
    s2 = readFromFile(in2);

    // 讲字符串转线性表
    m = ConvertCharArrayToSqList(s1);
    n = ConvertCharArrayToSqList(s2);

    // 算法计时开始
    start = clock();
    // 传入参数计算GCD
    result = greaterGCD(m, n);
    // 算法计时结束
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;

    // 打印相关信息并输入到文件
    generateResult(result, steps, cost);

    return 0;
}
