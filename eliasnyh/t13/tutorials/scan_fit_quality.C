
#include <TH1.h>
#include <TF1.h>

#include <TStyle.h>

double hist_gen_mod(int nRandom, double sigma)
{
  TH1D* hist = new TH1D("hist", "Histogram", 40, -3, 3);
  
  
  
  
  TF1* fGaus = new TF1("fGaus", "gaus", -3, 3);
  fGaus->SetParameters(1, 0, sigma); // amplitude, mean, sigma

  for(Int_t i = 0; i < nRandom; i++) {

    hist->Fill(fGaus->GetRandom());
  }
  
hist->SetMinimum(0);	
hist->Sumw2();
hist->Draw();
hist->Fit("pol2");
gStyle->SetOptFit();
}

scan_fit_quality(const Int_t nRandomMin, const Int_t nRandomMax, const Double_t sigma)
{
	/*TH1D* sigmaHist = new TH1D("sigmaHist", "Histogram", 10, nRandomMin, nRandomMax);
	
	double deltaNRandom = (nRandomMax - nRandomMin) / 9;
	for(int i = 0; i < 10; i++){
		hist_gen_mod(nRandomMin + deltaNRandom, sigma);
	*/
	hist_gen_mod(nRandomMin, sigma);
	fGaus->GetChisquare();
}
