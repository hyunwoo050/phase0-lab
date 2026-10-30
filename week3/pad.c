#include <stdio.h>
#include <stddef.h>

struct bad  { char a; int b; char c; };
struct good { int b; char a; char c; };

int main(void) {
	struct bad dummy1;
	struct good dummy2;

	printf("bad  size=%zu	offset b=%zu c=%zu\n",
		sizeof(struct bad),
		offsetof(struct bad, b), offsetof(struct bad, c));
	printf("good size=%zu	offset a=%zu c=%zu\n",
		sizeof(struct good),
		offsetof(struct good, a), offsetof(struct good, c));
	return 0;
}
