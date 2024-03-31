#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10
#define LEN1 100

    int ID[LEN];
    char password[LEN][LEN1];
    float balance[LEN];
    int acc_ID;
    char acc_pass[LEN];
    int acc;

void MenuBar();

void MainLogin ()
{
     char Input[LEN];
    printf("Login into account with LOGIN \n");
    fflush(stdin);
    gets(Input);
    do {
        if (strcmp(Input,"LOGIN")==0){
        printf("Input ID ");
        scanf("%d", &acc_ID);
        printf("Input password: ");
        fflush(stdin);
        gets(acc_pass);
        if(strcmp(password[acc_ID],acc_pass)== 0)

            {
                MenuBar();
            }
                     else {
            printf("Wrong pass and ID\n");
                }
            }

        }   while(strcmp(password[acc_ID],acc_pass)!= 0);
}


void Put (int id)
{
    float deposit;
    printf("How much you want to deposit: ");
    scanf("%f", &deposit);
    balance[id] += deposit;
    printf("You deposit %.2f, your new balance is %.2f\n",deposit,balance[id]);
     MenuBar();
}
void Transfer (int id)
{
    int ID_Transfer;
    float cashout;
    printf("In the account with which ID you want to transfer your money: ");
    do {
    scanf("%d",&ID_Transfer);
    if (ID_Transfer >= acc || ID_Transfer < 0){
        printf("There is not a account with this ID\nTry again:");
    } else {
    printf("How much you want to transfer: ");
    do {
        scanf("%f", &cashout);
    if(cashout<=balance[id]){
    balance[ID_Transfer] += cashout;
    balance[id] -= cashout;
    printf("You new balance is: %.2f \n", balance[id]);
    printf("Successfully transferred\n");
    break;
    }
        else {
        printf("Sorry, you don't have enough money\n");
        printf("Your balance is %.2f, try again:", balance[id]);
        }
     } while (cashout>=balance[id]);
    }
    } while (ID_Transfer >= acc || ID_Transfer < 0);
    MenuBar();
}
void Info (int id)
{
    printf("Your balance is: %.2f\n", balance[id]);
     MenuBar();
}
void Draw (int id)
{
    float cashout;
    printf("How much you want to cashout from your acc: ");
    do {
    scanf("%f", &cashout);
    if(cashout>balance[id]){
        printf("Sorry, you don't have enough money\n");
        printf("Your balance is %.2f, try again:", balance[id]);
    } else
    {
     balance[id] -= cashout;
     printf("You successfully drew %.2f, your new balance is: %.2f\n", cashout, balance[id]);
    }
    } while (cashout>balance[id]);
    MenuBar();
}
void MenuBar()
{
    char input[LEN];
    printf("LOGOUT / DRAW / PUT / TRANSFER / INFO / EXIT \n");
            fflush(stdin);
            gets(input);
            if(strcmp(input,"LOGOUT")==0){
                    printf("You logged out from a account\n");
                    MainLogin();
               } else if(strcmp(input,"DRAW")==0){
                    Draw(acc_ID);

               } else if(strcmp(input,"PUT")==0){
                    Put(acc_ID);

               } else  if(strcmp(input,"TRANSFER")==0){
                    Transfer(acc_ID);
               } else if(strcmp(input,"INFO")==0){
                    Info(acc_ID);
               } else if(strcmp(input,"EXIT")==0){
               exit(0);
               }

        }

int main()
{
    char DATA[LEN];
    int i;
   do{
    printf("To start inputing new bank accounts type DATA:");
    gets(DATA);
    if(strcmp(DATA,"DATA")!= 0){
        printf("Invalid input. \n");
        }
   } while (strcmp(DATA,"DATA")!= 0);
    printf("How many bank accounts you want to input: ");
    scanf("%d", &acc);
    for (i=0; i<acc; i++)
    {
        ID [i] = i;
        printf("ID= %d\n", ID[i]);
        printf("Password= %s",password[i]);
        fflush(stdin);
        while (strlen(gets(password[i]))!=6){
         printf("Pass must be 6 digits, pass:  ");
        }
        printf("balance(%d)= ", i);
        scanf("%f",&balance[i]);
        while (balance[i]<=0){
         printf("Input number > 0: ");
         scanf("%f",&balance[i]);
        }
    }
    MainLogin();
    MenuBar ();
return 0;
}


