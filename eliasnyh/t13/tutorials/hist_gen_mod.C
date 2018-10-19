#include <TH1.h>
#include <TF1.h>

#include <TStyle.h>

void hist_gen_mod(int nRandom, double sigma)
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

/* The value of Chi² exceeds 2 when the number of data points exceeds ~400 000 data points, which could be a threshold for a "bad" fit.
 */
