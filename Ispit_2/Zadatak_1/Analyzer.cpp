#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop()
{
   if (!fChain) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0;

   for (Long64_t jentry = 0; jentry < nentries; jentry++) {
      if (LoadTree(jentry) < 0) break;
      nbytes += fChain->GetEntry(jentry);
   }
}

void Analyzer::ChiSquareFit()
{
   TCanvas *c = new TCanvas("c", "c", 1200, 800);
   gStyle->SetOptFit();

   float x_array[11] = {0};
   float y_array[11] = {0};
   float sigma_y[11] = {0};
   float sigma_x[11] = {0};

   fit_funciton = new TF1("fit_function", "[0]*TMath::Exp(-[1]*x)*TMath::Sin([2]*x)", 0.1, 10.);
   fit_funciton->SetParNames("A", "alpha", "beta");
   fit_funciton->SetParameters(0.2, 0.2, 2.);

   if (!fChain) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0;

   for (Long64_t jentry = 0, i = 0; jentry < nentries && i < 11; jentry++) {
      if (LoadTree(jentry) < 0) break;
      nbytes += fChain->GetEntry(jentry);

      x_array[i] = x;
      y_array[i] = y;
      sigma_y[i] = error;
      sigma_x[i] = 0;
      i++;
   }

   gr = new TGraphErrors(11, x_array, y_array, sigma_x, sigma_y);
   gr->Fit(fit_funciton);

   gr->SetTitle("Chi-Square function fit");
   gr->SetMarkerColor(kBlack);
   gr->SetMarkerStyle(21);
   gr->SetMaximum(0.9);
   gr->SetMinimum(-0.7);
   gr->GetXaxis()->SetTitle("x");
   gr->GetYaxis()->SetTitle("y");
   gr->Draw("AP");

   c->SaveAs("histo.pdf");

   cout << "alpha = " << fit_funciton->GetParameter(1) << " +- " << fit_funciton->GetParError(1) << "\n";
   cout << "beta = " << fit_funciton->GetParameter(2) << " +- " << fit_funciton->GetParError(2) << "\n";
}
