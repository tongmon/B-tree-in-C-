#include <iostream>
#include <queue>
using namespace std;

int Fibonacci_Q(int loop) // ť�� �̿��� �Ǻ���ġ
{
    queue<int> Fib;
    Fib.push(0); Fib.push(1);
    while (loop >= 1)
    {
        loop--;
        Fib.push(Fib.front() + Fib.back());
        Fib.pop();
    }
    return Fib.front();
}

int Fibonacci_Re(int loop, int post = 0, int front = 1) // �ݺ��� ��͸� �̿��� �Ǻ���ġ
{
    if (loop <= 0) return post;
    Fibonacci_Re(--loop, front, post + front);
}

int Fibonacci(int loop) // ��͸� �̿��� �Ǻ���ġ
{
    if (loop <= 0) return 0;
    else if (loop == 1) return 1;
    else
    {
        return Fibonacci(loop - 1) + Fibonacci(loop - 2);
    }
}

int Fibo(int* count, int loop)
{
    count[loop]++;
    if (loop <= 0)
    {
        return 0;
    }
    else if (loop == 1)
    {
        return 1;
    }
    else
    {
        return Fibo(count, loop - 1) + Fibo(count, loop - 2);
    }
}

void printFib(int loop) // �Ǻ���ġ ��Ͱ� �󸶳� ��ȿ�������� �˱����� ī��Ʈ �Լ�
{
    int* ary = new int[loop + 1];
    for (int i = 0; i <= loop; i++)
    {
        ary[i] = 0;
    }
    Fibo(ary, loop);
    for (int i = 0; i <= loop; i++)
    {
        cout << "Fibo(" << i << ") = " << ary[i] << "��\n";
    }
    delete[]ary;
}

int Ackermann(int m, int n) // ���� �����ص� ��ģ���� ���� �ҷ����� ��Ŀ�� �Լ�
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return Ackermann(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
    cout << "error" << endl;
    return -1;
}