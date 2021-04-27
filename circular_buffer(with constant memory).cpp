#include <iostream>
#include <algorithm>
#include <string>
#include "getCPUTime.c"

double startTime = getCPUTime();

using namespace std;

class circularBuffer {
private:
    int buffSize;
    string buff[10000];
    int count;

public:
    circularBuffer() {
        buffSize = 10000;
        count = 0;
    }

    void leftShift() {
        reverse(begin(buff), begin(buff) - 1);
        reverse(begin(buff) + 1, end(buff));
        reverse(begin(buff), end(buff));
    }

    void enQ(string value) {
        buff[0] = value;
        leftShift();
    }

    void deQ() {
        while (buff[0] == "NULL") {
            leftShift();
            count++;
            if (count == buffSize) {
                cout << "buffer is empty";
                break;
            }
        }
        count = 0;
        buff[0] = "NULL";
        leftShift();
    }

    void printQ() {
        for (auto i:buff)
            if (i != "NULL")
                cout << i << " ";
        cout << endl;
    }
};

int main() {
    circularBuffer t;
    for (int i = 0; i < 10000; i++)
        t.enQ("1");
    for (int i = 0; i < 10000; i++)
        t.deQ();
    double endTime = getCPUTime();
    fprintf(stderr, "CPU time used = %lf\n", (endTime - startTime));
    return 0;
}