#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "Hash.h"

using namespace std;

string RandomWord(int length){
	string word="";
	for(int i=0;i<length;i++){
		word += char((rand()%26)+65);
	}
	return word;
}

const int SIZE = 997;

void main(){

	CHash H;
	int i=0;
	int h=0;

	ifstream ifile;
	string temp = " ";

	srand(time(0));

	ifile.open("dictionary.TXT");


	H.SetArraySize(SIZE);
	H.InitializeHashTable();

	string DataArray[SIZE];
	string HashArray[] = {"RSH","JSH","PJWH","ELFH","BKDRH","SDBMH","DJBH","DEKH","BPH","FNVH","APH","RAND"};


	for(i=0;i<SIZE;i++){
		DataArray[i] = RandomWord(5);
	}


	for(h=0;h<12;h++){ 	
		cout<<HashArray[h]<<endl;
		for(double B=.50;B>=.05;B-=.05){
			H.SetHashTableRatio(B);	
			for(double L=.7;L<=1;L+=.05){
				H.SetMaxLoadFactor(L);
				H.InitializeHashTable();
				i=0;
				while(!H.Full()){
					if(!H.Insert(DataArray[i],HashArray[h])){
						break;
					}else{
						i++;
						//cout<<H.GetCurrentLoadFactor()<<" ";
					}
				}
				//H.PrintHashTable(0);
				//exit(0);
				cout<<setprecision(2)<<fixed;
				cout<<"B:"<<setw(5)<<B<<" , "<<"L:"<<setw(5)<<L<<" , Total Inserted:"<<setw(5)<<H.GetTotalInserted()<<
					" Average Probes:"<<setw(5)<<H.GetAverageProbes()<<endl;
			}
		}
	}


}