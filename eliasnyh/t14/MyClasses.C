
#include <TObject.h>

class MyEvent : public TObject {
	private:
	
		Int_t nTracks;
		Double_t fV2;
	
	public:
		
		MyEvent();

		ClassDef(MyEvent, 1); // Help class
		
		void SetnTracks(Int_t newTracks) {
			
			nTracks = newTracks;
			
		}
		
		Int_t GetnTracks() {
			
			return nTracks;
			
		}
		
		void SetfV2(Double_t newfV2) {
			
			fV2 = newfV2;
			
		}
		
		Double_t GetfV2() {
			
			return fV2;
			
		}
	};

ClassImp(MyEvent)

MyEvent::MyEvent():
TObject(),
	nTracks(-1),
	fV2(-1)
{

// default constructor

};





class MyTrack : public TObject {
	public:
	
		Double_t fPhi;
		MyTrack();
		
		ClassDef(MyTrack, 1);
		
		void SetfPhi(Double_t newfPhi) {
			
			fPhi = newfPhi;
			
		}
		
		Double_t GetfPhi() {
			
			return fPhi;
			
		}
};

ClassImp(MyTrack)

MyTrack::MyTrack():
TObject(),
	fPhi(-1)
{
	// Constructor
};
