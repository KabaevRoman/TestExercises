#include <iostream>
#include <vector>

using namespace std;

class circularBuffer {
private:
    vector<int> buff;
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
        if (buff.empty()) {
            cout << "buffer is empty" << endl;
        } else {
            buff.erase(buff.begin() + count % buffSize);
        }
        printQ();//опционально, использовалось для проверки работспособности
    }

    void enQ(int value) {
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
        printQ();//опционально, использовалось для проверки работспособности
    }
};

int main() {
    circularBuffer t(6);
    for (int i = 0; i < 8; i++)
        t.enQ(i);
    t.printQ();
    t.deQ();
    t.deQ();
    t.deQ();
    t.enQ(9);
    t.deQ();
    t.enQ(1);

    return 0;
}
