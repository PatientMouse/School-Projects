import java.util.Arrays;

/*
 * @author Andrew Gerber
 * Date:september 2020
 * Desc: this is a run of the mill maxheap class that sorts nodes that are Processes useing both up and down heapifys to sort by priority
 */

public class MaxHeap {
	private Process[] heapArry;
	private int currentSize; //aka index
	private int maxSize;
	
	public MaxHeap() {
		//consructio makes a maxheap onject with the max size as the input and sets size to 0
		// makes arry heap with max size
		
		//this.maxSize = inSize;
		this.maxSize =100;
		this.heapArry = new Process[maxSize];
		
		
		
		//self:do i need more:
		
	}
	
	public Process getProcess(int index) {
		return this.heapArry[index];
	}

	
	public boolean isEmpty() {
		//returns true if arry empty
		return currentSize==0;
		
	}
	
	public boolean isFull() {
		//if it is full double size and retun true
		if(currentSize >= this.maxSize) {
			maxSize=maxSize*2;
			heapArry = Arrays.copyOf(heapArry, maxSize);
			return true;
		}else {
			return false;
		}
	}
	
	
	//return index of parent
	private int daddy(int index) {
		return index/2;
	}
	//rutn child indexies
	private int leftKid(int index) {
		return(2*index);
	}
	private int rightKid(int index) {
		
	return (2*index)+1;
	}
	
	private void swap(int firstIndex, int secondIndex) {
		Process placeHolder;
		placeHolder = heapArry[firstIndex];
		heapArry[firstIndex] = heapArry[secondIndex];
		heapArry[secondIndex] =placeHolder;
	}
	public void insert(Process o) {
		isFull();
		heapArry[++currentSize]=o;
		if(currentSize > 1) {
		while(heapArry[currentSize].compareTo(heapArry[daddy(currentSize)]) == 1) {
			swap(currentSize,daddy(currentSize));
			currentSize=daddy(currentSize);
		}
		}
		
	}
	
	//check to see if on end /leaf
	public boolean isEnd(int index) {
		if(index >= (this.currentSize/2) && index <=currentSize) {
			return true;
		}else{
		return false;
		}
	}
	public Process removeMax() {
		//this is root
		Process yeeted = heapArry[1];
		heapArry[1] =heapArry[currentSize--];
		maxHeapifyDown(1);
		return yeeted;
	}
	
	public void heapifyUP() {
	
	int index = ((maxSize/2) -1);
	for(int i = index; index >=0;i--) {
		maxHeapifyDown(i);
	}
	}
	
	public int getCurrentSize() {
		return this.currentSize;
	}
	
	
	
	
	public void maxHeapifyDown(int index) {
		if(isEnd(index)) {
			return;
		}if(currentSize > 1) {
		if((heapArry[index].compareTo(heapArry[leftKid(index)]) == -1) || (heapArry[index].compareTo(heapArry[rightKid(index)]) == -1 )) {
			if(heapArry[leftKid(index)].compareTo(heapArry[rightKid(index)])==1) {
				swap(index,leftKid(index));
				maxHeapifyDown(leftKid(index));
			}else {
				swap(index,rightKid(index));
				maxHeapifyDown(rightKid(index));
			}
		}
		}
	}

}
