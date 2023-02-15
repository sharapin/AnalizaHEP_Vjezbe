#include"Analyzer.h"


Analyzer::Analyzer(){



}


Analyzer::~Analyzer(){



}


void Analyzer::Fit(){

	file = new TFile("/home/sharapin/Vjezbe/Ispit_1/Zadatak_1/Lifetime.root");
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
	f = new TF1("fit funkcija", "[0] * (TMath::Exp(-x / [1]) + TMath::Exp(-(x - [2]) * (x - [2]) / 2. / [3] / [3]))", 0, 10);
	f -> SetParameter(0, 224.);
	f -> SetParameter(1, 4.);
	f -> SetParameter(2, 3.);
	f -> SetParameter(3, 0.3);

	hist -> Fit(f, "L", "", 0, 10);

	hist -> SetTitle("Fit");
	hist -> GetXaxis() -> SetTitle("var");

	hist -> Draw("HIST");
	f -> Draw("SAME");
	canvas -> Print("Fit.pdf");

	cout << "A =" << f -> GetParameter(0) << "±" << f -> GetParError(0) << endl;
	cout << "alfa = " << f -> GetParameter(1) << "±" << f -> GetParError(1) << endl;
	cout << "mu = " << f -> GetParameter(2) << "±" << f -> GetParError(2) << endl;
	cout << "sigma = " << f -> GetParameter(3) << "±" << f -> GetParError(3) << endl;

}
