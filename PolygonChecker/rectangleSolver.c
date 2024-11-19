#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"

void processRectangle() {
    double points[4][2]; // Array to store (x, y) coordinates
    printf("Enter the four points (x, y) one by one:\n");

    for (int i = 0; i < 4; i++) {
        printf("Point %d - Enter x and y: ", i + 1);
        if (scanf_s("%lf %lf", &points[i][0], &points[i][1]) != 2) {
            printf("Invalid input. Please enter numeric values.\n");
            i--; 
        }
    }

    // Compute distances between points
    double distances[4], diagonals[2];
    distances[0] = calculateDistance(points[0][0], points[0][1], points[1][0], points[1][1]); 
    distances[1] = calculateDistance(points[1][0], points[1][1], points[2][0], points[2][1]); 
    distances[2] = calculateDistance(points[2][0], points[2][1], points[3][0], points[3][1]); 
    distances[3] = calculateDistance(points[3][0], points[3][1], points[0][0], points[0][1]); 
    diagonals[0] = calculateDistance(points[0][0], points[0][1], points[2][0], points[2][1]); 
    diagonals[1] = calculateDistance(points[1][0], points[1][1], points[3][0], points[3][1]); 

    // Check if it's a rectangle
    if (isRectangle(distances, diagonals)) {
        printf("The points form a rectangle.\n");
        double side1 = distances[0], side2 = distances[1];
        double perimeter = calculateRectanglePerimeter(side1, side2);
        double area = calculateRectangleArea(side1, side2);
        printf("Perimeter: %.2lf\n", perimeter);
        printf("Area: %.2lf\n", area);
    }
    else {
        printf("The points do not form a rectangle.\n");
    }
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isRectangle(double distances[], double diagonals[]) {
    // Check if opposite sides are equal and diagonals are equal
    return (distances[0] == distances[2] && distances[1] == distances[3] &&
        diagonals[0] == diagonals[1]);
}

double calculateRectangleArea(double side1, double side2) {
    return side1 * side2;
}

double calculateRectanglePerimeter(double side1, double side2) {
    return 2 * (side1 + side2);
}
