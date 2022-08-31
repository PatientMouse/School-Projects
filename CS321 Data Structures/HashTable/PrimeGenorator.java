import java.util.*;
import java.lang.*;

public class PrimeGenorator {

//	static int GenoratePrime(int lowerbound, int upperbound) {
//		Random rand = new Random();
//		int p = rand.nextInt(upperbound-lowerbound) + lowerbound;
//		int tmpPrime;
//		int realPrime =0;
//		//int p = 95789;              
//
//		int bigP = 0;
//		//a^p-1 mod p /= p then its not a prime
//		while(realPrime ==0) {
//			for(int i =lowerbound; i<upperbound;i++) {
//				if(isPrime(i) == 1 && isPrime(i+2) == 1) {
//					realPrime = i;
//					break;
//				}
//			}
//
//		}
//
//
//
//		//System.out.print("p: "+p+", p+2: "+(p+2) + ". Are Twin Primes: ");
//		return realPrime;
//	}

	static public int getPrime() {
		int prime = -1;
		Random rand = new Random();
		int upperbound = 96000;
		int lowerbound = 95500;

		//String binary = Integer.toBinaryString(m);
		//int base = rand.nextInt(m)+1;
		//int result = base;
		int num = 95500;//rand.nextInt(upperbound-lowerbound) + lowerbound;
		boolean isprime = false;
		for(int j = num; j < upperbound; j++) {
			if(isPrime(j) == true && isPrime(j-2)== true) {
				if(isPrime(j) == true && isPrime(j-2)== true) {
					return j;
				}
			}
		}
		return prime;
	}
	
	public static boolean isPrime(int n) 
    { 
        if (n <= 1) {
            return false; 
        }for (int i = 2; i < n; i++) {
            if (n % i == 0) 
                return false; }
  
        return true; 
        
    } 
//	static public int isPrime() {
//		int num = 29;
//		boolean flag = false;
//		for (int i = 2; i <= num / 2; ++i) {
//			// condition for nonprime number
//			if (num % i == 0) {
//				flag = true;
//				break;
//			}
//		}
//
//		if (!flag)
//			System.out.println(num + " is a prime number.");
//		else
//			System.out.println(num + " is not a prime number.");
//	}
//}

	
}