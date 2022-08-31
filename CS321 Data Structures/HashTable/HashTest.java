import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;

public class HashTest {


	@SuppressWarnings("unused")
	public static void main(String[] args) throws Exception {
		if(args[1]==null || args[0]==null) {
			System.out.println("Missing args");
		}
		if(args.length<=2 || Integer.parseInt(args[2])==0) {
			int tableSize = PrimeGenorator.getPrime();

			Random rand = new Random();
			double loadFactor = Double.parseDouble(args[1]);

			double loadValue = (tableSize * loadFactor);

			String type = "";
			HashTable singleTable = new HashTable(1,tableSize);
			HashTable doubleTable = new HashTable(2,tableSize);



			if(Integer.parseInt(args[0]) == 1) {//INTEGER TYPE
				type = "Random Integers";


				//			singleTable.tableAdd(testDup);
				//			singleTable.tableAdd(testDup);

				for(int i =0; i<loadValue; i++) {
					int rando = rand.nextInt();
					while(rando < 0) {
						rando = rand.nextInt();
					}
					HashObject<Object> newInt = new HashObject<Object>(rando);
					singleTable.tableAdd(newInt,loadValue);
					doubleTable.tableAdd(newInt, loadValue);
					//singleTable.upEele();
				}
				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + singleTable.getElements() + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
			}else if(Integer.parseInt(args[0]) == 2) {//TIME TYPE
				type = "Current Time";
				for(int i =0;i<loadValue;i++) {
					long time = System.currentTimeMillis();
					HashObject<Object> newobj = new HashObject<Object>(time);
					singleTable.tableAdd(newobj,loadValue);
					doubleTable.tableAdd(newobj, loadValue);
				}


				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + singleTable.getElements() + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);

			}else if(Integer.parseInt(args[0]) == 3) {//WORD LSIT
				File file = new File("word-list");
				Scanner scan = new Scanner(file);
				type = "Word List";

				while(scan.hasNextLine() && singleTable.getElements() < loadValue) {
					HashObject<Object> word = new HashObject<Object>(scan.nextLine());
					singleTable.tableAdd(word,loadValue);
					doubleTable.tableAdd(word, loadValue);
					//singleTable.upEele();
					//System.out.println(singleTable.getElements());
				}
				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.print("");
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + (singleTable.getElements()+singleTable.getTotalDup()) + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);

				scan.close();
			}
		}else if(Integer.parseInt(args[2]) == 1) {
			File singlefile = new File("linear-dump");
			File doublefile = new File("double-dump");
			FileWriter singlewriter = new FileWriter("linear-dump");
			FileWriter doublewriter = new FileWriter("double-dump");
			int tableSize = PrimeGenorator.getPrime();

			Random rand = new Random();
			double loadFactor = Double.parseDouble(args[1]);

			double loadValue = (tableSize * loadFactor);

			String type = "";
			HashTable singleTable = new HashTable(1,tableSize);
			HashTable doubleTable = new HashTable(2,tableSize);



			if(Integer.parseInt(args[0]) == 1) {//INTEGER TYPE
				type = "Random Integers";


				//			singleTable.tableAdd(testDup);
				//			singleTable.tableAdd(testDup);

				for(int i =0; i<loadValue; i++) {
					int rando = rand.nextInt();
					while(rando < 0) {
						rando = rand.nextInt();
					}
					HashObject<Object> newInt = new HashObject<Object>(rando);
					singleTable.tableAdd(newInt,loadValue);
					doubleTable.tableAdd(newInt, loadValue);
					//singleTable.upEele();
				}
				singlewriter.write(singleTable.printArry());
				doublewriter.write(doubleTable.printArry());
				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + singleTable.getElements() + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
			}else if(Integer.parseInt(args[0]) == 2) {//TIME TYPE
				type = "Current Time";
				for(int i =0;i<loadValue;i++) {
					long time = System.currentTimeMillis();
					HashObject<Object> newobj = new HashObject<Object>(time);
					singleTable.tableAdd(newobj,loadValue);
					doubleTable.tableAdd(newobj, loadValue);
				}
				singlewriter.write(singleTable.printArry());
				doublewriter.write(doubleTable.printArry());

				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + singleTable.getElements() + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);

			}else if(Integer.parseInt(args[0]) == 3) {//WORD LSIT
				File file = new File("word-list");
				Scanner scan = new Scanner(file);
				type = "Word List";
				
				

				while(scan.hasNextLine() && (singleTable.getElements() < loadValue)) {
					HashObject<Object> word = new HashObject<Object>(scan.nextLine());
					singleTable.tableAdd(word,loadValue);
					doubleTable.tableAdd(word, loadValue);
					
					//System.out.println(singleTable.getElements());
				}
				singlewriter.write(singleTable.printArry());
				doublewriter.write(doubleTable.printArry());
				
				double probes = singleTable.getTotalProbes();
				double eles = singleTable.getElements();
				double probeAVG = probes/eles;
				System.out.print("");
				System.out.println("A good table size is found: "+tableSize);
				System.out.println("Data source type: "+type);
				System.out.println("\n\nUsing Linear Hashing....");
				System.out.println("Input " + (singleTable.getElements()+singleTable.getTotalDup()) + " elements, of which " + singleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);
				probes = doubleTable.getTotalProbes();
				//System.out.println(doubleTable.getTotalProbes());
				eles = doubleTable.getElements();
				//System.out.println(eles);
				probeAVG = probes/eles;
				System.out.println("\n\nUsing Double Hashing....");
				System.out.println("Input " + (doubleTable.getElements()+doubleTable.getTotalDup()) + " elements, of which " + doubleTable.getTotalDup() + " duplicates");
				System.out.println("Load Factor = "+loadFactor+", Avg. no. of probes " + probeAVG);

				scan.close();
			}
			
			singlewriter.close();
			doublewriter.close();
		}

	}


}
