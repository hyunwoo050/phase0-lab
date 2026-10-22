#include <stdio.h>
#include "mystr.h"

// 문자열 길이 계산 함수
int my_strlen(const char *s) {
	int n = 0;
	while (s[n] != '\0') n++;
	return n;
}

// 문자열 복사 함수
void my_strcpy(char *dst, const char *src) {
	int i = 0;
	while (src[i] != '\0') { dst[i] = src[i]; i++; }
	dst[i] = '\0'; // 널 문자까지 반드시 복사
}

// 문자열 비교 함수 (같으면 0, 다르면 먼저 달라진 글자의 차이 반환)
int my_strcmp(const char *s1, const char *s2) {
	int i = 0;
	while (s1[i] == s2[i]) {
		if (s1[i] == '\0') {
			return 0; // 끝까지 일치하므로 0 반환
		}
		i++;
	}
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}
