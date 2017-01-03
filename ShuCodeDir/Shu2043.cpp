import java.math.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		Scanner  in = new Scanner(System.in);
		int cas = 0;
		int index;
		char [] Num = new char[40];
		for(int i=0;i<=36;i++){
			if(i>=0&&i<=9){
				Num[i] = (char) ('0'+i);
			}
			else{
				Num[i] = (char) ('A'+i-10);
				
			}
		}
		while(in.hasNext()){
			cas++;
			System.out.print("Case "+cas+": ");
			n = in.nextInt();
			index = in.nextInt();
			StringBuilder str = new StringBuilder();
			while(n>0){
				String s = String.valueOf(Num[n%index]);
				str = str.append(s);
				n/=index;
			}
			String ans = str.toString();
			char[] ans1 = ans.toCharArray();
				
			for(int i=ans1.length-1;i>=0;i--){
				System.out.print(ans1[i]);
			}
			System.out.println("");

			
		}	
	}
}

