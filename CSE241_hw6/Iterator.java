
public class Iterator<E> {
    
    private Object copy_array[];
    
    private int index;
    private Collection a;
    public Iterator(Object[] copy,Collection c)
    {
        a=c;
        copy_array = copy;
        index=0;
    }
    /**
    *Returns true if the iteration has more elements.
    *@return true if the iteration has more elements
    */
    public boolean hasNext()
    {
        if(index<copy_array.length)
        {
            return true;
        }
        else {
            return false;
        }
    }
    /**
    *Returns the next element in the iteration.
    *@return the next element in the iteration
    */
    @SuppressWarnings("unchecked")
    public E next()
    {
        
        if(hasNext())
        {
            index+=1;
            return ((E)copy_array[index-1]);
        }
        else 
        {
            return null;
        }
    }
    /**
    Resets the index
    */
    public void zero(){
    	index=0;
    }
    /**
    *Removes from the underlying collection the last element returned by this iterator
    *@throws Exception_queue -This method does not work for Queues, it throws an exception.
    */
    public void remove(){
       Object tmp[]=new Object[copy_array.length-1];
       int j=0;
       try{
            if(a instanceof Queue) 
                throw new Exception_queue("Invalid");
            for(int i=0;i<copy_array.length;i++){
                if(i!=index){
                    tmp[j]=copy_array[i];
                    j++;
                }
            }
            index--;
            copy_array=tmp;
       }
       catch(Exception_queue e){
            e.print_queue_exception();
       }
    }
}