#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
    queue<int> left;
    queue<int> right;
    queue<int> cars;
    int c;
    int n;
    int t;
    int m;
    int arrivetime;
    string bank;
    char boat;
    int ct; //current time
    int nt; //new time
    cin >> c;

    for (int a = 0; a < c; a++) {

        cin >> n;
        cin >> t;
        cin >> m;

        boat = 'l';
        for (int b = 0; b < m; b++) {
            cin >> arrivetime;
            cin >> bank;
            if (bank == "left") {
                left.push(arrivetime);
            } else {
                right.push(arrivetime);
            }
        }

        ct = 0;
        while (!left.empty() || !right.empty()) {

            switch (boat) {
            case 'l': { //pickup from left
                for (int c = 0; c < n; c++) {
                    if (left.front() <= ct) {
                        cars.push(left.front() + ct);
                        left.pop();
                    } else {
                        break;
                    }
                }
                //traveling
                if (!cars.empty()) {
                    while (!cars.empty()) {
                        cout << cars.front() + t << endl;
                        cars.pop();
                    }
                    boat = 'r';
                    ct = ct + t;
                } else if (cars.empty()) {
                    if (right.front() <= ct) {
                        ct = ct + t;
                        boat = 'r';
                    }
                } else //not traveling
                {
                    ct++;
                }
            }

            case 'r': {
                for (int c = 0; c < n; c++) {
                    if (right.front() <= ct) {
                        cars.push(right.front() + ct);
                        right.pop();
                    } else {
                        break;
                    }
                }
                //traveling
                if (!cars.empty()) {
                    while (!cars.empty()) {
                        cout << cars.front() + t << endl;
                        cars.pop();
                    }
                    boat = 'l';
                    ct = ct + t;
                } else if (cars.empty()) {
                    if (left.front() <= ct) {
                        ct = ct + t;
                        boat = 'r';
                    }
                } else //not traveling
                {
                    ct++;
                }
            }
            }
        }

        cout << endl;
    }
    return 0;
}