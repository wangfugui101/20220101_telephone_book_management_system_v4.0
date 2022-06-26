/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: interface.c
文件说明：主题框架的显示界面系统的设计结构

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
函数名称:menu
函数功能、性能等的描述:
	菜单的显示界面
输入参数说明：无
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void menu()
{
    printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "********************************************\n"DEFAULT_MODE);
    printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "***********"DEFAULT_MODE);
	printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN "欢迎来到电话本管理系统"DEFAULT_MODE);
	printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "***********\n"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN "1--增加联系人       2--删除联系人\n"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN "3--查询联系人       4--修改联系人\n"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN "5--保存联系人       6--显示联系人\n"DEFAULT_MODE);
    printf(DEFAULT_MODE FONT_HIGHLIGHT_CYAN "7--退出\n"DEFAULT_MODE);
	printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "********************************************\n" DEFAULT_MODE);
	printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED  "********************************************\n" DEFAULT_MODE);
}



/************************************************* 
函数名称:Interface
函数功能、性能等的描述:
	主题框架的显示界面
输入参数说明：一个带头结点的链表
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void Interface(PNODE pHead)
{
    while(1)
    {
        menu();
        int key = getKey();
        switch (key)
        {
        case 1:
            {
                add_menu(pHead);
                break;
            }
        case 2:
            {
                delete_menu(pHead);
                break;
            }
        case 3:
            {
                query_menu(pHead);
                break;
            }
        case 4:
            {
                update_menu(pHead);
                break;
            }
        case 5:
            {
                Save(pHead);
                printf(DEFAULT_MODE FONT_HIGHLIGHT_RED"保存成功！\n"DEFAULT_MODE);
                break;
            }
        case 6:
            {
                show_menu(pHead);
                break;
            }

        case 7:
            {
                Save(pHead);
                printf(DEFAULT_MODE FONT_HIGHLIGHT_RED"保存成功！\n"DEFAULT_MODE);
                printf(DEFAULT_MODE BLINK FONT_HIGHLIGHT_RED"感谢使用本系统！！\n"DEFAULT_MODE);
                return;
            }
        default :
            {
                printf(DEFAULT_MODE FONT_HIGHLIGHT_RED"没有任何条件满足,请你确认一下！\n"DEFAULT_MODE);
                break;
            }
        }
    }
}
