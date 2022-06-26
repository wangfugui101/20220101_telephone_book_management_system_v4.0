/************************************************************ 
Copyright (C), 2021-2031, 周湘祯. Co., Ltd. 
文件名称: 电话本管理系统的设计
文件说明：

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

PNODE pHead = NULL;
/*返回头结点*/


int main()
{
    while(1){
        int tmp = login();
        if(1 == tmp){
            break;
        }else{
            continue;
        }
    }

    FILE *fp;
    char ch;
    fp = fopen("1.txt","rb+");
    ch = fgetc(fp);

    if(!fread(&ch,sizeof(char),1,fp))
    {
        pHead = CreatList();
        Save(pHead);
        Interface(pHead);
    }
    else
    {
        Read();
        Interface(pHead);
    }
    return 0;
}

