class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }

        std::unordered_set<int> uniqueEvenNumbers;

        // 1. Hundreds digit: 1 through 9 (cannot start with 0)
        for (int h = 1; h <= 9; ++h) {
            if (count[h] == 0) continue;
            count[h]--; // Use digit for Hundreds

            // 2. Tens digit: 0 through 9
            for (int t = 0; t <= 9; ++t) {
                if (count[t] == 0) continue;
                count[t]--; // Use digit for Tens

                // 3. Units digit: even digits only (0, 2, 4, 6, 8)
                for (int u = 0; u <= 8; u += 2) {
                    if (count[u] > 0) {
                        uniqueEvenNumbers.insert(h * 100 + t * 10 + u);
                    }
                }

                count[t]++; // Backtrack Tens digit
            }

            count[h]++; // Backtrack Hundreds digit
        }

        return uniqueEvenNumbers.size();
    }
};