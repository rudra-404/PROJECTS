#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

FILE *file;
char choice;
char name[20];
char number[20];

void add_a_number()
{
    system("cls");
    printf("------------| Add A Number |------------\n");
    add_a_number:
    printf("\nName   : ");
    getchar();
    gets(name);
    printf("Number : ");
    gets(number);
    file = fopen("contacts.txt","a");
    if(file!=NULL)
    {
        fputs("Name   : ", file);
        fputs(name, file);
        fputs("\nNumber : ",file);
        fputs(number, file);
        fputs("\n\n", file);
        fclose(file);
        printf("\nNumber Added Successfully !\n");
        user_choice:
        printf("\nAdd An Another Number (y/n) >>> ");
        scanf(" %c", &choice);
        if(choice=='y') goto add_a_number;
        else if(choice=='n')
        {
            printf("\nPress Any Key To Go Main Menu ... ");
            getch();
            menu();
        }
        else
        {
            printf("\nInvalid Choice !\n");
            goto user_choice;
        }
    }
    else
    {
        printf("\nSorry ! \'contacts.txt\' File Not Found !\n");
        printf("\nPress Any Key To Go Main Menu ... ");
        getch();
        menu();
    }
}

void menu()
{
    system("cls");
    printf("---------| Phone Number Notes |---------\n\n");
    printf("1. Add A Number\n");
    printf("2. Exit\n");
    user_choice:
    printf("\nEnter Your Choice >>> ");
    scanf(" %c", &choice);
    switch(choice)
    {
        case '1':
        add_a_number();

        case '2':
        printf("\nThank You !\n\n");
        getch();
        exit(0);

        default:
        printf("\nInvalid Choice !\n");
        goto user_choice;
    }
}

int main()
{
    menu();
    return 0;
}