#ifndef RECTANGLESOLVER_H
#define RECTANGLESOLVER_H

#include <stdbool.h>

void processRectangle();
double calculateDistance(double x1, double y1, double x2, double y2);
void sortDistances(double* distances, int size);
bool isRectangleFromDistances(double distances[]);
double calculateRectangleArea(double side1, double side2);
double calculateRectanglePerimeter(double side1, double side2);

#endif
