#include <stdio.h>
#include <stdint.h>

uint32_t to_u32(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
	return ((uint32_t)a << 24) | ((uint32_t)b << 16)
		| ((uint32_t)c << 8) | (uint32_t)d;
}

int main(void) {
	uint32_t ip = to_u32(192, 168, 0, 10);
	printf("ip = 0x%08X\n", ip);
	uint32_t mask = 0xFFFFFF00u;
	uint32_t net = ip & mask;
	printf("network = %u.%u.%u.%u\n",
		(net >> 24) & 0xFF, (net >> 16) & 0xFF,
		(net >> 8) & 0xFF, net & 0xFF);
	return 0;
}
