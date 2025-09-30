class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (numerator == 0) {
            result = "0";
            return result;
        }

        // Handle negative numbers and make both numerator and denominator positive
        bool isNegative = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
        long num = abs(static_cast<long>(numerator));
        long denom = abs(static_cast<long>(denominator));

        // Append negative sign if the result should be negative
        if (isNegative) {
            result += "-";
        }

        // Calculate integer part of the division and append it to the result
        long quotient = num / denom;
        result += to_string(quotient);
        num %= denom;

        // If there is no remainder, return the integer part
        if (num == 0) {
            return result;
        }

        // Append decimal point and start calculating the fractional part
        result += ".";

        // Use a hash map to detect repeating sequences in the fractional part
        unordered_map<long, int> seen;
        long divisor = 1; // Starting with tenths place
        while (num != 0) {
            // Check if the current remainder has been seen before
            auto it = seen.find(num);
            if (it != seen.end()) {
                // If seen before, insert parentheses around the repeating part
                result.insert(it->second, "(");
                result += ")";
                break;
            }

            // Store the index where this remainder was first seen
            seen[num] = result.size();
            num *= 10; // Move to the next decimal place
            long digit = num / denom;
            result += to_string(digit);
            num %= denom;
        }

        return result;
    }
};
