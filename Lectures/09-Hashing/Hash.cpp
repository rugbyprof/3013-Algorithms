// Hash.cpp: implementation of the CHash class.
//
//////////////////////////////////////////////////////////////////////

#include "Hash.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction
//////////////////////////////////////////////////////////////////////

CHash::CHash()
{
	ArraySize = 997;
	HashTableSize=ArraySize;
	HashTableRatio=1;
	FileName = "HashOut.txt";
	HashTable = new HashTableType[ArraySize];
	OrderInserted=0;
	ChainId='A';
	CellarIndex=997;
	Collisions = 0;
	CellarFull = false;
	CurrentLoadFactor = 0.0;
}

CHash::CHash(int size)
{
	ArraySize = size;
	HashTableSize = ArraySize;
	HashTableRatio=1;
	FileName = "HashOut.txt";
	HashTable = new HashTableType[ArraySize];
	OrderInserted=0;
	ChainId='A';
	CellarIndex=size;
	Collisions = 0;
	CellarFull = false;
	CurrentLoadFactor = 0.0;

}

CHash::CHash(int size, string InFileName)
{
	ArraySize = size;
	HashTableSize = size;
	HashTableRatio=1;
	FileName = InFileName;
	HashTable = new HashTableType[ArraySize];
	OrderInserted=0;
	ChainId='A';
	CellarIndex=size;
	Collisions = 0;
	CellarFull = false;
	CurrentLoadFactor = 0.0;

}

//////////////////////////////////////////////////////////////////////
// Methods
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// HashFunction:
// Description: Gives user ability to specify a certain hash function
//
// Inputs:	string name - chooses which hash function to use
//			string key - value to be hashed
// Returns	integer hash key
//////////////////////////////////////////////////////////////////////

unsigned int CHash::HashFunction(string name, string key)
{

	if(name=="RSH")
		return RSHash(key)%HashTableSize;
	else if(name=="JSH")
		return JSHash(key)%HashTableSize;
	else if(name=="PJWH")
		return PJWHash(key)%HashTableSize;
	else if(name=="ELFH")
		return ELFHash(key)%HashTableSize;
	else if(name=="BKDRH")
		return BKDRHash(key)%HashTableSize;
	else if(name=="SDBMH")
		return SDBMHash(key)%HashTableSize;
	else if(name=="DJBH")
		return DJBHash(key)%HashTableSize;
	else if(name=="DEKH")
		return DEKHash(key)%HashTableSize;
	else if(name=="BPH")
		return BPHash(key)%HashTableSize;
	else if(name=="FNVH")
		return FNVHash(key)%HashTableSize;
	else if(name=="APH")
		return APHash(key)% HashTableSize;
	else if(name=="RAND")
		return rand() % HashTableSize;
	else
		return -1;
}

//////////////////////////////////////////////////////////////////////
// Full:
// Description:	Determines if hash table is full, based on load factor, 
//				not available cells in the array.
//
// Inputs:	none

// Returns:	bool value specifying full or not
//////////////////////////////////////////////////////////////////////
bool CHash::Full()
{
	return (CurrentLoadFactor >= MaxLoadFactor) || CellarFull;
}

//////////////////////////////////////////////////////////////////////
// SetMaxLoadFactor:
// Description:	user sets max loadfactor of hash table
// Inputs:	double InMaxLoadFactor - value between 0 -1 to set the hash 
//									 tables max load factor
//
// Returns:	nada
//////////////////////////////////////////////////////////////////////
void CHash::SetMaxLoadFactor(double InMaxLoadFactor)
{
	MaxLoadFactor = InMaxLoadFactor;
}

//////////////////////////////////////////////////////////////////////
// Insert:
// Description: Insert a word into hash table
// Inputs:	string word - value to be hashed
//
// Returns:	bool value of success 
//////////////////////////////////////////////////////////////////////
bool CHash::Insert(string word,string HashChoice)
{
	int CellarLink=0;
	int HashKey = HashFunction(HashChoice,word);
	//int HashKey =ELFhash(word);
	//HashKey = 3;
	if(HashTable[HashKey].Key.length()>0){//location full
		Collisions++;
		if(HashTable[HashKey].ChainPointer.ChainId == "null"){//location full, but no others in chain
			CellarLink = InsertCellar(word,ChainId);
			if(CellarLink>0){
				HashTable[HashKey].ChainPointer.ChainId=ChainId;
				HashTable[HashKey].ChainPointer.ArrayIndexPointer=CellarLink;
				//HashTable[HashKey].ChainPointer.OrderInserted = ++OrderInserted;
				NextChainId();
				CurrentLoadFactor = (double)((double)OrderInserted / (double)ArraySize);
				//cout<<CurrentLoadFactor<<endl;
			}else{
				CellarFull=true;
				return 0;
			}
		}else{//it's already in a chain
			bool EndOfChain=false;
			int CurrKey = HashTable[HashKey].ChainPointer.ArrayIndexPointer;
			int PrevKey = CurrKey;
			string CurrentChainId = HashTable[CurrKey].ChainPointer.ChainId;
			CellarLink = InsertCellar(word,CurrentChainId);

			while(!EndOfChain){//follow the chain until the end.
				if(HashTable[CurrKey].ChainPointer.ArrayIndexPointer>=0){
					PrevKey = CurrKey;
					CurrKey = HashTable[CurrKey].ChainPointer.ArrayIndexPointer;
				}else{
					EndOfChain=true;
				}
			}
			HashTable[CurrKey].ChainPointer.ArrayIndexPointer=CellarLink;
			if(!(CellarLink>0)){
				CellarFull=true;
				return 0;
			}
		}
	}else{//location empty, just enter it
		HashTable[HashKey].Key = word;
		HashTable[HashKey].ChainPointer.OrderInserted = ++OrderInserted;
		CurrentLoadFactor = (double)((double)OrderInserted / (double)ArraySize);
		//cout<<CurrentLoadFactor<<endl;


	}
	//PrintHashTable(2);
	return 1;
}

//////////////////////////////////////////////////////////////////////
// InsertCellar:
// Description:	Places a word in cellar if collision occurs
// Inputs:	string word - value to be hashed
//			string CurrentChainId - value specifying which chain the word is in
// Returns:	int index of cellar location 
//////////////////////////////////////////////////////////////////////
int CHash::InsertCellar(string word,string CurrentChainId){

	if(CellarIndex<ArraySize){
		CellarFull=false;
		HashTable[CellarIndex].Key=word;
		HashTable[CellarIndex].ChainPointer.ChainId = CurrentChainId;		
		HashTable[CellarIndex].ChainPointer.OrderInserted = ++OrderInserted;
		HashTable[CellarIndex].ChainPointer.ArrayIndexPointer = -1;
		return CellarIndex++;
	}else{
		CellarFull=true;
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////
// InitializeHashTable:
// Description: Initializes hash table to spaces, -1's, nulls 
// Inputs:	none
//		
// Returns:	none
//////////////////////////////////////////////////////////////////////
void CHash::InitializeHashTable()
{
	HashTableSize = (int)(ArraySize*HashTableRatio);
	for(int i=0;i<ArraySize;i++){
		HashTable[i].Key="";
		HashTable[i].ChainPointer.ArrayIndexPointer = -1;
		HashTable[i].ChainPointer.OrderInserted = -1;
		HashTable[i].ChainPointer.ChainId = "null";
	}
	CellarIndex = HashTableSize;
	OrderInserted=0;
	ChainId='A';
	Collisions = 0;
	CellarFull=false;
	CurrentLoadFactor=0;
}

//////////////////////////////////////////////////////////////////////
// SetArraySize:
// Description: Sets or resets the total size of the array. Does not re-
//				initialize array.
// Inputs:	int InSize - size to set array.
//		
// Returns:	none
//////////////////////////////////////////////////////////////////////

void CHash::SetArraySize(int InSize){
	ArraySize = InSize;
	HashTableSize = (int)(ArraySize*HashTableRatio);
	delete [] HashTable;
	HashTable = new HashTableType[ArraySize];
	CellarIndex=HashTableSize;
}

//////////////////////////////////////////////////////////////////////
// SetHashTableRatio:
// Description: Sets ratio of hash table to cellar size
// Inputs:	double InHashTableRatio -  value between 0 and 1
//		
// Returns:	none
//////////////////////////////////////////////////////////////////////
void CHash::SetHashTableRatio(double InHashTableRatio)
{
	HashTableRatio = InHashTableRatio;
}

void CHash::NextChainId()
{	

	ofstream ofile;
	ofile.open("ChainId.txt",ios::app);
	ofile<<ChainId<<endl;
	ofile.close();
	int i=0;
	bool carry=true;

	for(i=ChainId.length()-1,carry=1;i>=0&&carry==true;i--){
		char t = ChainId[i];
		if(t=='Z'){
			ChainId[i]='A';
			if(i==0)
				ChainId =  "A" + ChainId;
			carry=true;
		}else{
			t++;
			ChainId[i]=t;
			carry=false;
		}

	}

}

//////////////////////////////////////////////////////////////////////
// SetHashTableRatio:
// Description: Prints the hash table:
//	0 = both (screen, and file) 
//	1 = screen only
//	2 = file only
// Inputs:	int choice - value 0,1,2 explain above
//		
// Returns:	none
//////////////////////////////////////////////////////////////////////

void CHash::PrintHashTable(int choice)
{

	string CoalesceValue="";
	char *temp= "";
	char upperleft = char(201);
	char upperright = char(187);
	char side = char(186);
	char bottomleft = char(200);
	char bottomright = char(188);
	char bottomdblt = char(202);
	char skinnyside = char(179);
	char skinnyline = char(196);
	char skinnyt = char(197);
	char topdblt = char(203);
	char topline = char(205);
    char leftdblsnglt = char(199);
	char middledblsnlt = char(215);
	char leftdblt = char(204);
	char rightdblt = char(185);
	char rightdblsnglt = char(182);
	char doubletcross = char(206);
	int i=0,j=0,k=0;

	std::stringstream out;

	if(choice<2){
		cout<<upperleft<<topline<<topline<<topline<<topline<<topline<<topdblt;
		for(j=0;j<18;j++)
			cout<<topline;
		cout<<topdblt<<setw(12)<<setfill(topline)<<topline<<upperright<<setfill(' ')<<endl;
		for(i=0;i<ArraySize;i++){

			CoalesceValue += 
				HashTable[i].ChainPointer.ChainId + ',' + to_string(HashTable[i].ChainPointer.OrderInserted) + ',' + to_string(HashTable[i].ChainPointer.ArrayIndexPointer);
			if(HashTableSize==i){
				cout<<side<<setfill('*')<<setw(19)<<"Cellar"<<setw(18)<<'*'<<side<<endl;
				cout<<leftdblsnglt<<setfill(skinnyline)<<setw(5)<<skinnyline<<middledblsnlt<<setw(18)<<skinnyline<<middledblsnlt<<setw(12)<<setfill(skinnyline)<<skinnyline<<setfill(' ')<<rightdblsnglt<<endl;
				cout<<setfill(' ');
			}
			cout<<side<<setw(5)<<i<<side<<setw(18)<<HashTable[i].Key<<side<<setw(12)<<CoalesceValue<<side<<endl;
			cout<<leftdblsnglt<<setfill(skinnyline)<<setw(5)<<skinnyline<<middledblsnlt<<setw(18)<<skinnyline<<middledblsnlt<<setw(12)<<setfill(skinnyline)<<skinnyline<<setfill(' ')<<rightdblsnglt<<endl;
			cout<<setfill(' ');
			CoalesceValue = "";
		}
		cout<<bottomleft<<topline<<topline<<topline<<topline<<topline<<bottomdblt;
		for(j=0;j<18;j++)
			cout<<topline;
		cout<<bottomdblt<<setw(12)<<setfill(topline)<<topline<<bottomright<<setfill(' ')<<endl;
	}
	if(choice != 1){
	    ofstream ofile;
		ofile.open(FileName.c_str());
		ofile<<endl<<endl;
		ofile<<'+'<<'-'<<'-'<<'-'<<'-'<<'-'<<'+';
		for(j=0;j<18;j++)
			ofile<<'-';
		ofile<<'+'<<setw(12)<<setfill('-')<<'-'<<'+'<<setfill(' ')<<endl;
		for(i=0;i<ArraySize;i++){
			CoalesceValue += 
				HashTable[i].ChainPointer.ChainId + ',' + to_string(HashTable[i].ChainPointer.OrderInserted) + ',' + to_string(HashTable[i].ChainPointer.ArrayIndexPointer);

			if(HashTableSize==i){
				ofile<<'|'<<setfill('*')<<setw(19)<<"Cellar"<<setw(18)<<'*'<<'|'<<endl;
				ofile<<'+'<<setfill('-')<<setw(5)<<'-'<<'+'<<setw(18)<<'-'<<'+'<<setw(12)<<setfill('-')<<'-'<<setfill(' ')<<'+'<<endl;
				ofile<<setfill(' ');
			}
			ofile<<'|'<<setw(5)<<i<<'|'<<setw(18)<<HashTable[i].Key<<'|'<<setw(12)<<CoalesceValue<<'|'<<endl;
			ofile<<'+'<<setfill('-')<<setw(5)<<'-'<<'+'<<setw(18)<<'-'<<'+'<<setw(12)<<setfill('-')<<'-'<<setfill(' ')<<'+'<<endl;
			ofile<<setfill(' ');
			CoalesceValue = "";
		}
		//ofile<<'+'<<'-'<<'-'<<'-'<<'-'<<'-'<<'+';
		//for(j=0;j<18;j++)
			//cout<<'-';
		//ofile<<'+'<<setw(8)<<setfill('-')<<'-'<<'+'<<setfill(' ')<<endl;
		ofile.close();
	}
	setfill(' ');
}

//////////////////////////////////////////////////////////////////////
// PrintTotal:
// Description: Prints the current order number for a value inserted
// Inputs:	none
// Outputs: int OrderInserted
// Returns:	none
//////////////////////////////////////////////////////////////////////
int CHash::GetTotalInserted()
{
	return OrderInserted;
}

//////////////////////////////////////////////////////////////////////
// GetCollisions:
// Description: returns number of collisions that occured to point when
//				function was called
// Inputs:	none
// Returns:	int number of collisions
//////////////////////////////////////////////////////////////////////
int CHash::GetCollisions()
{
	return Collisions;
}

//////////////////////////////////////////////////////////////////////
// destructor:
//////////////////////////////////////////////////////////////////////
CHash::~CHash()
{

}





double CHash::GetCurrentLoadFactor()
{
	return CurrentLoadFactor;
}

double CHash::GetAverageProbes()
{
	int TotalProbes=0;
	for(int i=0;i<HashTableSize;i++){
		if(HashTable[i].ChainPointer.ArrayIndexPointer < 0){
			TotalProbes++;
		}else{
			bool EndOfChain=false;
			int CurrentIndex = i;
			while(!EndOfChain){//follow the chain until the end.
				if(HashTable[CurrentIndex].ChainPointer.ArrayIndexPointer<0){
					EndOfChain=true;
				}else{
					CurrentIndex = HashTable[CurrentIndex].ChainPointer.ArrayIndexPointer;
				}

				TotalProbes++;
			}
		}

	}
	return (double)((double)TotalProbes/(double)HashTableSize);
}
