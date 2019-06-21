#include <stdio.h>
int new_pow(int base, int exponent) //base를 exponent승 한 후 결과를 출력하는 함수
{
    int num = 1;
    for (int i=0; i< exponent; i++, num *= base);
    return num;
} //math.h에 pow(double,double) 함수가 있지만, double형으로 나누는 결과를 int형으로 바꾸는 과정에서 '10의 제곱은 99'와 같이 오류가 발생해서 새로운 함수를 만듬

int is_prime (int num) //num이 소수인지 아닌지 판별하여 소수면 0을 반환하는 함수, 소수가 아니라면 1을 반환하여 main함수에서 num이 증가하도록 하는 함수
{
    for (int i = 1; i<= num; i++) if ( (i!= 1 && i != num && num % i == 0) || num == 1) return 1; //1과 자기자신을 제외하고 나누어지는 수가 있을 경우에 1을 반환함.
    return 0;
}

int prime_sender(int num,int repeat) //넘어온 num을 조건에 맞게 잘라, 잘린 수를 is_prime()에 보내서 소수인지 판별한 후, 모든 잘린 수가 소수라면, 1을 반환하는 함수.
{
    for (int i = 0; i< repeat; i++) { //num을 잘라 잘린 수를 소수인지 검사하는 알고리즘 구현 for문
        /*
            repeat은 num의 자리수를 나타낸다.
            넘어온 num을 자르는 방법은 아래와 같다. (3797을 예시로 계산) :
            3797의 자리 수는 4이므로, i= 0 ~ 3이다, 3797을 잘라서 만족해야 할 수를 나열해 보면 다음과 같다.

            / 10^0 (1) = 3797     % 10^1 = 3
            / 10^1 (10) = 379     % 10^2 = 97
            / 10^2 (100) = 37     % 10^3 = 797
            / 10^3 (1000) = 3     % 10^4 = 3797
            위의 수들은 num / 10^i , num % 10^(i+1)를 햇을 때 나오는 수들의 집합이다.
            어떤 수가 prime_Sender로 넘어오더라도 length까지 for문을 돌려, num / 10^i , num % 10^(i+1)식을 적용하여, 나오는 수들은 잘린 수들이다.
            위의 잘린 수들을 is_prime으로 넘겨, 소수가 아니라면 1일 반환되어 아래 if문에 의해 prime_sender에서 main함수로 0이 반환된다. (넘어온 num은 조건에 맞지 않습니다 라고 전달함)
        */

        if (is_prime(num / new_pow(10,i))) return 0;
        if (is_prime(num % new_pow(10,i+1))) return 0;
    }
    printf("%d\n",num); //조건에 맞는 수를 출력하여 작업이 진행중임을 표시
    return 1; //잘라진 모든수가 소수임이 확인되면 1을 반환하여 main함수로 돌아가 다음 명령어를 실행한다 (count++, sum+=num).
}

int main() {
    int sum = 0,length,count=0; //sum : 조건에 만족하는 수의 합 , length = 증가하는 num의 자리수, count = for문을 중지시키기 위해 조건에 만족하는 수를 저장하는 변수
    for (int num= 11; num<= 10000000; num+=2) { //num을 11부터 시작해서 2씩 증가시키는 for문 (소수는 2로 끝나지 않음 , 2 , 3 ,  5 , 7는 문제에 제시된대로 제외함)
        if (count >= 11) break; //문제조건을 만족하는 소수가 11개 이상이 되면 for문 중지
        for (length = 0; length < 9; length++) if (num / new_pow(10, length) == 0) break;
        /*
            for문 에서 2씩 증가하는 수의 자리수를 구하는 코드이다.
            length는 자리수를 저장하는 변수, 아래와 같은 과정으로 자리수를 구한다
            length는 0부터 시작해서 1씩 증가하며, num을 10의 i승으로 나누었을 때 0이라면, for문을 탈출하여 length에 자리수가 저장된다.
            ex> 3757을 예제로 한다면. 10^4 (10000)로 나누었을 때 처음으로 0이 나오므로 ,length에는 4가 저장됨.
         */
        if (prime_sender(num,length) == 1) { //수를 prime_sender에 num과 자리수를 보내어 수를 잘라 소수인지 판별하게 함, 잘라진 모든 수가 소수임이 확인된다면
            count ++; //count를 증가시켜 for문을 중지하도록 한다.
            sum += num; //sum에 num을 더한후 sum에 넣은다.
        }
    }
    printf ("\n%d",sum); //조건을 만족하는 수의 합인 sum을 출력함
    return 0;
}
