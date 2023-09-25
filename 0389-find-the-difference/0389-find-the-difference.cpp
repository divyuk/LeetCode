#define ll long long
const ll mod = 1e9 + 7;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define bugpair(a) cout << #a << " = ( " << ((a).first) << " , " << ((a).second) << " )\n";

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#define rep(i, a, n) for (long long int i = (a); i < (n); ++i)
#define repI(i, a, n) for (int i = (a); i < (n); ++i)
#define repD(i, a, n) for (long long int i = (a); i >= (n); --i)
#define repDI(i, a, n) for (int i = (a); i >= (n); --i)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(auto i : s) c^=i;
        for(auto i : t) c^=i;
        return c;
    }
};