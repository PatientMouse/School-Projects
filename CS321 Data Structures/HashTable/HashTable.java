//andrew gerber
public class HashTable {
	//private int prime;
	private int maxSize;
	private int currentSize;
	private int totalDups;
	private int totalProbes;
	private int hashType; // 1 is single 2 is double
	private HashObject[] array;
	private double elements;
	
	public HashTable(int type,int tableSize) {
		//this.prime = m;
		this.maxSize = tableSize;
		this.currentSize = 0;
		this.hashType = type;
		array = new HashObject[this.maxSize]; 
	}
	
	public static int PositiveMod(int dividend, int divisor) {
		int value = dividend % divisor;
		if( value <0) {
			value += divisor;
		}
		return value;
	}
	public int hashSingle(HashObject o,int i) {
		//int code = o.getKey().hashCode();
		int code = o.getKey().hashCode();
		int index;
		
		//index = code % this.size;
		index = PositiveMod(code,this.maxSize);
		
		return ((i+index) % this.maxSize);
		
	}
	
	
	public int hashDouble(HashObject o,int i) {
		int code = o.getKey().hashCode();
		int h2 = 1+(PositiveMod(code,this.maxSize-2));
		int h1 = PositiveMod(o.getKey().hashCode(),this.maxSize);
		// PositiveMod
		
		int index;
	
		//h2 = 1+(posCode % (this.maxSize -2));
		// (h1+ (i*h2)) %this.maxSize
		index = (h1 + (i*h2)) % this.maxSize;
		
		
		return index;
	}
//	public boolean isDupe(HashObject o) {
//		if(o == null) {
//			throw new NullPointerException();
//		}
//		if(this.hashType == 1) {
//		//int index = hashSingle(o);
//		
//		for(int i = 0; i < this.maxSize; i++) {
//			if(this.array[i] != null) {
//				if(array[i].equals(o)) {
//					array[i].incrementDup();
//					this.totalDups++;
//					return true;
//				}
//			}
//		}
//		}
//		return false;
//	}
//	public int nextOpen(HashObject o, int index) {
//		
//		if(this.array[index] == null) {
//			return index;
//		}else if(this.array[index] != null) {
//			
//			for(int i = index; i<maxSize;i++) {//check indez:max(load factor*table size)=
//				o.incrementProbe();
//				if(array[i] == null) {
//					
//					return i;
//				}
//				
//			}
//			for(int i = 0 ; i <index;i++) {//check 0:index
//				o.incrementProbe();
//				if(array[i] == null) {
//				
//				return i;
//				}
//			}
//		}
//		return -1; //no open slots
//	}
	
	public void tableAdd(HashObject o, double loadValue) {
		if(o == null) {
			throw new NullPointerException();
		}
		//while(this.currentSize < loadValue) {
		if(this.hashType == 1) { //single hash add
			int index; //hash for index
			// index= key % tablesize
			// index= (i +(key % tablesize)) % tablesize
			// for loop from0 to tablesize
			// caclcate the index
			// check if null( you add new element)
			// if not null, if equals (increment dup count)
			// continue the loop
			int x=0;
			for(int i = 0; i<this.maxSize;i++) {
				index  = hashSingle(o,i);
//				System.out.println(this.elements +", " + loadValue);
//				if(index == 95791) {
//					System.out.println("hit 95791");
//				}
				x++;
				if(array[index] == null) {
					array[index] = o;
					this.totalProbes+=x;
					array[index].incrementProbe();
					this.currentSize++;
					this.elements++;
					return;
				}else if(array[index].equals(o)) {
					array[index].incrementDup();
					this.totalDups++;
					return;
				}
			}
			
			
		}else if(this.hashType == 2) {
			int index; //hash for index
			// index= key % tablesize
			// index= (i +(key % tablesize)) % tablesize
			// for loop from0 to tablesize
			// caclcate the index
			// check if null( you add new element)
			// if not null, if equals (increment dup count)
			// continue the loop
			int y=0;
			for(int i = 0; i<this.maxSize;i++) {
				index  = hashDouble(o,i);
				//System.out.println(index);
				y++;
				if(array[index] == null) {
					array[index] = o;
					this.totalProbes+=y;
					
					array[index].incrementProbe();
					
					this.currentSize++;
					this.elements++;
					return;
				}else if(array[index].equals(o)) {
					array[index].incrementDup();
					this.totalDups++;
					return;
				}
						}
			
		}
		
	}
	
	public int getTotalDup() {
		return this.totalDups;
	}
	public int getTotalProbes() {
		
		return this.totalProbes;
	}
	public double getElements() {
		return this.elements;
	}

	public void upEele() {
		this.elements++;
	}
	public String printArry() {
		String output = "";
		for(int i = 0;i<this.maxSize;i++) {
			if(array[i] != null) {
				//System.out.println("table["+i+"]: " + array[i].toString());
				output+= "table["+i+"]: "+array[i].getKey() + " "+ (array[i].getDupCount()/2) +" "+ array[i].getProbeCount()+"\n";
			}
		}
		return output;
	}
}
