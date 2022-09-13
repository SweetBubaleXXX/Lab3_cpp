#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdarg>

using namespace std;

const double A = -2;
const double B = -0.1;
const int K = 20; // 140

const int PRECISION = 15;
const int NUMBER_OF_COLUMNS = 3;
const int COLUMN_WIDTH = 25;
const int TABLE_WIDTH = (COLUMN_WIDTH + 3) * NUMBER_OF_COLUMNS;

void drawHeader(int, int, const char*, ...);

void drawLine(int);

void drawColumn(int, long double);

long double t_cos(double, int);

long double t_cos_iteration(double, int);

unsigned long long fact(int);


int main() {
    double h = (B - A) / 10;

    cout.precision(PRECISION);

    drawLine(TABLE_WIDTH);
    drawHeader(COLUMN_WIDTH, 3, "x", "y(x)", "s(x)");

    for (double x = A; x <= B; x += h) {
        drawLine(TABLE_WIDTH);
        cout << '|';
        drawColumn(COLUMN_WIDTH, x);
        cout << " | ";
        drawColumn(COLUMN_WIDTH, x * cos(x));
        cout << " | ";
        drawColumn(COLUMN_WIDTH, x * t_cos(x, K));
        cout << '|' << endl;
        drawLine(TABLE_WIDTH);
    }

    system("pause");

    return 0;
}


void drawHeader(int columnWidth, int columns, const char* name, ...) {
    va_list args;
    va_start(args, name);
    cout << '|';
    cout << setw(columnWidth) << setfill(' ') << name << " | ";
    for (int i = 1; i < columns; i++) {
        char* columnName = va_arg(args, char*);
        cout << setw(columnWidth) << setfill(' ') << columnName << " |";
    }
    cout << endl;
    va_end(args);
}


void drawLine(int width) {
    cout << setw(width) << setfill('-') << '\n';
}


void drawColumn(int width, long double value) {
    cout << setw(width) << setfill(' ') << value;
}


long double t_cos(double x, int k) {
    long double result = 0;
    for (int n = 0; n <= k; n++) {
        result += t_cos_iteration(x, n);
    }
    return result;
}


long double t_cos_iteration(double x, int n) {
    return pow(-1, n) * pow(x, 2 * n) / fact(2 * n);
}


unsigned long long fact(int n) {
    unsigned long long f, i;
    for (f = 1, i = 1; i <= n; f *= i, i++);
    return f;
}
