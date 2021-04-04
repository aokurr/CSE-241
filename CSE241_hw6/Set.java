/**
*A collection that contains no duplicate elements
*/
public interface  Set<E> extends Collection<E>{
	/**
    *Adds the specified element to this set if it is not already present.
    *@return an Iterator over the elements in this set
    */
	public Iterator iterator();
	
	/**
    *Appends the specified element to the end of this set.
    *@param e - element to be added to this set
    */
	public void add(E e);
	
	/**
    *Appends all of the elements in the specified collection to the end of this set, in the order that they are returned by the specified collection's Iterator.
    *@param c - collection containing elements to be added to this set
    */
	public void addAll(Collection c);
	
	/**
    *Removes all of the elements from this set. The set will be empty after this call returns.
    */
	public void clear();
	
	/**
    *Returns true if this set contains the specified element.
    *@param e - element whose presence in this set is to be tested
    *@return true if this set contains the specified element
    */
	public boolean contains(E e);
	
	/**
    *Returns true if this collection contains all of the elements in the specified collection.
    *@param c - element whose presence in this set is to be tested
    *@return true if this set contains the specified object
    */
	public boolean containsAll(Collection c);
	
	/**
    *Returns true if this set contains no elements.
    *@return true if this set contains no elements
    */
	public boolean isEmpty();
	
	/**
    *Removes the specified element from this set if it is present.
    *@param e - object to be removed from this set, if present
    */
	public void remove(E e);
	
	/**
    *Removes all of this collection's elements that are also contained in the specified collection
    *@param c - collection to be removed from this set, if present
    */
	public void removeAll(Collection c);
	
	/**
    *Retains only the elements in this collection that are contained in the specified collection
    *@param c - collection containing elements to be removed from this set
    */
	public void retainAll(Collection c);
	/**
    *Returns the number of elements in this set (its cardinality).
    *@return the number of elements in this set (its cardinality)
    */
	public int size();
}