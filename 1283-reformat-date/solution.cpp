class Solution {
public:
    string reformatDate(string date) {
       vector <string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
       map <string,string> mn;
       for(int i=0;i<months.size();i++)
       {
            int tmp = i + 1;
            string M = "";
            while(tmp > 0)
            {
                M = (char)(tmp%10 + '0') + M;
                tmp/=10;
            }
            if(M.length()==1) M = '0' + M;
            mn[months[i]] = M;
       } 

       string D,Y,M;
       stringstream ss;
       ss << date;
       ss >> D >> M >> Y;
       string d = "";
       for(auto it : D)
       {
        if('0'<=it && it<='9') d += it;
       }
       if(d.length()==1) d = '0' + d;
       string res = Y + "-" + mn[M] + "-" + d;
       return res;
    }
};
