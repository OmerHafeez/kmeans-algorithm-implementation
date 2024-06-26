# kmeans-algorithm-implementation
K-Means Clustering Algorithm Implementation in C++
This C++ program demonstrates the K-Means clustering algorithm to group a set of data points into clusters based on their distances to centroids.

Description
The program initializes with a set of data points and predefined centroids. It iteratively assigns each data point to its nearest centroid, updates the centroids based on the assigned data points, and checks for convergence until the centroids no longer change significantly.

Features
Point Struct: Defines a structure for 2D points and includes functions for calculating distances, assigning points to centroids, updating centroids, and checking convergence.

Main Function: Implements the K-Means algorithm using the Point struct functions to cluster data points into groups.
Example
const int numberOfPoints = 8;
const int numberOfGroups = 3;
Point pts[numberOfPoints] = { {2,10}, {2,5}, {8,4}, {5,8}, {7,5}, {6,4}, {1,2}, {4,9} };
Point Cents[numberOfGroups] = { {2,10}, {5,8}, {1,2} };
Final average of each group:
Group 1: (2,10)
Data points assigned to Group 1:
(2,10)

Group 2: (5.75,6.5)
Data points assigned to Group 2:
(5,8)
(7,5)
(6,4)
(4,9)

Group 3: (1.5,3.5)
Data points assigned to Group 3:
(2,5)
(8,4)
(1,2)

Number of iterations: 3
