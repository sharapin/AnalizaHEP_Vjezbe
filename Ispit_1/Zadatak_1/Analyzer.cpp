#include"Analyzer.h"


Analyzer::Analyzer(){



}


Analyzer::~Analyzer(){



}


void Analyzer::Fit(){

	file = new TFile("/home/public/data/Toy/ChiSquareTree.root");
	tree = (TTree*)file -> Get("tree");
	tree -> SetBranchAddress("var", &var);
	Long64_t nentries = tree -> GetEntriesFast();
	canvas = new TCanvas();
	canvas -> SetCanvasSize(700, 700);
	hist = new TH1F("hist", "hist", 100, 0., 0.03);
	for (int i = 0; i < nentries; i++){

		tree -> GetEntry(i);
		hist -> Fill(var);
	
	}
	gStyle -> SetOptStat(0);
	f = new TF1("fit funkcija", "(TMath::Exp(-x*[0]) * TMath::Sin(x * [1]))", 0, 0.03);
	f -> SetParameter(0, 0.2);
	f -> SetParameter(1, 2.);

        hist -> SetMaximum(0.15);        

	hist -> Fit(f, "L", "", 0, 0.03);

	hist -> SetTitle("Fit_Function");
	hist -> GetXaxis() -> SetTitle("x");

	hist -> Draw("HIST");
	f -> Draw("SAME");
	canvas -> Print("Fit_ChiSquareTree.pdf");

	cout << "alfa =" << f -> GetParameter(0) << "±" << f -> GetParError(0) << endl;
	cout << "beta = " << f -> GetParameter(1) << "±" << f -> GetParError(1) << endl;

}
