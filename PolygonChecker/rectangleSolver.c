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

    // Compute pairwise distances
    double distances[6]; // 6 unique pairs
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            distances[k++] = calculateDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
        }
    }

    // Sort distances for easier comparison
    sortDistances(distances, 6);

    // Validate if the points form a rectangle
    if (isRectangleFromDistances(distances)) {
        printf("The points form a rectangle.\n");

        // Compute sides from sorted distances
        double side1 = distances[0];
        double side2 = distances[1];

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

void sortDistances(double* distances, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (distances[i] > distances[j]) {
                double temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
            }
        }
    }
}

bool isRectangleFromDistances(double distances[]) {
    // Check if the smallest four distances represent two equal pairs (sides)
    // and the largest two represent equal diagonals
    return (distances[0] == distances[1] && distances[2] == distances[3] &&
        distances[4] == distances[5]);
}

double calculateRectangleArea(double side1, double side2) {
    return side1 * side2;
}

double calculateRectanglePerimeter(double side1, double side2) {
    return 2 * (side1 + side2);
}
