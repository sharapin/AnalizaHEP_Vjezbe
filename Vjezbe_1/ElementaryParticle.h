#include<string>
#include<math.h>
#include<iostream>
using namespace std;

class ElementaryParticle
{ 
  public:

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

  double EnergyF(double impulsx, double impulsy, double impulsz); 

  double TransImpulsF(double impulsx, double impulsy, double impulsz);


};	
