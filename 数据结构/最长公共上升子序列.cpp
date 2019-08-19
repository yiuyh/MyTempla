void dp(){
	for(int i = 1; i <= n; i++){
		int MAX = 0; //维护最大值
		for(int j = 1; j <= m; j++){
			f[i][j] = f[i-1][j]; //a[i] != b[j]
			if(a[i] > b[j]) MAX = max(MAX, f[i-1][j]);
			if(a[i] == b[j]) f[i][j] = MAX+1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) ans = max(ans, f[n][i]);
	printf("%d\n", ans);
}//n方

void dp(){
	init();
	for(int i = 1; i <= n; i++){
		int MAX = 0;
		for(int j = 1; j <= n; j++){
			if(a[i] > b[j]) MAX = max(MAX, f[j]);
			if(a[i] == b[j]) f[j] = MAX+1;
		}
	}
	int ans = 0;
	for(int j = 1; j <= m; j++) ans = max(ans, f[j]);
	printf("%d\n", ans);
}//n方+空间优化
