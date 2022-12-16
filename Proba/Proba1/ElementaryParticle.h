#include<string>
#include<math.h>
#include<iostream>
#include<ctime>
#include<cstdlib>

#include<stdio.h>
#include<stdlib.h>

using namespace std;

// long idum=(-2578);
// FILE *fin, *fout; 

class ElementaryParticle
{ 
  public:
  
  ElementaryParticle(string name, double mass, string spin); 
  ElementaryParticle();

  string name;
  double mass;
  string spin;
  double impulsx;
  double impulsy;
  double impulsz;  
  double Energy;  
  double TransImpuls;
  int random; 
               
  void printInfo();

  void InsertImpulsF();

  double EnergyF(double, double, double); 

  double TransImpulsF(double, double, double);

  void bosonDecay(ElementaryParticle*, ElementaryParticle*);


};	
