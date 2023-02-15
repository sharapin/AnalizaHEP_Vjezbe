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
	hist = new TH1F("hist", "hist", 100, 0., 10.);
	for (int i = 0; i < nentries; i++){

		tree -> GetEntry(i);
		hist -> Fill(var);
	
	}
	gStyle -> SetOptStat(0);
	f = new TF1("fit funkcija", "(TMath::Exp(-x*[1]) * TMath::Sin(x * [2])", 0, 10);
	f -> SetParameter(0, 224.);
	f -> SetParameter(1, 4.);
	f -> SetParameter(2, 3.);
	f -> SetParameter(3, 0.3);

	hist -> Fit(f, "L", "", 0, 10);

	hist -> SetTitle("Fit_Function");
	hist -> GetXaxis() -> SetTitle("x");

	hist -> Draw("HIST");
	f -> Draw("SAME");
	canvas -> Print("Fit_ChiSquareTree.pdf");

	cout << "A =" << f -> GetParameter(0) << "±" << f -> GetParError(0) << endl;
	cout << "alfa = " << f -> GetParameter(1) << "±" << f -> GetParError(1) << endl;
	cout << "mu = " << f -> GetParameter(2) << "±" << f -> GetParError(2) << endl;
	cout << "sigma = " << f -> GetParameter(3) << "±" << f -> GetParError(3) << endl;

}
