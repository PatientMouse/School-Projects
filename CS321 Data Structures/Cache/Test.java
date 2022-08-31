import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Test {
	//@author andrewG

	private static boolean twocache = false;
	private static Cache1 cache1;
	private static Cache1 cache2;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
//		if(args.length < 4) {
//			System.out.println("Too many inputs");
//		}
		if(args[0].equalsIgnoreCase("1")) {
			//check if there is too many commands
//			if(args.length < 3) {
//				System.out.print("Error");
//				System.exit(1);
//			}
			
			cache1 = new Cache1(Integer.parseInt(args[1])); //make cache with given size
			//TODO read file with args[2] did i do that? no 
//			System.out.println(args[0]);
//			System.out.println(args[1]);
//			System.out.println(args[2]);
//			System.out.println(twocache);
			twocache = false;
			fileSearch(new File(args[2]));
			
		}else if(args[0].equalsIgnoreCase("2")){
			//check if there is too many commands
			if(args.length < 4) {
				System.out.print("Error");
				System.exit(1);
			}
			
			cache1 = new Cache1(Integer.parseInt(args[1]));//make first cache
			cache2 = new Cache1(Integer.parseInt(args[2]));//make second cache
			twocache =true; //set it so were using two cache, usefull is read me
			//TODO read file with args[3]
			fileSearch(new File(args[3]));
		}else {
			System.out.println("ERR: Too many or Too little cache amount");
			System.exit(1);
		}
	}
	public static void fileSearch(File fileName) {
		int cacheOneMiss= 0;
		int cacheTwoMiss = 0;
		
		//hit ratios
		double gHR = 0;
		double oneHR =0;
		double twoHR =0;
		
		//number of hits
		double gNH =0;
		double oneNH =0;
		double twoNH =0;
		
		//refrences
		
		double totalRefrences =0;
		double gNR =0;
		double oneNR =0;
		double twoNR =0;
		String tokenWord;
		
		//try catche for no file
		try {
			String index;//use string b/c text files are sentances
			Scanner fileScan = new Scanner(fileName);

			
//		if(twocache=false){
//			System.out.println("FirHAHAHAHAHAst level cache with " + cache1.getMaxSize()+ " entries has been created\n\n");
//		}
		if(twocache==true) {
			System.out.println("First level cache with " + cache1.getMaxSize()+ " entries has been created");
			System.out.println("Second level cache with " + cache2.getMaxSize()+ " entries has been created\n\n");
		}else {
			System.out.println("First level cache with " + cache1.getMaxSize()+ " entries has been created\n\n");

		}
			
		while(fileScan.hasNextLine()){
			String tokenLine = fileScan.nextLine();
			
			
			//Asked TA and told me to use a string tokenizer like so:
			StringTokenizer splitter = new StringTokenizer(tokenLine, " ");
			totalRefrences =+ splitter.countTokens();
			while(splitter.hasMoreTokens()) {
				
				tokenWord = splitter.nextToken(); 
				
				if(twocache==false) {
					if(cache1.cacheHit(tokenWord)) {
						cache1.addObject(tokenWord);
						oneNH++;
						oneNR++;
					}else {
						cacheOneMiss++;
						oneNR++;
					}
					cache1.addObject(tokenWord);
					oneNR++;
				}
				
				if(twocache==true) {
					if(cache1.cacheHit(tokenWord)) {
						cache1.addObject(tokenWord);
						cache2.addObject(tokenWord);
						oneNH++;
						oneNR++;
					}else {
						oneNR++;
						twoNR++;
						cacheOneMiss++;
						if(cache2.cacheHit(tokenWord)) {
							cache2.addObject(tokenWord);
							twoNH++;
						}
						cache1.addObject(tokenWord);
					}
					cache1.addObject(tokenWord);
					cache2.addObject(tokenWord);
				}
				
			}
		}
			/*[jhyeh@onyx sol]$ java Test 2 5 10 small.txt
First level cache with 5 entries has been created
Second level cache with 10 entries has been created
.
The number of global references: 20
The number of global cache hits: 1
The global hit ratio                  : 0.05

The number of 1st-level references: 20
The number of 1st-level cache hits: 1
The 1st-level cache hit ratio             : 0.05

The number of 2nd-level references: 19
The number of 2nd-level cache hits: 0
The 2nd-level cache hit ratio             : 0.0

----------------------------------------------------------------
*/
			
			//print out how amny hits
			
			System.out.println("The number of global references: " + (oneNR));


			
			if(twocache==false) {
				System.out.println("The number of global cache hits: " + (oneNH));
				System.out.println("The global hit ratio: " + (oneNH / oneNR) +"\n");
				System.out.println("The number of 1st-level references: " + oneNR );
				System.out.println("The number of 1st-level cache hits: " + oneNH);
				System.out.println("The 1st-level cache hit ratio             : " + (oneNH / oneNR));

			}else if (twocache == true) {
				System.out.println("The number of global cache hits: " + (oneNH + twoNH));
				System.out.println("The global hit ratio: " + ((oneNH + twoNH) / oneNR) +"\n");
				
				
				System.out.println("The number of 1st-level references: " + oneNR );
				System.out.println("The number of 1st-level cache hits: " + oneNH);
				System.out.println("The 1st-level cache hit ratio             : " + (oneNH / oneNR));
				
				System.out.println("\nThe number of 2nd-level references: " + twoNR);
				System.out.println("The number of 2nd-level cache hits: " + twoNH);
				System.out.println("The 2nd-level cache hit ratio             : " + (twoNH / twoNR));
				System.out.println("\n----------------------------------------------------------------\n");
			}
			
			
		
			
		} catch(FileNotFoundException e){
			System.out.println("No File");
		}
		
	}

}
