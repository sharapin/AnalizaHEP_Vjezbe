#include <TROOT.h>
#include <TChain.h>

#include <TRandom3.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TMath.h>
#include <TLegend.h>

#include <iostream>

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TF1.h>
#include <vector>
#include <TStyle.h>

using namespace std;

// Header file for the classes stored in the TTree if any.

class Analyzer
{
  public:
    Analyzer();
    ~Analyzer();
    void Histogram();

  private:
};