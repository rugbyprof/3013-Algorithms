## Timer.hpp - A timer class

### Usage

```cpp
// Usage: 

#include <iostream>
#include "Timer.hpp"

using namespace std;

int main(){
    Timer T;                        // create a timer instance
    T.Start();                      // start your timer instance (get current clock value)
    double s;
    long m;
   
    // do stuff
    // do stuff
    T.Sleep(1500);                  //sleep for 1.5 seconds
    // do stuff
    // do stuff

    T.End();                        // end the clock

    s = T.Seconds();                // get how many seconds
    m = T.MilliSeconds();           // get how many millisecondxs

    cout <<s << " seconds" <<endl;  // print seconds
    cout <<m << " milli" <<endl;    // print milliseconds


    // do more stuff
    // do more stuff
    T.Sleep(2200);                  //sleep for 2.2 seconds
    // do more stuff
    // do more stuff

    T.End();                        // end the clock again

    s = T.Seconds();                // get how many seconds (since the first start)
    m = T.MilliSeconds();           // get how many millisecondxs (since the first start)

    cout <<s << " seconds" <<endl;  // print seconds
    cout <<m << " milli" <<endl;    // print milliseconds
}
```