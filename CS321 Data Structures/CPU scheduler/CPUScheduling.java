// File CPUScheduling.java to simulate the cpu round robin scheduling

class CPUScheduling
{
    public static void main(String[] args)
    {
	if (args.length != 5)
	    {
		System.out.println
		    ("Usage: java CPUScheduling <max-process-time> <max-level> <time-to-increment-level> <simulation-time> <process arrival rate>");
		System.out.println
		    ("<max-process-time>: max number of unit time for executing a process.");
		System.out.println
		    ("<max-level>: priority levels are 1, 2, .. <max-level>");
		System.out.println
		    ("<time-to-increment-level>: number of unit time before a process to increment its priority by 1 if this process does not get any CPU time during this time period."); 
		System.out.println
		    ("<simulation-time>: number of unit time for this simulation.");
		System.out.println
		    ("<process arrival rate>: the process arrival probability within each time unit.");
		System.exit(1);
	    }

	int maxProcessTime = Integer.parseInt(args[0]);
	if (maxProcessTime <= 0)
	    throw new IllegalArgumentException
		("Illegal argument: maxProcessTime must >= 1.");
	int maxLevel = Integer.parseInt(args[1]);
	if (maxLevel <= 0)
	    throw new IllegalArgumentException
		("Illegal argument: maxPriorityLevel must >= 1.");	
	int timeToIncrementLevel = Integer.parseInt(args[2]);
	if (timeToIncrementLevel <= 0)
	    throw new IllegalArgumentException
		("Illegal argument: time-to-increment-level must >= 1.");
	int simulationTime = Integer.parseInt(args[3]);
	if (simulationTime <= 0)
	    throw new IllegalArgumentException
		("Illegal argument: simulationTime must >= 1.");
	double probability = Double.parseDouble(args[4]);
		
	PQueue pqueue = new PQueue();
	Averager averager = new Averager();
	ProcessGenerator pGenerator = new ProcessGenerator(probability);

	for (int currentTime = 0; currentTime < simulationTime; currentTime++)
	    {
		System.out.format("second %3d: ", currentTime);
		
		boolean arrival = false;
		// Check to see if there is any incoming new process.
		if (pGenerator.query())
		    {
			Process p = pGenerator.getNewProcess(currentTime, maxProcessTime, maxLevel);
			System.out.println("JOB " + currentTime + " arrives, timeRequired " + p.getTimeRemaining() + ", priority " + p.getPriority());
			pqueue.enPQueue(p);
			arrival = true;
		    }


		// If the priority queue is not empty. Let the process with
		// highest priority has this time slice. Update the status
		// of this process. Also update the status of all other 
		// processes in the priority queue.
		if (!pqueue.isEmpty())
		    {
			Process next = pqueue.dePQueue();
			next.reduceTimeRemaining();
			pqueue.update(timeToIncrementLevel, maxLevel);
			if (arrival)
			    System.out.print("\t    ");
			if (next.finish())
			    {
				System.out.print("    (Assign to JOB " + next.getArrivalTime() + ": finish, priority " + next.getPriority() + ")");
				averager.addNumber(currentTime - next.getArrivalTime() + 1);
			    }
			else
			    {
				System.out.print("    (Assign to JOB " + next.getArrivalTime() + ": timeRemaining " + next.getTimeRemaining() + ", priority " + next.getPriority() + ")");
				next.resetTimeNotProcessed();
				pqueue.enPQueue(next);
			    }
		    }
		System.out.println();
	    }
	
	System.out.println("--- Simulation completed ---");
	System.out.println("Simulation time: " + args[3] + " unit time.");
	System.out.println("Number of processes: " 
			   + averager.howManyProcesses());
	System.out.println("Average Turn around time for a process: "
			   + averager.average());
    }
}








