class Solution {
public:
    int arr[10];
    int temp;

    void func(int val)
    {
        while(val>0)
        {
            arr[val%10]+=temp;
            val/=10;
        }
    }

    int countDigitOne(int n) {
        memset(arr,0,sizeof(arr));

        int a = 1;
        int b = n;
        temp = 1;
        
        while(a<=b)
        {
            while(1)
            {
                if(a%10==0 || a>b)
                {
                    break;
                }
                func(a);
                a++;
            }

            if(a>b)
            {
                break;
            }

            while(1)
            {
                if(b%10==9 || a>b)
                {
                    break;
                }
                func(b);
                b--;
            }

            for(int i=0;i<10;i++)
            {
                arr[i] += ((b/10) - (a/10) + 1)*temp;
            }

            a/=10;
            b/=10;
            temp*=10;
        }

        return arr[1];
        }
};
