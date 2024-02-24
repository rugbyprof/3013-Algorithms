///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Title:            Timer Class
// Semester:         Spring 2020
// Date:             3 Feb 2020
//
// Description:
//       This is a simple class that wraps the "chrono" data type and allows a user
//       to time code snippets at the granularity of seconds or milliseconds.
//
// Usage:
//      #include "timer.hpp"
//
//
//      Timer T;
//      T.Start();
//
//      // do stuff to be timed here
//
//      T.End();
//
//      double s = T.Seconds();
//      long m = T.MilliSeconds();
//
//      cout <<s << " seconds" <<endl;
//      cout <<m << " milli" <<endl;
//
/////////////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <thread>
#include <time.h>

using namespace std;

// typedef std::chrono::high_resolution_clock Time;
//typedef std::chrono::milliseconds Msec;
// typedef std::chrono::duration<float> Fsec;
// using std::chrono::duration_cast;
// using std::this_thread::sleep_for;

// int main()
// {
//     auto start = chrono::steady_clock::now();

//     // do some stuff here
//     sleep(3);

//     auto end = chrono::steady_clock::now();

//     cout << "Elapsed time in nanoseconds: "
//         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
//         << " ns" << endl;

//     cout << "Elapsed time in microseconds: "
//         << chrono::duration_cast<chrono::microseconds>(end - start).count()
//         << " µs" << endl;

//     cout << "Elapsed time in milliseconds: "
//         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
//         << " ms" << endl;

//     cout << "Elapsed time in seconds: "
//         << chrono::duration_cast<chrono::seconds>(end - start).count()
//         << " sec";

//     return 0;
// }

class Timer {
private:
    int seed;
    int micro;
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
    // Fsec seconds;
    // Msec milliseconds;

public:
    Timer() {
    }

    void Start() {
        //start = Time::now();
        start = chrono::steady_clock::now();
    }

    void End() {
        //end = Time::now();
        end = chrono::steady_clock::now();
    }

    auto NanoSeconds() {
        return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }

    auto Seconds() {
        return chrono::duration_cast<chrono::seconds>(end - start).count();
    }

    auto MilliSeconds() {
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }

    // double Seconds() {
    //     auto dur = end - start;
    //     auto secs = duration_cast<Fsec>(dur);
    //     return secs.count();
    // }

    // long MilliSeconds() {
    //     auto dur = end - start;
    //     auto millis = duration_cast<Msec>(dur);
    //     cout << dur.count() << endl;
    //     cout << duration_cast<micro>(dur) << endl;
    //     return millis.count();
    // }

    // void Sleep(long x) {
    //     sleep_for(Msec(x));
    // }
};
