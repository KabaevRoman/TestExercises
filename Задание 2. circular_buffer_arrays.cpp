#include <iostream>
#include <memory>

using namespace std;

struct elem {
    int content;
    bool exists = false;
};

class circularBuffer {
private:
    int buffSize = 0;
    unique_ptr<elem[]> buffer;
    int head = 0;
    int tail = -1;
    int count = 0;
public:
    circularBuffer() {
        buffSize = 5;
        buffer = make_unique<elem[]>(buffSize);
    }

    circularBuffer(int size) {
        buffSize = size;
        buffer = make_unique<elem[]>(buffSize);
    }

    void enQ(int value) {
        if (count < buffSize) {
            buffer[count % buffSize].content = value;
            buffer[count % buffSize].exists = true;
            cout << buffer[count % buffSize].content << " enqueued\n";
            tail = 0;
            count++;
        } else {
            buffer[head].content = value;
            buffer[head].exists = true;
            cout << buffer[head].content << " enqueued\n";
            if (head == tail)
                tail++;
            head++;
            count++;
            if (tail == buffSize)
                tail = 0;
            if (head == buffSize)
                head = 0;
        }
    }

    void deQ() {
        if (!isEmpty()) {
            buffer[tail].exists = false;
            cout << buffer[tail].content << " dequeued\n";
            tail++;
            if (tail == buffSize)
                tail = 0;
        } else
            cout << "buffer is empty\n";
    }

    void printQ() {
        if (!isEmpty()) {
            for (int i = 0; i < buffSize; i++)
                if (buffer[i].exists)
                    cout << buffer[i].content << " ";
            cout << endl;
        } else { cout << "buffer is empty\n"; }
    }

    bool isEmpty() {
        for (int i = 0; i < buffSize; i++) {
            if (buffer[i].exists) { return false; }
        }
        return true;
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
