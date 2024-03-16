#include <stdio.h>

#define PR(x) printf(#x "=%p, *" #x "=%d, &" #x "=%p\n", (void*)x, *x, (void*)&x)

int main(void) {
    int mas[] = { 100, 200, 300 };
    int* ptr1, * ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%d\n", ptr2 - ptr1);
    return 0;
}