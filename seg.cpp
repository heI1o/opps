#include <iostream>
#include <memory.h>
using namespace std;

#define mx first
#define mn second
#define MX 0x7fffffff

int arr[100001];
pair<int, int> segtree[400004]; // mx, mn

pair<int, int> init(int node, int s, int e){ // arr의 start, end idx
    if(s == e){
        segtree[node].first = arr[s];
        segtree[node].second = arr[s];
        return segtree[node];
    }

    // int mid = 
    pair<int, int> l = init(node * 2, s, (s + e) / 2);
    pair<int, int> r = init(node * 2 + 1, (s + e) / 2 + 1, e);

    segtree[node].first = max(l.first, r.first);
    segtree[node].second = max(l.second, r.second);

    return segtree[node];
}

pair<int, int> query(int node, int ts, int te, int qs, int qe){
    if(qs <= ts && te <= qe) return segtree[node];

    if(te < qs || qe < ts) return make_pair(0, 0x7fffffff);

    pair<int, int> l, r;
    l = query(node * 2, ts, (ts + te) / 2, qs, qe);
    r = query(node * 2 + 1, (ts + te) / 2 + 1, te, qs, qe);
    return make_pair(max(l.first, r.first), min(l.second, r.second));
}

// // bottom-up, top-down 둘다 가능
// void update(int node, int s, int e, int ii, int value){
//     // if(s == e) segtree[node].first = value;
//     if(s == e){
//         segtree[node].first = value;
//         segtree[node].second = value;
//         return;
//     }else if(s <= ii && ii <= e){
//         if(segtree[node].first < value || segtree[node].first == -1) segtree[node].first = value;
//         if(segtree[node].second > value || segtree[node].second == -1) segtree[node].second = value;

//         update(node * 2, s, (s + e) / 2, ii, value);
//         update(node * 2 + 1, (s + e) / 2 + 1, e, ii, value);

//         return;
//     }else if(s > ii || e < ii) return;
// }
pair<int, int> update(pair<int, int>* tree, int node, int ts, int te, int ii, int value){
    // 범위를 완전히 벗어난 경우
    if(ii < ts || te < ii) return tree[node];
    
    if(ts == te){
        tree[node].mx = value;
        tree[node].mn = value;
        return tree[node];
    }

    int m = (ts + te) / 2;
    auto a = update(tree, node * 2, ts, m, ii, value);
    auto b = update(tree, node * 2 + 1, m + 1, te, ii, value);

    tree[node].mx = max(a.mx, b.mx);
    tree[node].mn = min(a.mn, b.mn);

    return tree[node];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int n, q;
    for(int tc = 0; tc < t; tc++){
        cin >> n >> q;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        memset(segtree, -1, sizeof segtree);
        init(1, 0, n - 1);
        
        int ins1, ins2, ins3;
        cout << "#" << tc + 1 << ' ';
        // char ins1;
        for(int i = 0; i < q; i++){
            cin >> ins1 >> ins2 >> ins3;
            if(ins1 == 0){
                update(segtree, 1, 1, n, ins2 + 1, ins3);
                // update(1, 1, n, ins2 + 1, ins3);
            }else{
                pair<int, int> tmp = query(1, 1, n, ins2 + 1, ins3);
                cout << tmp.first - tmp.second << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
