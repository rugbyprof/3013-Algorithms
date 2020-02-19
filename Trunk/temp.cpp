#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Card{
protected:
    string Rank;
    int value;
public:
    Card(){

    }

    bool operator==(Card& rhs){
        
    }
}


int main(){
    int arr[2][5] =
    {
        {1,8,12,20,25},
        {5,9,13,24,26}
    };

    avg(arr,2,5);

}