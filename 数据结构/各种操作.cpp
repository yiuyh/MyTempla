#include<vector>
vector<int> v;
vector<int> v1(v); //用另一个vector来初始化
vector<int> v2(n, i); //大小为n，并全部初始化为元素i
v.push_back(int); // 尾部插入数字
v.empty(); //判断是否为空，为空返回true,否则返回false;
v.resize(n+m); //调整vec的大小变为n+m
v.insert(v.begin(),8);//在最前面插入新元素。
v.insert(v.begin()+2,1);//在2位置插入一个1
v.insert(v.end(),3);//在向量末尾追加新元素
v.insert(v.end(),4,1);//在尾部插入4个1
vec.erase(v.begin()+2);//删除第3个元素
v.erase(v.begin()+i,v.end()+j);//删除区间[i,j-1];
v.clear();　　　//清空之后，v.size()为０
v.reverse(vec.begin(),vec.end()); //使用reverse将元素翻转：需要头文件#include<algorithm>

#include<string>
string &substr(int pos = 0,int n = npos) const;//返回pos开始的n个字符组成的字符串
string &assign(const string &s,int start = 0,int n = len);//把字符串s中从start开始的n个字符赋给当前字符串
string &assign(const char *s,int n = len);//用c字符串s开始的n个字符赋值
string &append(const char *s,int n = len);//把c类型字符串s的前n个字符连接到当前字符串结尾
string &append(const string &s,int pos = 0,int n = len);//把字符串s中从pos开始的n个字符连接到当前字符串的结尾
int compare(const char *s) const;
int compare(int pos, int n,const char *s) const;
int compare(int pos, int n,const string &s,int pos2,int n2)const;//比较当前字符串从pos开始的n个字符组成的字符串与s中pos2开始的n2个字符组成的字符串的大小
void swap(string &s2);    //交换当前字符串与s2的值
int find(const char *s, int pos = 0, int n = len) const;//从pos开始查找字符串s中前n个字符在当前串中的位置
int find(const string &s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//查找成功时返回所在位置，失败返回string::npos的值
int rfind(const char *s, int pos = 0, int n = len) const;
int rfind(const string &s,int pos = len) const;
//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置，成功返回所在位置，失败时返回string::npos的值
int find_first_of(const char *s, int pos = 0, int n = len) const;
int find_first_of(const string &s,int pos = 0) const;
//从pos开始查找当前串中第一个在s的前n个字符组成的数组里的字符的位置。查找失败返回string::npos
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//从当前串中查找第一个不在串s中的字符出现的位置，失败返回string::npos
string &replace(int p0, int n0,const char *s, int n = len);//删除p0开始的n0个字符，然后在p0处插入字符串s的前n个字符
string &replace(int p0, int n0,const string &s, int pos, int n);//删除p0开始的n0个字符，然后在p0处插入串s中从pos开始的n个字符
string &replace(int p0, int n0,int n, char c);//删除p0开始的n0个字符，然后在p0处插入n个字符c
string &insert(int p0,const string &s, int pos, int n);//前4个函数在p0位置插入字符串s中pos开始的前n个字符
string &insert(int p0, int n, char c);//此函数在p0处插入n个字符c
string &erase(int pos = 0, int n = len);//删除pos开始的n个字符，返回修改后的字符串

#include<bitset>
bitset<MAXN> b; //  bt 包括 MAXN 位，下标 0 ~ MAXN - 1，默认初始化为 0
bitset<MAXN> b(0xf); //  0xf 表示十六进制数 f，对应二进制 1111，将 bt1 低 4 位初始化为 1
bitset<MAXN> b(012);//  012 表示八进制数 12，对应二进制 1010，即将 bt2 低 4 位初始化为 1010
bitset<MAXN> b("1010");//  将 bt3 低 4 位初始化为 1010
bitset<MAXN> b(sring, pos, len);  //将string类从pos开始的len个字符赋给b
b(s, pos, n);//  将 01 字符串 s 的 pos 位开始的 n 位初始化 bt4
bt.any();//  bt 中是否存在置为 1 的二进制位？
bt.none();//  bt 中不存在置为 1 的二进制位吗？
bt.count(); //  bt 中置为 1 的二进制位的个数
bt.size(); //  bt 中二进制位的个数
bt[pos];//  访问 bt 中在 pos 处的二进制位
bt.test(pos);//  bt 中在 pos 处的二进制位是否为 1
bt.set();//  把 bt 中所有二进制位都置为 1
bt.set(pos, val = 1); //  把 bt 中在 pos 处的二进制位置为 1
bt.reset(); //  把 bt 中所有二进制位都置为 0
bt.reset(pos);//  把 bt 中在pos处的二进制位置为0
bt.flip();//  把 bt 中所有二进制位逐位取反
bt.flip(pos);//  把 bt 中在 pos 处的二进制位取反
bt[pos].flip();//  同上
bt.to_ulong();//  用 bt 中同样的二进制位返回一个 unsigned long 值
bt.to_string();// 转化为string类
os << bt;//  把 bt 中的位集输出到 os 流

#include<queue> //priority_queue
q.size();//返回q里元素个数
q.empty();//返回q是否为空，空则返回1，否则返回0
q.push(k);//在q的末尾插入k
q.pop();//删掉q的第一个元素
q.top();//返回q的第一个元素
q.back();//返回q的末尾元素
priority_queue <int,vector<int>,greater<int> > q; //注意后面两个“>”不要写在一起，“>>”是右移运算符
priority_queue <int,vector<int>,less<int> >q; //less是从大到小，greater是从小到大

#include<pair>
pair<int, pair<pair> > p;
pair<int, double> p(1, 2.4);  /*用给定值初始化*/
pair<int, double> p(p2);  /*拷贝构造函数*/
pair <string ,double> p = make_pair("aa",5.0); //利用make_pair
p.first  p.second //访问
