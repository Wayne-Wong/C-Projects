// Wayne Wong
// TIC TAC TOE
#include "header.h"

tick::tick() {
	for(int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			table[i][j] = '_';
		}
	}
	
	for(int i=0; i<10; i++) 
		location[i] = 0;
	
	cout << "TIC-TAC-TOE" << endl;
	cout << "Created by Mr. Wong\n" << endl;
	cout << "Field numbers correspond to the following... \n" << endl;
	cout << "7  8  9\n4  5  6\n1  2  3" << endl;
	cout << "\n\n";
}

void tick::player1(void) {
	int a;

	do {
		cout << "Player 1 please select your field: ";
		cin >> a;
	} while (a > 9 || a < 1 || location[a] != 0);

	location[a] = 1;
	
	switch(a) {
		case 1 : table[2][0] = 'O';
			break;
		case 2 : table[2][1] = 'O';
			break;
		case 3 : table[2][2] = 'O';
			break;
		case 4 : table[1][0] = 'O';
			break;
		case 5 : table[1][1] = 'O';
			break;
		case 6 : table[1][2] = 'O';
			break;
		case 7 : table[0][0] = 'O';
			break;
		case 8 : table[0][1] = 'O';
			break;
		case 9 : table[0][2] = 'O';
			break;
	}
	
}


void tick::player2(void) {
	int a;

	do {
		cout << "Player 2 please select your field: ";
		cin >> a;
	} while (a > 9 || a < 1 || location[a] != 0);

	location[a] = 2;
	
	switch(a) {
		case 1 : table[2][0] = 'X';
			break;
		case 2 : table[2][1] = 'X';
			break;
		case 3 : table[2][2] = 'X';
			break;
		case 4 : table[1][0] = 'X';
			break;
		case 5 : table[1][1] = 'X';
			break;
		case 6 : table[1][2] = 'X';
			break;
		case 7 : table[0][0] = 'X';
			break;
		case 8 : table[0][1] = 'X';
			break;
		case 9 : table[0][2] = 'X';
			break;
	}
	
}

void tick::check() {
	
	if (location[1] == 1 && location[2] == 1 && location[3] == 1)
		winner(1);
	else if (location[4] == 1 && location[5] == 1 && location[6] == 1)
		winner(1);
	else if (location[7] == 1 && location[8] == 1 && location[9] == 1)
		winner(1);
	else if (location[1] == 1 && location[4] == 1 && location[7] == 1)
		winner(1);
	else if (location[2] == 1 && location[5] == 1 && location[8] == 1)
		winner(1);
	else if (location[3] == 1 && location[6] == 1 && location[9] == 1)
		winner(1);
	else if (location[1] == 1 && location[5] == 1 && location[9] == 1)
		winner(1);
	else if (location[3] == 1 && location[5] == 1 && location[7] == 1)
		winner(1);
	
	if (location[1] == 2 && location[2] == 2 && location[3] == 2)
		winner(2
	);
	else if (location[4] == 2 && location[5] == 2 && location[6] == 2)
		winner(2);
	else if (location[7] == 2 && location[8] == 2 && location[9] == 2)
		winner(2);
	else if (location[1] == 2 && location[4] == 2 && location[7] == 2)
		winner(2);
	else if (location[2] == 2 && location[5] == 2 && location[8] == 2)
		winner(2);
	else if (location[3] == 2 && location[6] == 2 && location[9] == 2)
		winner(2);
	else if (location[1] == 2 && location[5] == 2 && location[9] == 2)
		winner(2);
	else if (location[3] == 2 && location[5] == 2 && location[7] == 2)
		winner(2);
	
	int count = 0;
	for (int i=0; i<10; i++) {
		if (location[i] != 0)
			count++;
	}
	
	if (count == 9)
			winner(3);
}

void tick::display(void) {
	system("clear");
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << table[i][j] << "  ";
		}
		cout << "\n\n";
	}
}

void tick::winner(int x) {
	if (x == 1) {
		cout << "**********************************" << endl;
		cout << "* Congratulations! Player 1 wins *" << endl;
		cout << "**********************************" << endl;
		cout << "\n\n";
		exit(0);
	}
	
	if (x == 2) {
		cout << "**********************************" << endl;
		cout << "* Congratulations! Player 2 wins *" << endl;
		cout << "**********************************" << endl;
		cout << "\n\n";
		exit(0);
	}
	
	if (x ==3) {
		cout << "********" << endl;
		cout << "* DRAW *" << endl;
		cout << "********" << endl;
		cout << "\n\n";
		exit(0);
	}
}