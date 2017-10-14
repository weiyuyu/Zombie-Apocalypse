/********************************************************
 * CS 103 Zombie-pocalypse PA
 * Name: Wei-Yu Yu
 * USC email: weiyuyu@usc.edu
 * Comments (you want us to know):
 *
 *
 ********************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
  // Array with enough entries for the maximum population size possible.
  bool pop[MAXPOP];

  // Your code here
  int N, k, M, nights=0;
  unsigned int s;
  bool repeat = false;

  cout << "Enter the following: N k M Seed: ";
  cin >> N >> k >> M >> s;

  int avg_nights = 0, max_nights = -1, min_nights= INT_MAX;
  int zom = k;
  srand(s);

  // Initialize array
  for(int i=0; i<N; i++){
  	
  	if(i<k){
  		pop[i] = true;
  	}
  	
  	else{
  		pop[i] = false;
  	}
  }

  for(int j=0; j<M; j++){


  	do{

  		for(int l=0; l<zom; l++){

  			int random = rand();
  			pop[(random%N)] = true;
  		
  		}

  		int zom_count = 0;

  		for(int i=0; i<N; i++){

  			if(pop[i]== false){
  			repeat = true;
  			}

  			else{
  				zom_count++;
  			}

  			if(zom_count == N){
  				repeat = false;
  			}
  		}

  		if(repeat == true)
  			nights++;
  		zom = zom_count;

  	} while(repeat);

  	if(nights>max_nights){
  		max_nights = nights;
  	}

  	if(nights<min_nights){
  		min_nights = nights;
  	}

  	avg_nights += nights;
  	
  	//Reset
  	nights =0;
  	zom = 0;
  	for(int z=0; z<N; z++){
  	
  	if(z<k){
  		pop[z] = true;
  	}
  	
  	else{
  		pop[z] = false;
  	}
  }

  }


  
  // Print out your average, max, and min number of nights here

  cout << "Average Nights: " << (double)avg_nights/M << endl;
  cout << "Max Nights: " << max_nights << endl;
  cout << "Min Nights: " << min_nights << endl;
  // Be sure to follow the format shown in the assignment writeup.


  return 0;
}
