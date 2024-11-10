#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <malloc.h>
#include <iostream>
void SearchSort(int mas[], int size) {
    for (int i = 0; i < size; ++i) {
        int a = mas[i];
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (mas[j] < mas[index]) {
                index = j;
            }
        }
        int tmp = mas[i];
        mas[i] = mas[index];
        mas[index] = tmp;
    }
}
void InsertionSort(int mas[], int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i - 1; j >= 0 && j < size; --j) {
            if (mas[j] > mas[j + 1]) {
                int tmp = mas[j + 1];
                mas[j + 1] = mas[j];
                mas[j] = tmp;
            }
        }
    }
}

void BubbleSort(int mas[], int size) {
    for (int i = 0; i < size ; ++i) {
        bool flag = true;
        for (int j = 0; j < size - i - 1; ++j) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
                flag = false;

            }          
        }
        if (flag) {
            break;
        }
    }
}
int main() {
        int* mas;
        int* cloneMas;
        float seconds = 0;
        srand(time(NULL));
        int size = 0;
        int sort = 0;
        int cnt = 0;
        printf("Enter lentgth of namber ");
        scanf_s("%d", &size);
        mas = (int*)malloc(size * sizeof(int));
        cloneMas = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; ++i) {
            mas[i] = rand() % 100;
        }
        while (true) {
            cnt = 0;
            for (int i = 0; i < size; ++i) {
                cloneMas[i] = mas[i];
            }
            printf("Choose name sort: \n 1 - Bubble Sort\n 2 - Search Sort \n 3 - Insertion Sort\n");
            scanf_s("%d", &sort);
            clock_t start = clock();
            switch (sort) {
            case 1:
                for (int i = 0; i < size; ++i) {
                    bool flag = true;
                    for (int j = 0; j < size - i - 1; ++j) {
                        if (cloneMas[j] > cloneMas[j + 1]) {
                            int temp = cloneMas[j];
                            cloneMas[j] = cloneMas[j + 1];
                            cloneMas[j + 1] = temp;
                            flag = false;
                            cnt += 1;

                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < size; ++i) {
                    int a = cloneMas[i];
                    int index = i;
                    for (int j = i + 1; j < size; ++j) {
                        if (cloneMas[j] < cloneMas[index]) {
                            index = j;
                        }
                    }
                    int tmp = cloneMas[i];
                    cloneMas[i] = cloneMas[index];
                    cloneMas[index] = tmp;
                    cnt += 1;
                }
                break;
            case 3:
                for (int i = 1; i < size; ++i) {
                    for (int j = i - 1; j >= 0 && j < size; --j) {
                        if (cloneMas[j] > cloneMas[j + 1]) {
                            int tmp = cloneMas[j + 1];
                            cloneMas[j + 1] = cloneMas[j];
                            cloneMas[j] = tmp;
                            cnt += 1;
                        }
                    }
                }
                break;
            }
            clock_t end = clock();
            seconds = (float)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            printf("time:%f swap:%d\n", seconds, cnt);
            cnt = 0;
        }
        free(mas);
        free(cloneMas);
        return 0;
}