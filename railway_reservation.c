#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[70];
	int train_num;
	int num_of_seats;
}ad;

void reservation(void);
void cancel(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void login();

int main()
{
    system("cls");
	printf("\n|        ------------------------------------        |\n");
	printf("\n|           Welcome to Railway Reservasion           |\n");
	printf("\n|        ------------------------------------        |\n");
	printf(" \n Press any key to continue: ");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("     ...TRAIN RESERVATION SYSTEM...     \n");
	printf("\n 1. Reserve A Ticket\n");
	printf("\n 2. View All Available Trains\n");
	printf("\n 3. Cancel Reservation\n");
	printf("\n 4. Exit\n");
	printf("\n\n");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu  ");
			getch();
			break;
		case 3:
			cancel();
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice!!!!");
	}
	goto start;
	return(0);
}

void login()/*password*/
{
	int a=0,i=0;
    char uname[15],c=' ';
    char passw[15],code[10];
    char user[15]="foysal";
    char pass[15]="1234";
    do
{

    printf("\n****************************************************************\n");
    printf("\n  ..........................LOGIN FORM..........................\n  ");
    printf("\n****************************************************************\n");
    printf(" \n       ENTER USERNAME: ");
	scanf("%s", &uname);
	printf(" \n       ENTER PASSWORD: ");
	while(i<10)
	{
	    passw[i]=getch();
	    c=passw[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	passw[i]='\0';

	i=0;

		if(strcmp(uname,"foysal")==0 && strcmp(passw,"1234")==0)
	{
	printf("  \n\n\n    ....Welcome to Railway Reservasion....\n\n YOUR LOGIN IS SUCCESSFUL\n");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n\tSORRY!!!!  USER NAME OR PASSWORD ERROR!!!!");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void viewdetails(void)
{
	system("cls");
	printf("\nTrain No\tName\t\t\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("................................................................................");
	printf("\n101\tSilkcity Express\t\t\tRajshahi to Komalapur\t\t420 tk\t\t8:30 am");
	printf("\n102\tPadma Express\t\t\t    \tRajshahi To Iswardi   \t\t150 tk\t\t9:00 pm");
	printf("\n103\tParbotipur Express\t\t\tRajshahi To Dinaajpur\t\t220 tk\t\t6:00 pm");
	printf("\n100\tBanolota Express\t\t\tRajshahi To Dhaka\t\t500 tk\t\t6:00 am");

}

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;

	ad passdetails;
	FILE *fp;
	fp=fopen("seats_reserved","a");
	system("cls");
	printf("\nPlease Enter Your Name: ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\nEnter the number of seats: ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n..Press Enter to View Available Trains... ");

	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number: ");

	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=100 && passdetails.train_num<=103)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number!!! \nPress Enter: ");
		goto start1;
	}
	printf("\n\nConfirm Ticket (y/n): ");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("\n Reservation is done \n\n\n");
		printf("\npress any key to go back to main menu...");
	}
	else
	{
		if(confirm=='n')

            {
			printf("\nReservation Not Done!!! \nPress any key to go back to  Main menu...");

		    }
		else
		{
			printf("\nInvalid choice entered!!! Enter again:  ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int train_num,int num_of_seats)
{
		if (train_num ==100)
	{
		return(500.0*num_of_seats);
	}
	if (train_num==101)
	{
		return(420.0*num_of_seats);
	}
	if (train_num==102)
	{
		return(150.0*num_of_seats);
	}
	if (train_num==103)
	{
		return(220.0*num_of_seats);
	}
}
void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats: \t%d",num_of_seats);
	printf("\nTrain Number: \t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

void specifictrain(int train_num)
{

	if (train_num==100)
	{
		printf("\nTrain:\t\t\tBanolota Express");
		printf("\nDestination:\t\tRajshahi To Dhaka");
		printf("\nDeparture:\t\t6:00 am ");
	}
	if (train_num==101)
	{
		printf("\nTrain:\t\t\tSilkcity Express");
		printf("\nDestination:\t\tRajshahi to Komalapur");
		printf("\nDeparture:\t\t9:00 pm");
	}
	if (train_num==102)
	{
		printf("\nTrain:\t\t\tPadma Express");
		printf("\nDestination:\t\tRajshahi To Iswardi");
		printf("\nDeparture:\t\t9:00 pm");
	}
	if (train_num==103)
	{
		printf("\nTrain:\t\t\tParbotipur Express");
		printf("\nDestination:\t\tRajshahi To Dinaajpur");
		printf("\nDeparture:\t\t6:00 pm ");
	}
}

void cancel(void)
{
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled!!!");
		getch();
}





