#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(double side1, double side2, double side3);
extern "C" double calculateAngle(double a, double b, double c);
extern "C" double calculateDistance(double x1, double y1, double x2, double y2);
extern "C" bool isRectangle(double distances[], double diagonals[]);
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

			double sumAngle = angle1 + angle2 + angle3;

			Assert::AreEqual(180.0, sumAngle);


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

			double sumAngle = angle1 + angle2 + angle3;

			Assert::AreEqual(180.0, sumAngle);
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

			double sumAngle = angle1 + angle2 + angle3;

			Assert::AreEqual(180.0, sumAngle);
		}
		TEST_METHOD(TestPolygonIsRectangle)
		{
			//Tests polygon is correctly identified as Rectangle when valid points entered: 2,4   2,6   4,4   4,6
		}
		TEST_METHOD(TestPolygonIsNotRectangle)
		{
			//Tests polygon is correctly identified as not a Rectangle with invalid points: 2,4   2,6   4,4   4,10
		}
		TEST_METHOD(TestPolygonPerimeterCorrect)
		{
			//Tests correct calculation of polygon perimeter when points entered: 2,4   2,6   4,4   4,10
		}
		TEST_METHOD(TestRectangleAreaCorrect)
		{
			//Tests correct calculation of rectangle area when points entered: 2,4   2,6   4,4   4,6
		}
	};
}
