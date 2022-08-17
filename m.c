#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * addBinary(char * a, char * b){
    int lenA = strlen(a);
    int lenB = strlen(b);
    char * longest = NULL;
    char * shortest = NULL;

    int s = 0;
    int l = 0;

    if(lenA>=lenB){
        longest = a;
        shortest = b;

        l=lenA;
        s=lenB;
    }
    else{
        longest = b;
        shortest = a;

        l=lenB;
        s=lenA;
    }

    char * res = malloc(l+2);
    *(res+l+1) = '\0'; /* NULL POINTER */

    int carry = 0;  int sum = 0; 
    for(int loop = l-1 ; loop>=0 ; loop--){
        sum = (s>0) ? ((longest[loop]-'0') + (shortest[s-1]-'0') + carry) : ((longest[loop]-'0') + carry);
        *(res+loop+1) = (sum%2) ? '1' : '0';
        s--;
        carry = sum/2;
    }
    *(res) = carry + '0';

    while(l>0 && *res == '0'){
        res++;
        l--;
    }
        

    return res;

}

int main(){

    char * a = "010";
    char * b = "01";
    printf("%s",addBinary(a,b));



    return 0;
}