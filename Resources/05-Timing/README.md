## Timer.hpp - A timer class

### Usage

```cpp
// Usage: 

#include <iostream>
#include "Timer.hpp"

using namespace std;

int main(){
    Timer T;
    T.Start();
   
    T.Sleep(1500); //milliseconds

    T.End(); 

    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
}
```