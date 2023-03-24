#include <iostream>
#include <fstream>

// My own class
#include <Analyzer.h>

using namespace std;

int main()
{
  Analyzer* analyzer = new Analyzer();

  analyzer->Histogram();

  delete analyzer;

  return 0;
}