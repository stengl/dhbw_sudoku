#include "variables.h"

int check(int i, int j) {

    int number = 0, count = 0;

    int _i, _j;

    for (_i = grid(i, j).y; _i < grid(i, j).y + 3; _i++) {

        for (_j = grid(i, j).x; _j < grid(i, j).x + 3; _j++) {

            if (s[i][j] != s[_i][_j])
                count++;


            number++;

            if (_i == i && _j == j)
                goto out;



        }

    }



out:{}


    if (count == (number - 1)) {

        int number1 = 0, count1 = 0, _i;


        for (_i = 1; _i <= i; _i++) {

            if (s[_i][j] != s[i][j])
                count1 = count1 + 1;

            if (_i == i) {
                number1 = _i;
                goto out1;
            }

        }


out1:{}

        if (count1 == (number1 - 1)) {

            int _j, number2_ = 0, count2_ = 0;

            for (_j = 1; _j <= j; _j++) {

                if (s[i][_j] != s[i][j])
                    count2_ = count2_ + 1;

                if (_j == j) {
                    number2_ = _j;
                    goto out2;
                }

            }


out2:{}

            if (count2_ == (number2_ - 1)) {
                a[i][j] = s[i][j];
                return 1;
            } else {
                return 0;
            }






        } else {
            return 0;
        }


    }//end of if


    else {
        return 0;
    }



}//end of check function

struct locate grid(int i, int j) {

    int x, y;

    if (i <= 3 && i >= 1)
        y = 1;

    else if (i >= 4 && i <= 6)
        y = 4;

    else if (i >= 7 && i <= 9)
        y = 7;

    if (j <= 3 && j >= 1)
        x = 1;

    else if (j >= 4 && j <= 6)
        x = 4;

    else if (j >= 7 && j <= 9)
        x = 7;


    location.x = x;
    location.y = y;

    return location;

}

struct retrace func(int *dontrepeat, int i, int j) {
    welcome[i][j]++;

    int k;

    for (k = 0; k <= 8; k++)
        dontrepeat[k] = 0;


    fretrace._i = linear[linearval(i, j) - welcome[i][j]].itsi;
    fretrace._j = linear[linearval(i, j) - welcome[i][j]].itsj;


    if (fretrace._j <= 0 || fretrace._i <= 0)
        main();

    return fretrace;

}//end of func

int initial() {

    int _i_, _j_;

    for (_i_ = 1; _i_ <= 9; _i_++) {
        for (_j_ = 1; _j_ <= 9; _j_++) {
            welcome[_i_][_j_] = 0;
        }
    }


    ///////////////////////////for loop to convert 2-D array into linear one////////////////////////////

    int position = 0;

    for (_i_ = 1; _i_ <= 9; _i_++) {
        for (_j_ = 1; _j_ <= 9; _j_++) {
            position++;

            linear[position].itsi = _i_;
            linear[position].itsj = _j_;

            linear[position].linearval = position;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////

    //array for filling

    for (_i_ = 1; _i_ <= 9; _i_++) {
        for (_j_ = 1; _j_ <= 9; _j_++) {
            filling[_i_][_j_] = 0;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    for (_i_ = 1; _i_ <= 9; _i_++) {
        for (_j_ = 1; _j_ <= 9; _j_++) {
            s[_i_][_j_] = 1;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    for (_i_ = 1; _i_ <= 81; _i_++)

        linear[_i_].linearval = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////


}

int makeasudoku(void) {

    int i, j;

    for (i = 1; i <= 9; i++) {

        for (j = 1; j <= 9; j++) {

            filla[i][j] = a[i][j];

        }

    }


    removenum = diff + rand() % 10; /////////////////DUFFICULTY LEVEL//////////////


donem:{}



    int t = 1, empty = 0;


    while (empty != removenum) {

        while (1) {

            t = 1 + rand() % 81;
            linear[t].linearval++;

            if (linear[t].linearval == 1)
                goto deciderem;

        }


deciderem:{}

        filla[linear[t].itsi][linear[t].itsj] = 0;

        empty++;
    }


    fillthesudoku();

}

int linearval(int i, int j) {

    int position = 0, i_, j_;

    for (i_ = 1; i_ <= 9; i_++) {

        for (j_ = 1; j_ <= 9; j_++) {
            position++;

            if (i_ == i && j_ == j)
                goto _out_;
        }

    }
_out_:{}

    return position;

}

int fillthesudoku(void) {

    int i_1, j_1;

    for (i_1 = 1; i_1 <= 9; i_1++) {

        for (j_1 = 1; j_1 <= 9; j_1++) {

            filling[i_1][j_1] = filla[i_1][j_1];

        }

    }

    system("clear");

    output();



    int i = 1, j = 1, tot, remi, remj;
    float score = 0;
    char pos;



    while (1) {

        gotoxy(1, 5);
        printf("Your score is %.1f", score);

        gotoxy(1, 1);
        printf("Hi, %s.", name);


        gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

        pos = getch();

        if (pos == 'd' || pos == 'D') {
            tot = linearval(i, j);
            tot++;


            if (tot > 81)
                tot = tot % 81;

            i = linear[tot].itsi;
            j = linear[tot].itsj;

            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);



        } else if (pos == 'a' || pos == 'A') {
            tot = linearval(i, j);
            tot--;

            if (tot < 1)
                tot = tot + 81;

            i = linear[tot].itsi;
            j = linear[tot].itsj;

            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

        }
        else if (pos == 'w' || pos == 'W') {

            i = i - 1;

            if (i < 1)
                i = i + 9;


            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

        }
        else if (pos == 'S' || pos == 's') {

            i = i + 1;

            if (i > 9)
                i = i - 9;


            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

        } else if (pos <= 57 && pos >= 49) {

            int flag = 0;

            if (filling[i][j] == 0 && filla[i][j] == 0)
                flag = 1;

            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

            int wronginput = 0;

            do {

                if (wronginput > 0) {
                    remi = i;
                    remj = j;
                    gotoxy(1, 1);
                    printf("\nNot a valid entry");
                    i = remi;
                    j = remj;
                }


                filling[i][j] = pos - 48;


                if (filla[i][j] == 0) {

                    gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);
                    printf(" ");

                    gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);
                    printf("%d", filling[i][j]);

                }

                wronginput++;

            } while (filling[i][j] > 9 || filling[i][j] < 0);


            if (filling[i][j] != a[i][j] && filling[i][j] != 0 && filla[i][j] == 0) {
                score--;

                remi = i;
                remj = j;

                gotoxy(1, 8);
                printf("\nWrong entry\n");

                gotoxy(1, 5);
                printf("Your score is %.1f", score);

                i = remi;
                j = remj;


                getch();


                remi = i;
                remj = j;

                gotoxy(1, 8);
                printf("\n           \n");

                i = remi;
                j = remj;



                filling[i][j] = filla[i][j];

                gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);
                printf(" ");

                if (filling[i][j] != 0) {

                    gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);
                    printf("%d", filling[i][j]);

                }



            }


            if (filling[i][j] != 0 && filla[i][j] == 0 && flag == 1)
                score = score + 100 / (81 - ((diff - 49)*3 + 40));




            ////////////////////////////keeps a track of your progress//////////////////////////////////////////////

            int done = 0, equali, equalj;

            for (equali = 1; equali <= 9; equali++) {

                for (equalj = 1; equalj <= 9; equalj++) {

                    if (filling[equali][equalj] == a[equali][equalj])
                        done++;

                }
            }



            if (done == 81) {

                getch();

                system("clear");

                printf("\n\nCongratulations..... %s. You have solved the sudoku.\n\nYour score was %.1f", name, score);

                printf("\n\nDo you want to solve another sudoku (y\\n) : ");


                char q;

                scanf("%c", &q);

                if (q == 'y' || q == 'Y') {
                    rep = 0;
                    main();
                } else
                    exit(2);

            }

        }
        else if (pos == 'I' || pos == 'i') {

            system("clear");

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

            system("clear");

            remi = i;
            remj = j;
            output();
            i = remi;
            j = remj;
            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

        }
        else if (pos == 'f' || pos == 'F') {

            system("clear");


            printf("Are you sure you want to fill the sudoku in that case game will be over (y\\n) ??? : ");

            char q;

            q = getch();

            if (q == 'y' || q == 'Y') {

                system("clear");

                int a, b;

                for (a = 1; a < 10; a++) {

                    for (b = 1; b < 10; b++) {

                        filling[a][b] = s[a][b];

                    }

                }




                score = 0;


                remi = i;
                remj = j;
                output();
                i = remi;
                j = remj;

                getch();

                system("clear");

                printf("Do you want to solve another sudoku (y\\n) : ");


                char q;

                q = getch();

                if (q == 'y' || q == 'Y') {
                    rep = 0;
                    main();
                } else
                    exit(2);


            } else {


                remi = i;
                remj = j;
                output();
                i = remi;
                j = remj;


                gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

            }




        } else if (pos == 'e' || pos == 'E') {

            system("clear");

            printf("Are you sure you want to exit (y\\n) ??? : ");

            char q;

            q = getch();

            if (q == 'y' || q == 'Y') {
                system("clear");
                exit(3);
            } else {

                system("clear");

                remi = i;
                remj = j;
                output();
                i = remi;
                j = remj;

                gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

            }


        } else if (pos == 'v' || pos == 'V') {

            system("clear");

            viewthesol();
            getch();

            system("clear");

            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);

            remi = i;
            remj = j;
            output();
            i = remi;
            j = remj;

            gotoxy(xcord - 55 + 7 * (j - 1), 6 + (i - 1)*3);



        }








    }//end of while

}//end of function



