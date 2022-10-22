#include<string>
#include<iostream>
using namespace std;

#include "ElementaryParticle.h"

int main()
{
  
  ElementaryParticle Higgs("Higgs Boson",125,"boson");
  ElementaryParticle Top("Top Quark",173,"fermion");
  ElementaryParticle Z("Z Boson",91,"boson");  

  Higgs.printInfo();  
  Top.printInfo();
  Z.printInfo();

}
