#include <stdio.h>

int main(int argc, char **argv)
{ 
char **ptr = argv; 
 
while (*ptr) 
{ 
	printf("character %c at %p\n", **ptr, *ptr);//l adresse *ptr est bien celle de la premiere variable qu elle contient/pointe
	printf("%p\n", ptr); 
	ptr++; 
} 
}
// https://www.quora.com/How-do-I-access-a-value-using-a-double-pointer-in-C