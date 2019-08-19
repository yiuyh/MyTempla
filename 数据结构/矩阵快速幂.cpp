struct node{
    long long m[5][5];
};
const long long sMod = 1000000007;
node m, a;

void init(){
    a.m[0][0] = 1, a.m[0][1] = 5, a.m[0][2] = 1, a.m[0][3] = -1;
    a.m[1][0] = 1, a.m[1][1] = 0, a.m[1][2] = 0, a.m[1][3] = 0;
    a.m[2][0] = 0, a.m[2][1] = 1, a.m[2][2] = 0, a.m[2][3] = 0;
    a.m[3][0] = 0, a.m[3][1] = 0, a.m[3][2] = 1, a.m[3][3] = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) {
            if(i == j) m.m[i][j] = 1;
            else m.m[i][j] = 0;
        }
}

node mul(node a, node b){
    node c;
    memset(c.m, 0, sizeof(node));
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0 ; k < 4; k++){
                c.m[i][j] += (a.m[i][k]*b.m[k][j] % sMod + sMod) % sMod;
    }
    return c;
}

void pos(int x){
    while (x) {
        if(x&1) m = mul(m, a);
        x >>= 1;
        a = mul(a, a);
    }
}
