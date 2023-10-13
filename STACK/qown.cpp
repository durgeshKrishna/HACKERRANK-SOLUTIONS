#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX 10

int s1[STACK_MAX], s2[STACK_MAX], top1 = -1, top2 = -1, n;

void IPpush(int item) {
    s1[++top1] = item;
}

void OPpush(int item) {
    s2[++top2] = item;
}

bool IPempty() {
    return top1 == -1;
}

bool OPempty() {
    return top2 == -1;
}

int IPpop() {
    n = s1[top1];
    top1--;
    return n;
}

int OPpop() {
    n = s2[top2];
    top2--;
    return n;
}

int IPtop(){
	return s1[top1];
}
int OPtop(){
	return s2[top2];
}


int top() {
    if(OPempty()){
    	while (!IPempty()) {
            OPpush(IPtop());
            IPpop();
        }
	}
	return OPtop();
}

int pop() {
    if (!OPempty()) {
        return OPpop();
    } else {
        while (!IPempty()) {
            OPpush(IPtop());
            IPpop();
        }
        return OPpop();
    }
}

int main() {
    
    IPpush(3);
    IPpush(4);
    printf("The popped element is %d\n", pop());
    //printf("The popped element is %d\n", pop());
    IPpush(5);
	printf("The peeked element is %d\n", top());
    
    return 0;
}

