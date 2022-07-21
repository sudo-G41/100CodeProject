package net.javaInputSpeedTest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main(String[] args)
    {
        final int maxSize = 300000;
        switch(Integer.parseInt(args[0])){
            case 1:
            SysteminTime sysin = new SysteminTime(maxSize);
            sysin.nextInt();
            sysin.nextDouble();
            sysin.nextString();
            break;
            case 2:
            BufferedStreamTime br = new BufferedStreamTime(maxSize);
            br.nextInt();
            br.nextDouble();
            br.nextString();
            break;
            case 3:
            ScannerBufferedInputStreamTime scbr = new ScannerBufferedInputStreamTime(maxSize);
            scbr.nextInt();
            scbr.nextDouble();
            scbr.nextString();
            break;
            default:
            System.out.println("...???");
            break;
        }
    }
}
abstract class TimeTest{
    protected int[] intArr;
    protected double[] doubleArr;
    protected String[] strArr;
    public TimeTest(){}
    public TimeTest(int maxSize){
        this.intArr = new int[maxSize];
        this.doubleArr = new double[maxSize];
        this.strArr = new String[maxSize];
    }

    void getTo(){
        System.out.println("int end : "+intArr[intArr.length-1]);
        System.out.println("double end : "+doubleArr[doubleArr.length-1]);
        System.out.println("String end : "+strArr[strArr.length-1]);
    }

    public abstract void nextInt();
    public abstract void nextDouble();
    public abstract void nextString();
}
class SysteminTime extends TimeTest{
    private Scanner sc;
    public SysteminTime(int maxSize){
        super(maxSize);
        sc = new Scanner(System.in);
        System.out.println("System.in class");
    }
    @Override
    public void nextInt(){
        long s = System.currentTimeMillis();
        System.out.println("Integer input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                intArr[idx] = sc.nextInt();
                idx++;
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextDouble(){
        long s = System.currentTimeMillis();
        System.out.println("Double input");
        for(int i=0,idx=0; i<5;){
            if(idx<doubleArr.length){
                doubleArr[idx] = sc.nextDouble();
                idx++;
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextString(){
        long s = System.currentTimeMillis();
        System.out.println("String input");
        for(int i=0,idx=0; i<5;){
            if(idx<strArr.length){
                strArr[idx] = sc.nextLine();
                idx++;
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
}
class BufferedStreamTime extends TimeTest{
    private BufferedReader br;
    public BufferedStreamTime(int maxSize){
        super(maxSize);
        br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("buffered stream class");
    }
    
    @Override
    public void nextInt(){
        long s = System.currentTimeMillis();
        System.out.println("Integer input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                try {
                    String str = br.readLine();
                    intArr[idx] = Integer.parseInt(str);
                    idx++;
                } catch (IOException e) {
                    System.out.println("Error : bufferedReader intArr");
                }
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextDouble(){
        long s = System.currentTimeMillis();
        System.out.println("Double input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                try {
                    String str = br.readLine();
                    doubleArr[idx] = Double.parseDouble(str);
                    idx++;
                } catch (IOException e) {
                    System.out.println("Error : bufferedReader doubleArr");
                }
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextString(){
        long s = System.currentTimeMillis();
        System.out.println("String input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                try {
                    strArr[idx] = br.readLine();
                    idx++;
                } catch (IOException e) {
                    System.out.println("Error : bufferedReader strArr");
                }
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
}
class ScannerBufferedInputStreamTime extends TimeTest{
    private Scanner sc = new Scanner(new InputStreamReader(System.in));
    public ScannerBufferedInputStreamTime(int maxSize){
        super(maxSize);
        System.out.println("scanner + buffered input stream class");
    }
    
    @Override
    public void nextInt(){
        long s = System.currentTimeMillis();
        System.out.println("Integer input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                intArr[idx] = Integer.parseInt(sc.nextLine());
                idx++;
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextDouble(){
        long s = System.currentTimeMillis();
        System.out.println("Double input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                doubleArr[idx] = Double.parseDouble(sc.nextLine());
                idx++;
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
    @Override
    public void nextString(){
        long s = System.currentTimeMillis();
        System.out.println("String input");
        for(int i=0,idx=0; i<5;){
            if(idx<intArr.length){
                strArr[idx] = sc.nextLine();
                idx++;
                // System.out.println(intArr[idx-1]);
            }
            else{
                idx = 0;
                i++;
                long e = System.currentTimeMillis();
                System.out.println("실행시간 : "+(e-s)+"ms");
                s = System.currentTimeMillis();
            }
        }
    }
}
