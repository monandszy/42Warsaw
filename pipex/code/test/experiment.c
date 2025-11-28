#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Required for write() and STDERR_FILENO

#define CHUNK_SIZE (1024 * 1024)               // Allocate in 1 MB chunks
#define HUGE_PRINT_WIDTH (100 * 1024 * 1024)   // Ask printf to format a 100 MB string

// A safe, low-level function for reliable error reporting that doesn't use malloc.
void safe_puts(const char *s) {
    write(STDERR_FILENO, s, strlen(s));
}

int main(void) {
    // To make this experiment run quickly and predictably, we need to limit
    // the virtual memory available to this process. Otherwise, it could take
    // gigabytes of RAM and a long time to fail.
    // We will do this from the command line before running.
    
    printf("Attempting to exhaust available memory by allocating 1MB chunks...\n");
    fflush(stdout); // Ensure the initial message is printed before any potential failure.

    // 1. Exhaust the heap memory
    int allocated_mb = 0;
    while (1) {
        void *p = malloc(CHUNK_SIZE);
        if (p == NULL) {
            // Success! Malloc has officially failed.
            break;
        }
        allocated_mb++;
    }

    // Use a simple printf, which will probably work, to announce the failure.
    printf("\n--- Malloc has failed after allocating %d MB. ---\n\n", allocated_mb);
    fflush(stdout);

    // 2. Attempt a "difficult" printf call
    // This asks the C library to format a string of 100 million spaces.
    // The glibc implementation will likely try to malloc a buffer for this, which will fail.
    safe_puts("--> Now attempting a 'difficult' printf with a huge format width...\n");
    
    int ret = printf("%*s", HUGE_PRINT_WIDTH, "");
    
    // 3. Check the result of the difficult printf
    if (ret < 0) {
        // A negative return value means printf failed.
        safe_puts("--> RESULT: The difficult printf() call FAILED, as expected!\n");
        
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "    printf returned: %d\n", ret);
        safe_puts(buffer);

        if (ferror(stdout)) {
            safe_puts("    The error indicator for stdout is set (checked with ferror).\n");
        }
    } else {
        // This would be surprising, but possible on some implementations.
        safe_puts("--> RESULT: The difficult printf() call SUCCEEDED unexpectedly.\n");
        
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "    printf returned: %d\n", ret);
        safe_puts(buffer);
    }
    
    safe_puts("\n--> The program is still running and can report this outcome via write().\n");

    return 0;
}
