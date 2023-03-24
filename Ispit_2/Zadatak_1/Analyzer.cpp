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

void Analyzer::GaussFit()
{
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
      sigma_x[i] = 0;
      i++;
   }

   gr = new TGraphErrors(11, x_array, sigma_x);
   gr->Fit(Gauss);

   gr->SetTitle("Gauss fit");
   gr->SetMarkerColor(kBlack);
   gr->SetMarkerStyle(21);
   gr->SetMaximum(0.9);
   gr->SetMinimum(-0.7);
   gr->GetXaxis()->SetTitle("X-os");
   gr->GetYaxis()->SetTitle("Y-os");
   gr->Draw("AP");

   c->SaveAs("Gauss_Histogram.pdf");

   cout << "mi = " << Gauss->GetParameter(1) << " +- " << Gauss->GetParError(1) << "\n";
   cout << "sigma = " << Gauss->GetParameter(2) << " +- " << Gauss->GetParError(2) << "\n";
}
