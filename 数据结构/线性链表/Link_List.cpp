#include<stdio.h> 
#include<malloc.h>  
#include<stdlib.h>  

typedef struct node
{
    float coef;
    int expn;
    node* next;
} Lnode, * Dxs;

Dxs create();
Dxs add_dxs(Dxs firsta, Dxs firstb);
void printDxs(Dxs h);
void deleteNode(Dxs h, Dxs p);

int main()
{
    system("color F0");
    system("title 多项式链表相加 @尚宇航");
    Dxs ha, hb, hc;
    printf("请依次输入第一个多项式的系数和指数（输入0 0结束）\n");
    ha = create();
    printf("请依次输入第二个多项式的系数和指数（输入0 0结束）\n");
    hb = create();
    printf("输入的第一个多项式是: ");
    printDxs(ha->next);
    printf("输入的第二个多项式是: ");
    printDxs(hb->next);
    hc = add_dxs(ha, hb);
    printf("两个多项式的和为: ");
    printDxs(hc->next);
    return 0;
}

//创建链表(读入数据以 0 0 结束)  
Dxs create()
{
    float coef;
    int expn;
    Dxs first, qa, s;
    first = (Dxs)malloc(sizeof(Lnode));
    first->coef = -1;
    first->expn = -1;
    first->next = NULL;
    qa = first;
    while (1)
    {
        scanf("%f", &coef);
        scanf("%d", &expn);
        if (coef == 0 && expn == 0)
        {
            break;
        }
        s = (Dxs)malloc(sizeof(Lnode));
        s->coef = coef;
        s->expn = expn;
        s->next = NULL;
        qa->next = s;
        qa = s;
    }
    return first;
}

//链表相加  
Dxs add_dxs(Dxs firsta, Dxs firstb)
{
    Dxs firstc, ha, hb, pc, s;
    int a, b;
    float sum;
    firstc = (Dxs)malloc(sizeof(Lnode));
    firstc->coef = -1;
    firstc->expn = -1;
    firstc->next = NULL;
    pc = firstc;
    ha = firsta->next;
    hb = firstb->next;
    while (ha != NULL && hb != NULL)
    {
        a = ha->expn;
        b = hb->expn;
        if (a < b)
        {
            //将a加入c中,移动a和c的指针  
            pc->next = ha;
            pc = pc->next;
            ha = ha->next;
        }
        else if (a > b)
        {
            //将b加入c中,移动b和c的指针  
            pc->next = hb;
            pc = pc->next;
            hb = hb->next;
        }
        else
        {
            sum = ha->coef + hb->coef;
            if (sum != 0.0)
            {
                //将和加入a中,再将a加入c中,移动c的指针  
                ha->coef = sum;
                pc->next = ha;
                pc = pc->next;
            }
            else
            {
                //查找删除A中系数之和为0的那个节点  
                s = firsta;
                while (s != ha)
                {
                    s = s->next;
                }
                s->next = ha->next;
            }
            //ab已经处理完成,同时后移一位  
            ha = ha->next;
            hb = hb->next;
        }
    }
    //将剩余部分加入c后面  
    if (ha != NULL)
    {
        pc->next = ha;
    }
    if (hb != NULL)
    {
        pc->next = hb;
    }
    return firstc;
}

//遍历显示链表  
void printDxs(Dxs h)
{
    while (h != NULL)
    {
        printf("%0.2f*X^%d + ", h->coef, h->expn);
        h = h->next;
    }
    printf("\n");
}
