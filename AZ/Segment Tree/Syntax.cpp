#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
using vi = vector <int>;
using ii = pair <int,int>;
int MOD = 1e9+7;
vi arr,seg;
void build(int ind,int l,int r){
    if(l==r) {seg[ind]=arr[l];return;}
    int mid=(l+r)/2;
    build(2*ind, l,mid);
    build(2*ind +1,mid+1,r);
    seg[ind]=seg[2*ind]+seg[2*ind +1];
    return;
}

void update(int ind,int l,int r,int pos,int val){
    if(l>pos||r<pos) return;
    if(l==r){
        seg[ind]=val;
        arr[l]=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*ind,l,mid,pos,val);update(2*ind+1,mid+1,r,pos,val); 
    seg[ind]=seg[2*ind]+seg[2*ind +1];
    return;
}

int query(int ind,int l,int r,int lq,int rq){
    if(r<lq||l>rq) return 0;
    if(l>=lq && r<=rq) return seg[ind];
    int mid=(l+r)/2;
    return query(2*ind,l,mid,lq,rq)+ query(2*ind+1,mid+1,r,lq,rq);
}

void solve() {
  int n,q;
  cin>>n>>q;
  arr.resize(n);
  seg.resize(4*n);
  for(int i=0;i<n;i++) cin>>arr[i];
  build(1,0,n-1);
  while(q--){
    int type;
    cin>>type;
    if(type==1){
        int x,v;
        cin>>x>>v;
        update(1,0,n-1,x-1,v);

    }
    else{
        int l,r;
        cin>>l>>r;
        cout<<query(1,0,n-1,l-1,r-1)<<endl;
    }
  }
  return;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // int t;cin>>t;while(t--)
    solve();
  return 0;
}