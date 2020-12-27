#include"ch07.h"
static void __attribute__((destructor))before_main(void)
{
	printf("-------Before Main-------\n");
}
int main()
{
	printf("-------Main Function is Running!-------\n");
	return 0;
}
