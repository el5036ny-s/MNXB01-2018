/* 
   In this ROOT function we generate a distribution according to sin(x)
   between 0 and pi

   To run do:
   root 
   .L rootgenerate_sinx.C+ 
   rootfuncgenerate(10000)
*/

// include C++ STL headers 
#include <iostream>

using namespace std;

// ROOT library obejcts
#include <TF1.h> // 1d function class
#include <TH1.h> // 1d histogram classes
#include <TStyle.h>  // style object
#include <TMath.h>   // math functions
#include <TCanvas.h> // canvas object
#include <TFile.h>
#include <TTree.h>
#include <TClonesArray.h>

#include <fstream>

#include "MyClasses.C"

void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t v2); // ROOT method (a bit dangerous since we don't know exactly what happens!)


//_______________________________________________________________________
void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t sigmaTracks, Double_t v2, Double_t sigmaV2)
{
	
	
	
  cout << "Generating " << nEvents << " events" << endl << endl;

  // create histogram that we will fill with random values
  TH1D* hPhi = new TH1D("hPhi", "ROOT func generated v2 distribution; phi; Counts", 
			100, 0, TMath::Pi());

  // Define the function we want to generate
  TF1* v2Func = new TF1("v2Func", "1+[0]*cos(2*x)", 0, TMath::Pi());
  
  Int_t currentNTracks;
  Double_t currentV2;
  
	
	// Gauss distributions for nTracks and v2
	
	 TF1* tracksGaus = new TF1("tracksGaus", "gaus", 1, 10000);
	tracksGaus->SetParameters(1, nTracks, sigmaTracks);
	
	TF1* v2Gaus = new TF1("v2Gaus", "gaus", 0, 0.5);
	v2Gaus->SetParameters(1, v2, sigmaV2);

	TFile* file = new TFile("phi_dist.root", "RECREATE");
	TTree* tree = new TTree("tree", "Output tree");
	
	MyEvent* event = new MyEvent();
	
	tree->Branch("event", &event);
	TClonesArray* trackArray = new TClonesArray("MyTrack", 1000);
	tree->Bronch("track", "TClonesArray", &trackArray);
	
	Int_t nT = 0;
  
  // make a loop for the number of events
  for(Int_t n = 0; n < nEvents; n++) {
	 
	currentV2 = v2Gaus->GetRandom();
	v2Func->SetParameter(0, currentV2);
	
	currentNTracks = tracksGaus->GetRandom();
	
    Double_t phi[currentNTracks];
    
    event->SetnTracks(currentNTracks);
    event->SetfV2(currentV2);
    
    // generate nTracks phi angles
	for (Int_t nt = 0; nt < currentNTracks; nt++) 
	{
		
		phi[nt] = v2Func->GetRandom();
		MyTrack* track = new((*trackArray)[nT]) MyTrack();
		nT++;
		track->SetfPhi(phi[nt]);
		
	}
	tree->Fill();
    trackArray->Clear();
 
  }
  
  file->Write();
  file->Close();
  
}
