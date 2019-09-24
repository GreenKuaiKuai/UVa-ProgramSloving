import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String input;

		while(sc.hasNextLine())
		{
			int ans = 0;
			input = sc.nextLine();
			while(input.indexOf("  ")!=-1)
			{
				input = input.replaceAll("  "," ");
				ans = ans + 1;
			}
			
			System.out.println(ans);
		}

	}
}
