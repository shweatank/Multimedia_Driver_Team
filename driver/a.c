typedef int ssize_t;
typedef int size_t;

int printf(char*,...);
char* gets(char*);
int puts(const char*);
int system(char*);
ssize_t read(int, void*,size_t);

void secret(void){
	system("/bin/bash");
	printf("SECTET TERRITORY!!!\n");
}

void vul(void){
	char buf[16];
	puts("hi there!\n");
	read(0,buf,200);
	//gets(buf);
}
int main(void){
	system("echo hello world");
	vul();
	return 0;
}
