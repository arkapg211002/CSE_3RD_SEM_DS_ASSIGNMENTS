#include <stdio.h>
#include <stdlib.h>
void towerOfHanoi(int n, char source, char target, char aux)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", source, target);
		return;
	}
	towerOfHanoi(n-1, source, aux, target);
	printf("\n Move disk %d from rod %c to rod %c", n, source, target);
	towerOfHanoi(n-1, aux, target, source);
}

void main()
{
	int n;
    printf("Enter number of disks : ");
    scanf("%d", &n);
	towerOfHanoi(n, 'S', 'A', 'T');
	
}
