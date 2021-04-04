public class Exception_queue extends Exception{
	public Exception_queue(String message){
		super(message);

	}
	/**	
	 use the queue with remove function
	*/
	public void print_queue_exception(){
		System.out.println("THIS IS QUEUE EXCEPTIN");
	}
	/**	
 	if queue is empty 
	*/
	public void print_queue_poll(){
		System.out.println("THIS IS POLL EXCEPTIN");
	}
	public void print_range_exception(){
		System.out.println("THIS IS RANGE  EXCEPTIN");
	}
}