//author: andrew gerber
//TODO needed instance vaitles, key, douplicent count, probe count
public class HashObject<T> {
	//declare vairbles
	int dupCount;
	int probeCount;
	T key;
	
	public HashObject(T input) {
		dupCount = 0;
		probeCount = 0;
		key = input;
		
	}
	
	public int getDupCount() {
		return this.dupCount;
	}
	
	public int getProbeCount(){
		return this.probeCount;
	}
	
	public T getKey() {
		return this.key;
	}
	
	public void setDupCount(int i) {
		this.dupCount = i;
	}
	
	public void setProbeCount(int i) {
		this.probeCount = i;
	}
	
	public void setKey(T i) {
		this.key = i;
	}
	
	public void incrementDup() {
		this.dupCount++;
	}
	public void incrementProbe() {
		this.probeCount++;
	}
	
	public void addDup(int i) {
		this.dupCount = this.dupCount + i;
	}
	
	public void addProbe(int i) {
		this.probeCount = this.probeCount + i;
	}
	
	
	public String toString() {
		return String.format("The key is: "+ this.key + "\nThe Duplicate Count is: " + this.dupCount + "\nThe Probe Count is: "+ this.probeCount);
	}
	
	public boolean equals(HashObject o) {
//		if(o.key == this.key) {
//			return true;
//		}else {
//			return false;
//		}
		
		return(this.getKey().equals(o.getKey()));
		
		
	}

}
