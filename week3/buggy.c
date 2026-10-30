#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct node {
	uint8_t mac[6];
	int	port;
	struct node *next;
} node_t;

// 노드 추가 함수 (머리에 추가)
int add_entry(node_t **head, const uint8_t *mac, int port) {
	node_t *n = malloc(sizeof(node_t));
	if (n == NULL) return -1;
	memcpy(n->mac, mac, 6);
	n->port = port;
	n->next = *head;	/* 먼저 연결 */
	*head = n;		/* 그 다음 머리 교체 */
	return 0;
}

// 노드 조회 함수
node_t *find_entry(node_t *head, const uint8_t *mac) {
	for (node_t *c = head; c != NULL; c = c->next)
		if (memcmp(c->mac, mac, 6) == 0) return c;
	return NULL;
}

// 노드 삭제 함수 (첫 노드 / 중간 노드 구분 없음)
int del_entry(node_t **head, const uint8_t *mac) {
	node_t **pp = head;
	while (*pp != NULL) {
		if (memcmp((*pp)->mac, mac, 6) == 0) {
			node_t *dead = *pp;
			*pp = dead->next;	/* 먼저 이어 준 뒤 */
			free(dead);		/* 해제 */
			return 0;
		}
		pp = &(*pp)->next;
	}
	return -1;
}

// 모든 노드를 안전하게 해제하는 함수
void free_entry(node_t **head) {
	node_t *curr = *head;
	while (curr != NULL) {
		node_t *next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

// main 함수
int main(void) {
	node_t *table = NULL;

	// 가상의 MAC 주소 3개 정의
	uint8_t mac1[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
	uint8_t mac2[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
	uint8_t mac3[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

	// 항목 3개 추가 등록
	add_entry(&table, mac1, 1);
	add_entry(&table, mac2, 2);
	add_entry(&table, mac3, 3);
	printf("[안내] 확인 항목 3개 등록 완료\n");

	// 하나를 조회하면 해당 포트 번호가 나옴
	printf("\n--- 1. mac2 항목 조회 시도 ---\n");
	node_t *found = find_entry(table, mac2);
	if(found) {
		printf("조회 성공! MAC 주소의 포트 번호: %d\n", found->port);
	} else {
		printf("조회 실패: 찾지 못했습니다.\n");
	}

	// 하나를 삭제
	printf("\n--- 2. mac2 항목 삭제 시도 ---\n");
	del_entry(&table, mac2);

	//버그 심기: 해제된 노드의 값을 읽기
	printf("[버그] 해제된 노드의 포트 값 읽기: %d\n", found->port);

	// 삭제 후 다시 조회하면 찾지 못했다는 결과가 나옴
	printf("\n--- 3. 삭제 후 mac2 항목 재조회 시도 ---\n");
	found = find_entry(table, mac2);
	if(found) {
		printf("조회 성공! 포트 번호: %d\n", found->port);
	} else {
		printf("결과: 해당 MAC 주소를 찾지 못했습니다.\n");
	}

	// 프로그램 끝에서 모든 노드 해제
	free_entry(&table);
	printf("\n[안내] 모든 메모리 해제 완료\n");

	return 0;
}
