#include <iostream>

using namespace std;

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void diferentaSimetrica(int A[], int m, int B[], int n, int rezultat[], int& k) {
    // Sortăm cele două multimi
    mergeSort(A, 0, m - 1);
    mergeSort(B, 0, n - 1);

    int i = 0, j = 0;

    while (i < m && j < n) {
        if (A[i] < B[j]) {
            if (k == 0 || A[i] != rezultat[k - 1]) {
                rezultat[k++] = A[i++];
            } else {
                i++;
            }
        } else if (A[i] > B[j]) {
            if (k == 0 || B[j] != rezultat[k - 1]) {
                rezultat[k++] = B[j++];
            } else {
                j++;
            }
        } else {
            i++;
            j++;
        }
    }

    while (i < m) {
        if (k == 0 || A[i] != rezultat[k - 1]) {
            rezultat[k++] = A[i++];
        } else {
            i++;
        }
    }

    while (j < n) {
        if (k == 0 || B[j] != rezultat[k - 1]) {
            rezultat[k++] = B[j++];
        } else {
            j++;
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6};
    int m = sizeof(A) / sizeof(A[0]);

    int B[] = {2, 3, 4, 7};
    int n = sizeof(B) / sizeof(B[0]);

    int rezultat[m + n];
    int k = 0;

    diferentaSimetrica(A, m, B, n, rezultat, k);

    cout << "Diferenta Simetrica: ";
    for (int i = 0; i < k; i++) {
        cout << rezultat[i] << " ";
    }
    cout << endl;

    return 0;
}
