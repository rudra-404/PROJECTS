#include<stdio.h>
#include<conio.h>

int total_amount = 0;
int total_vehicle = 0;

int number_of_car = 0;
int number_of_bike = 0;
int number_of_cycle = 0;

int charge_of_car = 100;
int charge_of_bike = 50;
int charge_of_cycle = 20;

char choice;

void car()
{
	system("cls");
	int car;
	printf("--------------| Enter Car |--------------\n\n");
	printf("How Many CAR Do You Want To Add >>> ");
	scanf("%d", &car);
	number_of_car += car;
	total_vehicle += car;
	total_amount += (car * charge_of_car);
	printf("\n%d Car Added !\n", car);
	printf("\nPress ENTER To Go Main Menu ... ");
	getch();
	main();
}

void bike()
{
	system("cls");
	int bike;
	printf("--------------| Enter Bike |--------------\n\n");
	printf("How Many BIKE Do You Want To Add >>> ");
	scanf("%d", &bike);
	number_of_bike += bike;
	total_vehicle += bike;
	total_amount += (bike * charge_of_bike);
	printf("\n%d Bike Added !\n", bike);
	printf("\nPress ENTER To Go Main Menu ... ");
	getch();
	main();
}

void cycle()
{
	system("cls");
	int cycle;
	printf("--------------| Enter Cycle |--------------\n\n");
	printf("How Many CYCLE Do You Want To Add >>> ");
	scanf("%d", &cycle);
	number_of_cycle += cycle;
	total_vehicle += cycle;
	total_amount += (cycle * charge_of_cycle);
	printf("\n%d Cycle Added !\n", cycle);
	printf("\nPress ENTER To Go Main Menu ... ");
	getch();
	main();
}

void ststus()
{
	system("cls");
	printf("--------------| Details |--------------\n\n");
	printf("Total Car      = %d\n", number_of_car);
	printf("Total Bike     = %d\n", number_of_bike);
	printf("Total Cycle    = %d\n", number_of_cycle);
	printf("Total Vehicle  = %d\n", total_vehicle);
	printf("Total Amount   = %d Taka\n", total_amount);
	printf("\nPress ENTER To Go Main Menu ... ");
	getch();
	main();
}

void reset()
{
	char delete_permission;
	system("cls");
	printf("------------------| Reset Data |------------------\n\n");
	printf("press \'y\' For YES\n");
	printf("press \'n\' For NO\n");
	permission_for_deleting:
	printf("\nDo You Want To Delete All Data (y/n) >>> ");
	scanf(" %c", &delete_permission);
	if(delete_permission=='y')
	{
		total_amount = 0;
		total_vehicle = 0;
		number_of_car = 0;
		number_of_bike = 0;
		number_of_cycle = 0;
		printf("\nYour Choice Is To Delete All The Data ! Done !\n");
	}
	else if(delete_permission=='n')
	{
		printf("\nYour Choice Is NOT To Delete The Data !\n");
	}
	else
	{
		printf("\nInvalid Input !\n");
		goto permission_for_deleting;
	}
	printf("\nPress ENTER To Go Main Menu ... ");
	getch();
	main();
}

void menu()
{
	system("cls");
	printf("--------------| Main Menu |--------------\n\n");
	printf("1. Enter Car\n");
	printf("2. Enter Bike\n");
	printf("3. Enter Cycle\n");
	printf("4. Show Details\n");
	printf("5. Reset Data\n");
	printf("6. Exit\n");
}

int main()
{
	while(1)
	{
		menu();
		user_choice:
		printf("\nEnter Your Choice >>> ");
		scanf(" %c", &choice);
		if(choice=='1') car();
		else if(choice=='2') bike();
		else if(choice=='3') cycle();
		else if(choice=='4') ststus();
		else if(choice=='5') reset();
		else if(choice=='6')
		{
			printf("\nThank You !\n\n");
			getch();
			exit(0);
		}
		else
		{
			printf("\nInvalid Choice !\n");
			goto user_choice;
		}
	}
}
