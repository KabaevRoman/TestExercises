#include <iostream>
#include <ctime>
#include <string>
#include "getCPUTime.c"

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

int compare(const void *x1, const void *x2)   // функция сравнения элементов массива
{
    return (*(int *) x1 -
            *(int *) x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main() {
    int arrSize = 100000000;//размер массива может задать пользователь
    int notation = 10;//систему счисления может задать пользователь
    double startTime, endTime;
    int *sourceArr = new int[arrSize];
    int *sourceArr2 = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        sourceArr[i] = rand();
        sourceArr2[i] = sourceArr[i];
    }


    startTime = getCPUTime();
    radixSort(sourceArr, arrSize, notation);
    endTime = getCPUTime();
    fprintf(stderr, "CPU time used = %lf\n", (endTime - startTime));

    startTime = getCPUTime();
    qsort(sourceArr2, arrSize, sizeof(int), compare);
    endTime = getCPUTime();
    fprintf(stderr, "CPU time used = %lf\n", (endTime - startTime));

    return 0;
}
