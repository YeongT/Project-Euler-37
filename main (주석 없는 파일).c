
#include <stdio.h>
int new_pow(int base, int exponent) {
    int num = 1;
    for (int i=0; i< exponent; i++, num *= base);
    return num;
} 

int is_prime (int num) {
    for (int i = 1; i<= num; i++) if ( (i!= 1 && i != num && num % i == 0) || num == 1) return 1;
    return 0;
}

int prime_sender(int num,int repeat) {
    for (int i = 0; i< repeat; i++) {
        if (is_prime(num / new_pow(10,i))) return 0;
        if (is_prime(num % new_pow(10,i+1))) return 0;
    }
    printf("%d\n",num);
    return 1;
}

int main() {
    int sum = 0,length,count=0;
    for (int num= 11; num<= 10000000; num+=2) {
        if (count >= 11) break;
        for (length = 0; length < 9; length++) if (num / new_pow(10, length) == 0) break;
        if (prime_sender(num,length) == 1) { 
            count ++;
            sum += num; 
        }
    }
    printf ("\n%d",sum); 
    return 0;
}
