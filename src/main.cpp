#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to count empty rectangles with marked points at bottom-left and top-right corners
long long countEmptyRectangles(vector<pair<int, int>>& points) {
    int n = points.size();
    if (n < 2) return 0;
    
    // Sort points by x-coordinate, then by y-coordinate
    sort(points.begin(), points.end());
    
    long long count = 0;
    
    // For each point as a potential bottom-left corner
    for (int i = 0; i < n; i++) {
        // Set to store y-coordinates of points processed so far
        set<int> y_coords;
        
        // Process points to the right of point i
        for (int j = i + 1; j < n; j++) {
            // If point j has a greater y-coordinate than point i, it could be a top-right corner
            if (points[j].second > points[i].second) {
                // Check if there are any points between points[i] and points[j] in y-direction
                // We need to check if there's any point with y-coordinate in the open interval (points[i].second, points[j].second)
                auto it = y_coords.upper_bound(points[i].second);
                
                // If no such point exists or the first such point has y-coordinate >= points[j].second, 
                // then the rectangle is empty
                if (it == y_coords.end() || *it >= points[j].second) {
                    count++;
                }
            }
            
            // Add the current point's y-coordinate to the set
            y_coords.insert(points[j].second);
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    cout << countEmptyRectangles(points) << endl;
    
    return 0;
}