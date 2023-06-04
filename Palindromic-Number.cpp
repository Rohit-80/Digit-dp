#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
 
using   ll =  long long  ; 
 
// template<class T> using ordered_set =tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> ;
 
 
 
#define All(x)       sort(x.begin(), x.end());
#define all(x)       reverse(x.begin(),x.end());
#define A_ll(x)      x.begin(),x.end()
#define endl         "\n";
#define nl           cout<<"\n";
#define work         cout<<"work"<<endl;
#define show(x)      { for(auto a  : x) cout<<a<<" "; cout<<endl;}
#define rep(a,b,c)   for(int a = b ; a < c; a++)
#define sz(x)        to_string(x).length()
 
typedef vector<ll> vll ;
typedef vector<ll> vi ;
/*---------------------[DEBUG TEMPLATE]-------------------------------------------------------------------------------------------------------*/
 
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
istream & operator >> (istream &is, T_container &v) {
    for (T &x : v) is >> x; return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value) {
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0)
        os << '-';
    else if (T == 0)
        return os << '0';
    for (; T > 0; ++index) {
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }
    while (index > 0)
        os << buffer[--index];
    return os;
}
 
istream& operator >> (istream& is, __int128& T) {
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for (; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;
    return is;
}
#endif
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << "," << p.second << ')' ;
}
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator << (ostream &os, const T_container &v) {
    os << '{'; string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}
template<class P, class Q = vector<P>, class R = less<P> > ostream & operator << (ostream& out, priority_queue<P, Q, R> const& M) {
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while (!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M) {
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while (!U.empty()) {
        out << sep << U.front(); sep = ", "; U.pop();
    }
    return (out << "}");
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    int count_open = 0, len = 1;
    for (int k = 1; ; ++k) {
        char cur = *(names + k);
        count_open += (cur == '(' ? 1 : (cur == ')' ? -1 : 0));
        if (cur == ',' && count_open == 0) {
            const char* comma = names + k;
            cout.write(names, len) << " : "  << arg1 << " | ";
            __f(comma + 1, args...);
            return;
        }
        len = (cur == ' ' ? len : k + 1);
    }
}
#else
#define trace(...) 1
#endif
 
/*----------------------------------------[SOLUTION]---------------------------------------------*/

//  DP problems
// form 1
// int n,q;
// vector<int> v;
// int dp[101][100007];

// int rec(int level, int left){
//      if(level == n){
//          if(left == 0) return 1;
//          else return 0;
//      }

//       if(dp[level][left] != -1 ) return dp[level][left];
//      // don't take
//      int ans = 0;
//      if(rec(level+1,left) == 1){
//         ans = 1;
//      }else if (rec(level+1,left-v[level]) == 1)
//        ans = 1;

//        return dp[level][left] = ans;
     
// }

// void printsub(int level, int left){
     
     
//        if(level == n){
//          return;
//      }


//       if(rec(level+1,left) == 1){
//           printsub(level+1,left);
//      }else if (rec(level+1,left-v[level]) == 1){
//           cout<<v[level]<<" ";
//           printsub(level+1,left-v[level]);
//      }
        

// }

// void test(){
//     cin>>n>>q;
//     v.assign(n,0);
//     for(int i =0 ; i< n; i++){
//           cin>>v[i];
//     }
//     memset(dp,-1,sizeof(dp));

//     while(q--){
//          int t; cin>>t;
//           if(rec(0,t)){
//              printsub(0,t);
//              cout<<endl;
//           }
//     }

// }
 
 
// Form 2 -- best at starting/ending index

// int n; 
// vector<int> v(100);
// int dp[100];

// int rec(int level){
//      //pruning
//       if(level > n) return 0;
//      // basecase
   
//       //cache
//     if(dp[level] != -1) return dp[level];

//      //code
//      int ans = 1;
//     for(int  i= 0; i < level; i++){
//            if(v[i] < v[level])
//              ans = max(ans,1+rec(i));
//     }

//     return dp[level] = ans;
// }




// void test(){
      
//        cin>>n;
//        for(int i =0 ; i < n; i++) cin>>v[i];



//        int best = 1;
//         memset(dp,-1,sizeof(dp));


//        for(int i =0 ; i < n; i++){
//            best = max(best,rec(i));
//        }
//          // for(int i =0 ; i < n; i++) cout<<dp[i]<<" ";
//        cout<<best<<endl;


// }

// Form 3 Longest common subsequences

 // int dp[1007][1007];
 //     string s1,s2;
 //      int n,m;
 //    int rec(int i , int j){
 //         // basecase
 //         if(i > n - 1 || j > m - 1) return 0;
         
 //         // cache
 //         if(dp[i][j] != -1) return dp[i][j];
         
         
 //         int ans = rec(i,j+1);
 //             ans = max(ans,rec(i+1,j));
             
 //             if(s1[i] == s2[j]){
 //                  ans = max(ans, 1+rec(i+1,j+1));
 //             }
             
 //             return dp[i][j] = ans;
 //    }
    
 //    //Function to find the length of longest common subsequence in two strings.
 //    int lcs(int x, int y, string s1, string s2)
 //    {
 //        memset(dp,-1,sizeof(dp))     ;
 //         n = x,m = y;
 //         this->s1 = s1;
 //         this->s2 = s2;
         
 //         return rec(0,0);
 //    } 
        
// Form 4 LR DP or interval dp

// int dp[1007][1007];
// int x[100];
// int rec(int l , int r){
//      // basecase
//        if(l+1 == r) return 0;

//      // cache
//       if(dp[l][r]  != -1) return dp[l][r];




//     // code
//      int ans = 1e9;
//     for(int p = l+1; p < r; p++){
//         ans = min(ans,x[r]-x[l] + rec(l,p) + rec(p,r));
        
//     }

//     return dp[l][r] = ans;
// }


// void test(){
//      int n; cin>>n;

//        for(int i =0 ; i < n; i++){
//             cin>>x[i];
//        }

//      memset(dp,-1,sizeof(dp));
//      cout<<rec(0,n)<<endl; 
// }

// Form 5 Game Dp
//{ Driver Code Starts
// Initial Template for C++
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++
//  vector<int> ans;
//  vector<vector<bool>> vis;
//  int n,m;
// void rec(int i,int j , vector<vector<int>>&a ){
//     bool check = false;
//      if(i >= 0 && j >= 0 && i < n && j < m) check = true;
//      // trace(i,j);
//      // return;
     
//      if(!check) return ;
     
//      if(!vis[i][j]) ans.push_back(a[i][j]);
//       vis[i][j] = true;
     
//      // right side 
//      if(i >= 0 && j+1 >= 0 && i < n && j+1 < m && !vis[i][j+1])
//      rec(i,j+1,a);
//      //down
//      if(i+1 >= 0 && j >= 0 && i+1 < n && j < m && !vis[i+1][j])
//      rec(i+1,j,a);
//      //left 
//      if(i >= 0 && j-1 >= 0 && i < n && j-1 < m && !vis[i][j-1])
//      rec(i,j-1,a);
//      // up
//      if(i-1 >= 0 && j >= 0 && i-1 < n && j < m && !vis[i-1][j])
//      rec(i-1,j,a);
     
//      return ;

     
// }
// class Solution {
//   public:
//     vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
//          n = R;
//          m = C;
//          vis = vector<vector<bool>> (n+1,vector<bool>(m+1,0));
//          rec(0,0,a);
//          // all(ans);
//          return ans;
//     }
// };

//{ Driver Code Starts.
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int R, C;
//         cin>>R>>C;
//         vector<vector<int>> a(R, vector<int>(C, 0));
//         for(int i = 0;i < R*C;i++)
//             cin>>a[i/C][i%C];
//         Solution ob;
//         vector<int>ans=ob.reverseSpiral(R,C,a);
//         for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
//             cout<<endl;
//     }
//     return 0;
// }


  // vector<ll> prime;
  // void PreAllPrime(){
  //    vector<bool> visted(1e6+200,false);

  //      for(ll i = 2 ; i < visted.size() ; i++){
  //          if(!visted[i]){
  //               prime.emplace_back(i);
  //             // prime[i]++;          
  //       for(ll j = i*i ; j < visted.size() ; j += i){
  //             visted[j] = true;
  //         }  
  //     }
  //      }  
  //  }
string s;
// ll m,d;
// ll mod = 1e9 + 7;

ll dp[20][20][2][2][2];

ll rec(ll pos,ll t1,ll st,ll backpos,bool boro){
    // trace(pos,t1,backpos);N
    if(pos > backpos) {if(t1 && boro) return 0; return 1; }
     if(dp[pos][backpos][t1][st][boro] != -1) return dp[pos][backpos][t1][st][boro];

    ll res = 0;
    ll en = t1 ? s[pos] - '0' : 9;

    for(ll i = 0 ; i <= en; i++){
         if(st == 0 && i == 0){
            res += rec(pos+1,t1&(i==en),st|(i>0),backpos,boro) ;  }
         // else if(pos == backpos){
         //    res += rec(pos+1,t1&(i==en),st|(i>0),backpos,boro) ;  
         // }
         else{
              
            if(i == (s[backpos]-'0') ){
                // trace(pos,backpos,i,boro&(i<=s[backpos]-'0'));
                // bool ok = boro&(i<=s[backpos]-'0');
                // if(!t1)
                res += rec(pos+1,t1&(i==en),st|(i>0),backpos-1,boro);  
            }else {
                 res += rec(pos+1,t1&(i==en),st|(i>0),backpos-1,(i > (s[backpos]-'0')));  
            }
      }
        
         
    }
    return dp[pos][backpos][t1][st][boro] = res;
}

void test(){
   
     ll l,r;

     // cin>>m>>d;
     cin>>l>>r;
     
      if(l > r) swap(l,r);

      
       s = to_string(r);

       memset(dp,-1,sizeof(dp)); 
     
       ll ans = rec(0,1,0,s.size()-1,0);
       // trace(ans);
       // trace(ans);
       // return;
        s.clear();
         s = to_string(l-1);
       memset(dp,-1,sizeof(dp)); 
         ll sec = rec(0,1,0,s.size()-1,0);
         // trace(sec);
         ans -= sec;


      cout<<ans<<endl; 
      // trace(lenx,ans);
      // cout<<lenx<<" "<<ans<<endl;



}








int main() {
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto start = std::chrono::high_resolution_clock::now();
    
 

    ll t = 1;
    
    cin>>t;
    int T = 1;
     
        while(t--){ 
            cout<<"Case "<<T++<<": ";
             test();
         }
           
 
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "T_taken : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;
    return 0;
}
