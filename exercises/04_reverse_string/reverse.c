// Include Emscripten's header for WebAssembly integration macros
#include <emscripten/emscripten.h>

// Include string.h for strlen() function (calculates string length)
#include <string.h>

// Include stdlib.h for malloc() function (dynamic memory allocation)
#include <stdlib.h>

// EMSCRIPTEN_KEEPALIVE: Export this function so JavaScript can call it
// Without this, the compiler would remove "unused" functions during optimization
EMSCRIPTEN_KEEPALIVE
char* reverse(const char* str) {
    // str: Pointer to the input string (const = we won't modify the original)
    // Returns: Pointer to a newly allocated reversed string
    
    // Calculate the length of the input string (number of characters, not including null terminator)
    int len = strlen(str);
    
    // Allocate memory for the reversed string in WebAssembly's linear memory
    // Size: len + 1 (the +1 is for the null terminator '\0' that marks string end in C)
    // malloc returns a pointer to the allocated memory block
    char* result = (char*)malloc(len + 1);
    
    // Loop through the input string and copy characters in REVERSE order
    for (int i = 0; i < len; i++) {  // i goes from 0 to len-1
        // Copy character from END of input string to START of result string
        // Example: if str = "abc" (len=3)
        //   i=0: result[0] = str[2] = 'c'
        //   i=1: result[1] = str[1] = 'b'
        //   i=2: result[2] = str[0] = 'a'
        result[i] = str[len - 1 - i];
    }
    
    // Add null terminator at the end to mark the string's end (required in C)
    // Without this, functions like strlen() wouldn't know where the string ends
    result[len] = '\0';
    
    // Return pointer to the reversed string
    // IMPORTANT: JavaScript must free this memory later using Module._free()
    // to prevent memory leaks in WebAssembly!
    return result;
}
