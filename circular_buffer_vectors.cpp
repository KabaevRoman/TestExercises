#include <iostream>
#include <vector>



using namespace std;

class circularBuffer {
private:
    vector<int> buff;
    int count = 0;
    int buffSize;
public:
    circularBuffer() {
        buffSize = 5;
    }

    circularBuffer(int size) {
        buffSize = size;
    }

    void printQ() {
        if (!buff.empty()) {
            for (auto i:buff)
                cout << i << " ";
            cout << endl;
        } else { cout << "buffer is empty\n"; }
    }

    void deQ() {
        if ((buff.size() - 1) < (count % buffSize)) {
            count -= count % buffSize;
        }
        if (buff.empty()) {
            cout << "buffer is empty" << endl;
        } else {
            cout << *(buff.begin() + count % buffSize) << " dequeued\n";
            buff.erase(buff.begin() + count % buffSize);

        }//опционально, использовалось для проверки работспособности
    }

    void enQ(int value) {
        if (count < buffSize) {
            buff.push_back(value);
            cout << value << " enqueued\n";
            count++;
        } else if (buff.size() < buffSize) {
            buff.insert(buff.begin() + count % buffSize, value);
            cout << value << " enqueued\n";
            count++;
        } else {
            *(buff.begin() + count % buffSize) = value;
            cout << value << " enqueued\n";
            count++;
        }//опционально, использовалось для проверки работспособности
    }
};

int main() {
    circularBuffer t(5);
    t.enQ(1);
    t.enQ(2);
    t.enQ(3);
    t.enQ(4);
    t.enQ(5);
    t.enQ(6);
    t.enQ(7);
    t.deQ();
    t.deQ();
    t.deQ();
    t.deQ();
    t.enQ(1);
    t.deQ();
    t.enQ(2);
    t.enQ(3);
    t.enQ(4);
    t.deQ();
    t.enQ(5);
    t.enQ(6);
    t.enQ(7);
    t.deQ();
    t.deQ();
    t.enQ(1);
    t.enQ(2);
    t.enQ(9);
    t.deQ();
    t.printQ();
    t.deQ();
    t.deQ();
    t.deQ();
    t.deQ();
    t.deQ();
    return 0;
}
