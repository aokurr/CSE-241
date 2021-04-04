/**
*Queues order elements in a FIFO (first-in-first-out) manner.
*/
public interface  Queue<E> extends Collection<E>{
	/**
    *Appends the specified element to the end of this queue.
    *@param e - element to be added to this queue
    */
	void add(E e);
	
	/**
    *Retrieves, but does not remove, the head (first element) of this queue.
    *@return the head of this queue
    */
	E element();
	/**
    Retrieves and removes the head of this queue, or returns null if this queue is empty.
    *@return the head of this queue
    */
	E poll();
	/**
    *inserts the specified element into this queue
    *@param e - element to be added to this queue
    */
	void offer(E e);
}