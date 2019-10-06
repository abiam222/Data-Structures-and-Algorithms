import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.Collection;
import java.util.Collections;
import java.util.Map;
import java.util.Iterator;
import java.util.Comparator;


class arrays {
    public static void main(String[] args){
        int[] A = {1,55,22,13,12};
        String B = "me";
       // Collection myCollect = 
        List<Integer> myIntList = new ArrayList<>();//List(ArrayList) doesn't take primitives
        List<String> myStringList = new ArrayList<>();
        
        myIntList.add(1);
        myIntList.add(2);

        myStringList.add("Lion");
        myStringList.add("Tiger");

        //add in a particular index
        myStringList.add(2,"Elephant");

        // System.out.println(A.length);
        // System.out.println(B.length());
        // System.out.println(myList.size());
       // evenOdd(A);
       // printArray(A);
       //System.out.println(myStringList);//you can print the whole array here

       List<Integer> myIntList2 = new ArrayList<>();
       myIntList2.add(13);
       myIntList2.add(14);

       myIntList2.addAll(myIntList);
       System.out.println(myIntList2);

       //Sorting #1
       //Collections.sort(myIntList2);
       //System.out.println(myIntList2);
       //printArray(myIntList2);

       //Sorting #2 (can be done 3 ways)
       //1.
    //    myIntList2.sort(new Comparator<Integer>() {
    //     @Override
    //     public int compare(String name1, String name2) {
    //         return name1.compareTo(name2);
    //     }
    //    });

        //2
        // myIntList2.sort((name1,name2) -> name1.compareTo(name2));

        //3
        myIntList2.sort(Comparator.naturalOrder());

       System.out.println(myIntList2);

       String test;
       //test.contains()
       //test.length()
      //  test.indeOf()
       // test.charAt(index)
      //  test[0]??
       //compare characters == 
      //compare characters, compare strings.

      //null
    }

    public static void evenOdd(int[] A) {
        int nextEven = 0, nextOdd = A.length - 1;
        while(nextEven < nextOdd) {
            if (A[nextEven]%2==0) {
                nextEven++;
            }else {
                int temp = A[nextEven];
                A[nextEven] = A[nextOdd];
                A[nextOdd--] = temp;
            }
        }
    }

    // public static void printArray(int[] A) {
    //     for (int i=0;i<A.length;i++) {
    //         System.out.print(A[i] + " ");
    //     }
    // }
    public static void printArray(List<Integer> A) {
        // A.forEach(val -> {
        //     System.out.println(val);
        // });

        // Iterator<Integer> listIterator = A.iterator();
        // while (listIterator.hasNext()) {
        //     Integer As  = listIterator.next();
        //     System.out.println(As);
        // }

        // Iterator<Integer> listIterator = A.iterator();
        // listIterator.forEachRemaining(val -> {
        //     System.out.println(val);
        // });

        //traverse backwards
        // ListIterator<Integer> listIterator = A.listIterator(A.size());
        // while(listIterator.hasPrevious()) {
        //     Integer As = listIterator.previous();
        //     System.out.println(As);
        // }

        // for (Integer As: A) {
        //     System.out.println(As);
        // }

        // for (int i=0; i < A.size(); i++) {
        //     System.out.println(A.get(i));
        // }

        
    }
}

/*
1. Instead of deleting an entry consider overwriting 
2. Know you array libraries

https://www.callicoder.com/java-arraylist/

List 
ArrayList (better than Array) - Dynamically sized collection of elements
Collection - a group of individual objects represented as a single unit.

    * Syntax initialize array
    * Call 2D array
    * Array.length, Collections.size(),String.length(), ArrayList.size()
    * asList, binarySearch, copyOf, copyOfRange, equals, fill, 
    find, sort, toString

List (ArrayList)

CREATE 
addAll(x), x=> ArrayList
add(x) x=> value, 
set(x,y) => x (index), y (value)

READ
get(x) => x (given index)

DELETE
remove(x) => x (index)
remove(x) => x (object)
removeAll() => removes all elem from a collection in ArrayList, removeIf() => remove all elem in collection from Arraylist if match a predicate
clear() => clear ArrayList

ITERATORS / SEARCH 
*Above, Collections and ArrayList
forEach
iterator()
forEachRemaining()
listIterator(), 
for (regular), 
simple for-each

contains(x) => x(value looking) boolean answer
indexOf(x) => x(index) find index of first occurrence of elem in ArrayList, else -1
lastIndex(x) => same above but last occurrence 

iterator and listIterator are useful when you need to modify ArrayList while traversing
I don't think you can modify ArrayList while traversing in others

Other
isEmpty() => boolean, size(),, 
f
 You can even add Objects to ArrayLists

You can sort arraylist one of two ways
 Collections.sort()
 ArrayList.sort() //this has 3 different ways
*You can also sort ArrayList that have objects in them

 */