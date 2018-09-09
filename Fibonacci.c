#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  https://blog.csdn.net/dangzhangjing97/article/details/78778536
/*  
    �ݹ�ʵ��쳲���������
    (1)�ݹ飺�����Լ������Լ�
    (2)�ݹ��"ȱ��"���ݹ鵽һ���̶ȣ��ᷢ��"ջ���"
    (3)�ݹ��"ʱ�临�Ӷ�"���ݹ��ܴ���*ÿ�εݹ�Ĵ���
    (4)�ݹ��"�ռ临�Ӷ�"���ݹ�����*ÿ�εݹ�ռ�Ĵ�С��ע�⣺"ÿ�εݹ�ռ�Ĵ�С"�Ǹ����������Ի������Բ��ƣ�
    (5)�ݹ��"���"�����ĸ߶ȣ��ݹ�Ĺ�����һ��"������"��

    ���ַ�����ȱ�ݣ��ظ�����Ĵ���̫�࣬Ч�ʵ�
    ���磺����ͼ�У�F(3)���ظ������� "3��"
    ʱ�临�Ӷȣ�O(2^N)
    �ռ临�Ӷȣ�O(N)
*/
long long FibRecursion(long long N) // ��ʵ֤�����ַ����������˷�ʱ�䣬FibRecursion(60) ��Ҫ�޳�ʱ����ܵó���������� 6133s���������ˣ�
{
    if (N < 3)
        return 1;
    else
        return FibRecursion(N - 1) + FibRecursion(N - 2);
}

/*  
    β�ݹ�ʵ��쳲���������
    "β�ݹ��ǰ���ǵݹ�"
    (1)���壺��һ�������У�ִ�е����һ������Ƕ��Լ��ĵ��ã�����û�б������
    (2)β�ݹ��ʵ�֣����ڱ������Ż���������ʵ�ֵ�

    �������Ż���
    �ݹ�ĵ�һ�ε���ʱ�Ὺ��һ�ݿռ䣬�˺�ĵݹ���ò����ٿ��ٿռ䣬�����ڸղſ��ٵĿռ�����һЩ�޸ģ�ʵ�ִ˴εݹ飬
    �����ڱ�������Fib��10�������������Fib��10���ĵ��ÿ���ջ֡������Fib��9����ʱ�򲻻������¿���ջ֡�������ڸտ��ٵ�ջ֡����һЩ�޸ģ�
    ��Ϊ�ݹ��ÿһ�ε��ö���һ�������̣�ֻ�ǻ���һЩ���ݲ�ͬ�����Բ����ٿ��ٿռ䡣

    ע��vsһ�㶼֧���Ż���Debug�±����������Ż�Ŷ��һ��Ҫ��Releaseģʽ�¡�

    ���ַ�����β�ݹ飬�ܴ�̶ȵļ�С�˵�һ�ַ������ݹ�ʵ��쳲��������У���ʱ�临�Ӷ�
    ʱ�临�Ӷȣ�O(N-2)Լ����0(N)
    �ռ临�Ӷȣ�O(N-2)Լ����0(N)������������Ż��Ļ���O��1����
*/
long long FibTailRecursion(long long first, long long second, long long N)
{
    if (N < 3)
        return 1;
    if (N == 3)
        return first + second;
    return FibTailRecursion(second, first + second, N - 1);
}

/*  
    ѭ��ʵ��쳲���������
    ʱ�临�Ӷȣ�O(N)
    �ռ临�Ӷȣ�O(1)���������ĸ������ǳ��������Կɺ��Բ��ƣ�
    ���ַ�����"���ŷ���"
    �ŵ㣺ʱ�临�ӶȺͿռ临�Ӷ���ͣ����ҿɶ��Ը�
*/
long long FibLoop(long long N)
{
    long long first = 1;
    long long second = 1;
    long long ret = 0;
    for (int i = 3; i <= N; ++i)
    {
        ret = first + second;
        first = second;
        second = ret;
    }
    return second;
}

int main()
{
    clock_t ts1, te1, ts2, te2, ts3, te3;
    long long result1, result2, result3;

    ts1 = clock();
    result1 = FibRecursion(60);
    te1 = clock();

    ts2 = clock();
    result2 = FibTailRecursion(1, 1, 60);
    te2 = clock();

    ts3 = clock();
    result3 = FibLoop(60);
    te3 = clock();

    printf(" �ݹ飺%lld\t%llds\n β�ݹ飺%lld\t%llds\n ѭ����%lld\t%llds",
           result1, (te1 - ts1) / CLOCKS_PER_SEC,
           result2, (te2 - ts2) / CLOCKS_PER_SEC,
           result3, (te3 - ts3) / CLOCKS_PER_SEC);
    getchar();
    return 0;
}