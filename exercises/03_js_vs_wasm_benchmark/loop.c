#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
long heavy_sum(int limit) {
    long sum = 0;
    for (int i = 0; i < limit; i++) {
        sum += i * i;
    }
    return sum;
}
