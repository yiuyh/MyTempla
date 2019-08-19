//第一个大于等于
int l = 0, r = n;//[l,r)
while (l < r) {
  int mid = (l+r)/2;
  if(a[mid] >= n ) r = mid;
  else l = mid + 1;
}

//第一个大于
int l = 0, r = n;//[l,r)
while (l < r) {
  int mid = (l+r)/2;
  if(a[mid] > n ) r = mid;
  else l = mid + 1;
}

//最后一个小于等于
int l = -1, r = 9;
  while (l < r) {
    int mid = (l+r+1)/2;
    if(a[mid] > n) r = mid-1;
    else l = mid;
}

//最后一个小于
int l = -1, r = 9;
  while (l < r) {
    int mid = (l+r+1)/2;
    if(a[mid] >= n) r = mid-1;
    else l = mid;
}
