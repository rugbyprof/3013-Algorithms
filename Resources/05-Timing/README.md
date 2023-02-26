## Timer.hpp - A timer class

### Usage

```cpp
// Usage: 

#include <iostream>
#include "Timer.hpp"

using namespace std;

int main(){
    Timer T1;                        // create a timer instance
    Timer T2;                        // another instance
    T1.Start();                      // start your timer instance (get current clock value)
    double s;
    long m;
   
    // do stuff
    // do stuff
    T1.Sleep(1500);                  //sleep for 1.5 seconds
    // do stuff
    // do stuff

    T1.End();                        // end the clock

    s = T1.Seconds();                // get how many seconds
    m = T1.MilliSeconds();           // get how many millisecondxs

    cout <<s << " seconds" <<endl;  // print seconds
    cout <<m << " milli" <<endl;    // print milliseconds

    T2.Start();                     // start second instance
    // do more stuff
    // do more stuff
    T1.Sleep(2200);                  //sleep for 2.2 seconds
    // do more stuff
    // do more stuff

    T1.End();                        // end both clocks
    T2.End();                       

    s = T1.Seconds();                // get how many seconds (since the FIRST start)
    m = T1.MilliSeconds();           // get how many millisecondxs (since the FIRST start)

    cout <<s << " seconds" <<endl;  // print total seconds
    cout <<m << " milli" <<endl;    // print total milliseconds

    s = T2.Seconds();                // get how many seconds (since the second start)
    m = T2.MilliSeconds();           // get how many millisecondxs (since the second start)

    cout <<s << " seconds" <<endl;  // print seconds
    cout <<m << " milli" <<endl;    // print milliseconds
}
```