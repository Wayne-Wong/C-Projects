/*
 ============================================================================
 Name        : dijkstra.cpp
 Author      : Wayne Wong Zhen Yann
 Date 		 : November 15, 2016
 Description : This program will use Dijkstra's algorithm to find the
 				shortest path from a starting vertex.
 Important	 : This program is same as program 2 (bellmanFord.cpp). The only 
 				thing that's different is the function above the relaxation.
 ============================================================================
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;

struct myGraph{
	char source;	// starting vertex
	char dest;		// ending vertex
	int weight;		// weight of edge source -> dest
};

// function prototypes
void openFile(ifstream &myFile, char *argv[], vector<string> &vect);
int calculateEdges(vector<string> &vect);
int populateEdges(myGraph graph[], vector<string> &vect, int numOfEdges, char array[]);
void dijkstra_relaxation(myGraph graph[], int numOfEdges, int numOfVertices, vector<string> &vect, char array[]);
void printResults(int *d, int *p, int numOfVertices, vector<string> &vect, myGraph graph[], char array[]);

// main function
int main(int argc, char* argv[]) {
	ifstream myFile;		// file pointer for input file
	vector<string> vect;	// declare a vector to store all the input	
	char array[26];			// variable to store vertex

	openFile(myFile, argv, vect);		// function call to openFile
	int numOfEdges = calculateEdges(vect);								// function call to calculateEdges
	myGraph *graph = new myGraph[numOfEdges];							// declare struct of size 1 at first
	int numOfVertices = populateEdges(graph, vect, numOfEdges, array);	// function call to populateEdges
	dijkstra_relaxation(graph, numOfEdges, numOfVertices, vect, array);		// function call to bellmanFord
	
	myFile.close();		// close the file
	return 0;			// end the program
}

/*
 ==============================================================================
 Function    : openFile
 Parameters  : file pointer, arguments, vector
 Return      : nothing
 Description : This function will read in the input file and store all the 
 				information about the graph in a vertex
 ==============================================================================
 */
void openFile(ifstream &myFile, char *argv[], vector<string> &vect) {
	myFile.open(argv[1]);		// open the file
	if (myFile.fail()) {		// if opening fails
		cout << "An error has occured." << endl;
		cout << "Please check the input file." << endl;
		exit(EXIT_FAILURE); 	// terminate the program
	}

	string input;				// variable to store each line

	while (!myFile.eof()) {		// read the file until the end of file
		getline(myFile, input);	// store each line to temp variable
		vect.push_back(input);	// push the temp value into the vector
	}

	cout << "========================================================" << endl;
	cout << ">> Reading from the input file..." << endl;
	for (int i=0; i<vect.size(); i++) {
		cout << vect[i];		// display result in the vector
		cout << endl;			// print out a new line
	}
	cout << "========================================================" << endl;
}

/*
 ==============================================================================
 Function    : calculateEdges
 Parameters  : vector
 Return      : number of edges
 Description : This function will calculate the number of edges exists
 				in the graph and return the value.
 ==============================================================================
 */
int calculateEdges(vector<string> &vect) {
	int edges = 0;		// counter for edges

	for (int i=0; i<vect.size(); i++) {			// loop over the vector
		string temp = vect[i];					// convert the current vector into string
		for (int j=0; j<temp.size(); j++) {		// loop over the temporary string
			if (temp[j] == '(')					// find the number of vectors based on the number of parenthesis
				edges++;						// increment the value of edges
		}
	}	
	return edges;		// return the number of edges
}

/*
 ==============================================================================
 Function    : populateEdges
 Parameters  : struct graph, vector, number of edges, character array
 Return      : number of vertices
 Description : This function will take in the information from the vector 
 				and distribute edges stored into a struct
 ==============================================================================
 */
int populateEdges(myGraph graph[], vector<string> &vect, int numOfEdges, char array[]) {
	int z = 0;				// count variable that increment the edges
	int m = 0, n = 0;		// variable to keep track of the weight's position
	int numOfVertices = 0;	// variable to store # of vertices
	bool newVertex = true;	// see if it's an existing vertex
	char vertex;			// variable to store current vertex
	string temp = "";		// store the weight of the edge

	for (int i=0; i<vect.size(); i++) {			// loop through the vector
		string line = vect[i];					// store the current vector as a string
		
		vertex = line[0];				// store curent vertex
		for (int a=0; a<26; a++) {		// check if it's an existing vertex
			if (array[a] == vertex)
				newVertex = false;
		}
		if (newVertex) {				
			array[numOfVertices] = vertex;			// add the new vertex to the array
			numOfVertices++;
		}
		newVertex = true;

		for (int j=0; j<line.size(); j++) {		
			if (line[j] == '(') {	
				vertex = line[j+1];					// store the current vertex
				for (int b=0; b<26; b++) {			// check if it's an existing vertex
					if (array[b] == vertex) {
						newVertex = false;
					}
				}	
				if (newVertex) {
					array[numOfVertices] = vertex;		// add the new vertex to the array
					numOfVertices++;
				}

				graph[z].source = line[0];			// store the source value
				graph[z].dest = line[j+1];			// store the destination value
				m = j+4;
				while (line[m] != ')') {
					temp[n] = line[m];			// as the weight value as temp
					n++; m++;					// increment n and m counters
				}
				
				graph[z].weight = stoi(temp);	// store the weight value
				for (int s=0; s<n; s++)
					temp[s] = 0;
				m = 0; n = 0; 		// reset the counters	
				z++; 				// increment z
				newVertex = true;	// set it back
			}
		}
	}

	cout << ">> List of all the vertices..." << endl;
	for (int i=0; i<numOfEdges; i++) {		// print out the results of all edges
		cout << "(" << graph[i].source << " -> " << graph[i].dest << "): " << graph[i].weight << endl;
	}
	cout << "========================================================" << endl;

	return numOfVertices;		// return the number of vertices
}

/*
 ==============================================================================
 Function    : bellmanFord_relaxation
 Parameters  : struct graph, number of edges, number of vertices, vector, character array
 Return      : nothing
 Description : This function will compute the shortest path using the 
 				Dijkstra's algorithm. It will also determine if the graph
 				has a negative cycle.
 ==============================================================================
 */
void dijkstra_relaxation(myGraph graph[], int numOfEdges, int numOfVertices, vector<string> &vect, char array[]) {

	int *d = new int [numOfVertices];	// distance - array of size = # of vertices
	int *p = new int [numOfVertices];	// predecessor - array of size = # of vertices
	vector<int> Q;	// Q - store the current queue
	vector<int> S;	// S - store the vertex that's been visitied

	for (int i=1; i<numOfVertices; i++)
		d[i] = INT_MAX;		// set all distances to infinity
	d[0] = 0;				// set the starting vertex to 0	

	for (int i=0; i<numOfVertices; i++)		
		Q.push_back(i);		// insert number of vertices into the queue

	while (Q.size() != 0) {	// while the queue is not empty
		int min_value = INT_MAX;	// variable to find smallest distance
		int min_index = 0;			// smallest spot
		int u = 0;	// starting vertex
		int v = 0;	// ending vertex

		for (int i=0; i<Q.size(); i++) {
			if (d[Q[i]] < min_value) {
				min_value = d[Q[i]];	// store the min value to check
				min_index = i;			// store the index of min value
			}
		}

		S.push_back(Q[min_index]);		// add the min value to S queue
		for (int i=0; i<numOfEdges; i++) {
			if (array[Q[min_index]] == graph[i].source) {

				for (int j=0; j<numOfVertices; j++) {
					if (array[j] == graph[i].source)
						u = j;		// get the value of u
					if (array[j] == graph[i].dest)
						v = j;		// get the value of v
				}

				// relax edges
				if (d[v] > (d[u] + graph[i].weight) ) {		// if distance v is greater
					d[v] = (d[u] + graph[i].weight);		// update the distance v
					p[v] = u;								// update predecessor v
				}
			}
		}
		Q.erase(Q.begin() + min_index);		// remove the value from the Q queue
	}
	printResults(d, p, numOfVertices, vect, graph, array);		// display result if it does not has a negative cycle
}

/*
 ==============================================================================
 Function    : printResults
 Parameters  : array d, array p, number of vertices, vect, struct graph
 Return      : nothing
 Description : This function will display the final results of shortest path
 				if the graph does not has a negative cycle.
 ==============================================================================
 */
void printResults(int *d, int *p, int numOfVertices, vector<string> &vect, myGraph graph[], char array[]) {	
	int a = 0;		// counter for number of vertices in a single path
	char u = graph[0].source;		// u - start vertex
	char *path = new char [numOfVertices];	// store the path 

	cout << ">> After relaxing all the edges.\nIndex: \t\t";
	for (int i=0; i<numOfVertices; i++) 
		cout << array[i] << "\t";
	cout << "\nDistance:\t";
	for (int i=0; i<numOfVertices; i++) {
		if (d[i] == INT_MAX) {
			cout << "INF" << "\t";
		} else {
			cout << d[i] << "\t";		// display the results of all distance after N-1 iterations
		}
	}
	cout << "\nPredecessor:\t";
	for (int i=0; i<numOfVertices; i++) 
		cout << array[p[i]] << "\t";		// display the results of all predecessor after N-1 iterations
	cout << "\n========================================================" << endl;

	for (int i=0; i<numOfVertices; i++) {
		cout << "(" << u << "->" << array[i] << ") Total weight: " << d[i] << "\n   Path: ";		// display results of shortest path
		
		char current = array[i];	// store the final vertex of its path
		path[a] = current;			// store into the array
		a++;						// increment its arraycounter

		while (current != u) {	// while the current vertex is not the first vertex 
			for(int j=0; j<26; j++)	{
				if (array[j] == current) {	
					current = array[p[j]];	// when found, get the value of the predecessor
					break;
				}
			}
			path[a] = current;		// store the value into the path array
			a++;					// increment the counter
		}

		for (int k=a-1; k>=0; k--)	{
			cout << "[" << path[k] << "]";		// display it's entire path starting from the last
			if (k != 0)
				cout << " -> ";
		}

		cout << endl;
		a = 0;	// reset counter to 0
	}

	cout << "========================================================" << endl;	
}

