#include <string>
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
    void Error();
    string ToBin(string x);
};

void Transf::run()
{
    Bin = ToBin(Base);
    cout << Bin << endl;
}

/**
 * @brief 先转二进制，再转到别的
 */
string Transf::ToBin(string x)
{
    string ans;
    return ans;
}