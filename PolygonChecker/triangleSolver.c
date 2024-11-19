#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define PI  3.14


char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "";
	double tem1, tem2;
	double angle1, angle2, angle3;
//	double A, B, C;

	double temMax = side1;
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
		angle1 = 60;
		angle2 = 60;
		angle3 = 60;
		printf(" The 3 angles to the triangle is %.2f %.2f %.2f  \n", angle1, angle2, angle3);

	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1))
	{
		
		result = "Isosceles triangle";   // cos(c)  = a^2 +b^2 - c^2 /2ab
		//A = acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / 2 * side2 * side3);
		//B = acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / 2 * side1 * side3);
		//C = acos(((side1 * side1) + (side2 * side2) - (side3 * side3)) / 2 * side1 * side2);

		//angle1 = A * (180 / PI);
		//angle2 = B * (180 / PI);
		//angle3 = C * (180 / PI);
		angle1 = calculateAngle(side1, side2, side3);
		angle2 = calculateAngle(side2, side1, side3);
		angle3 = calculateAngle(side3, side1, side2);

		printf(" The 3 angles to the triangle is %.2lf %.2lf %.2lf  \n", angle1, angle2, angle3);
	}
	else {
		result = "Scalene triangle";
		/*A = acos(((side2 * side2) + (side3 * side3) - (side1 * side1)) / 2 * side2 * side3);
		B = acos(((side1 * side1) + (side3 * side3) - (side2 * side2)) / 2 * side1 * side3);
		C = acos(((side1 * side1) + (side2 * side2) - (side3 * side3)) / 2 * side1 * side2);*/
		
	/*	angle1 = A * (180 / PI);
		angle2 = B * (180 / PI);
		angle3 = C * (180 / PI);*/

		angle1 = calculateAngle(side1, side2, side3);
		angle2 = calculateAngle(side2, side1, side3);
		angle3 = calculateAngle(side3, side1, side2);
 
		printf(" The 3 angles to the triangle is %.2lf %.2lf %.2lf  \n", angle1, angle2, angle3);
	}

	return result;
}

double calculateAngle(double a, double b, double c) {
	return acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / PI);
}