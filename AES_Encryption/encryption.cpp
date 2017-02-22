/*
 ============================================================================
 Name        : encryption.cpp
 Author      : Wayne Wong Zhen Yann
 Date 		 : December 2, 2015
 Description : This program is an encryption system in C++ using a modified 
 				version of AES. This program will read in 2 input files and 
 				output the result to an output file. Some functions include:
 					- Preprocessing, Substitution, Padding, Shift Rows,
 					  Parity Bit, Mix Columns
 ============================================================================
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

// function prototypes
void readFile(string &input, char key[], ifstream &inFile1, ifstream &inFile2);
void displayPlaintext(ofstream &outFile, char outputName[], string &input, char key[]);
void substitution(ofstream &outFile, string &input, char key[]);
void padding(ofstream &outFile, string &input);
void rowShift(ofstream &outFile, string &input);
void parityBit(ofstream &outFile, string &input);
void mixColumn(ofstream &outFile, string &input, unsigned int *values);
unsigned int rgfMul(unsigned int x, unsigned int y);

// main function
int main(int argc, char *argv[]) {

	ifstream inFile1, inFile2;		// file pointers for reading input files
	ofstream outFile;				// file pointer for writing to output file
	string input;					// store the original plaintext 
	char key[16];					// store the 16 bit key
	char outputName[30];			// store the name of the output file
	
	readFile(input, key, inFile1, inFile2);		// reading the input file 

	cout << "Please enter the name of the output file: ";	// prompt for output file name
	cin >> outputName;										// store output file name

	displayPlaintext(outFile, outputName, input, key);		// display the plaintext after preprocessing and the key
	substitution(outFile, input, key);						// substitute each character with the given 16 key
	padding(outFile, input);								// apply padding to make sure each block has 16 characters
	rowShift(outFile, input);								// row shifting to apply diffusion
	parityBit(outFile, input);								// apply parity bit and convert into hex

	inFile1.close();	// close file1
	inFile2.close();	// close file2
	outFile.close();	// close file3
	return 0;
}

/*
 ==============================================================================
 Function    : readFile
 Parameters  : original string, 16 bit key, file pointers for both input files
 Return      : nothing
 Description : This function will ask the user for the plaintext file name
 				and the key text file name. The function will then read both 
 				of the files and store everything in the file appropriately.
 ==============================================================================
 */
void readFile(string &input, char key[16], ifstream &inFile1, ifstream &inFile2) {

	char name1[30];		// store plaintext file name
	char name2[30];		// store key text file name
	string temp;		// temporary store each line of the plaintext file
	
	cout << "Please enter plaintext file name: ";
	cin >> name1;

	inFile1.open(name1);		// open the plaintext file
	if (inFile1.fail()) {		// if opening fail, print out error message
		cout << "Error opening plaintext file.\nProgram terminated.\n\n";
		exit(EXIT_FAILURE);		// terminate the program
	}

	while (!inFile1.eof()) {		// loop until it gets to the end of file
		getline(inFile1, temp);		// read a line and store into temp string
		input = input + temp;		// append the temp string into input string
	}

	for (int i=0; i<input.length(); i++) {				// nested for-loop
		if (input[i] < 65 || input[i] > 90) {			// if character is not within (A-Z)
			for (int j=i; j<input.length(); j++) {		// start from the position go to the end of string
				input[j] = input[j+1];					// shift every position one space to the left
			}
			input.erase(input.length()-1, input.length());		// remove that chatacter from the string
			i--;												// decrement the counter
		}
	}

	cout << "Please enter key file name: ";		// ask user for key text file name
	cin >> name2;				// store the file name
	inFile2.open(name2);		// open the file
	if (inFile2.fail()) {		// if opening fail, print out error message
		cout << "Error opening key file.\nProgram terminated.\n\n";
		exit(EXIT_FAILURE);		// terminate the program
	}

	inFile2 >> key;		// store the 16 bit key string key
}

/*
 ==============================================================================
 Function    : displayPlaintext
 Parameters  : file pointer for output file, output file name, original string,
 				and the 16 bit key
 Return      : nothing
 Description : This function will open an output file and display the preprocessed
 				plaintext as well as the key
 ==============================================================================
 */
void displayPlaintext(ofstream &outFile, char outputName[30], string &input, char key[16]) {

	outFile.open(outputName);		// open the file
	if (outFile.fail()) {			// if file opening fail, print error message
		cout << "Error opening " << outputName << "file.\n";
		exit(EXIT_FAILURE);			// terminate the program
	}

	//----- Displaying into output file and screen -----//
	outFile << "1. Plaintext after removing punctuation and whitespaces.\n";
	outFile << "-------------------------------------------------------------\n";
	outFile << input; 		// display the new input string 
	outFile << "\n\n\n"; 	// print new line
	outFile << "2. Encryption key.\n";
	outFile << "-------------------------------------------------------------\n";

	cout << "1. Plaintext after removing punctuation and whitespaces.\n";
	cout << "-------------------------------------------------------------\n";
	cout << input; 		// display the new input string 
	cout << "\n\n\n"; 	// print new line
	

	for (int i=0; i<16; i++)	// for loop that runs 16 times 
	{
		outFile << key[i];		// display the key into output file
		cout << key[i];			// display the key on the screen
	}
	outFile << "\n\n\n";		// print new line
	cout << "\n\n\n";			// print new line
	//-------------------------------------------------//
}

/*
 ==============================================================================
 Function    : substitution
 Parameters  : file pointer for output file, original string, and the 16 bit key
 Return      : nothing
 Description : This function will perform the substitution based on Vigenere 
 				cipher based on the key provided in the key input file 
 ==============================================================================
 */
void substitution(ofstream &outFile, string &input, char key[16]) {

	int newKey[16];		// stdire the difference between A and the key at each position
	int count = 0;		// count that keeps track of the position

	for (int i=0; i<16; i++)		// for-loop that runes 16 times
		newKey[i] = key[i] - 'A';	// calculate and store  the difference between the key and A

	for (int i=0; i<input.length(); i++) {	// loop until the end of the input string
		if (count == 16) {			// after 16 times (1 block), start back from 0 
			count = 0;				// set count back to 0
		}
		input[i] = input[i] + newKey[count];	// substituting input the calculated difference
		if (input[i] > 90) {					// if new value is over Z, start back from A
			input[i] = input[i] % 90 + 64;		// bring the value back to starting position A
		}
		count++;
	}

	//----- Displaying into output file and the screen-----//
	outFile << "3. Substitution using Vigenere Cipher.\n";
	outFile << "-------------------------------------------------------------\n";
	outFile << input;		// display the new input string
	outFile << "\n\n\n";	// print new lines

	cout << "3. Substitution using Vigenere Cipher.\n";
	cout << "-------------------------------------------------------------\n";
	cout << input;		// display the new input string
	cout << "\n\n\n";	// print new lines
	//-----------------------------------------------------//
}

/*
 ==============================================================================
 Function    : padding
 Parameters  : file pointer for output file, original string
 Return      : nothing
 Description : This function will perform padding to make sure that the whole 
 				string is in blocks of 16, otherwise it will pad A's to the end
 ==============================================================================
 */
void padding(ofstream &outFile, string &input) {

	int row=0;		// keeps track of row printing
	int column=0;	// keeps track of column printing

	if ((input.length() % 16) != 0) {			// modulus 16 has aremainder
		int x = 16 - (input.length() % 16);		// calculate the remainder
		for (int i=0; i<x; i++) {				// loop for the number of remainder
			input.append("A");					// append the character A to the end
		}
	}

	//----- Displaying into the output file and the screen -----//
	outFile << "4. Padding.\n";
	outFile << "-------------------------------------------------------------\n";

	cout << "4. Padding.\n";
	cout << "-------------------------------------------------------------\n";
	
	for (int i=0; i<input.length(); i++) {		// loop for the size of the input string
		outFile << input[i];		// display the new input string after padding into output file
		cout << input[i];			// display the new input string after padding on the screen
		row++; column++;			// increment both row and column counters
		if (row % 4 == 0)			// when row reaches 4 (because of 4x4)
		{
			outFile << endl;		// print a new line
			cout << endl;			// print a new line
		}
		if (column % 16 == 0)		// when column reaches 16 (because of 4x4 = 16)
		{
			outFile << endl;		// print a new line
			cout << endl;			// print a new line
		}
	}
	outFile << "\n\n\n";			// print new lines
	cout << "\n\n\n";				// print new lines
	//----------------------------------------------------------//
}

/*
 ==============================================================================
 Function    : rowShift
 Parameters  : file pointer for output file, original string
 Return      : nothing
 Description : This function will perform row shifting to apply diffusion.
 				The first row remain the same. Second row is shifted to the left
 				once. Third row is shifted to the left twice while the fourth 
 				row will be shifted to the left 3 times.
 ==============================================================================
 */
void rowShift(ofstream &outFile, string &input) {

	int pos = 0;		// keeps track of the position
	char temp[16];		// temporary store 16 block for row shifting

	while (pos <= input.length() - 16) {		// loop until the end of string
										//  position	|	replaced with 	
		temp[0] = input[pos];			//		0		|		0
		temp[1] = input[pos+1];			//		1		|		1
		temp[2] = input[pos+2];			//		2		|		2
		temp[3] = input[pos+3];			//		3		|		3
		temp[4] = input[pos+5];			//		4		|		5
		temp[5] = input[pos+6];			//		5		|		6
		temp[6] = input[pos+7];			//		6		|		7
		temp[7] = input[pos+4];			//		7		|		4
		temp[8] = input[pos+10];		//		8		|		10
		temp[9] = input[pos+11];		//		9		|		11
		temp[10] = input[pos+8];		//		10		|		8
		temp[11] = input[pos+9];		//		11		|		9
		temp[12] = input[pos+15];		//		12		|		15
		temp[13] = input[pos+12];		//		13		|		12
		temp[14] = input[pos+13];		//		14		|		13
		temp[15] = input[pos+14];		//		15		|		14

		int newpos = pos;	// keeps track of the new position
		for (int i=0; i<16; i++) {		// loop 16 times
			input[newpos] = temp[i];	// replace the original string with the temp string
			newpos++;					// increment the counter
		}
		pos = pos + 16;		// increment the position by 16 to go to a new block
	}

	//----- Displaying into the output file and the screen -----//
	outFile << "5. ShiftRows.\n";
	outFile << "-------------------------------------------------------------\n";
	cout << "5. ShiftRows.\n";
	cout << "-------------------------------------------------------------\n";
	int row=0;		// keeps track of the row for printing
	int column=0;	// keeps track of the column for printing

	for (int i=0; i<input.length(); i++) {	// loop until the end of string
		outFile << input[i];		// display new input string into output file
		cout << input[i];			// display new input string to the screen
		row++; column++;			// increment row and column counters
		if (row % 4 == 0)			// when row reaches 4, new line
		{
			outFile << endl;		// display a new line
			cout << endl;			// display a new line
		}
		if (column % 16 == 0)		// when column reaches 16, new line
		{
			outFile << endl;		// display a new line
			cout << endl;			// display a new line
		}
	}
	outFile << "\n\n\n";		// print new lines 
	cout << "\n\n\n";			// print new lines
	//----------------------------------------------------------//
}

/*
 ==============================================================================
 Function    : parityBit
 Parameters  : file pointer for output file, original string
 Return      : nothing
 Description : This funtion will convert the numeric value and use the most 
 				significant bit as a parity bit. If there is an odd number of 
 				1s in its binary representation, the most significant bit will 
 				be added a 1 to it.
 ==============================================================================
 */
void parityBit(ofstream &outFile, string &input) {

	int bin[8];		// store the current value in binary 
	int row=0;		// keeps track of the row for printing
	int column=0;	// keeps track of the column for printing
	int counter=0; 	// counter variable that starts off as 0
	unsigned int * values;		// an unsigned int pointer to store the new values
	values = new unsigned int [input.length()];		// dynamically assign the size of its array
	char temp;		// holds the current variable 
	
	// displaying into output file
	outFile << "6. ParityBit.\n";
	outFile << "-------------------------------------------------------------\n";
	// displaying on the screen
	cout << "6. ParityBit.\n";
	cout << "-------------------------------------------------------------\n";

	for (int i=0; i<input.length(); i++) {		// loop until the of the string
		temp = input[i];		// set temp as the current character

		for (int j=7; j>=0; j--) {	// loop 8 times to get its binary value
			bin[j] = temp % 2;		// mod 2 will return 1 or 0
			temp = (temp / 2);		// divide it by 2
		}		

		int check = 0;				// counter how many 1s are in binary form
		for (int k=0; k<8; k++) {	// loop through the array
			if (bin[k] == 1)		// when 1 is found, increment the counter
				check++;			// increment counter
		} 

		if (check % 2 != 0)		// if the counter is not even
			bin[0] = 1;			// add 1 to the most significant bit

		unsigned int total = 0; 	// holds the unsigned int of the final value
		int MAX = 7;				// MAX is set to 7 to get the new binary value in decimal
		for (int k=7; k>=0; k--) {	// loop through the array
			if (bin[k] == 1) {		// when 1 is found, add it to the total
				total = total + pow(2, MAX - k);	// add two to the power of (MAX-position) to the total
			}
		}
		
		//----- Displaying into the output file and the screen -----//
		outFile << hex << total << " ";		// display the final result in hex in an output file
		cout << hex << total << " ";		// display the final result in hex on the screen
		values[counter] = total;			// store the new value in a new unsigned int array

		row++; column++; counter++;			// increment row, column, and counter
		if (row % 4 == 0)					// when row reaches 4, print new line
		{
			outFile << endl;				// display new line
			cout << endl;					// display new line
		}
		if (column % 16 == 0)				// when column reaches 16, print new line
		{
			outFile << endl;				// display new line
			cout << endl;					// display new line
		}
		//---------------------------------------------------------//
	}

	mixColumn(outFile, input, values);		// perform mix column step

}

/*
 ==============================================================================
 Function    : mixColumn
 Parameters  : file pointer for output file, original string, and new int array
 Return      : nothing
 Description : This funtion will multiply the circulant MDS matrix with each 
 				column from the input using the Rijndael's Galois field.
 ==============================================================================
 */
void mixColumn(ofstream &outFile, string &input, unsigned int *values) {

	int counter = 0;	// keeps track of the counter
	int row = 0;		// keeps track of the row for printing
	int column = 0;		// keeps track of the column for printing
	unsigned int *mixCol;	// pointer of an unsigned int
	mixCol = new unsigned int [input.length()];	// dynamic array size of unsigned int

	while (counter <= input.length())	// keep doing until it reaches the end of string
	{
		//Formulas given in the instruction sheet
		mixCol[counter] = ( rgfMul(values[counter], 2) ^ rgfMul(values[counter+4], 3) ^ values[counter+8] ^ values[counter+12] );
		mixCol[counter+4] = ( values[counter] ^ rgfMul(values[counter+4], 2) ^ rgfMul(values[counter+8], 3) ^ values[counter+12] );
		mixCol[counter+8] = ( values[counter] ^ values[counter+4] ^ rgfMul(values[counter+8], 2) ^ rgfMul(values[counter+12], 3) );
		mixCol[counter+12] = ( rgfMul(values[counter], 3) ^ values[counter+4] ^ values[counter+8] ^ rgfMul(values[counter+12], 2) );

		counter++;					// increment counter
		if (counter % 4 == 0)		// after finishing 4 columns, go to a new block
			counter = counter + 12;	// add counter by 12 when it reaches 4 to go to a new block
	}

	//----- Displaying into the output file and the screen -----//
	outFile << "7. MixColumns.\n";
	outFile << "-------------------------------------------------------------\n";
	cout << "7. MixColumns.\n";
	cout << "-------------------------------------------------------------\n";
	for (int i=0; i<input.length(); i++)	// loop until the end of string
	{
		if (mixCol[i] > 256)				// remove the third 1 in hex if it exists
			mixCol[i] = mixCol[i] - 256;	// remove the third 1 (value = 256)

		outFile << hex << mixCol[i] << " ";	// output the new calculated value into output file
		cout << hex << mixCol[i] << " ";	// output the new calculated value to the screen

		row++; column++; 		// increment row and column counters
		if (row % 4 == 0)		// when row reaches 4, print new line
		{
			outFile << endl;	// display new line
			cout << endl;		// display new line
		}
		if (column % 16 == 0)	// when columnn reaches 16, print new line
		{
			outFile << endl;	// display new line
			cout << endl;		// display new line
		}
	}
	//---------------------------------------------------------//
}

/*
 ==============================================================================
 Function    : rgfMul
 Parameters  : int value that is calculated and integer value for multiplication
 Return      : nothing
 Description : This funtion will multiply the given calculated value by the
 				second integer value. Some XOR calculations also apply
 ==============================================================================
 */
unsigned int rgfMul(unsigned int x, unsigned int y)
{
	unsigned int result = 0;	// holds the final calculated value
	unsigned int temp = x;		// temp value that holds the int that gets passed in
	unsigned int MSB = 0;		// holds the most significant bit in binary form

	if (y == 2)		// multiplying by 2
	{
		for (int i=0; i<8; i++)	// loop 8 times to get it in binary form
		{	
			MSB = temp % 2;		// mod 2 to get a number between 0 and 1
			temp = temp / 2; 	// divide temp by 2
		}
		
		if (MSB == 1)	// if the most significant bit was 1
		{
			result = x << 1;		// multiply the value by 2 (shift once to left)
			result = result ^ 27;	// XOR it by 27 after multiplying
		}
		else 
			result = x << 1;		// multiply the value by 2 (shift once to left)
	}
	else if (y == 3)	// multiplying by 3
	{
		for (int i=0; i<8; i++) // loop 8 times to get it in binary form
		{	
			MSB = temp % 2;		// mod 2 to get a number between 0 and 1
			temp = temp / 2; 	// divide temp by 2
		}

		if (MSB == 1)	// if the most significant bit was 1
		{
			result = x << 1 ^ x;	// multiply the value by 2 and XOR it with original value
			result = result ^ 27;	// XOR the result with 27
		}
		else
			result = x << 1 ^ x;	// multiply the value by 2 and XOR it with original value
	}

	return result;	// return the final calculated value
}
