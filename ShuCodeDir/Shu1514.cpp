import java.util.Scanner;

public class Main {

	 static Scanner cin=new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger a,b,c;
		while(cin.hasNext()){
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			c=a.multiply(b);
			System.out.println(a+"*"+b+"="+c);
		}

	}

}

