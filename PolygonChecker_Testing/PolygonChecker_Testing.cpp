#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(double side1, double side2, double side3);
extern "C" double calculateAngle(double a, double b, double c);
extern "C" double calculateDistance(double x1, double y1, double x2, double y2);
extern "C" bool isRectangleFromDistances(double distances[]);
extern "C" void sortDistances(double* distances, int size);
extern "C" double calculateRectangleArea(double side1, double side2);
extern "C" double calculateRectanglePerimeter(double side1, double side2);



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTesting
{
	TEST_CLASS(PolygonCheckerTesting)
	{
	public:

		TEST_METHOD(TestInvalidTriangleSideLengthZero)
		{
			//Tests Triangle is identified as invalid when at least one side length is zero and other two are 3.00, 4.00

			char* result = " ";
			result = analyzeTriangle(3.00, 4.00, 0.00);

			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(TestInvalidTriangleTwoSidesTooShort)
		{
			//Tests Triangle is identified as invalid when two shortest side lengths are not greater than the largest using lengths 3.00, 4.00, 9.00

			char* result = " ";
			result = analyzeTriangle(3.00, 4.00, 9.00);

			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(TestTriangleIsEquilateral)
		{
			//Tests Triangle is identified as Equilateral when side lengths are 3.00, 3.00, 3.00

			char* result = " ";
			result = analyzeTriangle(3.00, 3.00, 3.00);

			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(TestTriangleIsIsosceles)
		{
			//Tests Triangle is identified as Isosceles when side lengths are 3.00, 2.00, 2.00

			char* result = " ";
			result = analyzeTriangle(3.00, 2.00, 2.00);

			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(TestTriangleIsScalene)
		{
			//Tests Triangle is identified as Scalene when side lenghs are 3.00, 4.00, 5.00

			char* result = " ";
			result = analyzeTriangle(3.00, 4.00, 5.00);

			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(TestEquilateralInnerAngleCorrect)
		{
			//Tests inner angles are valid for Equilateral Triangle with lengths 3.00, 3.00, 3.00

			double side1 = 3.00;
			double side2 = 3.00;
			double side3 = 3.00;

			double angle1 = calculateAngle(side1, side2, side3);
			double angle2 = calculateAngle(side2, side1, side3);
			double angle3 = calculateAngle(side3, side1, side2);

			double sumAngle = (angle1 + angle2 + angle3);
			double roundAngle = round(sumAngle);

			Assert::AreEqual(180.0, roundAngle);


		}
		TEST_METHOD(TestIsoscelesInnerAngleCorrect)
		{
			//Tests inner angles are valid for Isosceles Triangle with lengths 3.00, 2.00, 2.00

			double side1 = 3.00;
			double side2 = 2.00;
			double side3 = 2.00;

			double angle1 = calculateAngle(side1, side2, side3);
			double angle2 = calculateAngle(side2, side1, side3);
			double angle3 = calculateAngle(side3, side1, side2);

			double sumAngle = (angle1 + angle2 + angle3);
			double roundAngle = round(sumAngle);

			Assert::AreEqual(180.0, roundAngle);
		}
		TEST_METHOD(TestScaleneInnerAngleCorrect)
		{
			//Tests inner angles are valid for Scalene Triangle with lengths 3.00, 4.00, 5.00

			double side1 = 3.00;
			double side2 = 4.00;
			double side3 = 5.00;

			double angle1 = calculateAngle(side1, side2, side3);
			double angle2 = calculateAngle(side2, side1, side3);
			double angle3 = calculateAngle(side3, side1, side2);

			double sumAngle = (angle1 + angle2 + angle3);
			double roundAngle = round(sumAngle);

			Assert::AreEqual(180.0, roundAngle);
		}
		TEST_METHOD(TestPolygonIsRectangle)
		{
			//Tests polygon is correctly identified as Rectangle when valid distances and diagonals are calculated from points

			double distances[] = { 4.00, 4.00, 6.00, 6.00,2.00, 2.00 };
			

			bool validRectangle = isRectangleFromDistances(distances);

			Assert::AreEqual(true, validRectangle);

		}
		TEST_METHOD(TestPolygonIsNotRectangleInvalidDistances)
		{
			//Tests polygon is correctly identified as not a Rectangle with invalid distances

			double distances[] = { 3.00, 4.00, 6.00, 6.00,2.00, 2.00 };

			bool validRectangle = isRectangleFromDistances(distances);

			Assert::AreEqual(false, validRectangle);
		}
		TEST_METHOD(TestPolygonIsNotRectangleInvalidDiagonals)
		{
			//Tests polygon is correctly identified as not a Rectangle with invalid diagonals

			double distances[] = { 4.00, 4.00, 6.00, 6.00, 2.00,2.00 };

			bool validRectangle = isRectangleFromDistances(distances);

			Assert::AreEqual(true, validRectangle);
		}
		TEST_METHOD(TestPolygonPerimeterCorrect)
		{
			//Tests correct calculation of polygon perimeter when side lengths are 3.00 and 6.00

			double side1 = 3.00;
			double side2 = 6.00;

			double perimeter = calculateRectanglePerimeter(side1, side2);

			Assert::AreEqual(18.00, perimeter);
		}
		TEST_METHOD(TestRectangleAreaCorrect)
		{
			//Tests correct calculation of rectangle area when side lengths are 3.00 and 6.00

			double side1 = 3.00;
			double side2 = 6.00;

			double area = calculateRectangleArea(side1, side2);

			Assert::AreEqual(18.00, area);
		}
	};
}
