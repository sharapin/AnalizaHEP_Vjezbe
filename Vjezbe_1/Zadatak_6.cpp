#include<string>
#include<iostream>

using namespace std;


class ElementaryParticle
{ 
  public:

  string name;
  double mass;
  string spin;  
  
  ElementaryParticle(string n, double m, string s)
  {
    name=n;
    mass=m;
    spin=s;
  }
               
  void printInfo()
  {
    cout<<endl;
    cout<< "Name: " << name <<endl;
    cout<< "Mass: " << mass << " GeV" <<endl;
    cout<< "Spin Type: " << spin <<endl;
    cout<<endl;
  }
    
};



int main()
{  
                                    
/////////////////  A   /////////////////////////////           
/*

  ElementaryParticle Higgs;
  ElementaryParticle Top;
  
  Higgs.name="Higgs Boson";
  Higgs.mass=125;
  Higgs.spin="boson";
  
  Top.name="Top Quark";
  Top.mass=173;
  Top.spin="fermion";

  Higgs.printInfo(); 
  Top.printInfo(); 

*/
////////////////////   B   ////////////////////////// 
/*

  ElementaryParticle Higgs;
  ElementaryParticle Top;
  ElementaryParticle Z;  
  ElementaryParticle* pointer=&Z;
  
  Higgs.name="Higgs Boson";
  Higgs.mass=125;
  Higgs.spin="boson";
  
  Top.name="Top Quark";
  Top.mass=173;
  Top.spin="fermion";

  Z.name="Z Boson";
  Z.mass=91;
  Z.spin="boson";

  pointer->printInfo();  

*/
/////////////////////   C   ///////////////////////////////


  ElementaryParticle Higgs("Higgs Boson",125,"boson");
  ElementaryParticle Top("Top Quark",173,"boson");
  ElementaryParticle Z("Z Boson",91,"boson");
  
  cout<<endl;
  cout<< "Name: " << Higgs.name <<endl; 
  cout<< "Mass: " << Higgs.mass <<endl; 
  cout<< "Spin Type: " << Higgs.spin <<endl; 
  cout<<endl;  
  cout<< "Name: " << Top.name <<endl; 
  cout<< "Mass: " << Top.mass <<endl; 
  cout<< "Spin Type: " << Top.spin <<endl; 
  cout<<endl;
  cout<< "Name: " << Z.name <<endl; 
  cout<< "Mass: " << Z.mass <<endl; 
  cout<< "Spin Type: " << Z.spin <<endl; 
  cout<<endl;


////////////////////////   D   ////////////////////////////
/*
  
  ElementaryParticle Z("Z",91,"boson");
  ElementaryParticle* pointer=&Z;
  
  pointer ->printInfo();

*/ 
}
	
