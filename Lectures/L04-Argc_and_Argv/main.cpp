#include <iostream>

using namespace std;

void usage(string processName) {
    cout << "##################################################################################" << endl;
    cout << "Usage  : " << processName << " fullThreshold emptyThreshold growRatio shrinkRatio" << endl;
    cout << "Example: " << processName << " 1.0 .15 2.0 0.5\n";
    cout << "##################################################################################" << endl;
}

int main(int argc, char **argv) {

    cout << "Argument Count = " << argc << endl;

    double fullThreshold = 1;
    double emptyThreshold = 0.15;
    double growRatio = 2.0;
    double shrinkRatio = .5;

    if (argc < 5) {
        usage(argv[0]);
    } else {
        cout << "Printing arguments ... \n";
        for (int i = 0; i < argc; i++) {
            if (i > 1) {
                // string to double
                cout << atof(argv[i]) << endl;
            } else {
                cout << argv[i] << endl;
            }
        }
    }
}