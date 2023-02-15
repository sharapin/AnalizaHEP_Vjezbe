#include"Analyzer.h"


Analyzer::Analyzer(){

}


Analyzer::~Analyzer(){


}


double Analyzer::UPL(int r, double CL){


   for(int lambda=0;lambda<50000;lambda++)
   {
     double UP;
      
     UP=lambda + 1.96 * sqrt(lambda/r);
   }


return UP;

}


double Analyzer::LPL(int r, double CL){


   for(int lambda=0;lambda<50000;lambda++)
   {
     double LP=lambda;     
      
     LP=LP - 1.96 * sqrt(LP/r);
   }


return LP;

}

