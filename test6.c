#include <stdio.h>


void ft_check(char **str)
{
    *str = (*str + 1);//fait reference a ce qui est pointe par le pointeur(&str), donc l adresse du premier char de la string(a), le pointeur pointe desormais sur char+1 dans le main egalement
    printf("%s\n",*str);
}


int main() 
{
    char *str;
    
    str = "abc";
    printf("%s\n",str);
    ft_check(&str); //j envoie l adresse du pointeur, le receptacle est un 2x pointeur cree sur le champ dont le str est justement *str, ie qui pointe sur str
    printf("%s\n", str);
    return(0);
}
