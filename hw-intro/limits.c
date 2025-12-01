#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    int ret;
    
    ret = getrlimit(RLIMIT_STACK, &lim);
    if (ret != 0) {
        fprintf(stderr, "getrlimit failed\n");
    } else {
        printf("stack size: %ld\n", (long)lim.rlim_cur);
    }
    
    ret = getrlimit(RLIMIT_NPROC, &lim);
    if (ret != 0) {
        fprintf(stderr, "getrlimit failed\n");
    } else {
        printf("process limit: %ld\n", (long)lim.rlim_cur);
    }

    ret = getrlimit(RLIMIT_NOFILE, &lim);
    if (ret != 0) {
        fprintf(stderr, "getrlimit failed\n");
    } else {
        printf("max file descriptors: %ld\n", (long)lim.rlim_cur);
    }
    
    return 0;
}
