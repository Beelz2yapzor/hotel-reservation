#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void gotoxy(int x, int y)//function used for cursor positioning
{
	COORD CR;
	CR.X = x;
	CR.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

int big;
option_menu() 
{
 	while (1) /*to loop the program*/
	{
		int v;
		system("cls"); 
		printf(" \n\n  ******************************  |HOTEL SMALL DIDI LOGIN OR SIGN UP PAGE|  ***************************** \n");
		printf("\t\t\t --Please enter your choice for menu:--");
		printf("\n\n 1. Login");
		printf("\n------------------------");
		printf("\n\n 2. Register");
		printf("\n------------------------");
		printf("\n\n 3. Admin Login");
		printf("\n------------------------");
		printf("\n\n 4. Exit");
		printf("\n------------------------");
		printf("\n");
		scanf("%d", &v);
		{
			if (v == 1)
			{
				login();
				break;
			}
			else if (v == 2)
				registerL();
			else if (v == 3)
				adminlogin();
			else if (v == 4)
				return 0;
			else
				printf("\n\n Invalid input please try again");
			_getch();
		}
	}
	return big;
}
login()

{
	char dummy[100];
	char uname[100];
	char pword[100];
	char user[100];
	char pass[100];
	int flag = 0;
	FILE *loginfile; /* to initialize the file*/
	
	loginfile = fopen("loginform.txt", "a+");
	printf("\n\n  ******************************|SMALL DIDI HOTEL LOGIN MAIN PAGE|****************************** \n");
	printf("\n  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf("\n  ENTER PASSWORD:-");
	scanf("%s", &pword);
	while (fscanf(loginfile, "%s %s\n", &user, &pass) != EOF) /*to scan data from the file*/
	{
		if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) /*to compare two strings*/
		{
			printf(" \n\n ****************************** |LOGIN SUCESSFUL| ****************************** \n");
			system("cls");
			printf(" \t\t  --------------------------------------------------------------------------------\n");
			printf("\t\t  |                                                                              |\n");
			printf("\t\t  |                                                                              |\n");
			printf("\t\t  |       OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
			printf("\t\t  |       O        O    O O      O        O      O    O O    O O        O        |\n");
			printf("\t\t  |       O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
			printf("\t\t  |       O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
			printf("\t\t  |       OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
			printf("\t\t  |                                                                              |\n");
			printf("\t\t\  --------------------------------------------------------------------------------\n");
			printf("\t\t\t\t  *************************************************\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *         -----------------------------         *\n");
			printf("\t\t\t\t  *          WELCOME TO HOTEL SMALL DIDI          *\n");
			printf("\t\t\t\t  *         -----------------------------         *\n");
			printf("\t\t\t\t  *             LOGIN SUCCESSFUL!!!               *\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *                                               *\n");
			printf("\t\t\t\t  *************************************************\n\n\n");
			printf("\t\t\t\t Press any button to continue with booking............\n");
			_getch();
			big = 1;
			flag = 1;
		}
		if (flag == 1) /* a boolean true of false value*/
			break;
	}
	fclose(loginfile);  /*to close the file*/
	if (flag == 0)
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
		printf("\n Enter any key and press enter to exit : ");
		scanf("%s", dummy); /* this is to hold the screen to show that login is unsuccessful as the getch was quite buggy and could not hold the screen*/
		option_menu();
	}
	if (big == 1)
	{
		main_menu();
	}
	_getch();
}
registerL()
{
	char uname[100];
	char pword[100];
	printf("\n  ******************************|SMALL DIDI HOTEL REGISTER PAGE|****************************** \n");
	printf("\n  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf("\n  ENTER PASSWORD:-");
	scanf("%s", &pword);
	printf("\n Register Succesful, You are now ready to start booking :) ");
	FILE *loginfile;
	loginfile = fopen("loginform.txt", "a+");
	fprintf(loginfile, "%s %s\n", uname, pword); /*to print the data in to file*/
	fclose(loginfile);
	_getch();
}
adminlogin()
{
	char dummy[100];
	char username[100];
	char password[100];
	char admin[1000] = "admin";
	char adminpassword[1000] = "adminpassword";
	printf("\n\n  ******************************|SMALL DIDI HOTEL ADMIN LOGIN MAIN PAGE|****************************** \n");
	printf("\n  ENTER USERNAME:-");
	scanf("%s", &username);
	printf("\n  ENTER PASSWORD:-");
	scanf("%s", &password);
	if (strcmp(username,"admin")==0 && strcmp(password,"admin12345")==0)
	{
		printf("\n Login successful ");
		printf("\n **********WELCOME BACK SIR*********");
		printf("\n Press any key and enter to go back to main menu : ");
		scanf("%s", &dummy);
		admin_menu();
	}
	
}
struct CustomerDetails   //STRUCTURE DECLARATION
{
	int roomnumber;
	char name[20];
	char nationalID[20];
	char gender[15];
	char checkin[100];
	char checkout[100];
	char age[35];
	int cid, cim, ciy, cod, com, coy;
	int ymdci, ymdco;
};

main()
{
	option_menu();
}

main_menu()
{
	while (1)
	{
		struct CustomerDetails s; /*to initialize the structure*/
		struct CustomerDetails s1;
		char dummy[1000];
		int choice;
		system("cls");
		printf("-");
		printf("\n");
		printf("   **********************************  |MAIN MENU|  ******************************** \n");
		printf("-");
		printf("\n");
		printf("\t\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room  **|Book the room we offer here|**");
		printf("\n----------------------------------------------------------");
		printf(" \n Enter 2 -> View Rooms That Has Been Booked **|Look at rooms that has been booked|**");
		printf("\n-----------------------------------------------------------------------------");
		printf(" \n Enter 3 -> Cancel A room **|Cancel the room you haved booked|**");
		printf("\n---------------------------------------------------------------");
		printf(" \n Enter 4 -> Modify Your Room **|Modify personal details and booking date|**");
		printf("\n---------------------------------------------------------------------");
		printf(" \n Enter 5 -> Exit");
		printf("\n-----------------");
		printf("\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			int roomtype;
			M: /* to point where to make an uncoditional jump*/
			system("cls");
			printf("\t\t *Please enter your choice for menu*:");
			printf("\n\n");
			printf(" \n Enter 1 -> Single Room **|A room assigned to ONE person. May have one or more beds.|**");
			printf("\n------------------------------------------------------------------------------");
			printf(" \n Enter 2 -> Double Room **|A room assigned to TWO people. May have one or more beds.|**");
			printf("\n------------------------------------------------------------------------------");
			printf(" \n Enter 3 -> Quad Room **|A room assigned to FOUR people. May have two or more beds.|**");
			printf("\n-------------------------------------------------------------------------------");
			printf(" \n Enter 4 -> Queen Room **|A room with a QUEEN-sized bed. May be occupied by one or more people|**");
			printf("\n-------------------------------------------------------------------------------");
			printf(" \n Enter 5 -> King Room **|A room with a KING-sized bed. May be occupied by one or more people.|**");
			printf("\n------------------------------------------------------------------------------");
			printf(" \n Enter 6 -> Exit to main menu");
			printf("\n\nEnter choice here : ");
			scanf("%d", &roomtype);
			printf("\n\n\tRoom type selected is : %d", roomtype);
			if (roomtype == 1)
			{
				FILE *f;
				f = fopen("booking.txt", "a+");
				printf("\n\nRoom selected is Single Room");
				printf("\n Please enter your details");
				printf("\n Please enter roomnumber in range of (1-10) : ");
				scanf("%d", &s.roomnumber);
				if (s.roomnumber > -1 && s.roomnumber < 11) /* to restrict users from input number more than 10 and less than 1*/
				{
					printf("\n Please enter your day of check in : ");
					scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
					printf("\n Please enter your day of checking out : ");
					scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
					s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid; /* this is to change the how the date is arranged from dd/mm/yy to yy/mm/dd*/
					s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
						if (s.roomnumber == s1.roomnumber &&
							((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
								|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco)))/* this is to restrict user from booking rooms that are not available on that day*/
						{
							printf("\nThis is room booked");
							_getch(); _getch();
							goto M; /* to make the jump to M*/
						}
					printf("\n Please enter your name : ");
					scanf("%s", &s.name);
					printf("\n Please enter your ID number : ");
					scanf("%s", &s.nationalID);
					printf("\n Please enter your gender : ");
					scanf("%s", &s.gender);
					printf("\n Please enter your age : ");
					scanf("%s", &s.age);



					fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);

					fclose(f);
					printf("\n Your room has been successfully booked");
					printf("\n Press any key and enter to go back to main menu : ");
					scanf("%s", dummy);
				} 
				else if (s.roomnumber > 10)
				{
					printf("invalid number");
					scanf("%s", dummy);
				}

				
				
			}
			else if (roomtype == 2)
			{
				FILE *f;
				f = fopen("booking.txt", "a+");
				printf("\n\nRoom selected is Double Room");
				printf("\n Please enter your details");
				printf("\n Please enter roomnumber in range of (11-20) : ");
				scanf("%d", &s.roomnumber);
				if (s.roomnumber > 10 && s.roomnumber < 21)
				{
					printf("\n Please enter your day of check in : ");
					scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
					printf("\n Please enter your day of checking out : ");
					scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
					s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
					s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
						if (s.roomnumber == s1.roomnumber &&
							((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
								|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco)))
						{
							printf("\nThis is room booked");
							_getch(); _getch();
							goto M;
						}
					printf("\n Please enter your name : ");
					scanf("%s", &s.name);
					printf("\n Please enter your ID number : ");
					scanf("%s", &s.nationalID);
					printf("\n Please enter your gender : ");
					scanf("%s", &s.gender);
					printf("\n Please enter your age : ");
					scanf("%s", &s.age);

					fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);

					fclose(f);
					printf("\n Your room has been successfully booked");
					printf("\n Press any key and enter to go back to main menu : ");
					scanf("%s", dummy);
				}
				else if (s.roomnumber > 20)
				{
					printf("invalid number");
					scanf("%s", dummy);
				}
				
			}
			else if (roomtype == 3)
			{
				FILE *f;
				f = fopen("booking.txt", "a+");
				printf("\n\nRoom selected is Quad Room");
				printf("\n Please enter your details");
				printf("\n Please enter roomnumber in range of (21-30) : ");
				scanf("%d", &s.roomnumber);
				if (s.roomnumber > 20 && s.roomnumber < 31)
				{
					printf("\n Please enter your day of check in : ");
					scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
					printf("\n Please enter your day of checking out : ");
					scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
					s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
					s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
						if (s.roomnumber == s1.roomnumber &&
							((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
								|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco)))
						{
							printf("\nThis is room booked");
							_getch(); _getch();
							goto M;
						}
					printf("\n Please enter your name : ");
					scanf("%s", &s.name);
					printf("\n Please enter your ID number : ");
					scanf("%s", &s.nationalID);
					printf("\n Please enter your gender : ");
					scanf("%s", &s.gender);
					printf("\n Please enter your age : ");
					scanf("%s", &s.age);


					fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);

					fclose(f);
					printf("\n Your room has been successfully booked");
					printf("\n Press any key and enter to go back to main menu : ");
					scanf("%s", dummy);
				}
				else if (s.roomnumber > 30)
				{
					printf("invalid number");
					scanf("%s", dummy);
				}

			}
			else if (roomtype == 4)
			{
				FILE *f;
				f = fopen("booking.txt", "a+");
				printf("\n\nRoom selected is Queen Room");
				printf("\n Please enter your details");
				printf("\n Please enter roomnumber in range of (31-40) : ");
				scanf("%d", &s.roomnumber);
				if (s.roomnumber > 30 && s.roomnumber < 41)
				{
					printf("\n Please enter your day of check in : ");
					scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
					printf("\n Please enter your day of checking out : ");
					scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
					s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
					s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
						if (s.roomnumber == s1.roomnumber &&
							((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
								|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco)))
						{
							printf("\nThis is room booked");
							_getch(); _getch();
							goto M;
						}
					printf("\n Please enter your name : ");
					scanf("%s", &s.name);
					printf("\n Please enter your ID number : ");
					scanf("%s", &s.nationalID);
					printf("\n Please enter your gender : ");
					scanf("%s", &s.gender);
					printf("\n Please enter your age : ");
					scanf("%s", &s.age);


					fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
					fclose(f);
					printf("\n Your room has been successfully booked");
					printf("\n Press any key and enter to go back to main menu : ");
					scanf("%s", dummy);
				}
				else if (s.roomnumber > 40)
				{
					printf("invalid number");
					scanf("%s", dummy);
				}

			}
			else if (roomtype == 5)
			{
				FILE *f;
				f = fopen("booking.txt", "a+");
				printf("\n\nRoom selected is King Room");
				printf("\n Please enter your details");
				printf("\n Please enter roomnumber in range of (41-50) : ");
				scanf("%d", &s.roomnumber);
				if (s.roomnumber > 40 && s.roomnumber < 51)
				{
					printf("\n Please enter your day of check in : ");
					scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
					printf("\n Please enter your day of checking out : ");
					scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
					s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
					s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
						if (s.roomnumber == s1.roomnumber &&
							((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
								|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco)))
						{
							printf("\nThis is room booked");
							_getch(); _getch();
							goto M;
						}
					printf("\n Please enter your name : ");
					scanf("%s", &s.name);
					printf("\n Please enter your ID number : ");
					scanf("%s", &s.nationalID);
					printf("\n Please enter your gender : ");
					scanf("%s", &s.gender);
					printf("\n Please enter your age : ");
					scanf("%s", &s.age);

					fprintf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);

					fclose(f);
					printf("\n Your room has been successfully booked");
					printf("\n Press any key and enter to go back to main menu : ");
					scanf("%s", dummy);
				}
				else if (s.roomnumber > 50)
				{
					printf("invalid number");
					scanf("%s", dummy);
				}
				
			}
			else if (roomtype == 6)
			{
				main_menu();
			}
		}
		if (choice == 2) /* this is for the viewing */
		{
			FILE *f;
			int i, q;
			if ((f = fopen("booking.txt", "r")) == 0)
				exit(0);
			system("cls");
			gotoxy(1, 6);
			printf("ROOMNUMBER ");
			gotoxy(15, 6);
			printf("NAME ");
			gotoxy(30, 6);
			printf("NATIONALID ");
			gotoxy(45, 6);
			printf("GENDER ");
			gotoxy(60, 6);
			printf("AGE ");
			gotoxy(75, 6);
			printf("CHECK IN DATE ");
			gotoxy(90, 6);
			printf("CHECK OUT DATE ");
			gotoxy(0, 7);
			for (i = 0; i < 110; i++)
			{
				printf("-");
			}
			q = 9;
			while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
			{
				gotoxy(1, q);
				printf("%d", s.roomnumber);
				gotoxy(16, q);
				printf("%s", s.name);
				gotoxy(27, q);
				printf("%s", s.nationalID);
				gotoxy(46, q);
				printf("%s", s.gender);
				gotoxy(61, q);
				printf("%s", s.age);
				gotoxy(76, q);
				printf("%2d/%2d/%2d", s.cid, s.cim, s.ciy);
				gotoxy(91, q);
				printf("%2d/%2d/%2d", s.cod, s.com, s.coy);
				q++;
			}
			printf("\n");
			for (i = 0; i < 110; i++)
				printf("-");

			fclose(f);
			_getch(); _getch();
		}
		if (choice == 3)
		{
			char dummy[100];
			char reason[1000];
			FILE *f;
			FILE *t;
			FILE *e;
			e = fopen("cancel.txt", "a+");
			int i = 0;
			int ret;
			int ram;
			int roomnumb;
			t = fopen("temp.txt", "w"); /* to open a temporary file*/
			if ((f = fopen("booking.txt", "r+")) == 0)
			{
				printf("NO RECORD ADDED.");
				main_menu();
			}
			else
			{
				system("cls");
				printf("Enter the Room Number of the hotel to be cancelled : ");
				scanf("%d", &roomnumb);
				while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
				{
					if (roomnumb != s.roomnumber)
					{
						fprintf(t, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
					}
					else
					{
							i = 1;
					}
				}
				if (!i)
				{
					printf("\n\n Roomnumber that has been keyed in is invalid as the room is not booked !!");
					_getch();
					fclose(f);
					fclose(t);
					main_menu();
				}
				else
				{
					fclose(f);
					fclose(t);
					printf("\n\tSuccessfully deleted.\n");
					remove("booking.txt"); /* to remove the current booking.txt file*/
					rename("temp.txt", "booking.txt"); /* to reaname*/
					printf("Please insert reason for cancellation : ");
					scanf(" %[^\n]s", reason);
					fprintf(e, "%s\n", reason);
					printf("\nKey In any button and press enter to exit");
					scanf("%s", dummy);
					fclose(e);
					
					
				}
			}
		}
		if (choice == 4)
		{
			FILE *f, *r;
			char dummy[100];
			int k = 0;
			char ed;
			int roomnumber;
			int cd, cm, cy;
			struct CustomerDetails s;
			if ((f = fopen("booking.txt", "r+")) == NULL)
			{
				printf("NO RECORD ADDED.");
				main_menu();
			}
			else
			{
				r = fopen("temp.txt", "a");
				system("cls"); 
				printf("Enter Room number of the customer to edit :\n\n");
				scanf("%d", &roomnumber);
				printf("Enter Check in date: \n\n");
				scanf("%2d/%2d/%2d", &cd, &cm, &cy);
				while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
				{
					if (roomnumber == s.roomnumber  && cd == s.cid && cm == s.cim && cy == s.ciy)/*to only allow modifying if room number and check in date match in data.*/
					{

						k = 1;
						printf("\n\t*** Existing Record ***");
						printf("\nRoom Number\t: %d", s.roomnumber);
						printf("\nName\t\t: %s", s.name);
						printf("\nNationalID\t\t: %s", s.nationalID);
						printf("\nGender\t: %s", s.gender);
						printf("\nAge\t: %s", s.age);
						printf("\nCheck in date\t\t: %2d/%2d/%2d", s.cid, s.cim, s.ciy);
						printf("\nCheck out date\t\t: %2d/%2d/%2d", s.cod, s.com, s.coy);
						G:
						printf("\n\n\t*** New Record ***");
						printf("\nEnter New Name           : ");
						scanf("%s", &s.name);
						printf("\nEnter New NationalID       : ");
						scanf("%s", &s.nationalID);
						printf("\nEnter New Gender   : ");
						scanf("%s", &s.gender);
						printf("\nEnter New Age    : ");
						scanf("%s", &s.age);
						printf("\nEnter Check in date          :  ");
						scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
						printf("\nEnter Check out date         :  ");
						scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
						s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
						s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
						while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
							if 
								((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
									|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco))
							{
								printf("\nThis is room booked");
								_getch();
								goto G;
							}
						printf("Press any key and enter to go back to main menu");
						
						
						fprintf(r, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
						//fflush(stdin);
						printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
						printf("\n Press any key and enter to go back to main menu");
						scanf("%s", dummy);

						
					}
					else
					{
						fprintf(r, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
						//fflush(stdin);
					}

				}
				if (!k)
				{
					printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
					printf("\n Press any key and enter to go back to main menu");
					scanf("%s", dummy);
				}
				fclose(r);
				fclose(f);
				remove("booking.txt");
				rename("temp.txt", "booking.txt");
				_getch();
			}
			main_menu();
		}
		if (choice == 5)
		{
			option_menu();
		}
		

	}
}
admin_menu()
{
	while (1)
	{
		struct CustomerDetails s;
		struct CustomerDetails s1;
		char dummy[1000];
		int choiceadmin;
		system("cls");
		printf("-");
		printf("\n");
		printf("   **********************************  |ADMIN MAIN MENU|  ******************************** \n");
		printf("-");
		printf("\n");
		printf("\t\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> View Rooms That Has Been Booked **|Look at rooms that has been booked|**");
		printf("\n-----------------------------------------------------------------------------");
		printf(" \n Enter 2 -> Delete Room **|Cancel the room you haved booked|**");
		printf("\n---------------------------------------------------------------");
		printf(" \n Enter 3 -> Modify Your Room **|Modify personal details and booking date|**");
		printf("\n---------------------------------------------------------------------");
		printf(" \n Enter 4 -> Search Room **|Search a room|**");
		printf("\n---------------------------------------------------------------------");
		printf(" \n Enter 5 -> Exit");
		printf("\n-----------------");
		printf("\n");
		scanf("%d", &choiceadmin);
		if (choiceadmin == 1)
		{
			FILE *f;
			int i, q;
			if ((f = fopen("booking.txt", "r")) == 0)
				exit(0);
			system("cls");
			gotoxy(1, 6);
			printf("ROOMNUMBER ");
			gotoxy(15, 6);
			printf("NAME ");
			gotoxy(30, 6);
			printf("NATIONALID ");
			gotoxy(45, 6);
			printf("GENDER ");
			gotoxy(60, 6);
			printf("AGE ");
			gotoxy(75, 6);
			printf("CHECK IN DATE ");
			gotoxy(90, 6);
			printf("CHECK OUT DATE ");
			gotoxy(0, 7);
			for (i = 0; i < 110; i++)
			{
				printf("-");
			}
			q = 9;
			while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
			{
				
				gotoxy(1, q);
				printf("%d", s.roomnumber);
				gotoxy(16, q);
				printf("%s", s.name);
				gotoxy(27, q);
				printf("%s", s.nationalID);
				gotoxy(46, q);
				printf("%s", s.gender);
				gotoxy(61, q);
				printf("%s", s.age);
				gotoxy(76, q);
				printf("%2d/%2d/%2d", s.cid, s.cim, s.ciy);
				gotoxy(91, q);
				printf("%2d/%2d/%2d", s.cod, s.com, s.coy);
				q++;
			}
			printf("\n");
			for (i = 0; i < 110; i++)
				printf("-");

			fclose(f);
			_getch();_getch();
		}
		if (choiceadmin == 2)
		{
			char dummy[100];
			FILE *f;
			FILE *t;
			int i = 0;
			int ret;
			int ram;
			int roomnumb;
			t = fopen("temp.txt", "w");
			if ((f = fopen("booking.txt", "r+")) == 0)
			{
				printf("NO RECORD ADDED.");
				main_menu();
			}
			else
			{
				system("cls");
				printf("Enter the Room Number of the hotel to be deleted from the database: ");
				//fflush(stdin);
				scanf("%d", &roomnumb);
				while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
				{
					if (roomnumb != s.roomnumber)
					{
						fprintf(t, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
					}
					else
					{
						i = 1;
					}
				}
				if (!i)
				{
					printf("\n\n Roomnumber that has been keyed in is invalid as the room is not booked !!");
					_getch(); _getch();
					fclose(f);
					fclose(t);
					main_menu();
				}
				else
				{
					fclose(f);
					fclose(t);
					printf("\n\tSuccessfully deleted.\n");
					remove("booking.txt");
					rename("temp.txt", "booking.txt");
					printf("\nKey In any button and press enter to exit");
					scanf("%s", dummy);

				}
			}
		}
		if (choiceadmin == 3)
		{
			{
				FILE *f, *r;
				char dummy[100];
				int k = 0;
				char ed;
				int roomnumber;
				int cd, cm, cy;
				struct CustomerDetails s;
				if ((f = fopen("booking.txt", "r+")) == NULL)
				{
					printf("NO RECORD ADDED.");
					main_menu();
				}
				else
				{
					r = fopen("temp.txt", "a");
					system("cls");
					printf("Enter Room number of the customer to edit :\n\n");
					scanf("%d", &roomnumber);
					printf("Enter Check in date: \n\n");
					scanf("%2d/%2d/%2d", &cd, &cm, &cy);
					while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF)
					{
						if (roomnumber == s.roomnumber  && cd == s.cid && cm == s.cim && cy == s.ciy)
						{

							k = 1;
							printf("\n\t*** Existing Record ***");
							printf("\nRoom Number\t: %d", s.roomnumber);
							printf("\nName\t\t: %s", s.name);
							printf("\nNationalID\t\t: %s", s.nationalID);
							printf("\nGender\t: %s", s.gender);
							printf("\nAge\t: %s", s.age);
							printf("\nCheck in date\t\t: %2d/%2d/%2d", s.cid, s.cim, s.ciy);
							printf("\nCheck out date\t\t: %2d/%2d/%2d", s.cod, s.com, s.coy);
						G:
							printf("\n\n\t*** New Record ***");
							printf("\nEnter New Name           : ");
							scanf("%s", &s.name);
							printf("\nEnter New NationalID       : ");
							scanf("%s", &s.nationalID);
							printf("\nEnter New Gender   : ");
							scanf("%s", &s.gender);
							printf("\nEnter New Age    : ");
							scanf("%s", &s.age);
							printf("\nEnter Check in date          :  ");
							scanf("%2d/%2d/%2d", &s.cid, &s.cim, &s.ciy);
							printf("\nEnter Check out date         :  ");
							scanf("%2d/%2d/%2d", &s.cod, &s.com, &s.coy);
							s.ymdci = (s.ciy * 10000) + (s.cim * 100) + s.cid;
							s.ymdco = (s.coy * 10000) + (s.com * 100) + s.cod;
							while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s1.roomnumber, s1.name, s1.nationalID, s1.gender, s1.age, &s1.cid, &s1.cim, &s1.ciy, &s1.cod, &s1.com, &s1.coy, &s1.ymdci, &s1.ymdco) != EOF)
								if
									((s.ymdci >= s1.ymdci && s.ymdci <= s1.ymdco) || (s.ymdco >= s1.ymdci && s.ymdco <= s1.ymdco)
										|| (s1.ymdci >= s.ymdci && s1.ymdci <= s.ymdco) || (s1.ymdco >= s.ymdci && s1.ymdco <= s.ymdco))
								{
									printf("\nThis is room booked");
									_getch();
									goto G;
								}
							printf("Press any key and enter to go back to main menu");


							fprintf(r, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
							//fflush(stdin);
							printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
							printf("\n Press any key and enter to go back to main menu");
							scanf("%s", dummy);


						}
						else
						{
							fprintf(r, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", s.roomnumber, s.name, s.nationalID, s.gender, s.age, s.cid, s.cim, s.ciy, s.cod, s.com, s.coy, s.ymdci, s.ymdco);
							//fflush(stdin);
						}

					}
					if (!k)
					{
						printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
						printf("\n Press any key and enter to go back to main menu");
						scanf("%s", dummy);
					}
					fclose(r);
					fclose(f);
					remove("booking.txt");
					rename("temp.txt", "booking.txt");
					_getch();
				}
				main_menu();
			}
		}
		if(choiceadmin == 4)
		{
			system("cls");
			FILE *f;
			int roomnumber;
			int flag = 1;
			char dummy[100];
			f = fopen("booking.txt", "r+");
			if (f == 0)
			{
				printf("NO RECORD ADDED.");
				main_menu();
			}
			else
			{
				printf("Enter Room number of the customer to search its details: \n");
				scanf("%i", &roomnumber);
				while (fscanf(f, "\n%d\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &s.roomnumber, &s.name, &s.nationalID, &s.gender, &s.age, &s.cid, &s.cim, &s.ciy, &s.cod, &s.com, &s.coy, &s.ymdci, &s.ymdco) != EOF) {
					if (roomnumber == s.roomnumber)
					{
						flag = 0;
						printf("\n\tRECORD HAS BEEN FOUND !!!!\n");
						printf("\nRoom Number\t: %d", s.roomnumber);
						printf("\nName\t\t: %s", s.name);
						printf("\nNationaID\t\t: %s", s.nationalID);
						printf("\nGender\t: %s", s.gender);
						printf("\nAge\t: %s", s.age);
						printf("\nCheck In\t\t: %2d/%2d/%2d", s.cid, s.cim, s.ciy);
						printf("\nCheck Out\t\t: %2d/%2d/%2d", s.cod, s.com, s.coy);
						printf("\n Press any key and enter to go back to main menu : \n");
						scanf("%s", &dummy);
						break;
					}
				}
				if (flag == 1) 
				{
					printf("\n\tRequested Customer could not be found!");
					printf("\n Press any key and enter to go back to main menu");
					scanf("%s", &dummy);
				}
				fclose(f);
				admin_menu();
			}

		}
		if (choiceadmin == 5)
		{
			option_menu();
		}
		
	}
}



	






