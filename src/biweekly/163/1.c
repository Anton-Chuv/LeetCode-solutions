int minSensors(int n, int m, int k) {
    int sensorsX = n / (2 * k + 1);
    if (n % (2 * k + 1) != 0) sensorsX++;
    int sensorsY = m / (2 * k + 1);
    if (m % (2 * k + 1) != 0) sensorsY++;
    return sensorsX * sensorsY;
}
