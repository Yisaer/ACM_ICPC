import java.math.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		int cas = 0;
		Scanner  in = new Scanner(System.in);
		while(in.hasNext()){
			cas++;
			str = in.nextLine();
			System.out.print("Case "+cas+": ");
			String[] StringSet = str.split(" ");
			int cnt = 0;
			int [] Num = new int[65566];
			int val;
			for(int i=0;i<StringSet.length;i++){
				val = Integer.parseInt(StringSet[i]);
				boolean flag = true;
				for(int j=0;j<cnt;j++){
					if(Num[j]==val){
						flag = false;
						break;
					}
				}
				if(flag){
					Num[cnt] = val;
					cnt++;
				}
			}
			for(int i=0;i<cnt;i++){
				if(i>0)
					System.out.print(" ");
				System.out.print(Num[i]);
			}
			System.out.println("");
		}
	}
}

