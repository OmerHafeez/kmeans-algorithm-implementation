#include <iostream>
#include<cmath>
using namespace std;

// Structure for a 2D point
struct Point 
{
    double x;
    double y;
    
    // Function to calculate distance between two points
	double distance(Point Pt1, Point Pt2) 
	{
    	double dx = Pt1.x - Pt2.x;
    	double dy = Pt1.y - Pt2.y;
    	return sqrt(dx*dx + dy*dy);
	}

	// Function to assign each point to the nearest cent
	void assignPoints(Point pts[], Point Cents[], int groups[], int numPoints, int numGroups) 
	{
   		for (int i = 0; i < numPoints; i++) 
		{
        	double minimin_distance = distance(pts[i], Cents[0]);
        	int minimin_group = 0;
        	for (int j = 1; j < numGroups; j++) 
			{
        		double dist = distance(pts[i], Cents[j]);
            	if (dist < minimin_distance) 
				{
               		minimin_distance = dist;
                	minimin_group = j;
           		}
        	}
        	groups[i] = minimin_group;
    	}
	}

	// Function to update the centroid of each group
	void updateCentroids(Point pts[], Point Cents[], int groups[], int numPoints, int numGroups) 
	{
    	for (int i = 0; i < numGroups; i++) 
		{
        	double sumX = 0.0;
        	double sumY = 0.0;
        	int count = 0;
        	for (int j = 0; j < numPoints; j++) 
			{
            	if (groups[j] == i) 
				{
                	sumX += pts[j].x;
                	sumY += pts[j].y;
                	count++;
            	}
        	}
        	if (count > 0) 
			{
           		Cents[i].x = sumX / count;
            	Cents[i].y = sumY / count;
       		}
    	}
	}

	// Function to check if Cents have converged
	bool hasConverged(Point PreCents[], Point updateCents[], int numGroups) 
	{
    	for (int i = 0; i < numGroups; i++) 
		{
        	if (PreCents[i].x != updateCents[i].x || PreCents[i].y != updateCents[i].y) 
			{
        		return false;
    		}
    	}
    	return true;
	}

};

int main() 
{
    const int numberOfPoints = 8;
    const int numberOfGroups = 3;
    Point pts[numberOfPoints] = { {2,10}, {2,5}, {8,4}, {5,8}, {7,5}, {6,4}, {1,2}, {4,9} };
    Point Cents[numberOfGroups] = { {2,10}, {5,8}, {1,2} };
    int groups[numberOfPoints] = { 0 };
    int numberOfIteration = 0;

    // Create a Point object to access its member functions
    Point point;

    // Iterate until Cents have converged
    while (true) {
        // Assign pts to nearest centroid
        for (int i = 0; i < numberOfPoints; i++) {
            double minimin_distance = point.distance(pts[i], Cents[0]);
            int minimin_group = 0;
            for (int j = 1; j < numberOfGroups; j++) {
                double dist = point.distance(pts[i], Cents[j]);
                if (dist < minimin_distance) {
                    minimin_distance = dist;
                    minimin_group = j;
                }
            }
            groups[i] = minimin_group;
        }
        
        // Save old Cents
        Point PreCents[numberOfGroups];
        for (int i = 0; i < numberOfGroups; i++) {
            PreCents[i].x = Cents[i].x;
            PreCents[i].y = Cents[i].y;
        }
        
        // Update Cents
        for (int i = 0; i < numberOfGroups; i++) {
            double sumX = 0.0;
            double sumY = 0.0;
            int count = 0;
            for (int j = 0; j < numberOfPoints; j++)
			{
                if (groups[j] == i) {
                    sumX += pts[j].x;
                    sumY += pts[j].y;
                    count++;
                }
            }
            if (count > 0) {
                Cents[i].x = sumX / count;
                Cents[i].y = sumY / count;
            }
        }
        
        numberOfIteration++;
        // Check for convergence
        if (point.hasConverged(PreCents, Cents, numberOfGroups)) 
		{
            break;
        }
    }

    // Print the final output
    cout << "Final average of each group:" << endl;
    for(int i = 0; i < numberOfGroups; i++) 
	{
        cout << "Group " << i+1 << ": (" << Cents[i].x << "," << Cents[i].y << ")" << endl;
        cout << "Data points assigned to Group " << i+1 << ":" << endl;
        for(int j = 0; j < numberOfPoints; j++) 
		{
            if (groups[j] == i) 
			{
                cout << "(" << pts[j].x << "," << pts[j].y << ")" << endl;
            }
        }
        cout << endl;
    }

    cout << "Number of iterations: " << numberOfIteration << endl;
    return 0;
}
