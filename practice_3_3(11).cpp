#include <iostream>
using namespace std;

int A(int n, int x, int y) {
    if (n == 0) {
        return x + 1;
    }
    else if (n == 1 && y == 0) {
        return x;
    }
    else if (n == 2 && y == 0) {
        return 0;
    }
    else if (n == 3 && y == 0) {
        return 1;
    }
    else if (n >= 4 && y == 0) {
        return 2;
    }
    else {
        return A(n - 1, A(n, x, y - 1), x);
    }
}

int main() {
    int n, x, y;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
        
    if (n < 0 || x < 0 || y < 0) {
        cout << "Error" << endl;
        return 1;
    }
        
    int result = A(n, x, y);
    cout << "A(" << n << ", " << x << ", " << y << ") = " << result << endl;

    return 0;
}