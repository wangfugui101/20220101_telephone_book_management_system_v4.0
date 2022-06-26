/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: add_menu.c
文件说明：增加子系统的设计结构

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
函数名称:InsertByHead
函数功能、性能等的描述:
	在联系人前面插入新添加的联系人信息
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void InsertByHead(PNODE pHead)
{
    int i=0;
    int pos;
    PNODE p = pHead;

    if(pHead == NULL){
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead =CreatList();
        InsertByHead(pHead);
    }else{
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "请输入你想要在第几个联系人前插入新添加的联系人信息:" DEFAULT_MODE);
        scanf("%d",&pos);

        while(NULL != p && i<pos-1){
            ++i;
            p=p->pNxet;
        }
        if(i>pos-1 ||NULL == p){
            printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "输入有误！\n" DEFAULT_MODE);
            InsertByHead(pHead);
            return;
            //setbuf(stdin,NULL);
        }

        PNODE pNew =  (PNODE)malloc(sizeof(NODE));
        contact * human=(contact *)malloc(sizeof(contact));


        if(NULL == pNew){
            printf("内存分配失败，程序退出！");
            exit(-1);
        }
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "在此联系人中，你要输入以下信息：\n"DEFAULT_MODE);


        AddPeople(human);

        pNew->people = human;
        pNew->pNxet = p->pNxet;
        p->pNxet = pNew;
		system("clear");
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "插入成功！新添加的联系人信息如下：\n" DEFAULT_MODE);
        TraverseNode(pNew);
    }

}

/************************************************* 
函数名称:InsertByTail
函数功能、性能等的描述:
	在联系人后面插入新添加的联系人信息
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void InsertByTail(PNODE pHead)
{
    int i=0;
    int pos;
    PNODE p = pHead;

    if(pHead == NULL){
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead = CreatList();
        InsertByTail(pHead);
    }else{
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN  "请输入你想要在第几个联系人前插入新添加的联系人信息:" DEFAULT_MODE);
        scanf("%d",&pos);

        while(NULL != p && i<pos){
            ++i;
            p=p->pNxet;
        }
        if(i>pos ||NULL == p){
            printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN  "输入有误！\n" DEFAULT_MODE);
            InsertByTail(pHead);
            return;
            //setbuf(stdin,NULL);
        }

        PNODE pNew =  (PNODE)malloc(sizeof(NODE));

        contact * human=(contact *)malloc(sizeof(contact));
        if(NULL == pNew){
            printf("内存分配失败，程序退出！");
            exit(-1);
        }
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN  "在此联系人中，你要输入以下信息：\n" DEFAULT_MODE);

        AddPeople(human);

        pNew->people = human;
        pNew->pNxet = p->pNxet;
        p->pNxet = pNew;
		system("clear");
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "插入成功！新添加的联系人信息如下：\n" DEFAULT_MODE);
        TraverseNode(pNew);
    }


}

/************************************************* 
函数名称:add_menu
函数功能、性能等的描述:
	增加子系统的显示界面
输入参数说明：无
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void add_menu(PNODE pHead)
{
    while(1){

        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "********************************************\n"DEFAULT_MODE); 
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "          欢迎来到增加联系人子系统          \n"DEFAULT_MODE);
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "1--前插联系人信息       2--后插联系人信息\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "3--退出\n"DEFAULT_MODE);
        int key = getKey();
        switch (key)
            {
            case 1:
                {
                    InsertByHead(pHead);
                    break;
                }
            case 2:
                {
                    InsertByTail(pHead);
                    break;
                }
            case 3:
                {
                    return;
                }
            default :
                {
                    //当所有条件都不满足的时候，就使用default语句
                    printf(DEFAULT_MODE FONT_RED "没有该选项！\n" DEFAULT_MODE);
                    return;
                }
            }
    }
}
