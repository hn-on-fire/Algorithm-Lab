#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char* ele;
    int* shift;
    int len;
} shiftTable;
short in(char a, char* ele, int len){
    for(int i=0;i<len;i++){
        if(a==ele[i]) return i+1;
    }
    return 0;
}
shiftTable* getShiftTable(char* str){
    int len = strlen(str);
    shiftTable* st = (shiftTable*)malloc(sizeof(shiftTable));
    st->len = 0;
    st->ele = (char*)calloc(len, sizeof(char));
    st->shift = (int*)calloc(len,sizeof(int));
    for(int i=len-1;i>=0;i--){
        if(in(str[i],st->ele, st->len))continue;
        st->shift[st->len] = (len-i-1!=0)?len-i-1:len;
        st->ele[st->len] = str[i];
        for(int j=i-1;j>=0;j--){             //hello
            if(str[i] == str[j]){
                st->shift[st->len] = i-j;
                
                break;
            }
        }
        (st->len)++;
    }
    return st;
    }
    int getOffset(char a, shiftTable* st){
        int val = in(a,st->ele,st->len);
        if(val == 0) return -1;
        return st->shift[val-1];
    }
    void printy(shiftTable* st){
        for(int i =0; i< st->len;i++)
        printf("ele: %c; shift: %d\n", st->ele[i], st->shift[i]);
    }
    void main(){
        char* a = "Hello";
        char* b = "What is Hello, Dummy?";
        shiftTable* st = getShiftTable(a);
        printy(st);
        int lena = strlen(a), lenb = strlen(b);
        int offset =0;
        if(lena>lenb){
            printf("Nada\n");
        }
        short matched = 0;
        while((offset+strlen(a))<=strlen(b) && !matched){
            matched = 1;
            for(int i = lena-1;i>0;i--)
            {
                if(a[i]!=b[offset+i]){
                    matched = 0;
                    int t = getOffset(b[offset+i], st);
                    if(t==-1){
                        offset+=lena;
                    }
                    else offset += t;
                    break;
                }
            }
            if(matched){
                printf("Found at index %d", offset);
                break;
            }
            matched=0;

        }
        if(matched == 0){
            printf("Not Found");
        }
        
}
