// Hash.h: interface for the CHash class.
//
//////////////////////////////////////////////////////////////////////

#include "GeneralHashFunctions.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Type to display a coalesced hash function somewhat
//visually (without lines etc.).
struct ChainPointerType {
    string ChainId;        //What chain is a value in (A,B,C....)
    int OrderInserted;     //When was a value inserted into table (1-N) where N = data set size.
    int ArrayIndexPointer; //Index of next value in chain, if any.
};

struct HashTableType {
    string Key;                    //hashed value in table
    ChainPointerType ChainPointer; //values defining a coalesced chain
};

class CHash {
private:
    bool CellarFull;
    int Collisions;
    void NextChainId();
    HashTableType *HashTable; //Structure to hold coalesced hash table
    int HashTableSize;        //Data portion of hash table (not the cellar)
    int ArraySize;            //Total array size (including cellar)
    string FileName;          //filename to dump hash table to
    int OrderInserted;        //value showing when a value was placed into hash table
    string ChainId;           //what chain a hashed value belongs to (if any)
    double HashTableRatio;    //ratio of data portion vs cellar portion of coalesced hash
    double MaxLoadFactor;     //ratio of cells available to data being hashed
    double CurrentLoadFactor; //how full is the hash table currently
    int CellarIndex;          //index value pointing to top of cellar
    inline std::string to_string(int t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }
    int InsertCellar(string, string);
    unsigned int HashFunction(string, string);

public:
    double GetAverageProbes();
    double GetCurrentLoadFactor();
    CHash();
    CHash(int);
    CHash(int, string);
    int GetCollisions();
    int GetTotalInserted();
    bool Full();
    void SetMaxLoadFactor(double InLoadFactor);
    void SetHashTableRatio(double);
    void InitializeHashTable();
    void PrintHashTable(int);
    void SetArraySize(int);
    bool Insert(string, string);
    bool Search(string);

    ~CHash();
};
