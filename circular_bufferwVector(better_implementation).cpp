#include <iostream>
#include <vector>
#include <string>
#include "getCPUTime.c"

double startTime = getCPUTime();

using namespace std;

class circularBuffer {
private:
    vector<string> buff;
    int count = 0;
    int buffSize;
public:
    circularBuffer(int size) {
        buffSize = size;
    }

    void printQ() {
        for (auto i:buff)
            cout << i << " ";
        cout << endl;
    }

    void deQ() {
        if ((buff.size() - 1) < (count % buffSize)) {
            count -= count % buffSize;
        }
        if (buff.size() == 0) {
            cout << "buffer is empty" << endl;
        } else {
            buff.erase(buff.begin() + count % buffSize);
        }
    }

    void enQ(string value) {
        if (count < buffSize) {
            buff.push_back(value);
            count++;
        } else if (buff.size() < buffSize) {
            buff.insert(buff.begin() + count % buffSize, value);
            count++;
        } else {
            *(buff.begin() + count % buffSize) = value;
            count++;
        }
    }
};

int main() {
    circularBuffer t(10000);
    for (int i = 0; i < 10000; i++)
        t.enQ("1");
    for (int i = 0; i < 10000; i++)
        t.deQ();
    double endTime = getCPUTime();
    fprintf(stderr, "CPU time used = %lf\n", (endTime - startTime));
    return 0;
}