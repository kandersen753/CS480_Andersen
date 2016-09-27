#include <iostream>
#include <stdio.h>

int main()
{
	char s[100];
	FILE * fp;
	fp = fopen ("read.txt" , "r");
	fscanf (fp, "%s" , s);
	printf ("%s\n", s);
	fclose (fp);
}
