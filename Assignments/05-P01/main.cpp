#include <iostream>
#include <fstream>

using namespace std;


int main(){
    ifstream fin("nums.dat");
    int num=0;

    int max=10;
    int count=0;
    int evens=0;
    int odds=0;
    int last=0;
    int 

    while(!fin.eof())
    {
        fin>>num;
        if(num % 2 == 0){
            count++;
            evens++;
            last=0;
        }else{
            count--;
            odds++;
            last=1;
        }

        if(count >= max){
            max *= 1.75;
        }

    }

    cout<<max<<" "<<evens<<" "<<odds<<endl;
}