/* 
 * File:   tools.h
 * Author: haralambitodorov
 *
 * Created on February 8, 2014, 1:14 PM
 */

#ifndef TOOLS_H
#define	TOOLS_H

int initial();
int makeasudoku(void);													/////
int fillthesudoku(void);
int linearval(int, int);
struct retrace func(int *dontrepeat, int, int);
int check(int i, int j);
struct locate grid(int i, int j);

#endif	/* TOOLS_H */

