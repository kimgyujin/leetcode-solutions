#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;

const long long int MOD = 1e9 + 7;

vector <long long int> v;
vector <long long int> tree;
vector <long long int> l;
long long int init(int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = v[start];
	}
	else
	{
		int mid = (start + end) / 2;
		return tree[node] = ((init(node * 2, start, mid)%MOD) + (init(node * 2 + 1, mid + 1, end)%MOD)%MOD);
	}
}

void lazy(int node, int start, int end)
{
	if (l[node] != 0)
	{
		tree[node] += ((end - start + 1)*l[node])%MOD;
		if (start != end)
		{
			l[node * 2] += l[node];
			l[node * 2]%=MOD;
			l[node * 2 + 1] += l[node];
			l[node * 2 + 1]%=MOD;
		}
		l[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, long long int diff)
{
	lazy(node, start, end);
	if (left > end || right < start)
	{
		return;
	}

	if (left <= start && end <= right)
	{
		tree[node] += ((end - start + 1)*diff)%MOD;
		tree[node]%=MOD;
		if (start != end)
		{
			l[node * 2] += diff;
			l[node *2]%=MOD;
			l[node * 2 + 1] += diff;
			l[node*2 + 1]%=MOD;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = ((tree[node * 2]%MOD) + (tree[node * 2 + 1]%MOD)%MOD);
	tree[node]%=MOD;
}

long long int sum(int node, int start, int end, int left, int right)
{
	lazy(node, start, end);
	if (left > end || right < start)
	{
		return 0;
	}

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	return ((sum(node * 2, start, mid, left, right)%MOD) + (sum(node * 2 + 1, mid + 1, end, left, right)%MOD)%MOD);
}

vector <int> idx[26];
int memo[26];

class Solution {
public:
    int uniqueLetterString(string S) {
        if(S=="")
        {
            return 0;
        }
        int n,h, size;    
        n = S.length();
        h = (int)ceil(log2(2*n));
        size = (1 << (h + 1)) - 1;
        v.resize(n);
        tree.resize(size);
        l.resize(size);    
        long long int val = 0;
        map <char,int> cnt;
        for(int i=0;i<n;i++)
        {
            idx[S[i]-'A'].push_back(i);
            if(cnt.find(S[i])==cnt.end())
            {
                val += 1;
                cnt[S[i]] = 1;
            }
            else
            {
                if(cnt[S[i]]==1)
                {
                    val -= 1;
                }
                cnt[S[i]]++;
            }
            v[i] = val;
        }
        init(1,0,n-1);
        long long int res = 0;
        for(int i=0;i<n;i++)
        {
            int a = S[i]-'A';
            res += sum(1,0,n-1,i,n-1);
            res%=MOD;
            int IDX = idx[a][memo[a]];
            if(memo[a]==(int)(idx[a].size())-1)
            {
                update(1,0,n-1,IDX+1,n-1,-1);
            }
            else if(memo[a]==(int)(idx[a].size())-2)
            {
                int IDX2 = idx[a][memo[a]+1];
                update(1,0,n-1,IDX+1,IDX2-1,-1);
                update(1,0,n-1,IDX2,n-1,1);
            }
            else
            {
                int IDX2 = idx[a][memo[a]+1];
                int IDX3 = idx[a][memo[a]+2];
                update(1,0,n-1,IDX+1,IDX2-1,-1);
                update(1,0,n-1,IDX2,IDX3-1,1);          
            }
            memo[a]++;
        }
        return res;        
    }
};
