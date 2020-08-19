// Java code to demonstrate Builder Pattern 

/*
Note : Try running main method statements in loop(i.e. multiple requests to server simultaneously).

To solve this problem, there is Builder pattern to ensure the thread-safety and atomicity of object 
creation.

Implementation : In Builder pattern, we have a inner static class named Builder inside our 
Server class with instance fields for that class and also have a factory method to return an new 
instance of Builder class on every invocation. The setter methods will now return Builder class 
reference. We will also have a build method to return instances of Server side class, i.e. outer class.


The builder pattern is a design pattern designed to provide a flexible solution to various object 
creation problems in object-oriented programming. The intent of the Builder design pattern is to 
separate the construction of a complex object from its representation. 
It is one of the Gang of Four design patterns.

*/
  
// Server Side Code 
final class Student { 
  
    // final instance fields 
    private final int id; 
    private final String name; 
    private final String address; 
  
    public Student(Builder builder) 
    { 
        this.id = builder.id; 
        this.name = builder.name; 
        this.address = builder.address; 
    } 
  
    // Static class Builder 
    public static class Builder { 
  
        /// instance fields 
        private int id; 
        private String name; 
        private String address; 
  
        public static Builder newInstance() 
        { 
            return new Builder(); //not singleton because you can always set up a new object
        } 
  
        private Builder() {} 
  
        // Setter methods 
        public Builder setId(int id) 
        { 
            this.id = id; 
            return this; 
        } 
        public Builder setName(String name) 
        { 
            this.name = name; 
            return this; 
        } 
        public Builder setAddress(String address) 
        { 
            this.address = address; 
            return this; 
        } 
  
        // build method to deal with outer class 
        // to return outer instance 
        public Student build() 
        { 
            return new Student(this); 
        } 
    } 
  
    @Override
    public String toString() 
    { 
        return "id = " + this.id + ", name = " + this.name +  
                               ", address = " + this.address; 
    } 
} 
  
// Client Side Code 
class StudentReceiver { 
  
    // volatile student instance to ensure visibility 
    // of shared reference to immutable objects 
    private volatile Student student; //synchronized atomic wrapper
  
    public StudentReceiver() 
    { 
  
        Thread t1 = new Thread(new Runnable() { 
            @Override
            public void run() 
            { 
                student = Student.Builder.newInstance() 
                              .setId(1) 
                              .setName("Ram") 
                              .setAddress("Noida") 
                              .build(); 
            } 
        }); 
  
        Thread t2 = new Thread(new Runnable() { 
            @Override
            public void run() 
            { 
                student = Student.Builder.newInstance() 
                              .setId(2) 
                              .setName("Shyam") 
                              .setAddress("Delhi") 
                              .build(); 
            } 
        }); 
  
        t1.start(); 
        t2.start(); 
    } 
  
    public Student getStudent() 
    { 
        return student; 
    } 
} 
  
// Driver class 
class BuilderNeedDemo { 
    public static void main(String args[]) 
    { 
        StudentReceiver sr = new StudentReceiver(); 
        System.out.println(sr.getStudent()); 
    } 
} 