#include<string>
#include<math.h>
#include<iostream>
#include "ElementaryParticle.h"

using namespace std;


int main()
{
  double Energy;  
  double Impuls;

  ElementaryParticle Higgs("Higgs Boson",125,"boson");
  ElementaryParticle Top("Top Quark",173,"fermion");
  ElementaryParticle Z("Z Boson",91,"boson");  

  Higgs.printInfo();  

  Higgs.InsertImpulsF();
 
  Energy=Higgs.EnergyF(Higgs.impulsx, Higgs.impulsy, Higgs.impulsz);
  cout<<endl<<"Energy of the Higgs Particle: "<< Energy <<endl;

  Impuls=Higgs.TransImpulsF(Higgs.impulsx, Higgs.impulsy, Higgs.impulsz);
  cout<<endl<<"Transverzal Impuls of the Higgs Particle: "<< Impuls <<endl;

}
