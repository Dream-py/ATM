#include "ATM.h"

extern Bank ATM;

extern FILE *fp;

void welcome()
{
    int i,j,l,k;
    
    for(i=1;i<=100;i++)
	{

		printf("\n\n\n\n\n\n\n\t\t\t  欢迎使用我的银行管理系统");
		for(j = 1; j <= i % 4; j++)
            printf(".");

		printf("\n\n\t\t");

		for(l=1;l<=i*0.2;l++)
            printf("■");

		printf("\n\t\t\t\t   %d%%",i);

		for(k=1;k<5000000;k++);
	    system("cls");
	}

}

//主界面函数
void mainMenu()
{
    char choice;

    while(1)
	{
		printf("\n\n\n\n\n\t\t\t\t1:用户注册\n\n");
		printf("\t\t\t\t2:用户登录\n\n");
		printf("\t\t\t\t3:退出系统\n\n\n\n");
		printf("\t\t\t\t请选择：");

		fflush(stdin);//清除键盘缓冲区的回车符
		scanf("%c",&choice);

		switch(choice)
		{
        case '1':
            regist();
            break;

        case '2':
            login();
            break;

        case '3':
            quit();
            break;

        default:
            printf("\n\n\t\t\t输入错误！\n");
		}

		printf("\n\n\t\t\t按任意键继续......");
		getch();
		system("cls");
	}
}

//注册函数
void regist()
{
	Bank newuser;
	Bank t;
	char a[7];//重复密码
	int k;

    system("cls");

	if(NULL == (fp = fopen("atm.txt", "ab+")))
	{
		printf("\n\n\t\t\t打开文件失败!");

		return;
	}

	printf("\n\n\n\n\t\t\t\t您正在使用注册服务\n");
	printf("\n\n\n\t\t\t请输入用户名:");
	fflush(stdin);
	scanf("%s", newuser.name);
	printf("\n\n\n\t\t\t您的用户名是%s\n", newuser.name);

	

	while(1)
	{
		system("cls");

		printf("\n\n\n\n\t\t\t\t您正在使用注册服务\n");
		printf("\n\n\n\t\t\t请输入六位数密码:");

        fflush(stdin);
        pws(newuser.pw);

        
        
            printf("\n\n\n\t\t\t请再次确认密码:");
            fflush(stdin);
            pws(a);

            if (!strcmp(newuser.pw, a))
                break;

            printf("\n\n\n\t\t\t两次密码不一致,请重新输入！");
        

		
	}

	fseek(fp, -sizeof(Bank), 2);

	if (fread(&t, 1, sizeof(Bank), fp))
	{
        newuser.id = t.id + 1;
	}
	else
    {
        newuser.id = 2017000;
    }

    newuser.amount = 0;
    newuser.flag = 0;

	fseek(fp, 0, 2);
	fwrite(&newuser, 1, sizeof(Bank), fp);

	printf("\n\n\n\t\t\t恭喜您,注册成功");
	printf("\n\n\n\t\t\t您的帐号是：%d\n", newuser.id);

  	fclose(fp);
}

//登陆函数
void login()
{
    int account, f = 0, j;
	char s[7];
    int i;
    system("cls");

	if (NULL == (fp = fopen("atm.txt","rb+")))
	{
	    printf("\n\n\n\n\t\t\t打开文件失败!");

		return;
	}

    printf("\n\n\n\n\t\t\t\t您正在使用登陆服务\n");
    printf("\n\n\n\t\t\t\t请输入账号：");

    fflush(stdin);
    scanf("%d", &account);

    rewind(fp);
    while(fread(&ATM, 1, sizeof(Bank), fp) == sizeof(Bank))//读文件的内容一个Bank结构体大小的内容
    {
        if(account == ATM.id && ATM.flag == 0)
        {
            f = 1;
            break;
        }
    }

    if(f == 1)
    {
        for(j = 0; j < 3; j++)
        {
            system("cls");

            printf("\n\n\n\n\t\t\t\t您正在使用登陆服务\n");
            printf("\n\n\n\t\t\t\t您的账户：%d", account);
            printf("\n\n\t\t\t\t请输入密码：");
            fflush(stdin);
            pws(s);

            if(!strcmp(s, ATM.pw))
                break;

            printf("\n\n\n\t\t\t\t密码错误，请重新输入！");

            for(i = 0; i < 500000000; i++);
        }

        if(j < 3)
        {
            printf("\n\n\n\t\t\t\t 登陆成功");

            for(i = 0; i < 500000000; i++);

            system("cls");

            service();
        }
		else
        {
            system("cls");

            printf("\n\n\n\n\n\t\t\t三次输入错误，吞卡中......");
            printf("\n\n\n\t\t\t正在退出,请稍等......");
        }
    }
    else
    {
        printf("\n\n\n\t\t\t没有此帐号");
        printf("\n\n\n\t\t\t正在退出,请稍等......");
    }

    fclose(fp);
}

//服务页面函数
void service()
{
	char choice;

	while(1)
	{
        printf("\n\n\n\n\t\t\t\t 服务页面\n\n");
        printf("\t\t\t\t1:存款服务\n\n");
        printf("\t\t\t\t2:取款服务\n\n");
        printf("\t\t\t\t3:转账服务\n\n");
        printf("\t\t\t\t4:更改密码\n\n");
        printf("\t\t\t\t5:打印信息\n\n");
        printf("\t\t\t\t6:注销服务\n\n");
        printf("\t\t\t\t7:返回主界面\n\n");
        printf("\t\t\t\t请选择：");

        fflush(stdin);
        scanf("%c", &choice);

        if (choice == '6')
        {
            cancel();

            if (ATM.flag)
                break;
        }

        if (choice == '7')
            break;


        switch(choice)
        {
        case '1':
            deposit();
            break;

        case '2':
            withdraw();
            break;

        case '3':
            transfer();
            break;

        case '4':
            changepw();
            break;

        case '5':
            print();
            break;

        case '6':
            break;

        default :
            printf("\n\n\t\t\t  输入错误！\n");
        }

        printf("\n\n\t\t\t按任意键继续......");
        getch();

        system("cls");
	}
}

//存款函数
void deposit()
{
	float money;

	system("cls");

	printf("\n\n\n\n\t\t\t您正在执行存款操作");
	printf("\n\n\t\t\t请输入存款金额：");
	fflush(stdin);
	scanf("%f", &money);

    ATM.amount = ATM.amount + money;

	fseek(fp, -sizeof(Bank), 1);
	fwrite(&ATM, 1, sizeof(Bank), fp);

	printf("\n\n\t\t\t  存款成功！");
}

//取款函数
void withdraw()
{
    float money;

    while(1)
	{
	    system("cls");

	    printf("\n\n\n\n\t\t\t您正在执行取款操作");
        printf("\n\n\n\n\t\t\t请输入取款金额：");
        fflush(stdin);
        scanf("%f", &money);

	    if(money <= ATM.amount)
		{
            ATM.amount = ATM.amount - money;

            fseek(fp, -sizeof(Bank), 1);
            fwrite(&ATM, 1, sizeof(Bank), fp);

            printf("\n\n\n\n\t\t\t  取款成功！\n\n");
            printf("\n\n\n\n\t\t\t您的账户余额为：%f", ATM.amount);

            break;
		}

        printf("\n\n\n\t\t\t余额不足，请重新操作！");

        printf("\n\n\n\t\t\t\t按任意键继续......");
        getch();
	}
}

//改密函数
void changepw()
{
	int i;
    char b[7], c[7], d[7];

	for(i=0; i<3; i++)
	{
        system("cls");

        printf("\n\n\n\n\t\t\t您正在执行修改密码操作\n\n");
        printf("\n\t\t\t请输入旧密码：");
        fflush(stdin);
        pws(b);

        if(!strcmp(b, ATM.pw))
            break;

        printf("\n\n\n\t\t\t旧密码输入有误，请重新输入:");

        for(i = 0; i < 500000000; i++);
	}

	if(i < 3)
	{
        while (1)
        {
            while (1)
            {
                system("cls");

                printf("\n\n\n\n\t\t\t你正在执行修改密码操作\n\n");

                printf("\n\t\t\t请输入新密码：");
                fflush(stdin);
                pws(d);

                if (strlen(d) < 6)
                    printf("\n\n\n\t\t密码必须为六位，请重新输入");

                else
                {
                    if (strcmp(ATM.pw, d))
                    break;

                    printf("\n\n\n\t\t两次密码一致，请重新输入");
                }

		      	for(i = 0; i < 500000000; i++);
            }

            printf("\n\n\n\n\t\t\t请再次输入新密码：");
	        fflush(stdin);
            pws(c);

            if(!strcmp(c, d))
            {
                strcpy(ATM.pw, d);

                fseek(fp, -sizeof(Bank), 1);
                fwrite(&ATM, 1, sizeof(Bank), fp);

                printf("\n\n\n\t\t\t  修改成功！");

                break;
            }
            else
            {
                printf("\n\n\n\t\t\t两次密码不一致，请重新输入");

                for(i = 0; i < 500000000; i++);
            }
        }
	}
	else
    {
        printf("\n\n\t\t\t三次输入错误，正在返回......");
    }
}

//打印函数
void print()
{
    system("cls");
    printf("\n\n\n\t\t\t您正在执行打印操作;");
    printf("\n\n\n\t\t\t您的账号为：%d", ATM.id);
    printf("\n\n\n\t\t\t您的用户名为：%s", ATM.name);
    printf("\n\n\n\t\t\t您的余额为：%f", ATM.amount);
}

//退出函数
void quit()
{
  	system("cls");
	printf("\n\n\n\n\n\t\t\t正在退出,请稍等......");

    exit(0);
}

//转账函数
void transfer()
{
    int account, f = 0, k = ftell(fp);
    float money;
    Bank t;

    system("cls");

    printf("\n\n\n\t\t\t您正在执行转账操作;");
    printf("\n\n\n\t\t\t请输入对方帐号：");

    fflush(stdin);
    scanf("%d",&account);

    rewind(fp);

    while(fread(&t, 1, sizeof(t), fp))
    {
        if(account == t.id && t.flag == 0 && t.id != ATM.id)
        {
            f = 1;
            break;
        }
    }

    if(f == 1)
    {
        while (1)
        {
            system("cls");

            printf("\n\n\n\t\t\t您正在执行转账操作");
            printf("\n\n\n\n\t\t\t请输入转账金额：");
            scanf("%f", &money);

            if(money <= ATM.amount)
            {
                t.amount += money;
                ATM.amount -= money;

                fseek(fp, -sizeof(Bank), 1);
                fwrite(&t, 1, sizeof(Bank), fp);

                fseek(fp, k - sizeof(Bank), 0);
                fwrite(&ATM, 1, sizeof(Bank), fp);

                printf("\n\n\n\t\t\t  转账成功！");
                printf("\n\n\t\t\t您的余额为：%f", ATM.amount);

                break;
            }

            printf("\n\n\n\t\t\t余额不足，转账失败！");

            printf("\n\n\n\t\t\t\t按任意键继续......");
            getch();
        }
    }
    else
    {
        fseek(fp, k, 0);
        printf("\n\n\n\t\t此账号不存在或状态异常，请确认后重新输入");
    }
}

//密码函数
void pws(char pw[])
{
	int i = 0;
	char c;

	while (1)
	{
		c = getch();

        if(c == '\r')
            break;

        if(c == '\b' && i > 0)
        {
            printf("\b \b");
            i--;
        }

        if ('0' <= c && '9' >= c && i < 6)
        {
            pw[i] = c;
            printf("*");
            i++;
        }
	}

	pw[i]='\0';
}

//注销函数
void cancel()
{
	char choice;

	system("cls");

	while(1)
	{
        printf("\n\n\n\t\t\t您正在使用注销功能");
        printf("\n\n\n\t\t\t您的余额为：%f", ATM.amount);
        printf("\n\n\n\t\t\t是否确认注销本账号？");
        printf("\n\n\n\t\t\t注销请按[Y]，取消注销请按[N]\n\n\t\t\t\t");

        fflush(stdin);
        scanf("%c",&choice);

        if(choice == 'Y' || choice == 'y')
        {
            ATM.flag = 1;

            fseek(fp, -sizeof(Bank), 1);
            fwrite(&ATM, 1, sizeof(Bank), fp);
            break;
        }

        if(choice == 'n' || choice == 'N')
        {
             break;
        }
        else
        {
             printf("\n\n\t\t\t输入错误请重新输入！");
        }
    }
}

