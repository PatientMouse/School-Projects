

/*
 * @author Andrew Gerber
 * Date:september 2020
 * Desc: This is a Priority queue class that is a simplified version of the build in java PQ class, it uses a max heap for a the queue 
 * 
 */
public class PQueue {
	private MaxHeap que;
	
	
	public PQueue(){
		que = new MaxHeap();
	}

	public void enPQueue(Process p) {
		// TODO Auto-generated method stub
		this.que.insert(p);
		
	}

	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return que.isEmpty();
	}

	public Process dePQueue() {
		// TODO Auto-generated method stub
		//get procces with .prity with higest
		
		return que.removeMax();
	}

	public void update(int timeToIncrementLevel, int maxLevel) {
		// if time not proc >= time to incrementlevel
		
		for(int i =0; i< this.que.getCurrentSize(); i++) {
			if(this.que.getProcess(i) ==null) {
				i++;
			}
			this.que.getProcess(i).notProcessedIncrement();
			if(this.que.getProcess(i).getTimeNotProcessed() >= timeToIncrementLevel) {
				this.que.getProcess(i).resetTimeNotProcessed();
				if(this.que.getProcess(i).getPriority() < maxLevel) {
					this.que.getProcess(i).upPrio();
					this.que.heapifyUP();
				}
			}
		}
		
	}

}
