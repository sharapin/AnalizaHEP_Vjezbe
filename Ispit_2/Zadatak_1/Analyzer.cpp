#define Analyzer_cxx
#include "Analyzer.h"
#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TStyle.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

void Analyzer::Histogram()
{
    TFile *file = new TFile("/home/public/data/Toy/Gauss.root");
    TTree *tree = static_cast<TTree*>(file->Get("tree"));

    double x_observed;
    tree->SetBranchAddress("x_observed", &x_observed);

    // Define null and alternative hypotheses
    TF1 nullHypothesis("nullHypothesis", "gaus", 0, 15);
    nullHypothesis.SetParameters(1, 3, 1.5);

    TF1 alternativeHypothesis("alternativeHypothesis", "gaus", 0, 15);
    alternativeHypothesis.SetParameters(1, 7, 1.5);

    // Create histograms for test statistics
    TH1F histNullTestStat("histNullTestStat", "Null Hypothesis Test Statistic", 150, 0, 15);
    TH1F histAltTestStat("histAltTestStat", "Alternative Hypothesis Test Statistic", 150, 0, 15);

    // Generate test statistics and fill histograms
    int nTestStat = 10000;
    for (int i = 0; i < nTestStat; ++i) {
        histNullTestStat.Fill(nullHypothesis.GetRandom());
        histAltTestStat.Fill(alternativeHypothesis.GetRandom());
    }

    // Normalize histograms
    histNullTestStat.Scale(1.0 / histNullTestStat.Integral());
    histAltTestStat.Scale(1.0 / histAltTestStat.Integral());

    // Find the critical region
    double type2Error = 0.0;
    double targetError = 0.7;
    int criticalBin = 0;
    for (int i = 1; i <= histAltTestStat.GetNbinsX(); ++i) {
        type2Error += histAltTestStat.GetBinContent(i);
        if (type2Error >= targetError) {
            criticalBin = i;
            break;
        }
    }

    // Calculate critical sigma
    double criticalSigma = histAltTestStat.GetBinCenter(criticalBin);

    // Calculate p-value
    double pValue = 1 - histNullTestStat.Integral(histNullTestStat.FindBin(histAltTestStat.GetBinLowEdge(1)), criticalBin);

    // Print results
    std::cout << "Critical Sigma: " << criticalSigma << std::endl;
    std::cout << "P-Value: " << pValue << std::endl;

    TCanvas c("hyptest", "hyptest", 1000, 700);

    gStyle->SetOptStat(0);

    histNullTestStat.SetFillColor(kRed - 2);
    histNullTestStat.SetLineColor(kRed - 2);

    histNullTestStat.SetTitle("Hypothesis testing");
    histNullTestStat.GetXaxis()->SetTitle("x");
    histNullTestStat.GetYaxis()->SetTitle("x frequency");

    histNullTestStat.Draw("HIST");

    histAltTestStat.SetFillColor(kBlue - 4);
    histAltTestStat.SetLineColor(kBlue - 4);

    histAltTestStat.SetTitle("Hypothesis testing");
    histAltTestStat.GetXaxis()->SetTitle("x");
    histAlt
}