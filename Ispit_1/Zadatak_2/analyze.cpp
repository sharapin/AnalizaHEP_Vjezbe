#include"Analyzer.h"

int main(void){

Analyzer *analyzer = new Analyzer();
cout << "UPL = " << analyzer -> UPL(100, 0.95) << endl;
cout << "LPL = " << analyzer -> LPL(100, 0.95) << endl;
analyzer -> ~Analyzer();

return 0;
}
