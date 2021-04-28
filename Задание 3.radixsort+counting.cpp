#include <iostream>
#include <string>


using namespace std;

int maxRank(int *arr, int arrSize) {
    int maxElem = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return to_string(maxElem).size();
}

void countSort(int *sourceArr, int notation, int powNotation, int arrSize) {
    int currentDigit = 0;
    int *resultArr = new int[arrSize]();
    int *countArr = new int[notation]();
    int count = 0;
    int temp = 0;

    for (int i = 0; i < arrSize; i++) {
        currentDigit = sourceArr[i] / powNotation % notation;
        countArr[currentDigit]++;
    }
    for (int i = 0; i < notation; i++) {
        temp = countArr[i];
        countArr[i] = count;
        count += temp;
    }
    for (int i = 0; i < arrSize; i++) {
        currentDigit = sourceArr[i] / powNotation % notation;
        resultArr[countArr[currentDigit]] = sourceArr[i];
        countArr[currentDigit]++;
    }
    memmove(sourceArr, resultArr, sizeof(sourceArr) * arrSize);
    delete[] resultArr;
    delete[] countArr;
}

void radixSort(int *sourceArr, int arrSize, int notation) {
    int biggestRank = maxRank(sourceArr, arrSize);
    for (int powNotation = 1, i = 0; i < biggestRank; i++) {
        countSort(sourceArr, notation, powNotation, arrSize);
        powNotation *= notation;
    }
}

int compare(const void *x1, const void *x2) {
    return (*(int *) x1 -
            *(int *) x2);
}

int main() {
    int arrSize = 100000000;//размер массива может задать пользователь
    int notation = 10;//систему счисления может задать пользователь
    int *sourceArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        sourceArr[i] = rand();
    }
    radixSort(sourceArr, arrSize, notation);
    return 0;
}
