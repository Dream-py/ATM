#include "ATM.h"

extern Bank ATM;

extern FILE *fp;

void welcome()
{
    int i,j,l,k;
    
    for(i=1;i<=100;i++)
	{

		printf("\n\n\n\n\n\n\n\t\t\t  ��ӭʹ���ҵ����й���ϵͳ");
		for(j = 1; j <= i % 4; j++)
            printf(".");

		printf("\n\n\t\t");

		for(l=1;l<=i*0.2;l++)
            printf("��");

		printf("\n\t\t\t\t   %d%%",i);

		for(k=1;k<5000000;k++);
	    system("cls");
	}

}

//�����溯��
void mainMenu()
{
    char choice;

    while(1)
	{
		printf("\n\n\n\n\n\t\t\t\t1:�û�ע��\n\n");
		printf("\t\t\t\t2:�û���¼\n\n");
		printf("\t\t\t\t3:�˳�ϵͳ\n\n\n\n");
		printf("\t\t\t\t��ѡ��");

		fflush(stdin);//������̻������Ļس���
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
            printf("\n\n\t\t\t�������\n");
		}

		printf("\n\n\t\t\t�����������......");
		getch();
		system("cls");
	}
}

//ע�ắ��
void regist()
{
	Bank newuser;
	Bank t;
	char a[7];//�ظ�����
	int k;

    system("cls");

	if(NULL == (fp = fopen("atm.txt", "ab+")))
	{
		printf("\n\n\t\t\t���ļ�ʧ��!");

		return;
	}

	printf("\n\n\n\n\t\t\t\t������ʹ��ע�����\n");
	printf("\n\n\n\t\t\t�������û���:");
	fflush(stdin);
	scanf("%s", newuser.name);
	printf("\n\n\n\t\t\t�����û�����%s\n", newuser.name);

	

	while(1)
	{
		system("cls");

		printf("\n\n\n\n\t\t\t\t������ʹ��ע�����\n");
		printf("\n\n\n\t\t\t��������λ������:");

        fflush(stdin);
        pws(newuser.pw);

        
        
            printf("\n\n\n\t\t\t���ٴ�ȷ������:");
            fflush(stdin);
            pws(a);

            if (!strcmp(newuser.pw, a))
                break;

            printf("\n\n\n\t\t\t�������벻һ��,���������룡");
        

		
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

	printf("\n\n\n\t\t\t��ϲ��,ע��ɹ�");
	printf("\n\n\n\t\t\t�����ʺ��ǣ�%d\n", newuser.id);

  	fclose(fp);
}

//��½����
void login()
{
    int account, f = 0, j;
	char s[7];
    int i;
    system("cls");

	if (NULL == (fp = fopen("atm.txt","rb+")))
	{
	    printf("\n\n\n\n\t\t\t���ļ�ʧ��!");

		return;
	}

    printf("\n\n\n\n\t\t\t\t������ʹ�õ�½����\n");
    printf("\n\n\n\t\t\t\t�������˺ţ�");

    fflush(stdin);
    scanf("%d", &account);

    rewind(fp);
    while(fread(&ATM, 1, sizeof(Bank), fp) == sizeof(Bank))//���ļ�������һ��Bank�ṹ���С������
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

            printf("\n\n\n\n\t\t\t\t������ʹ�õ�½����\n");
            printf("\n\n\n\t\t\t\t�����˻���%d", account);
            printf("\n\n\t\t\t\t���������룺");
            fflush(stdin);
            pws(s);

            if(!strcmp(s, ATM.pw))
                break;

            printf("\n\n\n\t\t\t\t����������������룡");

            for(i = 0; i < 500000000; i++);
        }

        if(j < 3)
        {
            printf("\n\n\n\t\t\t\t ��½�ɹ�");

            for(i = 0; i < 500000000; i++);

            system("cls");

            service();
        }
		else
        {
            system("cls");

            printf("\n\n\n\n\n\t\t\t������������̿���......");
            printf("\n\n\n\t\t\t�����˳�,���Ե�......");
        }
    }
    else
    {
        printf("\n\n\n\t\t\tû�д��ʺ�");
        printf("\n\n\n\t\t\t�����˳�,���Ե�......");
    }

    fclose(fp);
}

//����ҳ�溯��
void service()
{
	char choice;

	while(1)
	{
        printf("\n\n\n\n\t\t\t\t ����ҳ��\n\n");
        printf("\t\t\t\t1:������\n\n");
        printf("\t\t\t\t2:ȡ�����\n\n");
        printf("\t\t\t\t3:ת�˷���\n\n");
        printf("\t\t\t\t4:��������\n\n");
        printf("\t\t\t\t5:��ӡ��Ϣ\n\n");
        printf("\t\t\t\t6:ע������\n\n");
        printf("\t\t\t\t7:����������\n\n");
        printf("\t\t\t\t��ѡ��");

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
            printf("\n\n\t\t\t  �������\n");
        }

        printf("\n\n\t\t\t�����������......");
        getch();

        system("cls");
	}
}

//����
void deposit()
{
	float money;

	system("cls");

	printf("\n\n\n\n\t\t\t������ִ�д�����");
	printf("\n\n\t\t\t���������");
	fflush(stdin);
	scanf("%f", &money);

    ATM.amount = ATM.amount + money;

	fseek(fp, -sizeof(Bank), 1);
	fwrite(&ATM, 1, sizeof(Bank), fp);

	printf("\n\n\t\t\t  ���ɹ���");
}

//ȡ���
void withdraw()
{
    float money;

    while(1)
	{
	    system("cls");

	    printf("\n\n\n\n\t\t\t������ִ��ȡ�����");
        printf("\n\n\n\n\t\t\t������ȡ���");
        fflush(stdin);
        scanf("%f", &money);

	    if(money <= ATM.amount)
		{
            ATM.amount = ATM.amount - money;

            fseek(fp, -sizeof(Bank), 1);
            fwrite(&ATM, 1, sizeof(Bank), fp);

            printf("\n\n\n\n\t\t\t  ȡ��ɹ���\n\n");
            printf("\n\n\n\n\t\t\t�����˻����Ϊ��%f", ATM.amount);

            break;
		}

        printf("\n\n\n\t\t\t���㣬�����²�����");

        printf("\n\n\n\t\t\t\t�����������......");
        getch();
	}
}

//���ܺ���
void changepw()
{
	int i;
    char b[7], c[7], d[7];

	for(i=0; i<3; i++)
	{
        system("cls");

        printf("\n\n\n\n\t\t\t������ִ���޸��������\n\n");
        printf("\n\t\t\t����������룺");
        fflush(stdin);
        pws(b);

        if(!strcmp(b, ATM.pw))
            break;

        printf("\n\n\n\t\t\t������������������������:");

        for(i = 0; i < 500000000; i++);
	}

	if(i < 3)
	{
        while (1)
        {
            while (1)
            {
                system("cls");

                printf("\n\n\n\n\t\t\t������ִ���޸��������\n\n");

                printf("\n\t\t\t�����������룺");
                fflush(stdin);
                pws(d);

                if (strlen(d) < 6)
                    printf("\n\n\n\t\t�������Ϊ��λ������������");

                else
                {
                    if (strcmp(ATM.pw, d))
                    break;

                    printf("\n\n\n\t\t��������һ�£�����������");
                }

		      	for(i = 0; i < 500000000; i++);
            }

            printf("\n\n\n\n\t\t\t���ٴ����������룺");
	        fflush(stdin);
            pws(c);

            if(!strcmp(c, d))
            {
                strcpy(ATM.pw, d);

                fseek(fp, -sizeof(Bank), 1);
                fwrite(&ATM, 1, sizeof(Bank), fp);

                printf("\n\n\n\t\t\t  �޸ĳɹ���");

                break;
            }
            else
            {
                printf("\n\n\n\t\t\t�������벻һ�£�����������");

                for(i = 0; i < 500000000; i++);
            }
        }
	}
	else
    {
        printf("\n\n\t\t\t��������������ڷ���......");
    }
}

//��ӡ����
void print()
{
    system("cls");
    printf("\n\n\n\t\t\t������ִ�д�ӡ����;");
    printf("\n\n\n\t\t\t�����˺�Ϊ��%d", ATM.id);
    printf("\n\n\n\t\t\t�����û���Ϊ��%s", ATM.name);
    printf("\n\n\n\t\t\t�������Ϊ��%f", ATM.amount);
}

//�˳�����
void quit()
{
  	system("cls");
	printf("\n\n\n\n\n\t\t\t�����˳�,���Ե�......");

    exit(0);
}

//ת�˺���
void transfer()
{
    int account, f = 0, k = ftell(fp);
    float money;
    Bank t;

    system("cls");

    printf("\n\n\n\t\t\t������ִ��ת�˲���;");
    printf("\n\n\n\t\t\t������Է��ʺţ�");

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

            printf("\n\n\n\t\t\t������ִ��ת�˲���");
            printf("\n\n\n\n\t\t\t������ת�˽�");
            scanf("%f", &money);

            if(money <= ATM.amount)
            {
                t.amount += money;
                ATM.amount -= money;

                fseek(fp, -sizeof(Bank), 1);
                fwrite(&t, 1, sizeof(Bank), fp);

                fseek(fp, k - sizeof(Bank), 0);
                fwrite(&ATM, 1, sizeof(Bank), fp);

                printf("\n\n\n\t\t\t  ת�˳ɹ���");
                printf("\n\n\t\t\t�������Ϊ��%f", ATM.amount);

                break;
            }

            printf("\n\n\n\t\t\t���㣬ת��ʧ�ܣ�");

            printf("\n\n\n\t\t\t\t�����������......");
            getch();
        }
    }
    else
    {
        fseek(fp, k, 0);
        printf("\n\n\n\t\t���˺Ų����ڻ�״̬�쳣����ȷ�Ϻ���������");
    }
}

//���뺯��
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

//ע������
void cancel()
{
	char choice;

	system("cls");

	while(1)
	{
        printf("\n\n\n\t\t\t������ʹ��ע������");
        printf("\n\n\n\t\t\t�������Ϊ��%f", ATM.amount);
        printf("\n\n\n\t\t\t�Ƿ�ȷ��ע�����˺ţ�");
        printf("\n\n\n\t\t\tע���밴[Y]��ȡ��ע���밴[N]\n\n\t\t\t\t");

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
             printf("\n\n\t\t\t����������������룡");
        }
    }
}

