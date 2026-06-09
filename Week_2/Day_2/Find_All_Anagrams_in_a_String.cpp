class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        vector<int> ans;

        for (char c : p)
            freqP[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {

            freqS[s[i] - 'a']++;

            if (i >= k)
                freqS[s[i - k] - 'a']--;

            if (freqS == freqP)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};