/*
 * @author Andrew Gerber
 * Date:september 2020
 *
 * Desc:randomly generates processes with a given probability. At beginning of each time unit,
 *  whether a process will arrive is decided by the given probability.
 *  In addition, while generating a new process, both its priority and the required time units to finish the
process are randomly generated within given ranges.
 */
import java.util.Random;
public class ProcessGenerator {
	
	private double probablity;
	private Random rand = new Random();
	
	public ProcessGenerator(double probablity ) {
		this.probablity = probablity;
	}

	
	
	public boolean query() {
	
		return (rand.nextDouble() <= this.probablity) ? true : false; 
	}
	
	public Process getNewProcess(int currentTime, int maxProcessTime,int maxLevel) {
		
		
		int randomPrio = rand.nextInt(maxLevel) + 1;
		int randomTime = rand.nextInt(maxProcessTime) + 1;
	
		Process newProcess = new Process(randomPrio, randomTime, currentTime);
		
		return newProcess;
	}
}
