#include<TROOT.h>
#include<TH1F.h>
#include<TMath.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<iostream>

using namespace std;


class Analyzer{

 public:
	Analyzer();
	~Analyzer();
	double Poisson(int, double);
	double UPL(int, double); //Upper Poisson Limit
	double LPL(int, double); //Lower Poisson Limit

 private:
	double CL, UP, LP, lambda;
	int r; 

};
