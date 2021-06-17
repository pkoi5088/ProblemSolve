#include <stdio.h>

int main(void) {
	int x, y, w, h, xr, yr;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	xr = w - x;
	yr = h - y;
	if (x <= y && x <= xr && x <= yr)
		printf("%d", x);
	else if (y <= x && y <= xr && y <= yr)
		printf("%d", y);
	else if (xr <= x && xr <= y && xr <= yr)
		printf("%d", xr);
	else
		printf("%d", yr);
	return 0;
}