#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define MAX_N 1000

std::vector<int> minimumDivisors(int n)
{
    std::vector<int> primes(n + 1, std::numeric_limits<int>::max());

    for(int p = 2; p <= n; ++p)
    {
        if(primes[p] == std::numeric_limits<int>::max())
            primes[p] = p;

        int i = p * p;
        while(i <= n)
        {
            if(primes[i] > p)
                primes[i] = p;
            i += p;
        }
    }

    return primes;
}

std::vector<int> findNumberOfDivisors(const std::vector<int>& min_divisors)
{
    std::vector<int> divisors(min_divisors.size(), 1);

    for(int i = 2; i < min_divisors.size(); ++i)
    {
        int k = 0;
        int n = i;
        int p = min_divisors[n];

        while(n > 1)
        {
            n = n / p;
            ++k;

            if(min_divisors[n] != p)
            {
                divisors[i] *= (k + 1);
                k = 0;
            }

            p = min_divisors[n];
        }
    }

    return divisors;
}

class SegmentTree final
{
    public:
    explicit SegmentTree(const std::vector<int>& divisors, int n) : m_divisors(divisors), m_n(n)
    {
        build(1, 0, m_n);
    }

    int query(int l, int r)
    {
        return queryInternal(1, 0, m_n, l, r);
    }

    private:
    void build(int v, int l, int r)
    {
        if(l == r)
        {
            m_segment_tree[v] = m_divisors[l];
            return;
        }

        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        m_segment_tree[v] = std::max(m_segment_tree[v * 2], m_segment_tree[v * 2 + 1]);
    }

    int queryInternal(int v, int tl, int tr, int l, int r)
    {
        if(l > r) return 0;

        if(tl == l && tr == r)
        {
            return m_segment_tree[v];
        }

        int tm = (tl + tr) / 2;

        return std::max(queryInternal(v * 2, tl, tm, l, std::min(r, tm)), 
                    queryInternal(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    int m_segment_tree[4 * MAX_N];
    int m_n;
    std::vector<int> m_divisors;
};

int main(int argc, char const *argv[])
{
    auto min_divisors = minimumDivisors(10);
    auto divisors = findNumberOfDivisors(min_divisors);
    SegmentTree tree{divisors, 10};

    std::cout << "(0, 10)=" << tree.query(0, 10) << '\n';
    std::cout << "(0, 2)=" << tree.query(0, 2) << '\n';
    std::cout << "(5, 7)=" << tree.query(5, 7) << '\n';
    std::cout << "(5, 5)=" << tree.query(5, 5) << '\n';
    std::cout << "(1, 1)=" << tree.query(1, 1) << '\n';

    return 0;
}
