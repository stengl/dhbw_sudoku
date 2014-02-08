#define MAX_SCREEN_AREA 100

int gotoxy(int x, int y)
{

	char essq[MAX_SCREEN_AREA]={0}; // String variable to hold the escape sequence
	sprintf(essq, "\033[%d;%df", y,x);
	printf("%s", essq);
	return 0;
} 




int output(void)
{
	system("clear");
	
	gotoxy(1,3);
	
	printf("Your you are playing a ");
	
	if((diff-40)/3+1==1)
		printf("beginner level");
	
	if((diff-40)/3+1==2)
		printf("mature level");

	if((diff-40)/3+1==3)
		printf("expert level");
	
	
	gotoxy(1,7);
	printf("Press I to view the instructions");
			
	gotoxy(1,9);
	
	printf("Result");		
	
	gotoxy(xcord-56,2);

	printf("  1      2      3      4      5      6      7      8      9");                            

	int counter=3;

	gotoxy(xcord-58,counter);
	hline

	printf("\n");
	counter++;

	printf("\n\n");
	counter=counter+2;


	int i1,j1;

	for(i1=1;i1<=9;i1++)
	{
		gotoxy(xcord-62,counter);
		printf("%d   ",i1);
	
		for(j1=1;j1<=9;j1++)
		{
			if(filling[i1][j1]!=0)
				printf("   %d   ",filling[i1][j1]);
			else
				printf("       ",filling[i1][j1]);
		
		}//end of inner for

		printf("\n");counter=counter+1;
						if(i1==3||i1==6)

							{
								gotoxy(xcord-58,counter);
								dashhline
							}
							
						else

							{
								gotoxy(xcord-58,counter);	
								hline
							}	

				printf("\n\n\n\n");counter=counter+2;

		}//end of outer for

	int m;

	for(m=0;m<10;m++)
		
		{

			if(m==3)
			dashvline(xcord-58+m*7,4,28,1)

			if(m==6)
			dashvline(xcord-58+m*7,4,28,2)

			if(m!=3&&m!=6)
			vline(xcord-58+m*7,4,28)


		}

return 0;

}





int viewthesol (void)

	{

		gotoxy(xcord-56+20,2);
		
		printf("Solution of Sudoku");
		
		gotoxy(xcord-56,5);
	
		printf("  1      2      3      4      5      6      7      8      9");                            

			int counter=6;

				gotoxy(xcord-58,counter);
				hline

					printf("\n");
					counter++;

						printf("\n\n");
						counter=counter+2;


		int i1,j1;

		for(i1=1;i1<=9;i1++)

			{
		
			gotoxy(xcord-62,counter);
			printf("%d   ",i1);
			
				for(j1=1;j1<=9;j1++)
	
					{
	
						printf("   %d   ",s[i1][j1]);
	
										
					}//end of inner for
	
						printf("\n");counter=counter+1;
		  	
		
		
								if(i1==3||i1==6)
		
									{
										gotoxy(xcord-58,counter);
										dashhline
									}
									
								else
		
									{
										gotoxy(xcord-58,counter);	
										hline
									}	
		
						printf("\n\n\n\n");counter=counter+2;

			}//end of outer for

		int m;

		for(m=0;m<10;m++)
			
			{

				if(m==3)
				dashvline(xcord-58+m*7,7,28,1)

				if(m==6)
				dashvline(xcord-58+m*7,7,28,2)
	
				if(m!=3&&m!=6)
				vline(xcord-58+m*7,7,28)


			}

	return 0;

	}


char getch(void)

	{
	
	struct termios oldt,
	newt;

	char ch;
	
		tcgetattr( STDIN_FILENO, &oldt );
		newt = oldt;
		newt.c_lflag &= ~( ICANON | ECHO );
		tcsetattr( STDIN_FILENO, TCSANOW, &newt );
		
		ch = getchar();

		tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
	}
