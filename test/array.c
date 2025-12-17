int main()
{
    int a = 2;
    int *p;
    p = &a;
    int array[10];
    array[0] = a;
    a = array[0];
    p = &a;
    *p = a;
    a = *p;
    int i;
    for(i=0;i<10;i=i+1)
    {
        array[i] = i;
    }
    print_int(a);
}
