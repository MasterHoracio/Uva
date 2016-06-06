import java.util.Scanner;
import java.util.Arrays;

public class Main2 {
	
	public static void main(String [] agrs){
		Scanner sc = new Scanner(System.in);
		String str1, str2;
		int []num1 = new int[10];
		int []num2 = new int[10];
		int carry, j;
		boolean carryNumber;
		while(sc.hasNext()){
			str1 = sc.next();str2 = sc.next();
			if(str1.equals("0") && str2.equals("0"))
				break;
			j = carry = 0;carryNumber = false;
			Arrays.fill(num1, 0);
			Arrays.fill(num2, 0);
			for(int i = str1.length() - 1; i >= 0; i--){
				num1[j] = Integer.parseInt(Character.toString(str1.charAt(i)));
				j++;
			}j = 0;
			for(int i = str2.length() - 1; i >= 0; i--){
				num2[j] = Integer.parseInt(Character.toString(str2.charAt(i)));
				j++;
			}
			for(int i = 0; i < 10; i++){
				if((num1[i] + num2[i] > 9) && !carryNumber){
					carry++;
					carryNumber = true;
					continue;
				}if(carryNumber){
					if(num1[i] + num2[i] + 1 > 9)
						carry++;
					else
						carryNumber = false;
				}
			}
			if(carry == 0)
				System.out.println("No carry operation.");
			else if(carry == 1)
				System.out.println("1 carry operation.");
			else
				System.out.println(carry+" carry operations.");
		}
		sc.close();
	}
}
