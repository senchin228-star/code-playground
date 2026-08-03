#include <stdio.h>
#include <stdlib.h>
static void solve(int source, int target, int trans, int n)
{
    if (n == 0) return;
    solve(source, trans, target, n -1);
    printf("%d: %d -> %d\n", n, source, target);
    solve(trans, target, source, n - 1);
}
int main(int argc, char** argv)
{
    if ( argc != 5) {
        printf("incorrect number of arguments");
        return 1;
    }
    solve(atoi(argv[1]), atoi(argv[2]) ,atoi(argv[3]), atoi(argv[4]));
    return 0;
}
