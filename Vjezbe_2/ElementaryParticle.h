#include<string>
#include<math.h>
#include<iostream>
using namespace std;

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
  
               
  void printInfo();

  void InsertImpulsF();

  double EnergyF(double, double, double); 

  double TransImpulsF(double, double, double);

  void bosonDecay(ElementaryParticle*, ElementaryParticle*);


};	
