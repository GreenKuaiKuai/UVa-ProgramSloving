import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String input;
		int ST = 0;
		ArrayList<Integer> myList = new ArrayList<>();

		while (sc.hasNextLine())
		{
			input = sc.nextLine();
			for (ST = 0; ST <= 10000; ST++)
			{
				myList.clear();
				for (int i = 0; i < input.length(); i++)
				{
					int a0 = ((int) input.charAt(i)) - 65 + ST; // 盢﹃锣Θ计(ㄌ酚ST)
					String a1 = String.valueOf(a0);

					for (int j = 1; j < a1.length(); j++) // 盢计皚
						myList.add(Integer.valueOf(a1.substring(j - 1, j)));
					myList.add(Integer.valueOf(a1.substring(a1.length() - 1))); // 程
				}

				while (myList.size() > 3) // 盢綟ㄢ计糶㎝计
				{
					for (int k = 0; k <= myList.size() - 2; k++)
					{
						int b = myList.get(k) + myList.get(k + 1);
						if (b >= 10)
							myList.set(k, b % 10);
						else
							myList.set(k, b);
					}
					myList.remove(myList.size() - 1); // 埃程计
				}

				if (myList.get(0) == 1 && myList.get(1) == 0 && myList.get(2) == 0) // 暗100
				{
					System.out.println(ST);
					break;
				}

				if (ST == 10000)
					System.out.println(":(");
			}
		}
	}
}