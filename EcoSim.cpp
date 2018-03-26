#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

/**
g: Rabbit Growth
p: Predator Growth
c: Fox to Prey Conversion
m: Fox Mortality Rate
K: Carrying Capacity
numRabbits: Number of Rabbits
numFoxes: Number of Foxes
*/
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);

void plotCharacter(int numberOfSpaces, char character);

void incrementCounter(int* integer);

void chartingFunction(double numberOfRabbits, double numberOfFoxes, double fractionalScaleFactor);

int main()
{
  //Initialization of Parameters
  double InitRabbitPop, InitFoxPop;

  //gets the user input and assigns it to the respective paramenters
  cout << "Enter the initial rabbit population: ";
  if(!(cin >> InitRabbitPop))
  {
    cerr << "Bad Input" << endl;
    return 1;
  }


  cout << "Enter the inital fox population: ";
  if(!(cin >> InitFoxPop))
  {
    cerr << "Bad Input" << endl;
    return 1;
  }

  //plots the graphs and updates the populations
  for(int steps = 0; steps < 500; steps++)
  {
    if(InitFoxPop <=0 || InitRabbitPop <= 0)
	  {
	     return 0;
	  }
    chartingFunction(InitRabbitPop, InitFoxPop, .1);
    updatePopulations(.2, .002, .6, .2, 1000.0, InitRabbitPop, InitFoxPop);
  }
}

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes)
{
  //Temp storage
  double Rabbits = numRabbits;
  double Foxes = numFoxes;

  //Calculates the change in each population
  double deltaRabbits = g*numRabbits*(1-numRabbits/K) - p*numRabbits*numFoxes;
  double deltaFoxes = c*p*numRabbits*numFoxes - m*numFoxes;

  //Updates the populations
  numRabbits = Rabbits + deltaRabbits;
  numFoxes = Foxes + deltaFoxes;
}

void plotCharacter(int numberOfSpaces, char character)
{
  //Prints out a specified number of spaces
  for(int i = 0; i < numberOfSpaces; i++)
  {
    cout << " ";
  }

  //prints out a specified character
  if(character == 'F' || character == '*')
  {
    cout << character << endl;
    return;
  }
}

void incrementCounter(int* integer)
{
  *integer += 1;
}

void chartingFunction(double numberOfRabbits, double numberOfFoxes, double fractionalScaleFactor)
{
  //checks to see if the number of rabbits is equal to that of the number of foxes
  if(floor(numberOfRabbits*fractionalScaleFactor)+1 == floor(numberOfFoxes*fractionalScaleFactor)+1)
    plotCharacter(floor(numberOfRabbits*fractionalScaleFactor)+1, '*');


  plotCharacter(floor(numberOfRabbits*fractionalScaleFactor)+1, 'r');
  plotCharacter(floor((numberOfRabbits-numberOfFoxes)*fractionalScaleFactor)+1, 'F');
}
