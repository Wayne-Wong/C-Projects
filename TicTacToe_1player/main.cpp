// Wayne Wong
// TIC TAC TOE
#include "header.h"


int main(void)
{
	tick TICK;
	
	while(1) {
		TICK.player1();
		TICK.display();
		TICK.check();
		
		TICK.player2();
		TICK.display();
		TICK.check();
	}

	return 0;
}