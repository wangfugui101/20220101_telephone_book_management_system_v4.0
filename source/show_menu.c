/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: show_menu.c
文件说明：显示子系统的设计结构

作者: 周湘祯  版本 : v3.0 创建日期: 2022年01月01日 
开发系统版本(lsb_release -a)：  Ubuntu 18.04 LTS
GCC编译器版本(gcc  -v)： gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)     
函数列表:  
1. main：启动代码的入口函数
历史记录:  
<作者>  <创建时间>       <版本号>
周湘祯   2022年01月01日    v3.0
***********************************************************/

#include "contact.h"

/************************************************* 
函数名称:SortByName
函数功能、性能等的描述:
	按照名字排序
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void SortByName(PNODE pHead)
{
    int i,j;
    int len=LengthList(pHead);
    PNODE p;
    PNODE q;
    contact * human=(contact *)malloc(sizeof(contact));

    for(i=0,p=pHead->pNxet ;i<len-1 ;i++, p=p->pNxet){
        for(j=i+1,q=p->pNxet ;j<len ;j++,q=q->pNxet){
			
            if((p->people->name) > (q->people->name)){
                human = p->people;
                p->people = q->people;
                q->people = human;
            }
        }
    }
    TraverseList(pHead);
}


/************************************************* 
函数名称:SortByAge
函数功能、性能等的描述:
	按照年龄排序
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void SortByAge(PNODE pHead)
{
    int i,j;
    int len=LengthList(pHead);
    PNODE p;
    PNODE q;
    contact * human=(contact *)malloc(sizeof(contact));

    for(i=0,p=pHead->pNxet ;i<len-1 ;i++, p=p->pNxet){
        for(j=i+1,q=p->pNxet ;j<len ;j++,q=q->pNxet){
            if((p->people->age) > (q->people->age)){
                human = p->people;
                p->people = q->people;
                q->people = human;
            }
        }
    }
    TraverseList(pHead);
}


/************************************************* 
函数名称:SortByPhone
函数功能、性能等的描述:
	按照电话号码排序
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void SortByPhone(PNODE pHead)
{
    int i,j;
    int len=LengthList(pHead);
    PNODE p;
    PNODE q;
    contact * human=(contact *)malloc(sizeof(contact));

    for(i=0,p=pHead->pNxet ;i<len-1 ;i++, p=p->pNxet){
        for(j=i+1,q=p->pNxet ;j<len ;j++,q=q->pNxet){
			int a[2];
			a[0]=atoi(p->people->phone);
			a[1] = atoi(q->people->phone);
            if(a[0] > a[1]){
                human = p->people;
                p->people = q->people;
                q->people = human;
            }
        }
    }
    TraverseList(pHead);
}


/************************************************* 
函数名称:show_menu
函数功能、性能等的描述:
	显示子系统的显示界面
输入参数说明：无
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void show_menu(PNODE pHead)
{
    while(1){
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"          欢迎来到显示联系人子系统          \n"DEFAULT_MODE);
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"1--按照联系人姓名排序       2--按照联系人电话号码排序\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"3--按照联系人姓名年龄排序   4--默认排序\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"5--退出\n"DEFAULT_MODE);
        int key = getKey();
        switch (key)
            {
            case 1:
                {
                    SortByName(pHead);
                    break;
                }
            case 2:
                {
                    SortByPhone(pHead);
                    break;
                }
            case 3:
                {
                    SortByAge(pHead);

                    break;
                }
            case 4:
                {
                    TraverseList(pHead);

                    break;
                }
            case 5:
                {

                    return;
                }
            default :
                {
                    printf(DEFAULT_MODE FONT_RED "没有该选项！\n"DEFAULT_MODE);
                    return;
                }
            }
    }
}

/************************************************* 
函数名称:TraverseList
函数功能、性能等的描述:
	遍历所有通讯录的联系人信息
输入参数说明：NODE * 的头结点
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void TraverseList(PNODE pHead)
{
    PNODE p = pHead->pNxet;
    if(p== NULL)
    {
        printf(DEFAULT_MODE FONT_RED "该系统联系人为空！\n"DEFAULT_MODE);
    }
    else
    {
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"姓名: \t"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"性别: \t"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"年龄: \t"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"电话: \t"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"地址: \t"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"个人简介:\n"DEFAULT_MODE);

        while(NULL != p)
        {
            printf("%s \t",p->people->name);
            printf("%s \t",p->people->sex);

            printf("%d \t",p->people->age);
            printf("%s \t",p->people->phone);
            printf("%s \t",p->people->address);
            printf("%s \t\n",p->people->info);
            p=p->pNxet;
        }
    }


}


/************************************************* 
函数名称:TraverseNode
函数功能、性能等的描述:
	遍历通讯录中一个联系人的信息
输入参数说明：NODE * 的头结点
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void TraverseNode(PNODE p)
{
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"姓名: \t"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"性别: \t"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"年龄: \t"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"电话: \t"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"地址: \t"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN"个人简介:\n"DEFAULT_MODE);

    printf("%s \t",p->people->name);
    printf("%s \t",p->people->sex);
    printf("%d \t",p->people->age);
    printf("%s \t",p->people->phone);
    printf("%s \t",p->people->address);
    printf("%s \t\n",p->people->info);

}
