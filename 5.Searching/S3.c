#include <stdio.h>
#include <stdbool.h>

int A[309][309];
bool ok[309][309][309];

void solve() {
    int R, C, L;
    scanf("%d %d %d", &R, &C, &L);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int mn = A[i][j], mx = A[i][j];
            for (int k = j; k < C; k++) {
                if (A[i][k] < mn) mn = A[i][k];
                if (A[i][k] > mx) mx = A[i][k];
                ok[i][j][k] = (mx - mn <= L);
            }
        }
    }

    int max_area = 0;
    for (int j = 0; j < C; j++) {
        for (int k = j; k < C; k++) {
            int width = k - j + 1;
            int consecutive_rows = 0;
            for (int i = 0; i < R; i++) {
                if (ok[i][j][k]) {
                    consecutive_rows++;
                    int area = consecutive_rows * width;
                    if (area > max_area) max_area = area;
                } else {
                    consecutive_rows = 0;
                }
            }
        }
    }

    printf("%d\n", max_area);
}

int main() {
    int T;
    if (scanf("%d", &T) == 1) {
        while (T--) {
            solve();
        }
    }
    return 0;
}