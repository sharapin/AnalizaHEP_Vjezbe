#include<string>
#include<math.h>
#include"ElementaryParticle.h"
#include<iostream>
using namespace std;



  ElementaryParticle::ElementaryParticle(string n, double m, string s)
  {
    name=n;
    mass=m;
    spin=s;
  }
  
  ElementaryParticle::ElementaryParticle()
  {}

               
  void ElementaryParticle::printInfo()
  {
    cout<<endl;
    cout<< "Name: " << name <<endl;
    cout<< "Mass: " << mass <<endl;
    cout<< "Spin Type: " << spin <<endl;
    cout<<endl;  
  } 
  

  void ElementaryParticle::InsertImpulsF()
  {
    cout<<"Insert impuls intensity for a chosen particle: "<<endl;
    cout<<"Impuls in x-direction: "; cin>>impulsx;
    cout<<"Impuls in y-direction: "; cin>>impulsy;
    cout<<"Impuls in z-direction: "; cin>>impulsz;
  }


  double ElementaryParticle::EnergyF(double impulsx, double impulsy, double impulsz) 
  {  
    Energy=sqrt(pow(sqrt(impulsx*impulsx + impulsy*impulsy + impulsz*impulsz),2)+mass*mass);   

  return Energy; 
  }
  

  double ElementaryParticle::TransImpulsF(double impulsx, double impulsy, double impulsz)
  {
    TransImpuls=sqrt(impulsx*impulsx + impulsy*impulsy); 

    return TransImpuls; 
  }


  void ElementaryParticle::bosonDecay(ElementaryParticle* decayParticle_1, ElementaryParticle* decayParticle_2)
  {
    if(spin!="boson")
      cout<<"Decay is not possible. "<<endl;
    else
      cout<<"Particle is boson. "<<endl; 
  }	
