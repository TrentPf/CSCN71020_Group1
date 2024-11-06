#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	int tem1, tem2;

	int temMax = side1;
	if (temMax < side2)
	{

		temMax = side2;
		tem1 = side1;

		if (temMax < side3) {
			temMax = side3;
			tem2 = side2;
		}
		else
			tem2 = side3;
	}
	else {
		tem1 = side2;
		if (temMax < side3) {
			temMax = side3;
			tem2 = side1;
		}
		else
		{
			tem2 = side3;
		}
	}
	if ((side1 <= 0 || side2 <= 0 || side3 <= 0) || (temMax >= (tem1 + tem2))) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";

	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";

	}
	else {
		result = "Scalene triangle";
	}

	return result;
}