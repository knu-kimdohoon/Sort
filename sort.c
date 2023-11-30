#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"



void main() {
	char filename[20] = { '\0' };
	FILE* fp = NULL;
	char* strings[50] = { '\0' };
	char buffer[1000] = { '\0' };
	char* ptr;
	int count = 0, choose = 0;

	printf("file name : ");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("failed to open file");
		exit(1);
	}

	while (!feof(fp)) {
		// 버퍼에 한 라인 입력 받기
		fgets(buffer, sizeof(buffer), fp);
		// 공백 기준으로 문장을 나누기
		ptr = strtok(buffer, " ");
		// 단어 하나하나에 접근한다
		while (ptr != NULL) {
			strings[count++] = ptr;
			ptr = strtok(NULL, " ");
		}
	}
	for (int j = 0; j < count; j++) {
		printf("[%d] %s [%d]\n", j, strings[j], strlen(strings[j]));
	}
	
	printf("choose (selectionSort[0], insertSort[1], bubbleSort[2], quickSort[3], heapSort[4], end[5]) : ");
	scanf("%d", &choose);
	if (choose == 5) exit(1);
	while (choose != 5) {
		printf("choose (selectionSort[0], insertSort[1], bubbleSort[2], quickSort[3], heapSort[4], end[5]) : ");
		scanf("%d", &choose);
		if (choose == 0) {
			selectionSort_c(strings, count);
			for (int i = 0; i < count; i++) {
				printf("[%d] %s [%c] [%d]\n", i, strings[i], strings[i][0], strlen(strings[i]));
			}
		}
		else if (choose == 1) {
			insertionSort(strings, count);
			for (int i = 0; i < count; i++) {
				printf("[%d] %s [%c] [%d]\n", i, strings[i], strings[i][0], strlen(strings[i]));
			}
		}
		else if (choose == 2) {
			bubbleSort(strings, count);
			for (int i = 0; i < count; i++) {
				printf("[%d] %s [%c] [%d]\n", i, strings[i], strings[i][0], strlen(strings[i]));
			}
		}
		else if (choose == 3) {
			quickSort(strings, 0, count);
			for (int i = 0; i < count; i++) {
				printf("[%d] %s [%c] [%d]\n", i, strings[i], strings[i][0], strlen(strings[i]));
			}
		}
		else if (choose == 4) {

		}
	}
	fclose(fp);
}