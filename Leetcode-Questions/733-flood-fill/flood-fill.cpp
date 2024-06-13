#include <vector>

using namespace std;

class Solution {
public:
    // The main function to initiate the flood fill algorithm
    // Takes an image (2D vector of integers), a starting row (sr), a starting column (sc),
    // and the new color to be applied.
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Store the original color of the starting pixel
        int originalColor = image[sr][sc];

        // If the original color is the same as the new color, no action is needed.
        // This avoids infinite loops and redundant work.
        if (originalColor != color) {
            // Start the recursive flood fill process
            fill(image, sr, sc, color, originalColor);
        }

        // Return the modified image
        return image;
    }

private:
    // Helper function to recursively fill connected pixels with the new color
    // Parameters:
    // - image: reference to the 2D vector representing the image
    // - sr: current row index
    // - sc: current column index
    // - color: the new color to be applied
    // - originalColor: the color of the pixel where the flood fill started
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        // Check if the current pixel is out of bounds
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) {
            return;
        }

        // Check if the current pixel's color is different from the original color
        // If it is different, we stop the recursion as this pixel is not part of the region to be filled
        if (image[sr][sc] != originalColor) {
            return;
        }

        // Change the color of the current pixel to the new color
        image[sr][sc] = color;

        // Recursively call fill for the four adjacent pixels (down, up, right, left)
        // This ensures that we process all connected pixels with the original color

        // Process the pixel below the current one
        fill(image, sr + 1, sc, color, originalColor); // Down

        // Process the pixel above the current one
        fill(image, sr - 1, sc, color, originalColor); // Up

        // Process the pixel to the right of the current one
        fill(image, sr, sc + 1, color, originalColor); // Right

        // Process the pixel to the left of the current one
        fill(image, sr, sc - 1, color, originalColor); // Left
    }
};
