class Solution {
public:
    string concatHex36(int n) {
        string a = "";
        string b = "";
        int val = n*n;
        while(val > 0)
        {
            int x = val%16;
            val/=16;
            if(x<10)
            {
                a = (char)(x+'0') + a;
            }
            else
            {
                a = char((x-10)+'A') + a;
            }
        }
        val = n*n*n;
        while(val > 0)
        {
            int x = val%36;
            val/=36;
            if(x<10)
            {
                b = (char)(x+'0') + b;
            }
            else
            {
                b = char((x-10)+'A') + b;
            }
        }        

        return a+b;
    }
};
