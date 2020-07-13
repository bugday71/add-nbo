#include <stdio.h>
#include <arpa/inet.h>
#include "my_ntohl.h"

int main(int argc, char *argv[]){

	char buf[256];
	FILE *fd1; 
	FILE *fd2;
	int retval1, retval2;

	uint32_t n1, n2;
	int sum;

	if( argc != 3 ){
		printf("syntax : %s <file1> <file2>\n", argv[0]);
		printf("sample : %s a.bin c.bin\n", argv[0]);
		return 0;
	}

	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[2], "r");

	retval1 = fread(&n1, 1, 4, fd1);
	retval2 = fread(&n2, 1, 4, fd2);
	
	if( BYTE_ORDER == BIG_ENDIAN){
		sum = n1 + n2;
	}
	else if( BYTE_ORDER == LITTLE_ENDIAN ){
		n1 = my_ntohl(n1);
	        n2 = my_ntohl(n2);
		sum = n1 + n2;
	}
	else{
		printf("what ENDIAN???\n");
		return 0;
	}

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n1, n1, n2, n2, sum, sum );

	fclose(fd1);
	fclose(fd2);
	return 0;
}
