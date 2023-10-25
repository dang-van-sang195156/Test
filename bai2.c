#include <stdio.h>
#include <string.h>

int main() {
    const char* haystack = "Hello, world!aiofa;oeiha;ưeoi";
    const char* needle = ",";

    const char* result = strstr(haystack, needle);

    if (result != NULL) {
        printf("Chuoi con duoc tim thay tai vi tri: %s\n", result);
    } else {
        printf("Chuoi con khong tim thay.\n");
    }

    return 0;
}
