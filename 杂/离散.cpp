for(int i = 0; i < n; i++){
  cin >> a[i];
  b[i] = a[i];
}
sort(b, b+n);
int m = unique(b, b+n)-b;
for(int i = 0; i < n; i++){
  a[i] = lower_bound(b,b+m,a[i])-b+1;
}

map<int, int> m;
int cnt = 1;
for(int i = 0; i < n; i++){
  cin >> a[i];
}
sort(a, a+n);
for(int i = 0; i < n; i++) if(!map[a[i]]) map[a[i]] = cnt++;
