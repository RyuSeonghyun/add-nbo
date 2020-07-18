#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

uint32_t read_binary(FILE *fp) {

	char str[30];
	
	uint8_t len = fread(str, 1, 29, fp);
	str[len] = '\0';
	
	uint32_t* p = reinterpret_cast<uint32_t*>(str);
	uint32_t n = ntohl(*p);
	
	return n;
	
}

int main(int argc, char *argv[]) {
	
	uint32_t fileA, fileB;
	uint32_t sum;
	
	FILE *fd1, *fd2;
	
	fd1 = fopen(argv[1], "rb");
	fd2 = fopen(argv[2], "rb");
	if (fd1==NULL || fd2==NULL){
		printf("File Open failed!\n");
		return 0;
	}

	fileA = read_binary(fd1);
	fileB = read_binary(fd2);
	sum = fileA + fileB;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", fileA, fileA, fileB, fileB, sum, sum);
	
	return 0;

}

