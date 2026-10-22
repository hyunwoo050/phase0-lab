#include <stdio.h>
#include <stdint.h>
int main(void) {
	printf("int=%zu long=%zu\n", sizeof(int), sizeof(long));
	unsigned char b = 255;
	b = b + 1;
	printf("255+1 in unchar = %u\n", b);
	return 0;
}
