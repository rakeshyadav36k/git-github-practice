/**
 * You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
 */

 class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            // Try both horizontal and vertical cuts
            return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
        }
    
    private:
        // Check if valid cuts can be made in a specific dimension
        bool checkCuts(vector<vector<int>>& rectangles, int dim) {
            int gapCount = 0;
    
            // Sort rectangles by their starting coordinate in the given dimension
            sort(rectangles.begin(), rectangles.end(),
                 [dim](const vector<int>& a, const vector<int>& b) {
                     return a[dim] < b[dim];
                 });
    
            // Track the furthest ending coordinate seen so far
            int furthestEnd = rectangles[0][dim + 2];
    
            for (size_t i = 1; i < rectangles.size(); i++) {
                vector<int>& rect = rectangles[i];
    
                // If current rectangle starts after the furthest end we've seen,
                // we found a gap where a cut can be made
                if (furthestEnd <= rect[dim]) {
                    gapCount++;
                }
    
                // Update the furthest ending coordinate
                furthestEnd = max(furthestEnd, rect[dim + 2]);
            }
    
            // We need at least 2 gaps to create 3 sections
            return gapCount >= 2;
        }
    };