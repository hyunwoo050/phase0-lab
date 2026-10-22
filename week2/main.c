#include <stdio.h>
#include "mystr.h"

int main(void) {
	char src[] = "router";
	char dst[16];

	// 문자열 복사 실행
	my_strcpy(dst, src);

	// 글자 수 길이(6) 출력
	printf("글자 수 길이 : %d\n", my_strlen(dst));

	// 복사 결과 ("router")
	printf("복사 결과 : %s\n", dst);

	// 복사 결과가 원본과 같은지 비교 (결과 0)
	printf("같은 문자열 비교 결과 : %d\n", my_strcmp(src, dst));
	return 0;
}
