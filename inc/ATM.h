#ifndef _ATM_H_
#define _ATM_H_

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



typedef struct account
{
    char name[20];//����
    char pw[7];//����
    int id;//�ʺ�
    float amount;//���
    int flag;   //״̬��0 ������ 1 ע��
}Bank;

void welcome();//����ҳ�溯��
void mainMenu();//�����溯��
void regist();//ע�ắ��
void login();//��½����
void service();//������
void pws(char pw[]);
void withdraw();//ȡ���
void deposit();//����
void print();//��ӡ����
void changepw();//���ܺ���
void cancel();//ע������
void quit();//�˳�����
void transfer();//ת�˺���

#endif 
