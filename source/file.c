/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: file.c
文件说明：写入与读取文件信息

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
函数名称:Save
函数功能、性能等的描述:
	将通讯录系统中的信息保存到文件里面
输入参数说明：NODE * 的头结点
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void Save(PNODE pHead)
{
    FILE * fp=fopen("1.txt","wb+");
    if(fp == NULL)
    {
        printf("打开失败！\n");
        exit(-1);
    }

    PNODE pNew = pHead->pNxet;

    while(pNew!=NULL){
        fwrite(pNew->people,sizeof(contact),1,fp);
        pNew = pNew->pNxet;
    }

    fclose(fp);
    fp = NULL;


}


/************************************************* 
函数名称:Read
函数功能、性能等的描述:
	将文件中的信息保存到通讯录系统中
输入参数说明：NODE * 的头结点
输出参数的说明: NODE * 的头结点
函数返回值的说明: NODE * 的头结点
其它说明: 无
*************************************************/
PNODE Read()
{

    pHead = (PNODE)malloc(sizeof(NODE));

    PNODE pTai = pHead;
    pTai->pNxet = NULL;


    if(NULL == pHead)
    {
        printf("内存分配失败，程序退出！");
        exit(-1);
    }

    FILE * fp1=fopen("1.txt","rb+");
    if(fp1 == NULL)
    {
        printf("打开失败！\n");
        exit(-1);
    }

    while(1)
    {

        contact * human = (contact *)malloc(sizeof(contact));
        PNODE pNew =  (PNODE)malloc(sizeof(NODE));

        if(1==(fread(human,sizeof(contact),1,fp1)))
        {
            pNew->people= human;

            pTai->pNxet = pNew;
            pNew->pNxet = NULL;
            pTai = pNew;

        }
        else
        {
            break;
        }
    }
    fclose(fp1);
    fp1 = NULL;
    return pHead;
}

