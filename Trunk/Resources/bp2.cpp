#include <iostream>

using namespace std;

void convert(int arr[], int start, int end){
    if(start>end){
        return;
    }
    int mid = (start + end)/2;
    cout<<arr[mid]<<"  ";
    convert(arr, start, mid-1);
    convert(arr, mid+1, end);
    return;
}

void printSorted(int arr[], int start, int end) 
{      
  if(start > end) 
    return; 
  
  // print left subtree 
  printSorted(arr, start*2 + 1, end); 
  
  // print root 
  printf("%d  ", arr[start]); 
  
  // print right subtree 
  printSorted(arr, start*2 + 2, end);   
} 
  
int main() 
{ 
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14}; 
  int arr_size = sizeof(arr)/sizeof(int); 

  cout<<arr_size<<endl;
  printSorted(arr, 0, arr_size-1); 
  cout<<endl;
  convert(arr, 0, arr_size-1);
  return 0; 
} 