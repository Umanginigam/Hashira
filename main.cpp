#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

// Decode a value from given base to decimal using long double
long double decodeValue(const string &value, int base) {
    long double result = 0.0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10;
        else continue;
        result = result * base + digit;
    }
    return result;
}

// Compute c using Lagrange interpolation (f(0))
long double findC(vector<pair<long double,long double>> &points) {
    long double c = 0.0;
    int k = points.size();
    for (int i = 0; i < k; i++) {
        long double term = points[i].second;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - points[j].first) / (points[i].first - points[j].first);
            }
        }
        c += term;
    }
    return c; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read entire input JSON as plain text
    string line, input;
    while (getline(cin, line)) {
        input += line;
    }

    // Parse n and k manually
    size_t posN = input.find("\"n\"");
    size_t posK = input.find("\"k\"");
    int n = stoi(input.substr(input.find(":", posN) + 1));
    int k = stoi(input.substr(input.find(":", posK) + 1));

    vector<pair<long double,long double>> points;
    int count = 0;

    // Parse each root
    for (size_t pos = 0; pos < input.size(); pos++) {
        if (input[pos] == '\"' && isdigit(input[pos+1])) {
            // Extract x (key)
            size_t endKey = input.find("\"", pos+1);
            string key = input.substr(pos+1, endKey - pos - 1);
            long double x = stold(key);

            // Find base
            size_t basePos = input.find("\"base\"", endKey);
            size_t baseStart = input.find("\"", basePos+6) + 1;
            size_t baseEnd = input.find("\"", baseStart);
            int base = stoi(input.substr(baseStart, baseEnd - baseStart));

            // Find value
            size_t valPos = input.find("\"value\"", baseEnd);
            size_t valStart = input.find("\"", valPos+7) + 1;
            size_t valEnd = input.find("\"", valStart);
            string val = input.substr(valStart, valEnd - valStart);

            long double y = decodeValue(val, base);

            points.push_back({x, y});
            count++;
            if (count == k) break; // only first k points needed
            pos = valEnd;
        }
    }

    long double c = findC(points);

    cout << "the value of c: " << fixed << setprecision(0) << c << "\n";

    return 0;
}
