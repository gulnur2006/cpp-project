#include <iostream>
#include <cmath>

using namespace std;

const int MAX_LIMIT = 100;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool contains(const int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    int primes[MAX_LIMIT];
    int primeCount = 0;

    
    for (int i = 2; i < MAX_LIMIT; ++i) {
        if (isPrime(i)) {
            primes[primeCount++] = i;
        }
    }

    int parabolicPrimes[MAX_LIMIT];
    int parabolicCount = 0;
    
    for (int i = 0; i < primeCount; ++i) {
        for (int j = 0; j < primeCount; ++j) {
            int q = primes[i];
            int r = primes[j];
            int p = q * q + r + 1;
                        
            if (p < MAX_LIMIT && isPrime(p)) {
              
                if (!contains(parabolicPrimes, parabolicCount, p)) {
                    parabolicPrimes[parabolicCount++] = p;
                }
            }
        }
    }
       
    for (int i = 0; i < parabolicCount - 1; ++i) {
        for (int j = 0; j < parabolicCount - i - 1; ++j) {
            if (parabolicPrimes[j] > parabolicPrimes[j + 1]) {
                int temp = parabolicPrimes[j];
                parabolicPrimes[j] = parabolicPrimes[j + 1];
                parabolicPrimes[j + 1] = temp;
            }
        }
    }
        
    cout << "Parabolic Primes:" << endl;
    for (int i = 0; i < parabolicCount; ++i) {
        cout << parabolicPrimes[i] << " ";
    }
    cout << endl;

    cout << "Count of Parabolic Primes: " << parabolicCount << endl;

    return 0;
}