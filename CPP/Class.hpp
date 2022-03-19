namespace Boxx
{
    const double PI = 3.14159;
    class Box
    {
    public:
        double a, ans;
        void calc();
        void print();
    };

    void Box::calc()
    {
        ans = a * a * PI;
    }
    void Box::print()
    {
        std::cout << a << ": " << ans << "\n";
    }
    bool cmp_ans(Box x, Box y)
    {
        return x.ans < y.ans;
    }
}

using namespace Boxx;