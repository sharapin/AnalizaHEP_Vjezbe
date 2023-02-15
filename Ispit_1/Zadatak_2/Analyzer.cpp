#include"Analyzer.h"


Analyzer::Analyzer(){

}


Analyzer::~Analyzer(){


}


double Analyzer::UPL(int r, double CL){


   for(int lambda=0;lambda<50000;lambda++)
   {
     UP+= 1.96 * sqrt((lambda/1000.)/r);
   }


return UP;

}


double Analyzer::LPL(int r, double CL){


   for(int lambda=0;lambda<50000;lambda++)
   {      
     LP+= -1.96*sqrt(LP/r);
   }


return LP;

}

