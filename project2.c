/*
* Name: Wayne Wong, Jacob Kizhakeparampil, Alejandro Olvera
* Project 2: Scheduling Disciplines
* Date: 04/28/2017
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAX = 50;

/* Structure of the four parameters */
struct parameters {
	char processID[20];
	int arrivalTime;
	int runTime;
	int priority;
};

/* Function prototypes */
void checkArgs(int argc, char *argv[]);
int readFile(struct parameters *param, char *argv[]);
void scheduling(struct parameters *param);

int main(int argc, char *argv[]) {
	int count;  /* Keeps track of the number of processes */
	checkArgs(argc, argv);  
	struct parameters *param = malloc(sizeof(struct parameters) * MAX);
	count = readFile(param, argv);

	/* Test to see if inputs are correctly stored */ 
	int i;
	for (i=0; i<count; i++) {
		printf("%s, %d, %d, %d\n", param[i].processID, param[i].arrivalTime, param[i].runTime, param[i].priority);
	}

	scheduling(param);

	return 0;
}

/* Checks to see if a filename has been provided */
void checkArgs(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please provide a proper filename.\n");
		printf("Program terminated.\n\n");
		exit(EXIT_FAILURE);
	}
}

/* Read from the input file. Store parameters into the struct */
int readFile(struct parameters *param, char *argv[]) {
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Invalid file name.\n");
		printf("Program terminated.\n\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;

	while (fscanf(fp, "%s %d %d %d", param[i].processID, &param[i].arrivalTime, &param[i].runTime, &param[i].priority) != EOF) {
		i++;
	}

	fclose(fp);
	return i;
}

/* Perform the actual scheduling algorithm */
void scheduling(struct parameters *param) {

/* START HERE PP !!!
//
//
//
//
*/

}
