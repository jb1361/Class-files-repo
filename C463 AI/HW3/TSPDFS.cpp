
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#define MAX 100 //the max array value for distance_mat
#define CITI 12 //The number of cities
#define POPSIZE 50

using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::iterator;

long distance_mat[MAX][MAX]; //Matrix storing the distances of all cities
vector<long> remainder; //Global remainder vector
vector<long> tour; //Global tour Vector
long bestCost; //Global bestCost variable

vector<vector<long> > population;
vector <long> fitness; 

//This is the code given on the web site to read a list of values into a matrix
void readDistanceMatrix()
{
	bool fileOpened = false; //bool used to make sure the file opened successfully
	ifstream inf;
	inf.open("tsp12.txt"); 
	int value, i, j; 
	for (i = 0; i < CITI && !inf.fail(); i++) { 
		for (j = i; j < CITI && !inf.fail(); j++){ 
			fileOpened = true; //Once the function gets to this point it is obvious that the file has opened successfully so I set the bool to true
			if (i == j) { 
				distance_mat[i][j] = 0;
			}
			else {
				inf>>value;
				distance_mat[i][j] = value;
				distance_mat[j][i] = value;
			}
		}
	}
	//This was a check added by me just to make sure the matrix was filled properly
	if(fileOpened)
		cout << "Matrix has been filled" << endl;
}

//My function for computing the cost of a tour whether partial or full
long computeTourCost(vector<long> tour)
{
	long sum = 0; //progressive total
	for(int i = 0; i < tour.size() - 1; i++) { //Go through the entire tour except for the last spot and add each pair of values
			long temp1 = tour.at(i);
			long temp2 = tour.at(i + 1);
			sum += distance_mat[temp1][temp2];
	}
	if(tour.size() == CITI) { //if the tour is a full tour add the return value
		long temp1 = tour.at(tour.size()-1);
		long temp2 = tour.at(0);
		sum += distance_mat[temp1][temp2];
	}
	return sum; //return the total cost
}

//My recursive function for the traveling salesperson
void recTSP(vector<long> tour, vector<long> remainder)
{
	if(remainder.empty()) { //If there is nothing left in remainder we have a full tour
		long tourCost = computeTourCost(tour);
		if(tourCost < bestCost) { //see if this full tour is better than the best known tour
			bestCost = tourCost;
			cout << "COST: " << bestCost << endl << "PATH: "; //if so print out the distance
			for(int i = 0; i < tour.size(); i++) {
				cout << tour.at(i) << " "; //now print the path taken (for verification if needed
			}
			cout << endl;
		}
	} else { // else go through a recursive algorithm
		for(int i = 0; i < remainder.size(); i++) {
			vector<long> newTour = tour;
			newTour.push_back(remainder.at(i));
			long newTourCost = computeTourCost(newTour);
			if(newTourCost < bestCost) {
				vector<long> newRemainder = remainder;
				newRemainder.erase(newRemainder.begin() + i);
				recTSP(newTour, newRemainder);
			}
		}
	}		
}
void twoSwap(int i, int p, int q)
{
	int temp = population[i][p];
	population[i][p] = population[i][q];
	population[i][q] = temp;
}

//Fill Population vector
void fillPopulation()
{
	for(int i = 0; i < POPSIZE; i++)
	{
		for(int j = 0; j < CITI; j++)
		{
			vector<long> v;
			v[0] = j;
			population.push_back(v);
			//population[i][j] = j;
		}	
	}
	for(int i = 0; i < POPSIZE; i++)
	{
		for(int k = 0; k < CITI; k++)
		{
			int p = 1 + (rand()%CITI-1);
			int q = 1 + (rand()%CITI-1);
			twoSwap(i,p,q);
		}
	}

}



void computeFitness()
{
	for(int i = 0; i < POPSIZE; i++)
	{
		fitness[i] = computeTourCost(population[i]);
	}
}


int main() 
{
	fillPopulation();
	bestCost = 100000; //set best cost very high so we can go under it
	for(int i = 0; i < CITI; i++) { //fill the remainder
		remainder.push_back(i);
	}
	readDistanceMatrix(); //read in our distance_matrix

	recTSP(tour, remainder); //start the recursive function
	system("pause"); //allows a pause before shutting down for use outside the compiler
	return 0;
}