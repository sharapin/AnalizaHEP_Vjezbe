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
    cout<< "Mass: " << mass <<endl;
    cout<< "Spin Type: " << spin <<endl;
    cout<<endl;  
} 

};	
