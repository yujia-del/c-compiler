int main()//这是一条注释
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
    /*
    这是多行注释
    */
}
