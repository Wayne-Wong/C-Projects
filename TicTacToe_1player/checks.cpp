// Wayne Wong
// TIC TAC TOE
#include "header.h"

int tick::check_player(void)
{
	if (location[1] == 1 && location[2] == 1)
	{
		if (location[3] == 0)
		{
			return 3;
		}
	}
	if (location[2] == 1 && location[3] == 1)
	{
			if (location[1] == 0)
		{
			return 1;
		}
	}
	if (location[1] == 1 && location[3] == 1)
	{
		if (location[2] == 0)
		{
			return 2;
		}
	}
	if (location[4] == 1 && location[5] == 1)
	{
		if (location[6] == 0)
		{
			return 6;
		}
	}
	if (location[5] == 1 && location[6] == 1)
	{
		if (location[4] == 0)
		{
			return 4;
		}
	}
	if (location[4] == 1 && location[6] == 1)
	{
		if (location[5] == 0)
		{
			return 5;
		}
	}
	if (location[7] == 1 && location[8] == 1)
	{
		if (location[9] == 0)
		{
			return 9;
		}
	}
	if (location[8] == 1 && location[9] == 1)
	{
		if (location[7] == 0)
		{
			return 7;
		}
	}
	if (location[7] == 1 && location[9] == 1)
	{
		if (location[8] == 0)
		{
			return 8;
		}
	}
	if (location[1] == 1 && location[4] == 1)
	{
		if (location[7] == 0)
		{
			return 7;
		}
	}
	if (location[4] == 1 && location[7] == 1)
	{
		if (location[1] == 0)
		{
			return 1;
		}
	}
	if (location[1] == 1 && location[7] == 1)
	{
		if (location[4] == 0)
		{
			return 4;
		}
	}
	if (location[2] == 1 && location[5] == 1)
	{
		if (location[8] == 0)
		{
			return 8;
		}
	}
	if (location[5] == 1 && location[8] == 1)
	{
		if (location[2] == 0)
		{
			return 2;
		}
	}
	if (location[2] == 1 && location[8] == 1)
	{
		if (location[5] == 0)
		{
			return 5;
		}
	}
	if (location[3] == 1 && location[6] == 1)
	{
		if (location[9] == 0)
		{
			return 9;
		}
	}
	if (location[6] == 1 && location[9] == 1)
	{
		if (location[3] == 0)
		{
			return 3;
		}
	}
	if (location[3] == 1 && location[9] == 1)
	{
		if (location[6] == 0)
		{
			return 6;
		}
	}
	if (location[1] == 1 && location[5] == 1)
	{
		if (location[9] == 0)
		{
			return 9;
		}
	}
	if (location[5] == 1 && location[9] == 1)
	{
		if (location[1] == 0)
		{
			return 1;
		}
	}
	if (location[1] == 1 && location[9] == 1)
	{
		if (location[5] == 0)
		{
			return 5;
		}
	}
	if (location[3] == 1 && location[5] == 1)
	{
		if (location[7] == 0)
		{
			return 7;
		}
	}
	if (location[5] == 1 && location[7] == 1)
	{
		if (location[3] == 0)
		{
			return 3;
		}
	}
	if (location[3] == 1 && location[7] == 1)
	{
		if (location[5] == 0)
		{
			return 5;
		}
	}

	srand(time(NULL));
	int a;
		
	do {
		a = rand()%9+1;
	} while (location[a] != 0);
		
	return a;
}





int tick::check_self(void)
{
	
	if (location[1] == 2 && location[2] == 2)
	{
		if (location[3] == 0)
		{
			location[3] = 2;
			return 3;
		}
	}
	if (location[2] == 2 && location[3] == 2)
	{
		if (location[1] == 0)
		{
			location[1] = 2;
			return 1;
		}
	}
	if (location[1] == 2 && location[3] == 2)
	{
		if (location[2] == 0)
		{
			location[2] = 2;
			return 2;
		}
	}
	if (location[4] == 2 && location[5] == 2)
	{
		if (location[6] == 0)
		{
			location[6] = 2;
			return 6;
		}
	}
	if (location[5] == 2 && location[6] == 2)
	{
		if (location[4] == 0)
		{
			location[4] = 2;
			return 4;
		}
	}
	if (location[4] == 2 && location[6] == 2)
	{
		if (location[5] == 0)
		{
			location[5] = 2;
			return 5;
		}
	}
	if (location[7] == 2 && location[8] == 2)
	{
		if (location[9] == 0)
		{
			location[9] = 2;
			return 9;
		}
	}
	if (location[8] == 2 && location[9] == 2)
	{
		if (location[7] == 0)
		{
			location[7] = 2;
			return 7;
		}
	}
	if (location[7] == 2 && location[9] == 2)
	{
		if (location[8] == 0)
		{
			location[8] = 2;
			return 8;
		}
	}
	if (location[1] == 2 && location[4] == 2)
	{
		if (location[7] == 0)
		{
			location[7] = 2;
			return 7;
		}
	}
	if (location[4] == 2 && location[7] == 2)
	{
		if (location[1] == 0)
		{
			location[1] = 2;
			return 1;
		}
	}
	if (location[1] == 2 && location[7] == 2)
	{
		if (location[4] == 0)
		{
			location[4] = 2;
			return 4;
		}
	}
	if (location[2] == 2 && location[5] == 2)
	{
		if (location[8] == 0)
		{
			location[8] = 2;
			return 8;
		}
	}
	if (location[5] == 2 && location[8] == 2)
	{
		if (location[2] == 0)
		{
			location[2] = 2;
			return 2;
		}
	}
	if (location[2] == 2 && location[8] == 2)
	{
		if (location[5] == 0)
		{
			location[5] = 2;
			return 5;
		}
	}
	if (location[3] == 2 && location[6] == 2)
	{
		if (location[9] == 0)
		{
			location[9] = 2;
			return 9;
		}
	}
	if (location[6] == 2 && location[9] == 2)
	{
		if (location[3] == 0)
		{
			location[3] = 2;
			return 3;
		}
	}
	if (location[3] == 2 && location[9] == 2)
	{
		if (location[6] == 0)
		{
			location[6] = 2;
			return 6;
		}
	}
	if (location[1] == 2 && location[5] == 2)
	{
		if (location[9] == 0)
		{
			location[9] = 2;
			return 9;
		}
	}
	if (location[5] == 2 && location[9] == 2)
	{
		if (location[1] == 0)
		{
			location[1] = 2;
			return 1;
		}
	}
	if (location[1] == 2 && location[9] == 2)
	{
		if (location[5] == 0)
		{
			location[5] = 2;
			return 5;
		}
	}
	if (location[3] == 2 && location[5] == 2)
	{
		if (location[7] == 0)
		{
			location[7] = 2;
			return 7;
		}
	}
	if (location[5] == 2 && location[7] == 2)
	{
		if (location[3] == 0)
		{
			location[3] = 2;
			return 3;
		}
	}
	if (location[3] == 2 && location[7] == 2)
	{
		if (location[5] == 0)
		{
			location[5] = 2;
			return 5;
		}
	}


	return 20;
}