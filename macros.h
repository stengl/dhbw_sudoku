int line,x,y,l;

#define hline for(line=1;line<=64;line++)\
	printf("%c",95);


#define vline(x,y,l)	for(line=1;line<=l;line++)\
	{\
	gotoxy(x,y+line-1);\
	printf("%c",124);\
	}

#define dashhline 	for(line=1;line<=64;line++)\
	printf("~");
		
#define dashvline(x,y,l,type)	for(line=1;line<=l;line++)\
	{\
	gotoxy(x,y+line-1);\
	if(type==1)\
	printf("{");\
	else\
	printf("}");\
	}