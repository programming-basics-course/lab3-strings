#include <pch.h>

//double newtons_method(d a, d b, d eps, int maxN, d(*f)(d x))
//{
//
//	// condition 1
//
//	double x0 = a;
//
//	for (int i = 0; i < maxN; i++)
//	{
//
//		if (abs(f(x0)) <= eps)
//		{
//			return x0;
//		}
//
//		x0 = x0 - f(x0) / df(x0);
//	}
//
//
//
//	std::cout << "error: insufficient number of iterations to perform calculation\n";
//}



//// df takes argument double x
//// and returns approximate value of the derivative of f()
//
//double df(double x)
//{
//	return (f(x + h) - f(x - h)) / (2 * h);
//}