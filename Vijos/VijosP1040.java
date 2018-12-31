import java.io.*;
import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        System.out.println(sc.nextBigInteger().multiply(sc.nextBigInteger()));
    }
}