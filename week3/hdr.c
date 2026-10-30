#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t mac[6];
	int	port;
} mac_entry_t;

typedef union {
	uint32_t v32;
	uint8_t  b[4];
} ip_u;

struct ipv4_first_byte {
	uint8_t ihl	: 4; /* 헤더 길이 항목: 4비트 */
	uint8_t version : 4; /* 버전 항목: 4비트 */
};

int main(void) {
	mac_entry_t e = { {0x00,0x1A,0x2B,0x3C,0x4D,0x5E}, 3 };
	mac_entry_t *p = &e;
	printf("port=%d first=%02X\n", p->port, p->mac[0]);

	ip_u u; u.v32 = 0xC0A8000A;
	printf("union size=%zu b[0]=%02X\n", sizeof(u), u.b[0]);

	uint8_t raw = 0x45;
	struct ipv4_first_byte *h = (struct ipv4_first_byte *)&raw;
	printf("version=%u ihl=%u\n", h->version, h->ihl);
	printf("shift version=%u ihl=%u\n", (raw >> 4) & 0x0F, raw & 0x0F);
	return 0;
}

