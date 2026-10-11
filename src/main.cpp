#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to count empty rectangles with marked points at bottom-left and top-right corners
long long countEmptyRectangles(vector<pair<int, int>>& points) {
    // Sort points by x-coordinate, then by y-coordinate
    sort(points.begin(), points.end());
    
    long long count = 0;
    int n = points.size();
    
    // For each pair of points (i, j) where i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if points[i] can be bottom-left and points[j] can be top-right
            if (points[i].first < points[j].first && points[i].second < points[j].second) {
                // Check if the rectangle is empty (no other points inside or on boundary)
                bool isEmpty = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    
                    // Check if point k is inside or on the boundary of the rectangle
                    if (points[k].first >= points[i].first && points[k].first <= points[j].first && 
                        points[k].second >= points[i].second && points[k].second <= points[j].second) {
                        isEmpty = false;
                        break;
                    }
                }
                
                if (isEmpty) {
                    count++;
                }
            }
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