int main() {
    int a[10];
    int i=0;
    int sum=0;
    for (i; i < 10; i=i+1) {
        a[i] = i;
    }
    i = 0;
    for (i; i < 10; i=i+1) {
        sum = sum + a[i];
    }
    return 0;
}