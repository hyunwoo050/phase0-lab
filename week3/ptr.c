#include <stdio.h>

void set_to(int *target, int v) { *target = v; }

int main(void) {
	int x = 10;
	int *p = &x;
	printf("x=%d &x=%p p=%p *p=%d\n", x, (void *)&x, (void *)p, *p);
	*p = 20;
	printf("after *p=20 -> x=%d\n", x);
	set_to(&x, 77);
	printf("after set_to -> x=%d\n", x);

	int a[3] = {5, 6, 7};
	printf("a[1]=%d *(a+1)=%d\n", a[1], *(a+1));
	printf("sizeof(a)=%zu sizeof(p)=%zu\n",sizeof(a), sizeof(p));
	return 0;
}
