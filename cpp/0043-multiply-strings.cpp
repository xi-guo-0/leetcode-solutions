class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0');
        for (int i = n1 - 1; 0 <= i; i--) {
            for (int j = n2 - 1; 0 <= j; j--) {
                int tmp = res[i + j + 1] - '0' + (num1[i] - '0')*(num2[j] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                res[i + j] += tmp / 10;
            }
        }
        for (int i = 0; i < res.size(); i++)
            if (res[i] != '0')
                return res.substr(i);
        return "0";
    }
};
