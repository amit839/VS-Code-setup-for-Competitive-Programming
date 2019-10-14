#include<bits/stdc++.h>
using namespace std;


int n,k;
int arr[2018],siz[2018];
int tree[2018][2];
vector<int> pre,post;

int root(int i){
    while(arr[i]!=i){
		arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}
bool find(int x, int y){
    return root(x)==root(y);
}

void join(int x, int y){
    int roota=root(x),rootb=root(y);
    if(roota==rootb) return;
    if(siz[roota]<siz[rootb]){
        arr[roota]=arr[rootb];
        siz[rootb]+=siz[roota];
    }
    else {
        arr[rootb]=arr[roota];
        siz[roota]+=siz[rootb];
    }
}



void solve(int t) {


    rep(i,1,n+1) arr[i]=i,siz[i]=1;
    rep(i,0,n){
        join(pre[i],post[i]);
    }
}

int power(int a, int b){
    int ans = 1;
    
    while(b > 0){
        if(b & 1){
            ans = (1LL * ans * a) % mod;
        }
        b >>= 1;
        a = (1LL * a * a) % mod;
    }
    return ans;
}

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

bool kmp(string text, string pattern) {
	int n = text.size(), m = pattern.size();

	vector<int> lps(m, 0);
	int i = 0, j = 1;
	while (j < m) {
		if (pattern[i] == pattern[j]) {
			lps[j] = i + 1;
			i++, j++;
		}
		else {
			if (i == 0) j++;
			else i = lps[i - 1];
		}
	}
	
	i = 0, j = 0;

	while (i < n and j < m) {
		if (text[i] == pattern[j]) i++, j++;
		else if(j > 0 ) j = lps[j - 1];
		else i++;
	}
	
	return j == m;// to check if present or not
	// to return the position return i - m;
}

struct TrieNode {
	map<char, TrieNode*> children;
	map<char, int> freq;
	bool isTerminal;
};

TrieNode *head;

void insert(string str) {
	
	TrieNode *current = head;
	for (auto x : str) {
		if (current->children.count(x) == 0) {
			current->children[x] = new TrieNode();
		}
		current->freq[x]++;
		current = current->children[x];
	}
	current->isTerminal = true;
}

string query(string str) {
	TrieNode *temp = head;
	string output;

	for (auto x : str) {
		output += x;
		if (temp->freq[x] < 2) return output;
		temp = temp->children[x];
	}
	return output;
}

//dijkstra's algorithm using priority_queue

#include <bits/stdc++.h>
using namespace std;
 
const int INF = 2147483647;
const int MAX = 5005;
int D[MAX], N; // Keeps minimum distance to each node
vector<pair<int,int>> E[MAX]; // Adjacency list
 
void dijkstra()
{
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
 
    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();
 
        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;
 
        for(pair<int,int> pr : E[u])
        {
            int v = pr.first;
            int next_dist = dist + pr.second;
 
            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
}



#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
const int MAX = 5005;
int D[MAX], N; // Keeps minimum distance to each node
vector<pair<int,int>> E[MAX]; // Adjacency list

void dijkstra()
{
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});

    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr : E[u])
        {
            int v = pr.first;
            int next_dist = dist + pr.second;

            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
}
