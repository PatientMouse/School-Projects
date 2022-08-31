import java.util.ArrayList;
import java.util.LinkedList;

public class Cache1 {
	private LinkedList<Object> cache;
	private int index;
	private int size;
	private Object obj;
	private int sizeLimit;
	private int hits;
	private int misses;
	private int ref;
	
	
	public Cache1(int limit) {
		cache = new LinkedList<Object>();
		sizeLimit = limit;
		index=0;
		
		//not needed
		//size =0;
		
		//moved to test
		//ref =0;
		//hits=0;
		//misses=0;
	}
	
	public int getRefrences() {
		return this.ref;
	}
	public int getHits() {
		return this.hits;
	}
	public int getMisses() {
		return this.misses;
	}
	public Object getObject(int i){
		
		return cache.get(i);
	}
	public Object getFirstObject() {
		return  cache.getFirst();
	}
	public void addObject(Object e) {
		//check if its full
		if(cache.size() < sizeLimit) {
			//check if it conains e
			if(cache.contains(e)) {
				cache.remove(e);
			}
			//add e
			cache.addFirst(e);
		}else {
			//if it full first check to see if its in list
			if(cache.contains(e)) {
				cache.remove(e);
				cache.addFirst(e);
			}else {
				//remover last and add obj e
				cache.removeLast();
				cache.addFirst(e);
			}
		}
	}
	public Object removeObject(int i) {
		//size--;
		return cache.remove(i);
	}
	public Object removeObject(Object e) {
		return cache.remove(e);
	}
	public void clearCache() {
		cache.clear();
	}
	public int getSize() {
		return cache.size();
	}
	public int getMaxSize() {
		return this.sizeLimit;
	}
	public boolean cacheHit(Object e) {
		
	return cache.contains(e);
		
		
	}

}
