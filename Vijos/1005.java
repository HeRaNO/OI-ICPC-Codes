import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
    static final int ms = 250;
    static BigInteger [] beginValue = new BigInteger[ms];
    static final BigInteger negOne = BigInteger.valueOf(-1);
    static final BigInteger nine = new BigInteger("9");
    static BigInteger [] rec = new BigInteger[ms];
    static BigInteger minLength = new BigInteger("0");
    //--------------------------------------------------------------------------//
    //取得后面一个数字.
    public static String getNextInt(String a)
    {
        String t = new String("");
        int len = a.length(), v, m = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            char c = a.charAt(i);
            v = (int)(c - 48) + m;
            m = v / 10;
            v %= 10;
            t = (char)(v + 48) + t;
        }
        while (m > 0)
        {
            v = m % 10;
            t = (char)(v + 48) + t;
            m /= 10;
        }
        return t;
    }
    //取得前一个数字
    public static String getFrontInt(String a)
    {
        String t = new String("");
        int len = a.length(), v, m = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            char c = a.charAt(i);
            v = (int)(c - 48) - m;
            if (v < 0)
            {
                v += 10;
                m = 1;
            }
            else
            {
                m = 0;
            }

            if (!(0 == i && v == 0))
            {
                t = (char)(v + 48) + t;
            }
        }
        if (t.length() == 0)
        {
            t = "0";
        }
        return t;
    }
    //比较两个字符串看看是否相等:相等则返回共长，否则返回-1
    public static int isEqualString(String a, String line, int pos)
    {
        int i;
        for (i = 0; i < a.length() && (pos + i) < line.length(); ++i)
        {
            if (a.charAt(i) != line.charAt(pos + i))
            {
                return -1;
            }
        }
        return i;
    }
    //这里按长度从next的segSize开始比较.
    public static boolean stringCompareBySegSize(String next, int segSize)
    {
        int beginPos = segSize, ret = 0, next_len = next.length();
        String head = next.substring(0, segSize);
        while (beginPos < next_len)
        {
            String back = getNextInt(head);
            ret = isEqualString(back, next, beginPos);
            if (-1 == ret)
            {
                return false;
            }
            else
            {
                beginPos += ret;
                head = back;
            }
        }
        return true;
    }
    //查看是否有进位
    public static boolean isCarryOut(String a)
    {
        int len = a.length();
        for (int i = 0; i < len; ++i)
        {
            if (a.charAt(i) != '9') return false;
        }
        return true;
    }
    //    --------------------------------------------------------------------------//
    //rec[]数组记录了每种长度的起始位置:比如两位起始于10，一位起始于1
    public static void genBeginPos()
    {
        BigInteger [] len = new BigInteger[ms];
        BigInteger ten = BigInteger.ONE;
        len[0] = BigInteger.ZERO;
        rec[0] = BigInteger.ZERO;
        rec[1] = BigInteger.ONE;
        for (int i = 1; i < ms; ++i)
        {
            len[i] = nine.multiply(ten);
            beginValue[i] = ten;
            ten = ten.multiply(BigInteger.valueOf(10));
        }
        for (int i = 2; i < ms; ++i)
        {
            rec[i] = rec[i - 1].add(len[i - 1].multiply(BigInteger.valueOf(i - 1)));
        }
    }
    public static BigInteger getPos(String value)
    {
        int len = value.length();
        BigInteger bValue = beginValue[len];
        BigInteger from = rec[len];
        BigInteger ret = (new BigInteger(value)).subtract(bValue);
        ret = ret.multiply(BigInteger.valueOf(len));
        ret = from.add(ret);
        return ret;
    }

    public static void setMinLength(BigInteger a)
    {
        if (minLength.compareTo(negOne) == 0 || minLength.compareTo(a) > 0)
        {
            minLength = a;
        }
    }

    public static boolean isAllZero(String a)
    {
        for (int i = 0; i < a.length(); ++i)
        {
            if (a.charAt(i) != '0') return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception
    {
        genBeginPos();
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = cin.readLine()) != null)
        {
            if (isAllZero(line))
            {
                line = "1" + line;
                BigInteger pos = getPos(line);
                pos = pos.add(BigInteger.ONE);
                System.out.println(pos.toString());
                continue;
            }

            final int line_len = line.length();
            /**
             * 分段时有如下考虑：(假设除头部head,余下部分为next).
             * 注意在分段过程中next的开头不能是以0字符开头。
             * 1、每段的长度都比字符串长度(len)要小
             *         这里需要分两种情况处理。
             *         A、头部不能取到分段长度:
             *             这里又分两种情况：
             *          a、next部分可以取到分段长度，这个易于处理，
             *          b、next部分不可以取到分段长度，这个不易处理。
             *         B、头部可以取到分段长度：比如111213，当分段长度为2时，头部可以取到11那么后面的数就顺理成章地推导下去了。
             * 2、每个分段的长度为len,但是头部与尾部均不足len,拼起来才足够.
             *         这里需要推导出头部的整个数字，比如99|15,按四位数分的话我们需要推出头部数为14[9915]00。从1499与1500中取了中间四位。
             * 3、整数字符串就是一个数(相当于第二种情况中头部长度为len)，不可拆分比如100, 1000,
             *    这时也不可以以0做为开头。
             */
            boolean have_find_min_length = false;
            int segSize = 1;
            minLength = negOne;
            for (segSize = 1; segSize < line_len; ++segSize)
            {
                String head = new String(""), next = new String("");
                int head_len = 0, next_len = 0;

                minLength = negOne;
                //Condition 1.A
                for (int headSize = 1; headSize < segSize; ++headSize)
                {
                    head = line.substring(0, headSize);
                    head_len = head.length();
                    next = line.substring(headSize, line_len);
                    next_len = next.length();
                    if (next_len > 0 && next.charAt(0) == '0') continue;

                    if (next_len >= segSize)
                    {
                        //Condition 1.A.a
                        String value = next.substring(0, segSize);
                        String front = getFrontInt(value);

                        //这里利用next[0~segSize)取得的front值与head进行比较
                        boolean ret = true;
                        for (int i = head.length() - 1, j = front.length() - 1;
                                i >= 0 && j >= 0; --i, --j)
                        {
                            if (head.charAt(i) != front.charAt(j))
                            {
                                ret = false;
                                break;
                            }
                        }

                        if (false == ret)
                        {
                            //比较失败，直接进行下轮测试。
                            continue;
                        }
                        else
                        {
                            //比较成功，那么从next开始，向后比较。
                            boolean bNextEqualToSegmentSize = stringCompareBySegSize(next, segSize);
                            if (false == bNextEqualToSegmentSize)
                            {
                                continue;
                            }
                            else
                            {
                                //这里需要推出完整的头值。
                                String beginValue = getFrontInt(value);
                                BigInteger pos = getPos(beginValue);
                                pos = pos.add(BigInteger.valueOf(beginValue.length() - head.length()));
                                setMinLength(pos);
                                //System.out.println("C 1.A.a Next larger than segSize: value = " + beginValue + " pos = " + pos.toString());
                                //System.out.println("Segment Size = " + segSize);
                            }
                        }
                    }
                    else
                    {
                        //Condition 1.A.b
                        String front_head = next.substring(0, segSize - head_len);
                        boolean bCarryOut = isCarryOut(head);

                        String front_part_value = "";
                        if (bCarryOut)
                        {
                            front_part_value = getFrontInt(front_head);
                        }
                        else
                        {
                            front_part_value = front_head;
                        }

                        String frontValue = "";
                        if (front_part_value.compareTo("0") != 0)
                        {
                            frontValue = front_part_value + head;
                        }
                        else
                        {
                            frontValue = head;
                        }

                        String NextValue = getNextInt(frontValue);
                        boolean bIsEqual = true;
                        for (int i = 0, j = 0; i < NextValue.length() && j < next_len; ++i, ++j)
                        {
                            if (NextValue.charAt(i) != next.charAt(j))
                            {
                                bIsEqual = false;
                                break;
                            }
                        }

                        if (bIsEqual)
                        {
                            String beginValue = frontValue;
                            BigInteger pos = getPos(beginValue);
                            pos = pos.add(BigInteger.valueOf(beginValue.length() - head.length()));
                            setMinLength(pos);
                            //System.out.println("C 1.A.b Next small than segSize: value = " + beginValue + " pos = " + pos.toString());
                            //System.out.println("Segment Size = " + segSize);
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                //Condition 1.B
                if (line.charAt(segSize) != '0' && line.charAt(0) != '0')
                {
                    boolean bHeadEqualToSegmentSize = stringCompareBySegSize(line, segSize);
                    if (bHeadEqualToSegmentSize)
                    {
                        String beginValue = line.substring(0, segSize);
                        BigInteger pos = getPos(beginValue);
                        setMinLength(pos);
                        //System.out.println("C1.B head equal to segSize: value = " + beginValue + " pos = " + pos.toString());
                    }
                }


                if (minLength.compareTo(negOne) != 0)
                {
                    have_find_min_length = true;
                    break;
                }
            }


            //Condition 2
            if (true == have_find_min_length)
            {
                System.out.println(minLength.toString());
                continue;
            }

            for (int headSize = 1; headSize < line_len && have_find_min_length == false; ++ headSize)
            {
                String head = line.substring(0, headSize);
                final int head_len = head.length();
                String next = line.substring(headSize, line_len);
                final int next_len = next.length();
                if (next_len > 0 && next.charAt(0) == '0') continue;

                boolean bCarryOut = isCarryOut(head);
                String beginValue = "";
                if (bCarryOut)
                {
                    beginValue = getFrontInt(next) + head;
                }
                else
                {
                    beginValue = next + head;
                }

                BigInteger pos = getPos(beginValue);
                pos = pos.add(BigInteger.valueOf(beginValue.length() - head.length()));
                setMinLength(pos);
                //System.out.println("C2 add equal to line_len: value = " + beginValue + " pos = " + pos.toString());
                //System.out.println("Segment Size = " + line_len);
            }

            //Condition 3
            if (line_len  > 0 && line.charAt(0) != '0')
            {
                String beginValue = line;
                BigInteger pos = getPos(beginValue);
                setMinLength(pos);
                //System.out.println("C3 hole length: front = " + beginValue + " pos = " + pos.toString());
                //System.out.println("Segment Size = " + line_len);
            }

            //最后的输出
            if (minLength.compareTo(negOne) != 0)
            {
                //System.out.println("Find min length");
                System.out.println(minLength.toString());
                continue;
            }
        }
    }
}