/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: update_menu.c
文件说明：修改子系统的设计结构

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
函数名称:UpdateByName
函数功能、性能等的描述:
	按照联系人姓名查询信息后修改
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void UpdateByName(PNODE pHead)
{

    int i=0;

    PNODE p = pHead;

    if(pHead == NULL){
        printf("查询失败，因为你是首次使用本系统。\n");
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead =CreatList();
        //printf("Pheads = %p",pHead);
        update_menu(pHead);
    }else{
        int len = LengthList(pHead);
        char pos[100];
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"请输入你要修改的联系人的姓名："DEFAULT_MODE);
        scanf("%s",pos);

        while(NULL != p&&i<len ){
            char val[100];
            strcpy(val,p->pNxet->people->name);
            int ret = strcmp(pos,val);
            if(ret == 0){

                //printf("q2=%p\n",p->pNxet);
                AddPeople(p->pNxet->people);
                //printf("q3=%p\n",p->pNxet);
				system("clear");
                TraverseNode(p->pNxet);
                break;
            }
            else{
                i++;
                p=p->pNxet;
            }
        }


        if(i==len || p->pNxet == NULL){
			system("clear");
            printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"未找到该联系人！\n"DEFAULT_MODE);

            return;
        }

    }

}


/************************************************* 
函数名称:UpdateByPhone
函数功能、性能等的描述:
	按照联系人电话号码查询信息后修改
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void UpdateByPhone(PNODE pHead)
{

    int i=0;
    PNODE p = pHead;

    if(pHead == NULL){
        printf("查询失败，因为你是首次使用本系统。\n");
        printf("由于你是首次使用本系统，请批量添加联系人：\n");
        pHead =CreatList();
        //printf("Pheads = %p",pHead);
        update_menu(pHead);
    }else{
        int len = LengthList(pHead);
        char pos[100];
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "请输入你要修改的联系人的电话号码：" DEFAULT_MODE);
        scanf("%s",pos);

        while(NULL != p&&i<len ){
            char val[100];
            strcpy(val,p->pNxet->people->phone);
            int ret = strcmp(pos,val);
            if(ret == 0){

                //printf("q2=%p\n",p->pNxet);
                AddPeople(p->pNxet->people);
                //printf("q3=%p\n",p->pNxet);
				system("clear");
                TraverseNode(p->pNxet);
                break;
            }
            else{
                i++;
                p=p->pNxet;
            }
        }


        if(i==len || p->pNxet == NULL){
			system("clear");
            printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "未找到该联系人！\n" DEFAULT_MODE);

            return;
        }


    }

}


/************************************************* 
函数名称:update_menu
函数功能、性能等的描述:
	修改子系统的显示界面
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void update_menu(PNODE pHead)
{
    while(1){
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "          欢迎来到修改联系人子系统          \n"DEFAULT_MODE);
        printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED "********************************************\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN"1--按照联系人姓名修改       2--按照联系人电话号码修改\n"DEFAULT_MODE);
        printf(DEFAULT_MODE FONT_HIGHLIGHT_GREEN "3--退出\n");
        int key = getKey();
        switch (key)
            {
            case 1:
                {
                    UpdateByName(pHead);
                    break;
                }
            case 2:
                {
                    UpdateByPhone(pHead);
                    break;
                }
            case 3:
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
