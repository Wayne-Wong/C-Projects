/*
 ============================================================================
 Name        : counting_sort.cpp
 Author      : Wayne Wong Zhen Yann
 Date 		 : September 24, 2016
 Description : This program will rearrange a list a numbers from smallest to
 				the greatest using counting sort implementation.
 ============================================================================
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
using namespace std;

// function prototypes
void openFile(ifstream &myFile, char *argv[], vector<int> &vect);
void countSort(vector<int> &vect, int *vect2, int *vect3, int *vect4);

// main function
int main(int argc, char *argv[]) {
	ifstream myFile; 				// file pointer for the input file
	vector<int> vect;				// create a vector variable
	int *vect2, *vect3, *vect4;		// create int pointer variable
	
	openFile(myFile, argv, vect);			// function call to openFile
	countSort(vect, vect2, vect3, vect4);	// function call to countSort
	
	myFile.close();					// close myFile
	return 0;						// end of program
}

/*
 ==============================================================================
 Function    : readFile
 Parameters  : empty vector to store input numbers
 Return      : nothing
 Description : This function will read in the input file and store every 
 				numbers into the vector
 ==============================================================================
 */
void openFile(ifstream &myFile, char *argv[], vector<int> &vect) {
	myFile.open(argv[1]);		// open the file
	if (myFile.fail()) {		// if opening fails
		cout << "An error has occured." << endl;
		cout << "Please check the input file." << endl;
		exit(EXIT_FAILURE); 	// terminate the program
	}

	int temp = 0;				// temp variable for each line

	while (!myFile.eof()) {		// read the file until the end of file
		myFile >> temp;			// store each line to temp variable
		vect.push_back(temp);	// push the temp value into the vector
	}

	cout << "========================================================" << endl;
	cout << "Input numbers: " << endl;
	for (int i=0; i<vect.size()-1; i++) {
		cout << vect[i];		// display result of stored numbers
		if (vect[i]-10 < 0)
			cout << "  ";
		else 
			cout << " ";
	}
	cout << "\n========================================================" << endl;
}

/*
 ==============================================================================
 Function    : countSort
 Parameters  : vector containing all input numbers, and 3 more empty vectors
 Return      : nothing
 Description : This function will dynamically create a new array of size equal 
 				to the largest integer number in the vector. Then, will 
 				increment each index accordingly and produce a new array 
 				that is arranged from smallest to biggest.
 ==============================================================================
 */
void countSort(vector<int> &vect, int *vect2, int *vect3, int *vect4) {
	int biggest = 0;	// temp variable to store the biggest value
	int size = vect.size()-1;

	for (int i=0; i<vect.size()-1; i++) {
		if (vect[i] > biggest)		// if the value is bigger
			biggest = vect[i];		// set the bigger value to variable biggest
	}
	biggest++;

	vect2 = new int [biggest];	// dynamically allocate new array
	vect3 = new int [biggest];	// dynamically allocate new array
	vect4 = new int [size];		// dynamically allocate new array
	

	for (int i=0; i<biggest; i++) {
		vect2[i] = 0; 					// initialize all values to 0
		vect3[i] = 0;
	}

	for (int i=0; i<vect.size()-1; i++)
		vect2[vect[i]]++;				// increment the index in vect2 according to vect

	cout << "Counting array (incremented): " << endl;
	for (int i=0; i<biggest; i++) {
		cout << vect2[i];				// display result of vect2
		if (vect2[i]-10 < 0)
			cout << "  ";
		else 
			cout << " ";
	}
	cout << "\n========================================================" << endl;

	vect3[0] = vect2[0];					// set the first element 
	for (int i=1; i<biggest; i++) {
		vect3[i] = vect3[i-1] + vect2[i]; 	// add up the sum of vect3 appropriately
	}

	cout << "Counting array (added): " << endl;
	for (int i=0; i<biggest; i++) {
		cout << vect3[i];					// display result of vect3
		if (vect3[i]-10 < 0)
			cout << "  ";
		else 
			cout << " ";
	}
	cout << "\n========================================================" << endl;

	for (int i=vect.size()-2; i>=0; i--) {
		int j = vect[i];
		
		vect4[vect3[vect[i]]-1] = vect[i];	// rearranging the numbers
		vect3[vect[i]] = vect3[vect[i]]-1;	// decrement the position by 1
	}

	cout << "Sorted array: " << endl;
	for (int i=0; i<vect.size()-1; i++) {
		cout << vect4[i];					// display result of vect4
		if (vect4[i]-10 < 0)
			cout << "  ";
		else 
			cout << " ";
	}
	cout << "\n========================================================" << endl;

}







