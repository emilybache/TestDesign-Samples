#include "sample.h"

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    return (year % 4 == 0);
}

string fizzBuzz(int n) {
    string return_value;

    if (n % 3 == 0)
        return_value += "Fizz";
    if (n % 5 == 0)
        return_value += "Buzz";
    if (n % 7 == 0)
        return_value += "Whizz";
    if (n % 11 == 0)
        return_value += "Bang";

    if (return_value.empty())
        return_value = to_string(n);

    return return_value;
}

int64_t closestToZero(vector<int> *numbers) {
    if (!numbers || numbers->empty())
        throw invalid_argument("no numbers given");
    int64_t min = numeric_limits<int>::min();
    for (int64_t n : *numbers) {
        long long int abs_n = abs(n);
        long long int abs_min = abs(min);
        if (abs_n <= abs_min) {
            if (abs_n == abs_min) {
                min = max(n, min);
            } else {
                min = n;
            }
        }
    }
    return min;
}