#include "Analyzer.h"

int main()
{
   Analyzer *analyzer;
  
       analyzer = new Analyzer();
  
         analyzer->ReadTxtFile("../Vjezbe_3/Analysis.txt");
           analyzer->ConvertTxtToRootFile("../Vjezbe_3/Analysis.txt","Analysis.root");
  
             delete analyzer;
  
               return 0;             
}
