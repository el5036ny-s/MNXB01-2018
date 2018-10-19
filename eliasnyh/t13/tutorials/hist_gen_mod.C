#include <TH1.h>
#include <TF1.h>

#include <TStyle.h>

void hist_gen_mod(int nRandom, double sigma)
{
  TH1D* hist = new TH1D("hist", "Histogram", 40, -3, 3);
  
  
  //gStyle->SetOptFit();
  
  TF1* fGaus = new TF1("fGaus", "gaus", -3, 3);
  fGaus->SetParameters(1, 0, sigma); // amplitude, mean, sigma

  for(Int_t i = 0; i < nRandom; i++) {

    hist->Fill(fGaus->GetRandom());
  }
  
hist->SetMinimum(0);	
hist->Sumw2();
hist->Draw();
hist->Fit("pol2");

}

//TH1D* hist = ...
//gStyle->SetOptFit();
