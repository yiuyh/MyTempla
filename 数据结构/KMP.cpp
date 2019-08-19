int next[maxn];
int str1[maxn], str2[maxn];
void get_next(char *str, int len){//next数组保存了以i结尾的字符串的最长公共前缀和后缀的起始坐标
    int i, j;
    next[0] = j = -1;
    i = 0;
    while(i < len){
        while(j!=-1 && str[j] != str[i]) j = next[j];
        next[++i] = ++j;
    }
}

int kmp(int len1, int len2){
     int i = 0, j = 0;
     while (i < len1 && j < len2){
          while (j != -1 && str1[i] != str2[j]) {
              j = next[j];
          }
          i++, j++;
     }
     if(j == len2) return i-j;
     return -1;
} //返回是否匹配成功

int kmp(int len1, int len2){
     int i = 0, j = 0;
     int ans = 0;
     while (i < len1) {
         while (j != -1 && str1[i] != str2[j]) j = next[j];
         if(j == len2-1){
              ans++;
              j = next[j];
          }
          i++m j++;
      }
      return ans;
} //返回匹配个数
