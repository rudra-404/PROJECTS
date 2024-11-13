#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

// About Function Work !

int POINT = 5;
int RANDOM;
char USER;
char COMPUTER;
char CHOICE;

void win()
{
    system("cls");
    printf("-------------| WINNER |-------------\n\n");
    printf("Congrates!!!\nYou Achived 10 Point !\n");
    printf("\nPress Any Key To Go Main Menu ... ");
    getch();
    main();
}

void defate()
{
    system("cls");
    printf("-------------| LOOSER |-------------\n\n");
    printf("You Lost All The Points !\n");
    printf("\nPress Any Key To Go Main Menu ... ");
    getch();
    main();
}

void result()
{
    srand(time(NULL));
    COMPUTER = 48 + (rand()%3) + 1;
    if(USER=='1' && COMPUTER=='1')
    {
        printf("\n----------| Draw |----------\n");
        printf("\nYour Choice \'ROCK\'\n");
        printf("Computers Choice \'ROCK\'\n");
        printf("\nYou Got 0 Point !\n");
    }
    else if(USER=='1' && COMPUTER=='2')
    {
        printf("\n---------| Defate |---------\n");
        printf("\nYour Choice \'ROCK\'\n");
        printf("Computers Choice \'PAPER\'\n");
        printf("\nYou Got -1 Point !\n");
        POINT--;
    }
    else if(USER=='1' && COMPUTER=='3')
    {
        printf("\n-----------| Win |----------\n");
        printf("\nYour Choice \'ROCK\'\n");
        printf("Computers Choice \'SCISSOR\'\n");
        printf("\nYou Got 1 Point !\n");
        POINT++;
    }
    else if(USER=='2' && COMPUTER=='1')
    {
        printf("\n-----------| Win |----------\n");
        printf("\nYour Choice \'PAPER\'\n");
        printf("Computers Choice \'ROCK\'\n");
        printf("\nYou Got 1 Point !\n");
        POINT++;
    }
    else if(USER=='2' && COMPUTER=='2')
    {
        printf("\n----------| Draw |----------\n");
        printf("\nYour Choice \'PAPER\'\n");
        printf("Computers Choice \'PAPER\'\n");
        printf("\nYou Got 0 Point !\n");
    }
    else if(USER=='2' && COMPUTER=='3')
    {
        printf("\n---------| Defate |---------\n");
        printf("\nYour Choice \'PAPER\'\n");
        printf("Computers Choice \'SCISSOR\'\n");
        printf("\nYou Got -1 Point !\n");
        POINT--;
    }
    else if(USER=='3' && COMPUTER=='1')
    {
        printf("\n---------| Defate |---------\n");
        printf("\nYour Choice \'SCISSOR\'\n");
        printf("Computers Choice \'ROCK\'\n");
        printf("\nYou Got -1 Point !\n");
        POINT--;
    }
    else if(USER=='3' && COMPUTER=='2')
    {
        printf("\n-----------| Win |----------\n");
        printf("\nYour Choice \'SCISSOR\'\n");
        printf("Computers Choice \'PAPER\'\n");
        printf("\nYou Got 1 Point !\n");
        POINT++;
    }
    else if(USER=='3' && COMPUTER=='3')
    {
        printf("\n----------| Draw |----------\n");
        printf("\nYour Choice \'SCISSOR\'\n");
        printf("Computers Choice \'SCISSOR\'\n");
        printf("\nYou Got 0 Point !\n");
    }
    printf("\nPress Any Key To Play Again ... ");
    getch();
    play();
}

void play()
{
    system("cls");
    if(POINT==10) win();
    if(POINT==0) defate();
    printf("----------| PLAY |----------\n\n");
    printf("\t Point = %02d\n\n", POINT);
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissor\n");
    user_choice:
    printf("\nEnter Your Choice >>> ");
    scanf(" %c", &USER);
    if(USER=='1' || USER=='2' || USER=='3') result();
    else
    {
        printf("\nInvalid Choice !\n");
        goto user_choice;
    }
}

void about()
{
    system("cls");
    printf("------------------| How To Play |------------------\n\n");
    printf("1. At Starting, You Will Get 5 Point\n");
    printf("2. If You Win, You Will Get 1 Point\n");
    printf("3. If You Defate, You Will Lose 1 Point\n");
    printf("4. If it\'s draw, You Will Not Get Any Point\n");
    printf("5. If You Achive 10 Point, You Will Be The WINNER\n");
    printf("6. If You Lose All Point, You Will Be The LOSER\n\n");
    printf("-------------------| Conditions |------------------\n\n");
    printf("1. Rock Vs Paper -------------------------> Paper\n");
    printf("2. Paper Vs Scissor ----------------------> Scissor\n");
    printf("3. Scissor Vs Rock -----------------------> Rock\n");
    printf("4. Paper Vs Scissor ----------------------> Scissor\n");
    printf("\nPress Any Key To Go Main Menu ... ");
    getch();
    main();
}

void menu()
{
    system("cls");
    printf("--------| Main Menu |--------\n\n");
    printf("1. Play\n");
    printf("2. About\n");
    printf("3. Exit\n");
    user_choice:
    printf("\nEnter Your Choice >>> ");
    scanf(" %c", &CHOICE);
    if(CHOICE=='1') play();
    else if(CHOICE=='2') about();
    else if(CHOICE=='3')
    {
        system("cls");
        printf("---------| Game Over |---------\n\n");
        printf("Thank You !\n\n");
        getch();
        exit(0);
    }
    else
    {
        printf("\nInvalid Choice !\n");
        goto user_choice;
    }
}

int main()
{
    menu();
    return 0;
}