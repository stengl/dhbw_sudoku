#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#include "helpers.h"
#include "macros.h"
#include "tools.h"
#include "variables.h"

int main()
{

    srand((unsigned) time(NULL));



    ////////to initialize element of welcome array to zero//////

    initial();

    ///////////////////////////////////////////////////////////

    /////////////////////////////////////////////////menu////////////////////////////////////////////////////////////////


    while (rep == 0) {
        system("clear");

        printf("\nSUDOKU\n");

        hline

        printf("\n\n1. NEW GAME");

        printf("\n\n2. INSTRUCTIONS");

        printf("\n\n3. ABOUT");

        printf("\n\n4. EXIT\n");


        printf("\n\nEnter your choice : ");
        char c = getch();

        while (c > 52 || c < 49)
            c = getch();

        system("clear");

        switch (c)
 {

            case '1':


                printf("The programm generates a random sudoku and allows user to fill it\n\n");
                printf("Enter your name : ");
                gets(name);

                printf("\n\nSelect the difficulty level : ");
                printf("\n\n\n1. Beginner");
                printf("\n\n2. Mature");
                printf("\n\n3. Expert");
                printf("\n\n\nEnter your choice : ");
                diff = 40 + (getch() - 49)*3;

                while (diff != 40 && diff != 43 && diff != 46)
                    diff = 40 + (getch() - 49)*3;


                printf("\n\n\nHi! %s. Please wait while the programm generates a sudoku.\n\n\nIt will roughly take 5-10 seconds.", name);
                printf("\n\n\nPress any key to continue.........");
                getch();

                rep = 1;

                system("clear");

                break;


            case '2':

                printf("\nINSTRUCTIONS");

                printf("\n");
                hline
                printf("\n");

                printf("\n1. Scoring is done out of 100 and for every wrong entry 1 is deducted.");

                printf("\n\n2. The user should use the following keys to navigate inside the sudoku\n\n\n\n");

                printf("				W	\n");
                printf("\n			A	S	D");

                printf("\n\n\n\n3. Press I whilie playing to view the Instructions");

                printf("\n\n4. Press F while playing to automatically fill the sudoku");

                printf("\n\n5. Press V while playing to view the solution of sudoku");

                printf("\n\n6. Press E while playing to exit the game");

                getch();

                break;


            case '3':

                printf("\nABOUT");

                printf("\n");
                hline
                printf("\n");

                printf("\n1. This program uses the computer to generate a random sudoku using the logics of sudoku.");
                printf("\n\n2. The number of numbers being removed is also random and the positions where the zeros occur is also random.\n\n");
                printf("3. This game has three levels of difficulty viz. Beginner, Mature, Expert.");

                getch();

                break;



            case '4':

                exit(2);




        }//end of switch

    }//end of while


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    s[1][1] = 1 + rand() % 9;

    //

    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {


            int dontrepeat[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

            while (check(i, j) == 0)
 {

newm:{}

                ////////////////////

                int _count_ = 0, _k_;

                for (_k_ = 0; _k_ <= 8; _k_++)
 {
                    if (dontrepeat[_k_] >= 1)
                        _count_++;
                }


                if (_count_ == 9)
 {
                    i = func(dontrepeat, i, j)._i;
                    j = func(dontrepeat, i, j)._j;
                }

                ///////////////////

                int m;

                while (1)
 {
                    m = rand() % 9;
                    if (dontrepeat[m] == 0)
                        break;
                }


                dontrepeat[m]++;
                if (dontrepeat[m] > 1)
                    goto newm;


                s[i][j] = 1 + m;

            }

        }
    }

    //


    //recheck after sudoku has been made
    int wow = 0;

    int i__1, j__1;

    for (i__1 = 1; i__1 <= 9; i__1++) {
        for (j__1 = 1; j__1 <= 9; j__1++) {
            if (check(i__1, j__1) == 1)
                wow++;
        }
    }

    if (wow != 81)
        main();


    makeasudoku();


}//end of main








