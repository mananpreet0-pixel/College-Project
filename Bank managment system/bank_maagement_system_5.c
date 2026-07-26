#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct acc
{
    char name[50];
    int acc_no;
    char pass[20];
    int balance;
};
int amount;

void create_account();
void deposit(int acc_no);
void log_in();
void withdraw(int acc_no);
void transfer(int acc_no);
void display(int acc_no);
void transaction_detail(int acc_no);
void last_detail(int acc_no);
void menu();
int checkpassword(char pass[]);
int length(char str[]);
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n========================================================================================================================\n");
        printf("                                                  WELCOME TO BANK\n");
        printf("========================================================================================================================\n");
        printf("1. Create new account\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("========================================================================================================================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {   
            case 1:
                printf("\n>> Creating Account...\n");
                create_account();
                break;
            case 2:
                printf("\n>> Logging In...\n");
                log_in();
                break;
            case 3:
                printf("\nThank you for using our Bank\n");
                exit(0);
            default: 
                printf("Invalid Choice!\n");
        }
    }
}

void menu()
{
    printf("\n\n========================================================================================================================\n");
    printf("                                                       ACCOUNT MENU");
    printf("\n========================================================================================================================\n");
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Display Account\n");
    printf("5. Transaction Detail\n");
    printf("6. log out\n");
    printf("========================================================================================================================\n");
}
void log_in()
{   
    printf("\n\n==========================================================\n");
    printf("                         LOG IN");
    printf("\n==========================================================\n");
    struct acc user;
    char pass[7];
    int found= 0;
    int acc_no;
    printf("Enter account number:");
    scanf("%d",&acc_no);
    int attempts = 0;
    while(attempts < 3)
    {

    printf("Enter password:");
    scanf("%6s",pass);
    FILE *fp = fopen("lAccount.dat", "rb");
        if(fp == NULL)
        {
            printf("File not found error!\n");
            return;
        }
    found = 0;
    while(fread(&user, sizeof(user), 1, fp))
    {
        if(user.acc_no==acc_no && (strcmp(user.pass,pass))==0)
        {
            found=1;
            break;
        }
    }
    fclose(fp);
    if(found)
         break;
    attempts++;
    printf("Wrong password! Attempts left: %d\n", 3 - attempts);
    }
    if(!found)
    {
        printf("Invalid Account Number or Password!\n");
        return;
    }
    printf("\nLogin Successful!\nWelcome %s\n", user.name);
    printf("\n===========================================================\n");
    int cho;
    while(1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d",&cho);
        switch (cho)
        {

            case 1: 
                deposit(acc_no); 
                break;
            case 2: 
                withdraw(acc_no); 
                break;
            case 3: 
                transfer(acc_no); 
                break;
            case 4: 
                display(acc_no); 
                break;
            case 5: 
                transaction_detail(); 
                break;
            case 6: 
                last_detail(acc_no); 
                return;
            default:
                printf("Invalid option");
            }
    }
}
void create_account()
{   
    printf("\n\n==========================================================\n");
    printf("                      CREATE ACCOUNT");
    printf("\n==========================================================\n");
    struct acc user;
    printf("Enter Name: ");
    scanf(" %[^\n]",user.name);
    printf("Enter Account Number: ");
    scanf("%d",&user.acc_no);
    if(user.acc_no <= 0)
    {
        printf("Invalid Account Number!\n");
        return;
    }
    FILE *check = fopen("lAccount.dat","rb");
    if(check!=NULL)
    {
    struct acc temp;
    while(fread(&temp,sizeof(temp),1,check))
    {
        if(temp.acc_no == user.acc_no)
        {
            printf("Account Number Already Exists!\n");
            fclose(check);
            return;
        }
    }
    fclose(check);
    }
    while(1)
    {
    int valid = 1;
    char ch;
    printf("Enter 6 digit password(numbers from 0-9):");
    scanf("%20s",user.pass);
    if((ch = getchar()) != '\n')
    {
        valid = 0;
        while(getchar() != '\n');
    }
    if(strlen(user.pass) != 6)
        valid = 0;
    else
    {
        for(int i=0;i<6;i++)
        {
            if(user.pass[i] < '0' || user.pass[i] > '9')
            {
                valid = 0;
                break;
            }
        }
    }

    if(valid)
        break;
    else
        printf("Invalid Password! Enter exactly 6 digits using numbers only.\n");
    }
    if(checkpassword(user.pass))
    {
        printf("Password should not be consecutive numbers or repeated numbers like 123456,111 !!!\n");
        return;
    }
    printf("Enter Initial Balance: ");
    scanf("%d",&user.balance);
    if(user.balance < 0)
    {
        printf("Balance cannot be negative!\n");
        return;
    }
    FILE *fp = fopen("lAccount.dat","ab");
    if(fp == NULL)
    {
        printf("File error!\n");
        return;
    }
    fwrite(&user,sizeof(user),1,fp);
    fclose(fp);
    printf("Account Created Successfully!\n");
    printf("\n==========================================================\n");

}
void deposit(int acc_no)
{
    printf("\n\n==========================================================\n");
    printf("                       DEPOSIT MONEY");
    printf("\n==========================================================\n");
    struct acc user;
    int found = 0;
    FILE *fp = fopen("lAccount.dat","rb+");
    if(fp == NULL)
    {
        printf("No account found!\n");
        return;
    }
    while(fread(&user,sizeof(user),1,fp))
    {
        if(user.acc_no == acc_no)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%d",&amount);
            if(amount <= 0)
            {
                printf("Invalid deposit amount!\n");
                fclose(fp);
                return;
            }
            user.balance += amount;
            fseek(fp,-sizeof(user),SEEK_CUR);
            fwrite(&user,sizeof(user),1,fp);
            FILE *log = fopen("lTransaction.txt","a");
            time_t t = time(NULL);
            fprintf(log,"Deposited %d in Acc %d | %s",amount,acc_no,ctime(&t));
            fclose(log);
            printf("Deposit Successful!\n");
            printf("Updated Balance: %d\n",user.balance);
            found = 1;
            break;
        }
    }
    if(!found)
    printf("Account Not Found!\n");
    fclose(fp);
    printf("\n==========================================================\n");
}

void withdraw(int acc_no)
{
    printf("\n\n==========================================================\n");
    printf("                      WITHDRAW MONEY");
    printf("\n==========================================================\n");
    struct acc user;
    int amount, found = 0;
    FILE *fp = fopen("lAccount.dat","rb+");
    if(fp == NULL)
    {
        printf("No account found!\n");
        return;
    }
    while(fread(&user,sizeof(user),1,fp))
    {
        if(user.acc_no == acc_no)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%d",&amount);
            if(amount <= 0)
            {
                printf("Invalid withdrawal amount!\n");
                fclose(fp);
                return;
            }
            if(amount > user.balance)
            {
                printf("Insufficient Balance!\n");
                fclose(fp);
                return;
            }
            user.balance -= amount;
            fseek(fp,-sizeof(user),SEEK_CUR);
            fwrite(&user,sizeof(user),1,fp);
            FILE *log = fopen("lTransaction.txt","a");
            time_t t = time(NULL);
            fprintf(log,"Withdrawn %d from Acc %d | %s",amount,acc_no,ctime(&t));
            fclose(log);
            printf("Withdrawal Successful!\n");
            printf("Updated Balance: %d\n",user.balance);
            found = 1;
            break;
        }
    }
    if(!found)
    printf("Account Not Found!\n");
    fclose(fp);
    printf("\n==========================================================\n");
}
void transfer(int acc_no)
{
    printf("\n\n==========================================================\n");
    printf("                      TRANSFER MONEY");
    printf("\n==========================================================\n");
    struct acc user1, user2;
    int from = acc_no, to, amount;
    int found1 = 0, found2 = 0;
    FILE *fp = fopen("lAccount.dat","rb+");
    if(fp == NULL)
    {
        printf("No account found!\n");
        return;
    }
    printf("Enter Receiver Account Number: ");
    scanf("%d",&to);
    printf("Enter Amount to Transfer: ");
    scanf("%d",&amount);
    rewind(fp);
    if(from == to)
    {
        printf("Cannot transfer to same account!\n");
        fclose(fp);
        return;
    }
    while(fread(&user1,sizeof(user1),1,fp))
    {
        if(user1.acc_no == from)
        {
            found1 = 1;
            break;
        }
    }
    rewind(fp);
    while(fread(&user2,sizeof(user2),1,fp))
    {
        if(user2.acc_no == to)
        {
            found2 = 1;
            break;
        }
    }
    if(found1 == 0 || found2 == 0)
    {
        printf("Transfer Failed! Account Not Found\n");
        fclose(fp);
        return;
    }
    if(amount <= 0)
    {
        printf("Invalid transfer amount!\n");
        fclose(fp);
        return;
    }
    if(amount > user1.balance)
    {
        printf("Insufficient Blance !\n");
        fclose(fp);
        return;
    }
    rewind(fp);
    while(fread(&user1,sizeof(user1),1,fp))
    {
        if(user1.acc_no == from)
        {
            user1.balance -= amount;
            fseek(fp,-sizeof(user1),SEEK_CUR);
            fwrite(&user1,sizeof(user1),1,fp);
            break;
        }
    }
    rewind(fp);
    while(fread(&user2,sizeof(user2),1,fp))
    {
        if(user2.acc_no == to)
        {
            user2.balance += amount;
            fseek(fp,-sizeof(user2),SEEK_CUR);
            fwrite(&user2,sizeof(user2),1,fp);
            break;
        }
    }
    FILE *log = fopen("lTransaction.txt","a");
    time_t t = time(NULL);
    fprintf(log,"Transferred %d from %d to %d | %s",amount,from,to,ctime(&t));
    fclose(log);
    printf("Transfer Successful!\n");
    fclose(fp);
    printf("\n==========================================================\n");
}
void display(int acc_no)
{
    struct acc user;
    int found = 0;
    FILE *fp = fopen("lAccount.dat","rb");
    if(fp == NULL)
    {
        printf("No account found!\n");
        return;
    }
    while(fread(&user,sizeof(user),1,fp))
    {
        if(user.acc_no == acc_no)
        {
            printf("\n\n===========================================================\n");
            printf("                       ACCOUNT DETAILS");
            printf("\n===========================================================\n");
            printf("Name: %s\n",user.name);
            printf("Account Number: %d\n",user.acc_no);
            printf("Balance: %d\n",user.balance);
            found = 1;
            printf("\n===========================================================\n");
            break;
        }
    }
    if(!found)
        printf("Account Not Found!\n");
    fclose(fp);
}
void transaction_detail(int acc_no)
{
    FILE *fp = fopen("lTransaction.txt","r");
    if(fp == NULL)
    {
        printf("No transaction history found!\n");
        return;
    }
    char line[200];
    int found = 0;
    printf("\n\n==========================================================\n");
    printf("                YOUR TRANSACTION DETAILS");
    printf("\n==========================================================\n");
    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, "Acc"))
        {
            char temp[20];
            sprintf(temp, "%d", acc_no);

            if(strstr(line, temp))
            {
                printf("%s", line);
                found = 1;
            }
        }
    }
    if(!found)
    {
        printf("No transactions found for this account.\n");
    }
    fclose(fp);
    printf("==========================================================\n");
}
void last_detail(int acc_no)
{
    printf("\n\n========================================================================================================================\n");
    printf("                                                FINAL SUMMARY");
    printf("\n========================================================================================================================\n");
    display(acc_no);
    printf("\nThank you for using Bank Management System!\n");
    printf("\n=======================================================================================================================\n");
}
int length(char str[])
{
    int i=0;
    while (str[i]!='\0')
    {
        i++;
    }
    return i;
}
int checkpassword(char pass[])
{
    int i, j;
    int same = 1;
    int arithmetic = 1;
    int unique = 1;
    int pattern = 0;
    int partial = 0;
    int len = length(pass);
    int diff = pass[1] - pass[0];
    for(i = 0; i < len - 1; i++)
    {
        if(pass[i] != pass[i+1])
            same = 0;

        if(pass[i+1] - pass[i] != diff)
            arithmetic = 0;
    }
    for(i = 1;i < len;i++)
    {
        int new = 1;
        for(j = 0;j < i;j++)
        {
            if(pass[i] == pass[j])
            {
                new = 0;
                break;
            }
        }

        if(new == 1)
            unique++;
    }

    for(int p = 2;p <= len/2;p++)
    {
        int valid = 1;

        for(i = 0;i < len;i++)
        {
            if(pass[i] != pass[i % p])
            {
                valid = 0;
                break;
            }
        }

        if(valid == 1)
        {
            pattern = 1;
            break;
        }
    }
    for(i = 0;i < len - 2;i++)
    {
        if(pass[i+1] == pass[i] + 1 &&
           pass[i+2] == pass[i] + 2)
        {
            partial = 1;
            break;
        }
    }
    if(same == 1)
    {
        return 1;
    }
    if(arithmetic == 1)
    {
        return 1;
    }
    if(unique < 3)
    {
        return 1;
    }
    if(pattern == 1)
    {
        return 1;
    }
    if(partial == 1)
    {
        return 1;
    }

    return 0;
}