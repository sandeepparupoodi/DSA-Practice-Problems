#include <stdio.h>
#include <stdlib.h>

struct Flat {
    int val;  
    int h;
};

int compare(const void *a, const void *b) {
    struct Flat *f1 = (struct Flat *)a;
    struct Flat *f2 = (struct Flat *)b;
    return (f1->val - f2->val);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while(t-->0) {
        int n;
        scanf("%d", &n);

        struct Flat flats[n];
        int total_people = 0;

        for(int i = 0; i < n; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            flats[i].val = x - y;
            flats[i].h = h;
            total_people += h;
        }

        if (total_people % 2 != 0) {
            printf("NO\n");
            continue;
        }

        qsort(flats, n, sizeof(struct Flat), compare);

        int target = total_people / 2;
        int pref[n];
        pref[0] = flats[0].h;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + flats[i].h;
        }

        int l = 0, r = n - 1;
        int found = 0;

        while(l<= r) {
            int mid = (l+r)/2;
            if (pref[mid] == target) {
                if (mid < n - 1 && flats[mid].val < flats[mid + 1].val) {
                    found = 1;
                }
                break;
            } else if (pref[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (found) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}