int xcord=110;
		
int initial()
{
	int _i_,_j_;

	for(_i_=1;_i_<=9;_i_++)
	{
		for(_j_=1;_j_<=9;_j_++)
			{
				welcome[_i_][_j_]=0;
			}
	}

	//for loop to convert 2-D array into linear one///

	int position=0;

	for(_i_=1;_i_<=9;_i_++)
		{
			for(_j_=1;_j_<=9;_j_++)
				{
					position++;

					linear[position].itsi=_i_;
					linear[position].itsj=_j_;
			
					linear[position].linearval=position;
				}
		}	

	//array for filling

	for(_i_=1;_i_<=9;_i_++)
	{
		for(_j_=1;_j_<=9;_j_++)
		{
			filling[_i_][_j_]=0;
		}
	}

	for(_i_=1;_i_<=9;_i_++)
	{
		for(_j_=1;_j_<=9;_j_++)
		{
			s[_i_][_j_]=1;
		}
	}

	for(_i_=1;_i_<=81;_i_++)
		linear[_i_].linearval=0;

}
char name[40];