#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

struct Segment {
    ll l;
    ll r;
};

int compare(const void *a, const void *b) {
    struct Segment *s1 = (struct Segment *)a;
    struct Segment *s2 = (struct Segment *)b;
    if (s1->l != s2->l) {
        return (s1->l > s2->l) - (s1->l < s2->l);
    }
    return (s1->r > s2->r) - (s1->r < s2->r);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while(t--) {
        ll n, L;
        scanf("%lld %lld", &n, &L);

        struct Segment seg[n];
        for(ll i=0;i<n;i++) {
            scanf("%lld %lld", &seg[i].l, &seg[i].r);
        }

        qsort(seg, n, sizeof(struct Segment), compare);

        int possible = 0;

        for(ll i=0;i<n;i++) {
            ll start_left = seg[i].l;
            ll cur_right = seg[i].r;
            ll maxright = cur_right;

            if (seg[i].r - seg[i].l == L) {
                possible = 1;
                break;
            }

            while (1) {
                for(ll j=0;j<n;j++) {
                    if (seg[j].l <= cur_right && seg[j].r > maxright) {
                        maxright = seg[j].r;
                    }
                    if (seg[j].l <= cur_right && seg[j].r - start_left == L) {
                        possible = 1;
                        break;
                    }
                }

                if (possible || (maxright - start_left == L)) {
                    possible = 1;
                    break;
                }

                if(cur_right==maxright) {
                    break;
                }

                cur_right = maxright;
            }

            if (possible) {
                break;
            }
        }

        if (possible) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}