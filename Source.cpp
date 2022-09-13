#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const double A = -2;
const double B = -0.1;
const int K = 20; // 140

const int PRECISION = 20;
const int COLUMN_WIDTH = 25;

void drawLine(int);

void drawColumn(int, long double);

long double t_cos(double, int);

long double t_cos_iteration(double, int);

unsigned long long fact(int);


int main() {
	double h = (B - A) / 10;

	cout.precision(PRECISION);

	for (double x = A; x <= B; x += h) {
		drawLine((COLUMN_WIDTH + 3) * 2);
		cout << '|';
		//cout << setw(COLUMN_WIDTH) << setfill(' ') << x * cos(x) << '|';
		//cout << setw(COLUMN_WIDTH) << setfill(' ') << x * t_cos(x, K);
		drawColumn(COLUMN_WIDTH, x * cos(x));
		cout << " | ";
		drawColumn(COLUMN_WIDTH, x * t_cos(x, K));
		cout << '|' << endl;
		drawLine((COLUMN_WIDTH + 3) * 2);
	}

	return 0;
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
