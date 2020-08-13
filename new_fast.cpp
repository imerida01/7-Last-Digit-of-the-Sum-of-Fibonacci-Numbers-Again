#include <iostream>
long long get_fibonacci_huge_sum_last_dig(long long n1,long long n2, long long m)
{
    if(n2<=1)
    {
        return n2;
    }
    long long remainder = n2 %m;
    long long z = n1%m;
    long long x=n1%m;
    long long sum_d=1;
    //std::cout<<x;

    long long sum;
    if (remainder == 0)
    {
        return 0;
    }

    if(n1<=2)
    {
                sum=1;
    }
    else if(remainder<z)
    {
        z=0;
      //  std::cout<<"(((((((((((((((("<<z<<"))))))))))))))))";
        sum=1;
    }
    //std::cout<<"\n\n(((((((((((((((("<<z<<"))))))))))))))))";
    else
        sum = 0;
    //std::cout<<"sum = "<<sum;

    long long first = 0;
    long long second = 1;
    long long res = remainder;
    for (long long i = 2; i <=remainder; i++)
        {
        res = (first + second) % m;
        first = second;
        second = res;
      //  std::cout<<"\nfirst : second :"<<first<<second;
        if(i>=z)
        {
            sum=(sum+res)%10;
      //      std::cout<<"\n++++++++++++++++++++++++++++++"<<sum;
        }
    }
    //std:: cout<<"\n\n___________________________________________________________________________________\n\n";
    long long a=0;
    long long b = 1;
    long long res_d = z;
    if(remainder < x)
    {
        for (long long i = 2; i <=60; i++)
            {
                res_d = (a + b) % m;
                //std::cout<<"\ni = "<<i<<"    res = "<<res_d;
                a = b;
                b = res_d;
                    if(i>=x-1)
                    {
                        sum_d=(sum_d+res_d)%10;
                       // std::cout<<"\n++++++++++++++++++++++++++++++"<<sum_d;
                    }
            }
    }
    if(remainder<x)
        return (sum+sum_d)%10;
    else
        return sum;
}

int main() {
    long long n1,n2, m;
    m=60;
    std::cin >> n1>>n2;
    std::cout <<"\n\n\n"<< get_fibonacci_huge_sum_last_dig(n1,n2,m) << '\n';
}
