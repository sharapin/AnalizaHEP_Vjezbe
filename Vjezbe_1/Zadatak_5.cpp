#include<iostream>

using namespace std;


double _my_cube(double x)
{
  double x3;

  x3=x*x*x;

return x3;
}


int main()
{
  double x; 

  cout<< "Write a real number to get a cube of that number: ";
  cin>>x;
  cout<< "Cube of that number is: "<< _my_cube(x) <<endl;
  
}

