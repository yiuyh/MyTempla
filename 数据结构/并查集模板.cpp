const int maxn = 500;

int uset[maxn];





void makeSet(int size) {

    for(int i = 0;i < size;i++)  uset[i] = i;

}
int find(int x) {
    if (x != uset[x]) uset[x] = find(uset[x]);
    return uset[x];
}
void unionSet(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;
    uset[y] = x;
}
