#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7; // Default mod for fast power

// Function to check if a number is prime (optimized with 6k ± 1)
bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find factors of a number
vector<int> findFactors(int num) {
    vector<int> factors;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) factors.push_back(num / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

// Function to generate Fibonacci sequence up to 'n' terms
vector<long long> generateFibonacci(int n) {
    vector<long long> fib;
    if (n <= 0) return fib;
    fib.push_back(0);
    if (n > 1) fib.push_back(1);

    for (int i = 2; i < n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

// Function to calculate (base^exp) % mod efficiently using Binary Exponentiation
long long fastPower(long long base, long long exp, long long mod = MOD) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find square root of a number using Binary Search
double findSquareRoot(double num, double precision = 1e-6) {
    if (num < 0) {
        cout << "Error: Square root of a negative number is undefined.\n";
        return NAN;
    }
    double low = 0, high = num, mid;
    while (high - low > precision) {
        mid = (low + high) / 2;
        if (mid * mid > num) high = mid;
        else low = mid;
    }
    return mid;
}

// Function to perform basic arithmetic operations
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : NAN;
        default: return NAN;
    }
}

// Main function to interact with the user
int main() {
    int choice;
    cout << "===== CALCI214: Advanced Calculator =====\n";
    cout << "1. Basic Arithmetic (+, -, *, /)\n";
    cout << "2. Generate Fibonacci Sequence\n";
    cout << "3. Find Factors of a Number\n";
    cout << "4. Prime Number Checker\n";
    cout << "5. Fast Power Calculation (base^exp % mod)\n";
    cout << "6. Square Root Finder\n";
    cout << "7. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            double a, b;
            char op;
            cout << "Enter first number: ";
            cin >> a;
            cout << "Enter an operator (+, -, *, /): ";
            cin >> op;
            cout << "Enter second number: ";
            cin >> b;
            double result = calculate(a, b, op);
            if (isnan(result)) cout << "Error: Invalid operation!\n";
            else cout << "Result: " << result << endl;

        } else if (choice == 2) {
            int n;
            cout << "Enter number of terms for Fibonacci sequence: ";
            cin >> n;
            vector<long long> fib = generateFibonacci(n);
            cout << "Fibonacci Sequence: ";
            for (long long num : fib) cout << num << " ";
            cout << endl;

        } else if (choice == 3) {
            int num;
            cout << "Enter a number to find its factors: ";
            cin >> num;
            vector<int> factors = findFactors(num);
            cout << "Factors: ";
            for (int f : factors) cout << f << " ";
            cout << endl;

        } else if (choice == 4) {
            int num;
            cout << "Enter a number to check if it's prime: ";
            cin >> num;
            if (isPrime(num)) cout << num << " is a Prime Number.\n";
            else cout << num << " is NOT a Prime Number.\n";

        } else if (choice == 5) {
            long long base, exp, mod;
            cout << "Enter base, exponent, and modulus (or -1 for default 1e9+7): ";
            cin >> base >> exp >> mod;
            if (mod == -1) mod = MOD;
            cout << "Result: " << fastPower(base, exp, mod) << endl;

        } else if (choice == 6) {
            double num;
            cout << "Enter a number to find its square root: ";
            cin >> num;
            double sqrtResult = findSquareRoot(num);
            if (!isnan(sqrtResult)) cout << "Square Root: " << sqrtResult << endl;

        } else if (choice == 7) {
            cout << "Exiting CALCI214... Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
//my calci...............