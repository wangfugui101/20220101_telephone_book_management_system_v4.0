#include "contact.h"

/************************************************* 
函数名称:getKey
函数功能、性能等的描述:
	获取按键的数字
输入参数说明：无
输出参数的说明: 一个key
函数返回值的说明: 一个key
其它说明: 无
*************************************************/
int getKey()
{
    int key;
    printf(DEFAULT_MODE FONT_RED "请做出您的选择:" DEFAULT_MODE);
    scanf("%d",&key);
	system("clear");
    return key;
}
/************************************************* 
函数名称:AddPeople
函数功能、性能等的描述:
	增加一个联系人信息
输入参数说明：contact * human：一个结构体指针
输出参数的说明: 无
函数返回值的说明: 无
其它说明: 无
*************************************************/
void AddPeople(contact * human)
{
    printf(DEFAULT_MODE FONT_RED"联系人的姓名："DEFAULT_MODE);
    scanf("%s",human->name);

    printf(DEFAULT_MODE FONT_RED"联系人的性别："DEFAULT_MODE);
    scanf("%s",human->sex);


    printf(DEFAULT_MODE FONT_RED"联系人的年龄："DEFAULT_MODE);
    scanf("%d",&human->age);

    printf(DEFAULT_MODE FONT_RED"联系人的电话："DEFAULT_MODE);
    scanf("%s",human->phone);

    printf(DEFAULT_MODE FONT_RED"联系人的地址："DEFAULT_MODE);
    scanf("%s",human->address);

    printf(DEFAULT_MODE FONT_RED"联系人的个人介绍："DEFAULT_MODE);
    scanf("%s",human->info);

}
/************************************************* 
函数名称:CreatList
函数功能、性能等的描述:
	初始化通讯录
输入参数说明：无
输出参数的说明: 一个带头结点的链表
函数返回值的说明: 一个带头结点的链表
其它说明: 无
*************************************************/
PNODE CreatList()
{
    int len;
    int i;

    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    if(NULL == pHead)
    {
        printf("内存分配失败，程序退出！");
        exit(-1);
    }

    PNODE pTai = pHead;
    pTai->pNxet = NULL;


    printf("你想要初始化几个人的通讯录：");
    scanf("%d",&len);

    for(i=0; i<len; i++)
    {
        contact * human = (contact *)malloc(sizeof(contact));


        PNODE pNew =  (PNODE)malloc(sizeof(NODE));

        printf("在第%d个人信息中，你需要输入以下信息：\n",i+1);

        printf("联系人的姓名：");
        scanf("%s",human->name);


        printf("联系人的性别：");
        scanf("%s",human->sex);

        getchar();

        printf("联系人的年龄：");
        scanf("%d",&human->age);
        getchar();

        printf("联系人的电话：");
        scanf("%s",human->phone);

        printf("联系人的地址：");
        scanf("%s",human->address);

        printf("联系人的个人介绍：");
        scanf("%s",human->info);
        getchar();

        pNew->people= human;
        pTai->pNxet = pNew;
        pNew->pNxet = NULL;
        pTai = pNew;
    }

    return pHead;
}
/************************************************* 
函数名称:LengthList
函数功能、性能等的描述:
	获取通讯录的人数
输入参数说明：NODE * 的头结点
输出参数的说明: 通讯录的人数
函数返回值的说明: 通讯录的人数
其它说明: 无
*************************************************/
int LengthList(PNODE pHead)
{
    int len=0;
    PNODE p = pHead->pNxet;
    while(NULL != p){
        ++len;
        p=p->pNxet;
    }
    return len;
}
/************************************************* 
函数名称:login
函数功能、性能等的描述:
	登录子系统
输入参数说明：无
输出参数的说明: 
	1：账号密码匹配成功
	0：账号密码不匹配
函数返回值的说明: 无
其它说明: 无
*************************************************/
int login()
{
    char account[12][24] = {{"zxz"}};
    char passwd[12][24] = {{"123"}};

    char input_account[24];
    bzero(input_account, sizeof(input_account));
    char input_passwd[24];
    bzero(input_passwd, sizeof(input_passwd));

    int result = 0;
	printf(DEFAULT_MODE BLINK FONT_BLUE  "********************************************\n"DEFAULT_MODE); 
    printf(DEFAULT_MODE FONT_BLUE "请输入账号和密码:\n" DEFAULT_MODE);
    while(1){
        result = scanf("%s%s", input_account, input_passwd);
		printf(DEFAULT_MODE BLINK FONT_BLUE  "********************************************\n"DEFAULT_MODE); 
        if(result != 2){
            while((result=getchar()) != '\n');
            printf(DEFAULT_MODE FONT_BLUE "数据输入错误，请重新输入!\n" DEFAULT_MODE);

        }
        else{
            break;
        }
    }
    if((strcmp(&account[0][0], input_account)==0) && (strcmp(&passwd[0][0], input_passwd)==0) ){
		system("clear");
        printf(DEFAULT_MODE FONT_BLUE "身份核验成功！\n" DEFAULT_MODE);
        return 1;

    }
    else{
        printf(DEFAULT_MODE FONT_BLUE "账号或者密码输错，请重新输入：\n" DEFAULT_MODE);
        return 0;
    }
}

