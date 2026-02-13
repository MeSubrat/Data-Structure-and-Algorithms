class Solution
{
public:
    int optimal(int n, string &s)
    {
        int maxi = 1;
        // 3 - character balance
        struct pair_hash
        {
            size_t operator()(const pair<int, int> &p) const
            {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };

        int a = 0, b = 0;
        unordered_map<pair<int, int>, int, pair_hash> mp;
        mp[{0, 0}] = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                a++;
            }
            else if (s[i] == 'b')
            {
                b++;
            }
            else if (s[i] == 'c')
            {
                a--;
                b--;
            }

            if (mp.count({a, b}))
            {
                maxi = max(maxi, i - mp[{a, b}]);
            }
            else
            {
                mp[{a, b}] = i;
            }
        }

        // 2 - character balance
        vector<pair<char, char>> pairs = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};

        for (auto &[c1, c2] : pairs)
        {

            int cnt = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == c1)
                {
                    cnt++;
                }
                else if (s[i] == c2)
                {
                    cnt--;
                }
                else
                {
                    cnt = 0;
                    mp.clear();
                    mp[0] = i;
                    continue;
                }

                if (mp.count(cnt))
                {
                    maxi = max(maxi, i - mp[cnt]);
                }
                else
                {
                    mp[cnt] = i;
                }
            }
        }

        // 1 - character balance
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == s[i])
            {
                len++;
            }
            else
            {
                len = 1;
            }

            maxi = max(maxi, len);
        }

        return maxi;
    }
    int longestBalanced(string s)
    {
        int n = s.length();
        return optimal(n, s);
    }
};