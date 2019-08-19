    sscanf与scanf类似，都是用于输入的，只是后者以屏幕(stdin)为输入源，前者以固定字符串为输入源。
　　其中的format可以是一个或多个 {%[*] [width] [{h | l | I64 | L}]type | ' ' | '/t' | '/n' | 非%符号}
　　注：
　　1、 * 亦可用于格式中, (即 %*d 和 %*s) 加了星号 (*) 表示跳过此数据不读入. (也就是不把此数据读入参数中)
　　2、{a|b|c}表示a,b,c中选一，[d],表示可以有d也可以没有d。
　　3、width表示读取宽度。
　　4、{h | l | I64 | L}:参数的size,通常h表示单字节size，I表示2字节 size,L表示4字节size(double例外),l64表示8字节size。
　　5、type :这就很多了，就是%s,%d之类。
　　6、特别的：%*[width] [{h | l | I64 | L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值
　　支持集合操作：
　　%[a-z] 表示匹配a到z中任意字符，贪婪性(尽可能多的匹配)
　　%[aB'] 匹配a、B、'中一员，贪婪性
　　%[^a] 匹配非a的任意字符，贪婪性

sscanf("123456 ", "%s", buf);
　　printf("%s/n", buf);
　　结果为：123456

sscanf("123456 ", "%4s", buf);
　　printf("%s/n", buf);
　　结果为：1234

sscanf("123456 abcdedf", "%[^ ]", buf);
　　printf("%s/n", buf);
　　结果为：123456

sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
　　printf("%s/n", buf);
　　结果为：123456abcdedf

sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
　　printf("%s/n", buf);
　　结果为：123456abcdedf

sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
　　printf("%s/n", buf);
　　结果为：12DDWDFF

sscanf(“hello, world”, "%*s%s", buf);
　　printf("%s/n", buf);
　　结果为：world

char sztime1[16] = "", sztime2[16] = "";
　　sscanf("2006:03:18 - 2006:04:18", "%s - %s", sztime1, sztime2);
