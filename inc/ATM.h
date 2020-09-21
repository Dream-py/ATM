#ifndef _ATM_H_
#define _ATM_H_

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



typedef struct account
{
    char name[20];//名字
    char pw[7];//密码
    int id;//帐号
    float amount;//余额
    int flag;   //状态：0 正常， 1 注销
}Bank;

void welcome();//载入页面函数
void mainMenu();//主界面函数
void regist();//注册函数
void login();//登陆函数
void service();//服务函数
void pws(char pw[]);
void withdraw();//取款函数
void deposit();//存款函数
void print();//打印函数
void changepw();//改密函数
void cancel();//注销函数
void quit();//退出函数
void transfer();//转账函数

#endif 
