#pragma once
void printWelcome();
int printShapeMenu();
double* getTriangleSides(double* triangleSides);
char* analyzeTriangle(double side1, double side2, double side3);
double calculateAngle(double a, double b, double c);
double calculateDistance(double x1, double y1, double x2, double y2);
bool isRectangle(double distances[], double diagonals[]);
double calculateRectangleArea(double side1, double side2);
double calculateRectanglePerimeter(double side1, double side2);
char* analyzeTriangle(double side1, double side2, double side3);