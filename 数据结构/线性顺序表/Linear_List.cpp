//============================================================================
// Name        : Linear_List.cpp
// Author      : Yuhang_Shang
// Date        : 2021.9.21
// Copyright   : all rights reserved
// Description : 实现《数据结构（严蔚敏）》中顺序线性表的增删改查功能
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量
#define OVERLOW -2         //函数结果状态代码
#define OK 1               //函数结果状态代码
#define ERROR 0            //函数结果状态代码
typedef int ElemType;      //假设线性表数据类型为int

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

int comp(ElemType c1, ElemType c2);                                          //数据元素判定函数(相等关系)
int InitList_Sq(SqList &L);                                                  //线性表L初始化
int ListInsert_Sq(SqList &L, int i, ElemType e);                             //线性表L插入元素
int ListDelete_Sq(SqList &L, int i, ElemType &e);                            //线性表L删除元素
int LocateElem_Sq(SqList L, ElemType e, int (*compare)(ElemType, ElemType)); //线性表L查找元素

int main()
{
    SqList list;
    InitList_Sq(list);

    //设定线性表初始数据数
    int n;
    printf("请输入线性表初始数据数：\n");
    scanf("%d", &n);
    //添加10个数字给线性表list
    printf("请输入%d个数：\n", n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        ListInsert_Sq(list, i + 1, x);
    }

    //删除元素
    ElemType e;
    printf("请输入删除的数的位置：\n");
    int y;
    scanf("%d", &y);
    ListDelete_Sq(list, y, e);
    printf("删除的元素是：%d\n", e);

    //在第2个位置插入一个元素-1
    printf("我在第2个位置插入一个元素-1\n");
    ListInsert_Sq(list, 2, -1);

    //查找元素
    int find_e;
    printf("请输入需要查找的元素的值：\n");
    scanf("%d", &find_e);
    int is = LocateElem_Sq(list, find_e, comp);
    if (is)
        printf("所查找的元素在%d位置\n", is);
    else
        printf("查不到该元素\n");

    //输出线性表
    printf("顺序表的最终结果为：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", list.elem[i]);
    }
    //输出结果是：1 -1 2 3 4 6 7 8 9 10

    return 0;
}

//数据元素判定函数(相等关系)
int comp(ElemType c1, ElemType c2)
{
    if (c1 == c2)
        return true;
    else
        return false;
}

//算法2.2 p23 线性表初始化
int InitList_Sq(SqList &L)
{
    //构造一个空的线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERLOW);           //存储分配失败
    L.length = 0;                //空表长度为0
    L.listsize = LIST_INIT_SIZE; //初始存储容量
    return OK;
} //InitList_Sq;

//算法2.3 p24 线性表插入元素
int ListInsert_Sq(SqList &L, int i, ElemType e)
{
    //在顺序线性表L中第i个位置之前插入新的元素e
    //i的合法值为1≤i≤ListLength_Sq(L)+1
    if (i < 1 || i > L.length + 1)
        return ERROR; //i值不合法(i值过小或越界)
    if (L.length >= L.listsize)
    {
        //当前存储空间已满，增加分配
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERLOW);           //存储分配失败
        L.elem = newbase;            //新基址
        L.listsize += LISTINCREMENT; //增加存储容量
    }
    //建立两个指针记录位置，q为插入位置，p用于遍历
    ElemType *q, *p;
    //q为插入位置
    q = &(L.elem[i - 1]);
    //把第i个数到第n-1个数从后往前依次后移
    for (p = &(L.elem[L.length - 1]); p >= q; --p)
    {
        *(p + 1) = *p;
    }
    //插入位置及之后的元素右移
    *q = e;     //插入e
    ++L.length; //表长增1
    return OK;
} //ListInsert_Sq

//算法2.5 p24 线性表L删除元素
int ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    //在顺序线性表L中删除第i个元素，并用e返回其值
    //i的合法值为1≤i≤ListLength_Sq(L)
    if ((i < 1) || (i > L.length))
        return ERROR; //i值不合法
    //建立指针记录位置
    ElemType *p, *q;
    //p是被删除的元素的位置
    p = &(L.elem[i - 1]);
    //e存储删除的元素的值。
    e = *p;
    //q为顺序表末尾元素的地址
    q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    --L.length; //表长减1
    return OK;
} //ListDelete_Sq

//算法2.6 P26 线性表L的查找
int LocateElem_Sq(SqList L, ElemType e, int (*compare)(ElemType, ElemType))
{
    //在顺序线性表L中查找第一个值与e满足compare()的元素的位序
    //若找到，则返回其在L中的位序，否则返回0
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
} //LocateElem_Sq;
