#include <iostream>
#include <iomanip>
#include <ctime>
#include <cfloat>

using namespace std;

typedef double (*integrable)(double);

static double parabola(double x)
{ return x * x; }

int main(int argc, char *argv[])
{
    const unsigned long long steps = 1000000000;
    double a = 0;
    double b = 1;
    double h = (b - a) / (steps * 1.0);
    double sum = 0;
    integrable f = parabola;
    clock_t begin = clock();
#ifdef PARALLEL
    cout << "Using OpenMP" << endl;
#else
    cout << "Without OpenMP" << endl;
#endif
#ifdef PARALLEL
#pragma omp parallel for reduction(+:sum)
#endif
    for (unsigned long long i = 1; i <= steps; i++)
    {
        double x = a + i * h;
        sum += h * f(x);
    }
    cout << fixed << setprecision(DBL_DIG) << sum << endl;
    clock_t end = clock();
    cout << fixed << setprecision(DBL_DIG) << double(end - begin) / (1.0 * CLOCKS_PER_SEC) << " seconds." << endl;
    return 0;
}

