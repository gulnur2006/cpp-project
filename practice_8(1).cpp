#include <iostream>
#include <ctime>    

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void generateSortedArray(int arr[], int length) {
    srand(time(0)); 
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 + 1; 
    }
       
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int findFirstOccurrence(int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}
int countOccurrences(int arr[], int length, int target) {
    int first = findFirstOccurrence(arr, length, target);
    if (first == -1) return 0; 
    int last = findLastOccurrence(arr, length, target);
    return last - first + 1;
}

int main() {
    setlocale(LC_ALL, "ru");
    int length;
    cout << "Введите длину массива: ";
    cin >> length;

    int* arr = new int[length]; 
    generateSortedArray(arr, length);

    cout << "Сгенерированный упорядоченный массив: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Введите число для поиска: ";
    cin >> target;

    int count = countOccurrences(arr, length, target);
    cout << "Число " << target << " встречается " << count << " раз(а)." << endl;

    delete[] arr; 
    return 0;
}