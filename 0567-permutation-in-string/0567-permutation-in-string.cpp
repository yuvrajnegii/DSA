class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);

        // Build frequency arrays
        for (int i = 0; i < n; i++) {
            s1hash[s1[i] - 'a']++;
            s2hash[s2[i] - 'a']++;
        }

        // Check first window
        if (s1hash == s2hash)
            return true;

        // Slide the window
        for (int right = n; right < m; right++) {
            s2hash[s2[right] - 'a']++;             // Add new character
            s2hash[s2[right - n] - 'a']--;         // Remove left character
            if (s1hash == s2hash)
                return true;
        }

        return false;
    }
};