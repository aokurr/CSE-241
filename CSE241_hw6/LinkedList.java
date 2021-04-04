public class LinkedList<E> implements List<E>,Queue<E>{
	public LinkedList(){
		Linked_list=null;
		size=0;
	}
	public  Object[] Linked_list;

	private int size;
	/**
    *Returns an iterator over the elements in this list.
    *@return an Iterator over the elements in this list
    */
	public Iterator iterator(){
		Iterator <E> iter =new Iterator<E>(Linked_list,this);

		return iter;
	}
	/**
    *inserts the specified element into this queue
    *@param e - element to be added to this list
    */
	public void offer(E e){
		
		if(Linked_list==null){
			Linked_list = new Object [1];
			Linked_list[0]=e;
			size++;
			return ;
		}
		else{
			Object tmp[]=new Object[size+1];
			int i;
			for(i=0;i<size;i++){
				tmp[i]=Linked_list[i];
			}
			tmp[size]=e;
			Linked_list=tmp;
			size++;
			
		}
	}
	/**
    *Appends the specified element to the end of this list.
    *@param e - element to be added to this list
    */
	public void add(E e){
		offer(e);
	}
	
	/**
    *Removes all of the elements from this list. The list will be empty after this call returns.
    */
	public void clear(){
		Linked_list=null;
		size=0;
	}
	
	/**
    *Appends all of the elements in the specified collection to the end of this list, in the order that they are returned by the specified collection's Iterator.
    *@param c - collection containing elements to be added to this list
    */
	public void addAll(Collection c){
		Iterator iter=c.iterator();
		int i;
		if(c.size()!=0){
			Object[]tmp=new Object[size+c.size()];
			for( i=0;i<size;i++){
				tmp[i]=Linked_list[i];
			}
			
			for( i=0;iter.hasNext();i++){
				tmp[i+size]=iter.next();
			}
			Linked_list=tmp;
			size+=c.size();
		}

	}
	
	/**
    *Returns the number of elements in this list.
    *@return the number of elements in this list .
    */
	public int size(){	
		return size;
	}
	
	/**
    *Returns true if this list contains the specified element.
    *@param e - element whose presence in this list is to be tested
    *@return true if this list contains the specified element
    */
	public boolean contains(E e){
		for(int i=0;i<size;i++){
			if(Linked_list[i]==e){
				return true;
			}
		}
		return false;
	}
	
	/**
    *Returns true if this collection contains all of the elements in the specified collection.
    *@param c - element whose presence in this list is to be tested
    *@return true if this list contains the specified object
    */
	@SuppressWarnings("unchecked")
	public boolean containsAll(Collection c){
		boolean flag =false;
		E e;
		if(c.size()>size)
			return false;

		Iterator iter=c.iterator();
		for(int i=0;iter.hasNext();i++){
			flag=false;
			e=(E)iter.next();
			for(int j=0;j<size;j++){
				if(e==Linked_list[j]){
					flag=true;
				}
			}
			if(flag==false)
				return false;
		}
		return true;
	}
	
	/**
    *Returns true if this list contains no elements.
    *@return true if this list contains no elements
    */
	public boolean isEmpty(){
		if(Linked_list==null)
			return true;

		return false;
	}
	
	/**
    *Removes the specified element from this list if it is present.
    *@param e - object to be removed from this list, if present
    */
	public void remove(E e){
		int j=0;
		if(contains(e)){
			
			Object[]tmp=new Object[size-1];
			for(int i=0;i<size;i++){
				if(Linked_list[i]!=e){
					tmp[j]=Linked_list[i];
					j++;
				}
			}
			size--;
			Linked_list=tmp;
		}
	}
	
	/**
    *Removes all of this collection's elements that are also contained in the specified collection
    *@param c - collection to be removed from this list, if present
    */
	@SuppressWarnings("unchecked")
	public void removeAll(Collection c){
		Iterator iter=c.iterator();
		for(int i=0;iter.hasNext();i++){
			
			remove((E)iter.next());
		}
	}
	
	/**
    *Retains only the elements in this collection that are contained in the specified collection
    *@param c - collection containing elements to be removed from this list
    */
	public void retainAll(Collection c){
		Iterator iter=c.iterator();
		Object[] tmp;
		int i,j;
		int count=0;
		for( i=0;i<size;i++){
			for(j=0;iter.hasNext();j++){
				if(Linked_list[i]==iter.next()){
					count++;
				}
			}
			iter.zero();
		}
		iter.zero();
		tmp=new Object[count];
		int k=0;
		for(i=0;i<size;i++){
			for(j=0;iter.hasNext();j++){
				if(Linked_list[i]==iter.next()){
					tmp[k]=Linked_list[i];
					k++;
				}
			}
			iter.zero();
		}
		size=count;
		Linked_list=tmp;
	}

	/**
    *Retrieves, but does not remove, the head (first element) of this list.
    *@return the head of this list
    */
	@SuppressWarnings("unchecked")
	public E element(){
		return (E)Linked_list[0];
	}
	

	/**
    *Retrieves and removes the head (first element) of this list.
    *@return the head of this list
    */
	@SuppressWarnings("unchecked")
	public E poll(){
		try{
			if(Linked_list==null)
				throw new Exception_queue("Invalid");
		}
		catch(Exception_queue e){
			e.print_queue_poll();
			return null;
		}
		
		if(size==1){
			Linked_list=null;
			return (E)Linked_list[0];
		}
		E e;
		e=(E)Linked_list[0];
		Object[] tmp=new Object[size-1];
		for(int i=1;i<size;i++){
			tmp[i-1]=Linked_list[i];
		}
		Linked_list=tmp;
		size--;
		return e;
	}

}
