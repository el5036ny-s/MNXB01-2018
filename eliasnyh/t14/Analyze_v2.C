#include <fstream>
#include <iostream>

#include <TMath.h>   // math functions

using namespace std;

void analyze_v2_2particle() {
	
	Int_t nEvents = 0; // event counter
	
	string helpString; // help variable
	
	Double_t sum_factor = 0;
	Double_t sum_factor_Q = 0;

	// open input file
	ifstream file("phi_dist.dat");
	Int_t eventNo = -1;
	
	while(file >> helpString >> eventNo) {
	
		cout << "Reading event : " << eventNo << endl;
		nEvents++;
		
		Int_t nTracks = -1;
		file >> helpString >> nTracks;
		cout << "Event contains " << nTracks << " tracks" << endl;
		
		Double_t phi[nTracks];
		Int_t trackNo;
		
		// Read data from .dat file
		
		for(Int_t nt = 0; nt < nTracks; nt++) {
			
			file >> helpString >> helpString >> phi[nt]; // Is there a nicer way of doing this?
			
		}

		// Analyze data using standard v2{2} method
		
		Double_t sum_cos2 = 0;
		Double_t sum_sin2 = 0;
		
		Double_t sum_cos2_diff = 0;
		
		for(Int_t i = 0; i < nTracks; i++) {
			
			sum_cos2 += TMath::Cos(2*phi[i]);
			sum_sin2 += TMath::Sin(2*phi[i]);
			
		
			for(Int_t j = i+1; j < nTracks; j++) 
			{
		
				sum_cos2_diff += 2*TMath::Cos(2*(phi[i]-phi[j]));
				
			}
			
		}
		
		Double_t M = (Double_t) nTracks;
		
		// Calculate v2 using standard method
		Double_t two_particle_factor = sum_cos2_diff / ( M*(M - 1 ) );
		
		sum_factor += two_particle_factor;
		
		// Calculate v2 using Q vectors
		Double_t two_particle_Q = ( TMath::Power(sum_cos2, 2) + TMath::Power(sum_sin2, 2) - M ) / (M*(M-1));
		
		sum_factor_Q += two_particle_Q;

		
	}
	
	Double_t average_v2 = TMath::Sqrt( sum_factor / ( (Double_t) nEvents ) );
	Double_t average_v2_Q = TMath::Sqrt( sum_factor_Q / ( (Double_t) nEvents ) );
	
	cout << "average v2 = " << average_v2 << endl << "Q: average v2 = " << average_v2_Q << endl;
	
	
}
