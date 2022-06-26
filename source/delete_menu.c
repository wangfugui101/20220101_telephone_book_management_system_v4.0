/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: delete_menu.c
文件说明：删除子系统的设计结构

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
函数名称:DeleteByName
函数功能、性能等的描述:
	按照联系人姓名来删除
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void DeleteByName(PNODE pHead)
{

    int i=0;

    PNODE p = (PNODE)malloc(sizeof(NODE));
    p = pHead;
    char pos[100];

    if(pHead == NULL){
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead =CreatList();
        DeleteByName(pHead);

    }else{
        int len=LengthList(pHead);

        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "请输入你要删除联系人的姓名："DEFAULT_MODE);
        scanf("%s",pos);

        while(NULL != p&&i<len ){
            char val[100];
            strcpy(val,p->pNxet->people->name);
            int ret = strcmp(pos,val);
            if(ret == 0){
                PNODE q;
                q=p->pNxet;
                p->pNxet = q->pNxet;
                free(q);
                q=NULL;
                break;
            }
            else{
                i++;
                p=p->pNxet;
            }
        }

        int len1=LengthList(pHead);
        if(len1 == len){
            if(i==len || p->pNxet == NULL){
                printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "未找到该联系人！请重新确认输入的姓名\n"DEFAULT_MODE);
                return;
            }
        }else{
			system("clear");
            printf(DEFAULT_MODE FONT_RED"删除成功！\n"DEFAULT_MODE);
        }
    }

}

/************************************************* 
函数名称:DeleteByPhone
函数功能、性能等的描述:
	按照联系人电话号码来删除
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void DeleteByPhone(PNODE pHead)
{

    int i=0;

    PNODE p = (PNODE)malloc(sizeof(NODE));
    p = pHead;
    char pos[100];

    if(pHead == NULL){
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead =CreatList();
        DeleteByPhone(pHead);

    }else{
        int len=LengthList(pHead);

        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"请输入你要删除联系人的电话号码："DEFAULT_MODE);
        scanf("%s",pos);

        while(NULL != p&&i<len ){
            char val[100];
            strcpy(val,p->pNxet->people->phone);
            int ret = strcmp(pos,val);
            if(ret == 0){
                PNODE q;
                q=p->pNxet;
                p->pNxet = q->pNxet;
                free(q);
                q=NULL;
                break;
            }
            else{
                i++;
                p=p->pNxet;
            }
        }

        int len1=LengthList(pHead);
        if(len1 == len){
            if(i==len || p->pNxet == NULL){
                printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"未找到该联系人！请重新确认输入的电话号码。\n"DEFAULT_MODE);
                return;
            }
        }else{
			system("clear");
            printf(DEFAULT_MODE FONT_RED"删除成功！\n"DEFAULT_MODE);
        }
    }

}

/************************************************* 
函数名称:delete_menu
函数功能、性能等的描述:
	删除子系统的显示界面
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void delete_menu(PNODE pHead)
{
    while(1){
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"          欢迎来到删除联系人子系统          \n"DEFAULT_MODE);
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"1--按照联系人姓名删除       2--按照联系人电话号码删除\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"3--退出\n");
        int key = getKey();
        switch (key)
            {
            case 1:
                {
                    DeleteByName(pHead);
                    break;
                }
            case 2:
                {
                    DeleteByPhone(pHead);
                    break;
                }
            case 3:
                {
                    return;
                }
            default :
                {
                    printf(DEFAULT_MODE FONT_RED"没有该选项！\n"DEFAULT_MODE);
                    return;
                }
            }
    }
}