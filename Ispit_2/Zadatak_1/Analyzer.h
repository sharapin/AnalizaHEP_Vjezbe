#ifndef Analyzer_h
#define Analyzer_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

//ROOT headers
#include <TROOT.h>
#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TString.h>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TLine.h>
#include <TH1F.h>
#include <TMath.h>

// ... (Other includes and using statements)

class Analyzer {
public:
   // ... (Other member variables and functions)

   virtual void     GaussFit(); // Updated function name

private:
   TGraphErrors *gr;
   TF1 *Gauss;

};

#endif

#ifdef Analyzer_cxx
// ... (Other functions)

void Analyzer::GaussFit() {
   TCanvas *c = new TCanvas("c", "c", 1200, 800);
   gStyle->SetOptFit();

   float x_array[11] = {0};
   float y_array[11] = {0};
   float sigma_y[11] = {0};
   float sigma_x[11] = {0};

   Gauss = new TF1("Gauss", "[0]*TMath::Exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))", 70., 130.);
   Gauss->SetParNames("C", "mi", "sigma");
   Gauss->SetParameters(0.2, 0.2, 2.);

   if (!fChain) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0;

   for (Long64_t jentry = 0, i = 0; jentry < nentries && i < 11; jentry++) {
      if (LoadTree(jentry) < 0) break;
      nbytes += fChain->GetEntry(jentry);

      x_array[i] = x_observed;
      y_array[i] = y;
      sigma_y[i] = error;
      sigma_x[i] = 0;
      i++;
   }

   gr = new TGraphErrors(11, x_array, y_array, sigma_x, sigma_y);
   gr->Fit(Gauss);

   // Rest of the code
}

// ... (Other functions)

#endif // #ifdef Analyzer_cxx
