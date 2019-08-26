Scanner s = new Scanner(System.in);//读入
while(s.hasNext){
    s.nextInt() // 读入整数
    s.nextBigDecimal() //
    s.nextBigInteger()// 读入一个大整数
    s.nextFloat() // 读入浮点
    s.nextLine(); // 读入一行
}
//运算
BigInteger a, b;
a = new BigInteger("string");
a.add(BigDecimal)           // BigDecimal对象中的值相加，然后返回这个对象。
a.subtract(BigDecimal)    //BigDecimal对象中的值相减，然后返回这个对象。
a.multiply(BigDecimal)    //BigDecimal对象中的值相乘，然后返回这个对象。
a.divide(BigDecimal)        //BigDecimal对象中的值相除，然后返回这个对象。
a.toString()                  //       将BigDecimal对象的数值转换成字符串。
a.doubleValue()                 //将BigDecimal对象中的值以双精度数返回。
a.floatValue()                    // 将BigDecimal对象中的值以单精度数返回。
a.longValue()                     //将BigDecimal对象中的值以长整数返回。
a.intValue()                       //将BigDecimal对象中的值以整数返回。
a.remainder(); //取模
a.compareTo(b) //比较 a = b return 0; // a > b return 1; // a < b return -1;
a.shiftRight(n) // 右移n位
Integer.toString(num, 2); // (num,back)把num当做10进制的数转成back进制的st(back <= 35).
Integer.parseInt(st, 8); // (st,back)把st当做back进制，转成10进制的int(parseInt有两个参数,第一个为要转的字符串,第二个为说明是什么进制).

BigDecimal a, b;
a.divide(b, len, BigDecimal./*ROUND_HALF_UP,ROUND_FLOOR*/)
BigDecimal.setScale()方法用于格式化小数点
setScale(1)表示保留一位小数，默认用四舍五入方式
setScale(1,BigDecimal.ROUND_DOWN)//直接删除多余的小数位，如2.35会变成2.3
setScale(1,BigDecimal.ROUND_UP)//进位处理，2.35变成2.4
setScale(1,BigDecimal.ROUND_HALF_UP)//四舍五入，2.35变成2.4
setScaler(1,BigDecimal.ROUND_HALF_DOWN)//四舍五入，2.35变成2.3，如果是5则向下舍
setScaler(1,BigDecimal.ROUND_CEILING)//接近正无穷大的舍入
setScaler(1,BigDecimal.ROUND_FLOOR)//接近负无穷大的舍入，数字>0和ROUND_UP作用一样，数字<0和ROUND_DOWN作用一样
setScaler(1,BigDecimal.ROUND_HALF_EVEN)//向最接近的数字舍入，如果与两个相邻数字的距离相等，则向相邻的偶数舍入。

//输出格式
import java.text.*;
DecimalFormat test1=new DecimalFormat("#.000000000#####");//小数部分超出的位数四舍五入（只看前一位）
//“#”若“#”为高位且高位为0则不显示
DecimalFormat test2=new DecimalFormat("0000000.0000000");
System.out.println(test1.format(34556.124553));
System.out.println(test2.format(34556.124553));


public class Main {
    public static void main(String []args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while(T-- != 0) {
            BigInteger n;
            n = in.nextBigInteger();
            System.out.println(f3);
        }
    }
}
