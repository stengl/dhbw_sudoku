int xcord;

struct locate								
{				
	int x,y;			
}location;			
						
struct retrace					
{							
	int _i,_j;						
}fretrace;						
									
struct linearization							
{							
	int itsi,itsj,linearval;				
}linear[82];						
																	
struct retrace func(int *,int,int);					
									
int linearval(int,int);							
									
int check(int,int);							
									
struct locate grid(int,int);						
									
int s[10][10];														
									
int welcome[10][10];							
									
int a[10][10];								
									
int filla[10][10];							
									
int initial();								
									
char getch(void);							
									
int output(void);							
									
int viewthesol(void);							
									
int makeasudoku(void);							
									
int fillthesudoku(void);						
									
int filling[10][10];							
									
int diff,removenum;							
		
int initial();

char name[40];
int rep;