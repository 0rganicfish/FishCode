#include <string>
#include <algorithm>
using namespace std;

class Transf
{
public:
    /** @brief 被转数 */
    string Base;

    /** @brief 输入的进制数 */
    string Cur;

    /** @brief 主 run 函数 */
    void run();

private:
    string Bin, Oct, Dec, Hex;
    string ToBin(string x);
    string Dec_Bin(int x);
    string Bu(string x, int l);
    void Error();
};

/**
 * @brief 错误处理
 */
void Transf::Error()
{
    cout << "\nError input!\n";
}

void Transf::run()
{
    Bin = ToBin(Base);
    cout << Bin << endl;
}

/**
 * @brief 进制补位
 * @param x   被补数
 * @param l   长度
 */
string Transf::Bu(string x, int l)
{
    for (int i = 0; i < x.size() % l; ++i)
        x = '0' + x;
    return x;
}

/**
 * @brief 十进制转二进制
 */
string Transf::Dec_Bin(int x)
{
    string ans;
    while (x)
        ans = char(x % 2 + '0') + ans, x >>= 1;
    return Bu(ans, 4);
}

/**
 * @brief 先转二进制，再转到别的
 */
string Transf::ToBin(string x)
{
    if (Cur == "Hex")
    {
        string ans;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        for (int i = x.size() - 1; i >= 0; --i)
        {
            int t = isdigit(x[i]) ? x[i] - '0' : x[i] - 'a' + 10;
            ans = Dec_Bin(t) + ans;
            return ans;
        }
    }
    else if (Cur == "Dec")
        return Dec_Bin(stoi(x));
    else if (Cur == "Bin")
        return Bu(x, 4);
    else if (Cur == "Otc")
    {
    }
    else
        Transf::Error();
    return "";
}