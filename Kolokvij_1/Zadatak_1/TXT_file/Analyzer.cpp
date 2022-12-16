#include<string>
#include<math.h>
#include"Analyzer.h"
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<iostream>

using namespace std;


  FILE *fin, *fout;

  Generator::Generator(int random)
  {
    random;
  }
  

  void Generator::GeneratePDF() 
  { 
    fout=fopen("Analysis.txt","w"); 
   
    double function,r;
    int r1,r2;   
    
   for(int i=0;i<100000;i++)
   {  
    r=rand();    
    r1=rand();
    r2=rand();   
  
    {
      r=(r1/100000000.)-3;
      if(r>13)
        r=r-13;
    }

    function=-(r+3)*(r-9);
    fprintf(fout,"%0.2f   %0.2f \n",r,function);    

} 

    fclose(fout);   
  }
  
