#include <iostream>

using namespace std;

int rec(int n){
    if (n == 0){
        return 1;
    }
    
    return 3 * rec(n-1);
}

double avg(int A[][5],int r, int c){

}

int main(){
    int arr[2][5] =
    {
        {1,8,12,20,25},
        {5,9,13,24,26}
    };

    avg(arr,2,5);

}