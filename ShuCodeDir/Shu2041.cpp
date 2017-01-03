import java.math.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		Scanner  in = new Scanner(System.in);
		int cas = 0;
		while(in.hasNext()){
			cas++;
			System.out.print("Case "+cas+": ");
			str = in.nextLine();
			double sum = 0;
			double muti = 1;
			String[] StrSet = str.split(" ");
			int cnt = StrSet.length;
			for(String s:StrSet){
//				System.out.println(s);
				sum += Double.parseDouble(s);
				muti *= Double.parseDouble(s);
			}
			double ans1 = sum/cnt;
			if(muti <0 && ((int)cnt & 1)==0){
				System.out.printf("%.1f, None\n", ans1);
			}
			else{
				if(muti <0){
					muti = -muti;
					double ans2 = Math.pow(muti, 1.0/cnt);
					System.out.printf("%.1f, %.1f\n", ans1,-ans2);
					continue;
				}
				double ans2 = Math.pow(muti, 1.0/cnt);
				System.out.printf("%.1f, %.1f\n", ans1,ans2);
	
			}
			
		}
	}
}
