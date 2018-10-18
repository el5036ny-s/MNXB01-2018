void hist_gen()
{
	#include <TStyle.h>
  TH1D* hist = new TH1D("hist", "Histogram", 40, -3, 3);
  hist->Sumw2();
  
  gStyle->SetOptFit();
  
  TF1* fGaus = new TF1("fGaus", "gaus", -3, 3);
  fGaus->SetParameters(1, 0, 1); // amplitude, mean, sigma

  for(Int_t i = 0; i < 10000; i++) {

    hist->Fill(fGaus->GetRandom());
  }

  hist->Draw();
}

//TH1D* hist = ...
//hist->Sumw2();
//gStyle->SetOptFit();
// also do #include <Tstyle.h>
