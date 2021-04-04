/**
*The root interface in the collection hierarchy.
*/
public interface  Collection<E>{
	/**
    *Returns an iterator over the elements in this collection.
    *@return an Iterator over the elements in this collection
    */
	public Iterator iterator();
	
	/**
    *Appends the specified element to the end of this collection.
    *@param e - element to be added to this collection
    */
	public void add(E e);
	
	/**
    *Appends all of the elements in the specified collection to the end of this collection, in the order that they are returned by the specified collection's Iterator.
    *@param c - collection containing elements to be added to this collection
    */
	public void addAll(Collection c);
	
	/**
    *Removes all of the elements from this collection. The collection will be empty after this call returns.
    */
	public void clear();
	
	/**
    *Returns true if this collection contains the specified element.
    *@param e - element whose presence in this collection is to be tested
    *@return true if this collection contains the specified element
    */
	public boolean contains(E e);
	
	/**
    *Returns true if this collection contains all of the elements in the specified collection.
    *@param c - element whose presence in this collection is to be tested
    *@return true if this collection contains the specified object
    */
	public boolean containsAll(Collection c);
	
	/**
    *Returns true if this collection contains no elements.
    *@return true if this collection contains no elements
    */
	public boolean isEmpty();
	
	/**
    *Removes the specified element from this collection if it is present.
    *@param e - object to be removed from this collection, if present
    */
	public void remove(E e);
	
	/**
    *Removes all of this collection's elements that are also contained in the specified collection
    *@param c - collection to be removed from this collection, if present
    */
	public void removeAll(Collection c);
	
	/**
    *Retains only the elements in this collection that are contained in the specified collection
    *@param c - collection containing elements to be removed from this collection
    */
	public void retainAll(Collection c);
	/**
    *Returns the number of elements in this set (its cardinality).
    *@return the number of elements in this set (its cardinality)
    */
	public int size();
}