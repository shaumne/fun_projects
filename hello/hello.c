#include <stdio.h>

int main(void)
{
    // kullanıcıdan adı al
    printf("What is your name?\n");
    char name[50];
    scanf("%s", name);

    // mesajı ekrana yazdır
    printf("Helo, %s!\n", name);
    return 0;
}
