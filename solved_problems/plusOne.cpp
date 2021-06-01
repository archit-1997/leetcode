class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n=digits.size();

        if(digits[n-1]<9){
            digits[n-1]++;
            return digits;
        }

        //go ahead until I don't encounter a number less than n
        int index=n-1;
        while(index>=0 && digits[index]==9){
            digits[index]=0;
            index--;
        }

        if(index>=0){
            digits[index]++;
            return digits;
        }

        reverse(digits.begin(),digits.end());
        digits.push_back(1);
        reverse(digits.begin(),digits.end());

        return digits;

    }
};