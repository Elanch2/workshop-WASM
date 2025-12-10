// Include Emscripten's header file for WebAssembly integration
// This provides the EMSCRIPTEN_KEEPALIVE macro we use below
#include <emscripten/emscripten.h>

// EMSCRIPTEN_KEEPALIVE: Marks this function for export to JavaScript
// Without this macro, the compiler would optimize away "unused" functions
// This allows JavaScript to call Module._add(a, b)
EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
    // a: first integer to add
    // b: second integer to add
    // Returns: the sum of a and b
    return a + b;
}

// Export subtract function to JavaScript (callable as Module._subtract)
EMSCRIPTEN_KEEPALIVE
int subtract(int a, int b) {
    // a: number to subtract FROM (minuend)
    // b: number to subtract (subtrahend)
    // Returns: the difference (a - b)
    return a - b;
}

// Export multiply function to JavaScript (callable as Module._multiply)
EMSCRIPTEN_KEEPALIVE
int multiply(int a, int b) {
    // a: first factor
    // b: second factor
    // Returns: the product of a and b (a × b)
    return a * b;
}

// Export divide function to JavaScript (callable as Module._divide)
EMSCRIPTEN_KEEPALIVE
double divide(int a, int b) {
    // a: dividend (number to be divided)
    // b: divisor (number to divide by)
    // Returns: quotient as a floating-point number (double precision)
    
    // Safety check: prevent division by zero (would cause crash/undefined behavior)
    // If b is 0, return 0 as a safe fallback value
    if (b == 0) return 0;
    
    // Cast both integers to double BEFORE dividing
    // This ensures we get a decimal result (e.g., 7/2 = 3.5, not 3)
    // Without the cast, C would perform integer division (truncating the decimal)
    return (double)a / (double)b;
}
