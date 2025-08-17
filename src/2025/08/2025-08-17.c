#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

double new21Game(int n, int k, int maxPts) {
    double *p = (double *)malloc(maxPts * sizeof(double));
    for (int i = 0; i < maxPts; i++) p[i] = 0.0;

    if (k == 0)
        return 1.0;

    for (int i = 1; i < k; i++) {
        double q = 0; // prob of get exact i score on any taken card within i card taken
        if (i <= maxPts) // take score with one card
            q = 1.0 / maxPts;
        q += p[0] / maxPts;
        for (int j = 1; j < maxPts; j++) {
            q += p[j] / maxPts;
            p[j - 1] = p[j];
        }
        p[maxPts - 1] = q;
    }
    double ans = 0;
    for (int i = k; i <= n; i++) {
        double q = 0; // prob of get exact i score on any taken card within i card taken
        if (i <= maxPts) // take score with one card
            q = 1.0 / maxPts;
        for (int j = 0; j < maxPts - (i - k); j++)
            q += p[maxPts - j - 1] / maxPts;
        ans += q;
    }

    return ans;
}

int main() {
    printf("\n%f", new21Game(1, 0, 1));
    return 0;
}
