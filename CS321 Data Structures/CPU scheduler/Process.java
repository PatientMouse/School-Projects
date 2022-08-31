/* this is a base object java for lab2 of cs321
* Author andrew gerber
* date sep 21 2020
* desc: object of a process used as founation of cpuscheduling, each process has variables that identify its imporatnce
* used a comparable method
*/



public class Process implements Comparable<Process> {
	/* Needs:
	 * Priority leve internal variable
	 * 
	 */

	private int priority;
	private int timeLeft;
	private int arrivalTime;
	private int reqProcessTime;
	private int timeNotProcesses;
	private int maxPriorityLevel;
	
	public Process(int p, int t, int ct){
		this.priority=p;
		this.timeLeft=t;
		//this.arrivalTime=System.currentTimeMillis();
		this.arrivalTime=ct;
		this.reqProcessTime=t;
		this.timeNotProcesses=0;
		
		
		
	}
	
	
	
	public void setPriority(int p) {
		this.priority = p;
	}
	public void setATime(int t) {
		
		this.arrivalTime=t;
	}
	@Override
	public int compareTo(Process o) {
		//if result is 1 it is bigger prio
		//-1 is less than?

		//check which is high priority
		if(o == null) {
			return -1;
		}
		if(this.priority == o.priority) {
			if(this.arrivalTime > o.arrivalTime) {
				return 1;
			}else if( this.arrivalTime < o.arrivalTime) {
				return -1;
			}else {
				return 0;
			}
		}
		
		if(this.priority > o.priority) {
			return 1;
		}else {
			return -1;
		}
				
	}

	public int getArrivalTime() {
		// TODO Auto-generated method stub
		return this.arrivalTime;
	}

	public int getPriority() {
		// TODO Auto-generated method stub
		return this.priority;
	}

	public int getTimeRemaining() {
		// TODO Auto-generated method stub
		return this.timeLeft;
	}

	public void resetTimeNotProcessed() {
		// TODO Auto-generated method stub
		this.timeNotProcesses=0;
	}
	
	public void upPrio() {
		this.priority++;
	}
	
	//if max but no fihished, increase everthing no enqued, interarte through not including max
	public void notProcessedIncrement() {
		this.timeNotProcesses++;
	}
	public int getTimeNotProcessed() {
		return this.timeNotProcesses;
	}

	public boolean finish() {
		// chec if time lfet =0?
		if(this.timeLeft==0) {
			return true;
		}else {
		return false;
		//reutrn false;
		}
	}
		

	public void reduceTimeRemaining() {
		// TODO Auto-generated method stub
		this.timeLeft--;
		
	}

}
