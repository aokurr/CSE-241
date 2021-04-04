/**
*<h1> JAVA COLLECTON HOMEWORK-6!</h1>
*@author AHMET OKUR
*@since 2021-01-25
*/
public class main{
	public static void main(String[] args){
		System.out.printf("\n\t****ARRAY LIST STRING TEST*****\n\n");
		ArrayList<String>Array_list_test  =new ArrayList<String>();
		ArrayList<String>Array_list_test2  =new ArrayList<String>();
		
		
		Array_list_test.add("ahmet");
		Array_list_test.add("ece");
		Iterator iter=Array_list_test.iterator();
		System.out.printf("FIRS LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		Array_list_test2.add("mehmet");
		Array_list_test2.add("gökçe");
		iter=Array_list_test2.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Array_list_test.addAll(Array_list_test2);
		iter=Array_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Array_list_test.removeAll(Array_list_test2);
		iter=Array_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Array_list_test.addAll(Array_list_test2);
		iter=Array_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST from LISTS2!!=");
		Array_list_test.retainAll(Array_list_test2);
		iter=Array_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Array_list_test.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Array_list_test.size());

		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Array_list_test.clear();
		System.out.printf("!!!CLEARING IS DONE!!");

		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");

		
		System.out.printf("\n\n\n\t****ARRAY LIST INTEGER TEST*****\n\n");
		ArrayList<Integer>Array_list_test3  =new ArrayList<Integer>();
		ArrayList<Integer>Array_list_test4  =new ArrayList<Integer>();
		
		Array_list_test3.add(8);
		Array_list_test3.add(1);
		Iterator iter2=Array_list_test3.iterator();
		System.out.printf("FIRS LIST=");
		while(iter2.hasNext()){
			System.out.printf("%s  ",iter2.next());
		}
		
		Array_list_test4.add(3);
		Array_list_test4.add(5);
		iter2=Array_list_test4.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter2.hasNext()){
			System.out.printf("%s  ",iter2.next());
		}

	
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Array_list_test3.addAll(Array_list_test4);
		iter2=Array_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Array_list_test3.removeAll(Array_list_test4);
		iter2=Array_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Array_list_test3.addAll(Array_list_test4);
		iter2=Array_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST FROM  LIST2!!=");
		Array_list_test3.retainAll(Array_list_test4);
		iter2=Array_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Array_list_test3.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Array_list_test3.size());

		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Array_list_test3.clear();
		System.out.printf("!!!CLEARING IS DONE!!\n");

		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");


		

/********************************LINKEDLIST TEST***********************************************************/

		System.out.printf("\n\n\n\n\t****LINKEDLIST STRING TEST*****\n\n");
		LinkedList<String>Lınked_list_test  =new LinkedList<String>();
		LinkedList<String>Lınked_list_test2  =new LinkedList<String>();
		
		
		Lınked_list_test.add("ahmet");
		Lınked_list_test.add("ece");
		iter=Lınked_list_test.iterator();
		System.out.printf("FIRS LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		Lınked_list_test2.add("mehmet");
		Lınked_list_test2.add("gökçe");
		iter=Lınked_list_test2.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Lınked_list_test.addAll(Lınked_list_test2);
		iter=Lınked_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Lınked_list_test.removeAll(Lınked_list_test2);
		iter=Lınked_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Lınked_list_test.addAll(Lınked_list_test2);
		iter=Lınked_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST from LISTS2!!=");
		Lınked_list_test.retainAll(Lınked_list_test2);
		iter=Lınked_list_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Lınked_list_test.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Lınked_list_test.size());

		System.out.printf("\n\n\t!!!ELEMENT METHOD TEST!!=%s",Lınked_list_test.element());
		System.out.printf("\n\n\t!!!POLL METHOD TEST!! DELETED=%s",Lınked_list_test.poll());

		
		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Lınked_list_test.clear();
		System.out.printf("!!!CLEARING IS DONE!!");

		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");

		
		/************************************************************************/
		System.out.printf("\n\n\n\t****LINKED LIST INTEGER TEST*****\n\n");
		LinkedList<Integer>Lınked_list_test3  =new LinkedList<Integer>();
		LinkedList<Integer>Lınked_list_test4  =new LinkedList<Integer>();
		
		Lınked_list_test3.add(8);
		Lınked_list_test3.add(1);
		 iter2=Lınked_list_test3.iterator();
		System.out.printf("FIRS LIST=");
		while(iter2.hasNext()){
			System.out.printf("%s  ",iter2.next());
		}
		
		Lınked_list_test4.add(3);
		Lınked_list_test4.add(5);
		iter2=Lınked_list_test4.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter2.hasNext()){
			System.out.printf("%s  ",iter2.next());
		}

	
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Lınked_list_test3.addAll(Lınked_list_test4);
		iter2=Lınked_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Lınked_list_test3.removeAll(Lınked_list_test4);
		iter2=Lınked_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Lınked_list_test3.addAll(Lınked_list_test4);
		iter2=Lınked_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST FROM  LIST2!!=");
		Lınked_list_test3.retainAll(Lınked_list_test4);
		iter2=Lınked_list_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Lınked_list_test3.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Lınked_list_test3.size());

		System.out.printf("\n\n\t!!!ELEMENT METHOD TEST!!=%d",Lınked_list_test3.element());
		System.out.printf("\n\n\t!!!POLL METHOD TEST!! DELETED=%d",Lınked_list_test3.poll());

		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Lınked_list_test3.clear();
		System.out.printf("!!!CLEARING IS DONE!!\n");

	
		System.out.printf("\n\n\t!!!THROW QUEUE TEST\n");
		iter2.remove();
		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");
		

/********************************HASHSET TEST*******************************************************/
		System.out.printf("\n\t****HASHSET STRING TEST*****\n\n");
		HashSet<String>Hash_set_test  =new HashSet<String>();
		HashSet<String>Hash_set_test2  =new HashSet<String>();
		
		
		Hash_set_test.add("ahmet");
		Hash_set_test.add("ece");
		iter=Hash_set_test.iterator();
		System.out.printf("FIRS LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\nFIRS LIST DUBLICATED TEST (add again 'ahmet')=");
		Hash_set_test.add("ahmet");
		iter=Hash_set_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		Hash_set_test2.add("mehmet");
		Hash_set_test2.add("gökçe");
		iter=Hash_set_test2.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Hash_set_test.addAll(Hash_set_test2);
		iter=Hash_set_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Hash_set_test.removeAll(Hash_set_test2);
		iter=Hash_set_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Hash_set_test.addAll(Hash_set_test2);
		iter=Hash_set_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST from LISTS2!!=");
		Hash_set_test.retainAll(Hash_set_test2);
		iter=Hash_set_test.iterator();
		while(iter.hasNext()){
			System.out.printf("%s  ",iter.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Hash_set_test.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Hash_set_test.size());

		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Hash_set_test.clear();
		System.out.printf("!!!CLEARING IS DONE!!");

		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");

		/***********************************************************************/
		System.out.printf("\n\n\n\t****ARRAY LIST INTEGER TEST*****\n\n");
		HashSet<Integer>Hash_set_test3  =new HashSet<Integer>();
		HashSet<Integer>Hash_set_test4  =new HashSet<Integer>();
		
		Hash_set_test3.add(8);
		Hash_set_test3.add(1);
		iter2=Hash_set_test3.iterator();
		System.out.printf("FIRS LIST=");
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		
		System.out.printf("\nFIRS LIST DUBLICATED TEST (add again '8')=");
		Hash_set_test3.add(8);
		iter2=Hash_set_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		Hash_set_test4.add(3);
		Hash_set_test4.add(5);
		iter2=Hash_set_test4.iterator();
		System.out.printf("\nSECOND LIST=");
		while(iter2.hasNext()){
			System.out.printf("%s  ",iter2.next());
		}

	
		System.out.printf("\n\t!!!ADD ALL METHOD TEST!!=");
		Hash_set_test3.addAll(Hash_set_test4);
		iter2=Hash_set_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		

		System.out.printf("\n\n\t!!!REMOVEALL ALL METHOD TEST!!=");
		Hash_set_test3.removeAll(Hash_set_test4);
		iter2=Hash_set_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}


		System.out.printf("\n\n\t!!!LIST!!=");
		Hash_set_test3.addAll(Hash_set_test4);
		iter2=Hash_set_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		System.out.printf("\n\t!!!RETAINALL ALL METHOD TEST LIST FROM  LIST2!!=");
		Hash_set_test3.retainAll(Hash_set_test4);
		iter2=Hash_set_test3.iterator();
		while(iter2.hasNext()){
			System.out.printf("%d  ",iter2.next());
		}
		
		System.out.printf("\n\n\t!!!isEmpty METHOD TEST!!=");
		if(Hash_set_test3.isEmpty())
			System.out.printf("TRUE!\n");
		else 
			System.out.printf("False!\n");

		System.out.printf("\n\n\t!!!SIZE METHOD TEST!!=");
		System.out.printf("%d\n",Hash_set_test3.size());

		System.out.printf("\n\n\t!!!CLEAR METHOD TEST!!=");
		Hash_set_test3.clear();
		System.out.printf("!!!CLEARING IS DONE!!\n");

		System.out.printf("\n\n\t!!!OTHER METHODS USED IN CLASSES!!\n");

		System.out.printf("\n\n\tRANGE CHECHKING CONTROL!!\n");
		int range=10;
		try{
			if(range-1>Array_list_test.size())
				System.out.printf("%s",Array_list_test.Array_list[range]);
		}
		catch(Exception e){
			System.out.println("RANGE OUT OF!!!");
		}
		

	}
}