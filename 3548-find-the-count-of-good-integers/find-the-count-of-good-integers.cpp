class Solution {
public:
    typedef long long ll;

    long long countGoodIntegers(int n, int k) {
        // digit signifies half the length of the palindrome
        int digit = (n + 1) / 2;

        // Precompute factorials up to 10 for permutations
        vector<ll> fact(11, 1);
        for (int i = 1; i <= 10; i++) {
            fact[i] = fact[i - 1] * i;
        }

        // Start and end range for the left half of the palindrome
        int begin = pow(10, digit - 1);
        int end = pow(10, digit);

        unordered_set<string> st; // to store unique sorted digits of good integers
        ll ans = 0;

        // Generate all possible palindromic numbers of length n
        for (int i = begin; i < end; i++) {
            string leftpart = to_string(i);
            string full = "";

            if (n & 1) {
                // If n is odd, exclude the last digit of leftpart when mirroring
                string rightpart = leftpart;
                rightpart.pop_back();
                reverse(rightpart.begin(), rightpart.end());
                full = leftpart + rightpart;
            } else {
                // If n is even, just mirror the leftpart
                string rightpart = leftpart;
                reverse(rightpart.begin(), rightpart.end());
                full = leftpart + rightpart;
            }

            // Convert the generated palindrome to number
            ll num = stoll(full);

            // Check divisibility by k
            if (num % k == 0) {
                // Sort digits to track uniqueness of digit combinations
                sort(full.begin(), full.end());
                st.insert(full); // store unique digit multisets
            }
        }

        // For each unique valid digit combination
        for (auto s : st) {
            unordered_map<ll, ll> mp;
            for (auto i : s) {
                mp[i - '0']++; // Count frequency of each digit
            }

            ll zeros = mp[0];         // Count of zeros
            ll otherdigit = n - zeros; // Non-zero digits

            // Total permutations considering leading zero restriction
            ll perm = otherdigit * fact[n - 1]; // Choose a non-zero digit at the start

            // Divide by factorial of frequencies to handle repeated digits
            for (auto j : mp) {
                perm /= fact[j.second];
            }

            ans += perm;
        }

        return ans;
    }
};