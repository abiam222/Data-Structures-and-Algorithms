class Singleton 
{ 
    // static variable single_instance of type Singleton 
    private static Singleton single_instance = null; 
  
    // variable of type String 
    public String s; 
  
    // private constructor restricted to this class itself 
    private Singleton() 
    { 
        s = "Hello I am a string part of Singleton class"; 
    } 
  
    // static method to create instance of Singleton class 
    public static Singleton getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new Singleton(); 
  
        return single_instance; 
    } 
} 

class Main 
{ 
    public static void main(String args[]) 
    { 
        // instantiating Singleton class with variable x 
        Singleton x = Singleton.getInstance(); 
  
        // instantiating Singleton class with variable y 
        Singleton y = Singleton.getInstance(); 
  
        // instantiating Singleton class with variable z 
        Singleton z = Singleton.getInstance(); 
  
        // changing variable of instance x 
        x.s = (x.s).toUpperCase(); 
  
        System.out.println("String from x is " + x.s); 
        System.out.println("String from y is " + y.s); 
        System.out.println("String from z is " + z.s); 
        System.out.println("\n"); 
  
        // changing variable of instance z 
        z.s = (z.s).toLowerCase(); 
  
        System.out.println("String from x is " + x.s); 
        System.out.println("String from y is " + y.s); 
        System.out.println("String from z is " + z.s); 
    } 
} 


/*

A singleton pattern ensures that you always get back the same instance of whatever type you are retrieving, 
whereas the factory pattern generally gives you a different instance of each type.

The purpose of the singleton is where you want all calls to go through the same instance.
An example of this might be a class that manages a disk cache, or gets data from a static dictionary; 
wherever it is important only one known instance interacts with the resource. 
This does make it less scalable.

The purpose of the factory is to create and return new instances. 
Often, these won't actually be the same type at all, 
but they will be implementations of the same base class. However, there may be many instances 
of each type



*/