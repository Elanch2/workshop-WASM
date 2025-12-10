// Include Emscripten's header file - provides macros and functions for WebAssembly integration
#include <emscripten/emscripten.h>

// Include standard library for memory allocation (malloc, free)
#include <stdlib.h>

// Include math library for sqrt() function used in edge detection
#include <math.h>

// EMSCRIPTEN_KEEPALIVE: Tells the compiler to export this function so JavaScript can call it
// Without this macro, the function would be optimized away during compilation
EMSCRIPTEN_KEEPALIVE
void edge_detection(unsigned char* imageData, int width, int height) {
    // imageData: Pointer to the image pixel data in memory (RGBA format: Red, Green, Blue, Alpha)
    // width: Number of pixels horizontally in the image
    // height: Number of pixels vertically in the image
    
    // Allocate temporary buffer in WebAssembly memory to store the processed image
    // Size calculation: width * height * 4 bytes (4 bytes per pixel for RGBA)
    unsigned char* temp = (unsigned char*)malloc(width * height * 4);
    
    // Sobel operator kernels: 3x3 matrices used to detect edges
    // sobelX detects HORIZONTAL edges (left-to-right intensity changes)
    // The middle column is 0, left side is negative, right side is positive
    int sobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    
    // sobelY detects VERTICAL edges (top-to-bottom intensity changes)
    // The middle row is 0, top is negative, bottom is positive
    int sobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    // Loop through each pixel in the image, skipping the border (1 pixel from each edge)
    // We skip borders because the Sobel operator needs neighboring pixels (can't process edges)
    for (int y = 1; y < height - 1; y++) {  // y: vertical position (row)
        for (int x = 1; x < width - 1; x++) {  // x: horizontal position (column)
            // gx: gradient in X direction (horizontal edge strength)
            // gy: gradient in Y direction (vertical edge strength)
            int gx = 0, gy = 0;
            
            // Apply Sobel operator: examine the 3x3 neighborhood around current pixel
            for (int ky = -1; ky <= 1; ky++) {  // ky: kernel Y offset (-1, 0, 1)
                for (int kx = -1; kx <= 1; kx++) {  // kx: kernel X offset (-1, 0, 1)
                    // Calculate index of neighbor pixel in the 1D imageData array
                    // Formula: ((row * width) + column) * 4 (multiply by 4 for RGBA)
                    int idx = ((y + ky) * width + (x + kx)) * 4;
                    
                    // Convert RGB to grayscale by averaging the three color channels
                    // idx = Red, idx+1 = Green, idx+2 = Blue, idx+3 = Alpha (we ignore alpha)
                    int gray = (imageData[idx] + imageData[idx + 1] + imageData[idx + 2]) / 3;
                    
                    // Multiply grayscale value by corresponding Sobel kernel values
                    // and accumulate to calculate the gradient (edge strength)
                    // ky+1 and kx+1 convert from range [-1,1] to array indices [0,2]
                    gx += gray * sobelX[ky + 1][kx + 1];  // Horizontal gradient accumulation
                    gy += gray * sobelY[ky + 1][kx + 1];  // Vertical gradient accumulation
                }
            }
            
            // Calculate edge strength (magnitude) using Pythagorean theorem
            // sqrt(gx² + gy²) gives us the overall edge intensity
            int magnitude = (int)sqrt(gx * gx + gy * gy);
            
            // Clamp magnitude to valid pixel range (0-255)
            // If calculated value exceeds 255, cap it at 255
            if (magnitude > 255) magnitude = 255;
            
            // Calculate index for current pixel in the output buffer
            int idx = (y * width + x) * 4;
            
            // Write grayscale edge value to all three color channels (R, G, B)
            // This creates a grayscale image where bright = strong edge, dark = weak edge
            temp[idx] = temp[idx + 1] = temp[idx + 2] = magnitude;
            
            // Set alpha channel to 255 (fully opaque, no transparency)
            temp[idx + 3] = 255;
        }
    }
    
    // Copy the processed image from temporary buffer back to the original imageData array
    // This modifies the image data that JavaScript passed to us
    // Loop through ALL bytes: width * height * 4 (4 bytes per pixel)
    for (int i = 0; i < width * height * 4; i++) {
        imageData[i] = temp[i];  // Copy each byte (R, G, B, or A)
    }
    
    // Free the temporary buffer to prevent memory leaks
    // WebAssembly has manual memory management - we must free what we malloc!
    free(temp);
}
