#include<Analyzer.h>

int main()
{
  Analyzer* analyzer = new Analyzer();
  analyzer->Fit();
  analyzer->~Analyzer();
  return 0;
}
